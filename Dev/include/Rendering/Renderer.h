#ifndef RENDERER_H_
#define RENDERER_H_

#include <gl\glew.h>
#include <GLFW\glfw3.h>


#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#include "Scene.h"
#include "ObjectVectorWrapper.h"



class Renderer {

private:
	Scene * m_CurrentScene_;
	ObjectVectorWrapper::t_Object_Vector_ m_sceneObjects_;
	GLFWwindow * m_Window_;

public:
	Renderer() {

	}
	Renderer(GLFWwindow * pWindow);
	
	void Render();
	
	void setScene(Scene * pScene);
};



#endif