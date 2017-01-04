#include "Game.h"
#include "Rendering\ResourceManager.h"
#include "Components\TransformComponent.h"
#include "Components\RenderComponent.h"
#include "Components\PlayerKeyboardControlComponent.h"
#include "Rendering\MeshFactory.h"



static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Close the window and thus kill the Engine.
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

	KeyboardHandler::invoke(key, scancode, action, mods);
}



void Game::update(double dTime) {
	//Update the scene, close to the initial loop to minimise time discrepancy.
	//TODO implement custom timer for better time management.
	m_SceneManager_.getCurrentScene()->Update(dTime);
}


void Game::beginLoop() {

	double m_dTickTime = glfwGetTime();
	double lastTime = 0.0;
	int nbFrames = 0;

	const float TICKS_PER_SECOND = 1.0f / 60.0f;
	double tick = 0.0;


	//Start the Scenes Components.
	m_SceneManager_.getCurrentScene()->Start();

	while (!glfwWindowShouldClose(m_WindowManager_.getWindow()))
	{


		// Measure speed
		double currentTime = glfwGetTime();
		nbFrames++;

		if (currentTime - lastTime >= 1.0) { 
			std::cout << nbFrames << std::endl;
			nbFrames = 0;
			lastTime += 1.0;


		}

		//float ratio;
		int width, height;
		glfwGetFramebufferSize(m_WindowManager_.getWindow(), &width, &height);
		//ratio = width / (float)height;
		glViewport(0, 0, width, height);


		double currentTickTime = glfwGetTime();

		double frame = currentTickTime - m_dTickTime;
		m_dTickTime = currentTickTime;

		/*
		If Time and Tick difference is more than 0.25 of a second, cap it.
		*/
		if (frame > 0.25f) {
			frame = 0.25f;
		}


		tick += frame;

		while (tick >= TICKS_PER_SECOND) {
			float fDelay = (tick / TICKS_PER_SECOND);

			update(frame);

			tick -= TICKS_PER_SECOND;

		}
		m_Renderer_->Render();
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}


Game::Game() {

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	m_WindowManager_.createWindow("Game", 0, 0, 1280, 720);
	m_WindowManager_.toggleVSYNC(false);
	
	//m_Window_ = glfwCreateWindow(1280, 720, "Game", NULL, NULL);
	glfwMakeContextCurrent(m_WindowManager_.getWindow());

	if (!m_WindowManager_.getWindow())
	{
		glfwTerminate();	
		exit(EXIT_FAILURE);
	}

	glewInit();

	glfwSetKeyCallback(m_WindowManager_.getWindow(), key_callback);
	ResourceManager::getInstance()->LoadShader("Shaders/default_shader.vert", "Shaders/default_shader.frag", "default");


	m_Renderer_ = new Renderer(m_WindowManager_.getWindow());

	m_SceneManager_ = SceneManager();

	if (m_SceneManager_.LoadScene(" ")) {
		m_SceneManager_.UpdateRenderer(m_Renderer_);
	}


}

//Create the Scene here. Should be data driven.
void Game::CreateScene() {

	

}


//Move somewhere else at some point. Preferably a Launcher file all on its own, isolated from other function calls.
int main(int argc, char* argv[]) {
	Game game = Game();

	game.beginLoop();

	//Should never reach here, if we do, something has gone terribly wrong. Upon termination, the beginLoop function will close GLFW and exit the program itself.
	return EXIT_FAILURE;

}