#ifndef _GAME_H_
#define _GAME_H_

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include "Rendering\Renderer.h"
#include "InputHandler.h"
#include "WindowManager.h"
#include "SceneManager.h"

#include "Rendering\GUI\GUIRenderer.h"

#include "Proxy.h"

#include <cstdlib>

//Could probably do with being renamed to Engine or similar.
class Game {
public:

	Game();
	void beginLoop();
	void update(double dTime);
private:
	WindowManager m_WindowManager_;
	Renderer * m_Renderer_;
	GUIRenderer * m_GUIRenderer_;
	void CreateScene();

	void switchScene(std::string pPath);

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);



};


#endif;