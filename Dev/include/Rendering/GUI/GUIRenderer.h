#ifndef _GUI_RENDERER_H_
#define _GUI_RENDERER_H_


#include <gl\glew.h>
#include <GLFW\glfw3.h>


#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#include "Scene.h"
#include "GameObjectVectorWrapper.h"
#include "Components\GUI\CanvasComponent.h"


class GUIRenderer {

	enum GUIType {
		FULL_MENU,
		OVERLAY
	};

private:
	Scene * m_CurrentScene_;
	GameObjectVectorWrapper::t_GameObject_Vector_ m_sceneGameObjects_;
	GLFWwindow * m_Window_;


	glm::mat4 Projection = glm::ortho((1280.f / 2) * 0, 1280.f, 720.f, (720.f / 2) * 0, -1.0f, 1.0f);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(1, 1, 1),
		glm::vec3(1, 1, 0),
		glm::vec3(0, 1, 0)
	);




public:
	GUIRenderer() {

	}
	GUIRenderer(GLFWwindow * pWindow);

	void Render();

	void setScene(Scene * pScene);
};


#endif