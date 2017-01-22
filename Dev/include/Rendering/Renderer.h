#ifndef RENDERER_H_
#define RENDERER_H_

#include <gl\glew.h>
#include <GLFW\glfw3.h>


#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#include "Scene.h"
#include "GameObjectVectorWrapper.h"



class Renderer {

private:
	Scene * m_CurrentScene_;
	GameObjectVectorWrapper::t_GameObject_Vector_ m_sceneGameObjects_;
	GLFWwindow * m_Window_;

public:
	Renderer() {

	}
	Renderer(GLFWwindow * pWindow);
	
	void Render();
	
	void setScene(Scene * pScene);
};



#endif