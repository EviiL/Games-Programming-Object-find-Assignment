#ifndef _GAME_H_
#define _GAME_H_

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include "Rendering\Renderer.h"
#include "KeyboardHandler.h"
#include "WindowManager.h"


//Could probably do with being renamed to Engine or similar.
class Game {
public:

	Game();
	void beginLoop();
	void update(double dTime);
private:
	WindowManager m_WindowManager_;
	Renderer * m_Renderer_;

	Scene * m_Scene_;

	void CreateScene();



};


#endif;