#include "Rendering\Renderer.h"
#include "Components\RenderComponent.h"

Renderer::Renderer(GLFWwindow * pWindow) {
	m_Window_ = pWindow;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClearColor(0.1, 0.1, 0.4, 1.0);
	
}

void Renderer::Render() {
	glm::mat4 Projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.f);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(5, 5, 5),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Check if the scene is dirty or not and needs an update.
	if (m_CurrentScene_->M_bIsDirty) {

		m_sceneObjects_.clear(); //Currently clearing the list, but should become more dynamic in the future.

		ObjectVectorWrapper::t_Object_Vector_ temp = m_CurrentScene_->getObjects();
		for (ObjectVectorWrapper::t_Object_Vector_Iterator_ iter = temp.begin(); iter != temp.end(); ++iter) {
			if ((*iter).CheckComponentTypeExists<RenderComponent>()) {
				m_sceneObjects_.push_back(*iter); //Add object to the list.
			}
		}
		//No need to check again.
		m_CurrentScene_->M_bIsDirty = false;
	}

	//Render the scenes objects. Possibly provide filtering to improve performance speed. Or maybe even have it within its own thread.
	for (ObjectVectorWrapper::t_Object_Vector_Iterator_ iter = m_sceneObjects_.begin(); iter != m_sceneObjects_.end(); ++iter) {
		//Get the render component from the object list and let it render itself.
		RenderComponent * render = (*iter).GetComponentByType<RenderComponent>();
		render->Render(Projection, View);
		
	}


	glfwSwapBuffers(m_Window_);
	glfwPollEvents();
}

void Renderer::setScene(Scene * pScene) {
	m_CurrentScene_ = pScene;
}

