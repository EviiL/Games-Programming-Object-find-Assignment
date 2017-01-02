#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <iostream>
#include <GLFW\glfw3.h>

class WindowManager {
private:
	GLFWwindow * m_Window_;

public:
	WindowManager();
	WindowManager(int pXPos, int pYPos, int pWidth, int pHeight);
	WindowManager(std::string pTitle, int pXPos, int pYPos, int pWidth, int pHeight);
	~WindowManager();

	GLFWwindow * createWindow(std::string pTitle, int pXPos, int pYPos, int pWidth, int pHeight);
	GLFWwindow * createWindow(std::string pTitle, int pXPos, int pYPos, int pWidth, int pHeight, GLFWmonitor * pMonitor);

	//Add input manager to listen to feedback.

	bool doesWindowExist();

	void toggleVSYNC(bool pToggle);

	void setCursorPosition(double pXPos, double pYPos);
	//Add get cursor position.

	void destroyWindow();

	GLFWwindow * getWindow();

};

#endif