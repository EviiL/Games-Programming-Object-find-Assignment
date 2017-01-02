#include "WindowManager.h"


void window_size_callback(GLFWwindow* window, int width, int height) {


}

void cursor_move_callback(GLFWwindow* window, double xpos, double ypos) {


}


WindowManager::WindowManager() {
	//Just shouldnt be used, other constructors should be used instead.

}
WindowManager::WindowManager(int pXPos, int pYPos, int pWidth, int pHeight) {
	m_Window_ = glfwCreateWindow(pWidth, pHeight, "Engine", NULL, NULL);
	glfwSetWindowPos(m_Window_, pXPos, pYPos);
	glfwMakeContextCurrent(m_Window_);

	glfwSetWindowSizeCallback(m_Window_, window_size_callback);
	glfwSetCursorPosCallback(m_Window_, cursor_move_callback);

}
WindowManager::WindowManager(std::string pTitle, int pXPos, int pYPos, int pWidth, int pHeight) {
	m_Window_ = glfwCreateWindow(pWidth, pHeight, pTitle.c_str(), NULL, NULL);
	glfwSetWindowPos(m_Window_, pXPos, pYPos);
	glfwMakeContextCurrent(m_Window_);

	glfwSetWindowSizeCallback(m_Window_, window_size_callback);
	glfwSetCursorPosCallback(m_Window_, cursor_move_callback);

}
WindowManager::~WindowManager() {
	delete m_Window_;
}

GLFWwindow * WindowManager::createWindow(std::string pTitle, int pXPos, int pYPos, int pWidth, int pHeight) {
	m_Window_ = glfwCreateWindow(pWidth, pHeight, pTitle.c_str(), NULL, NULL);
	//glfwSetWindowPos(m_Window_, pXPos, pYPos);
	glfwMakeContextCurrent(m_Window_);


	glfwSetWindowSizeCallback(m_Window_, window_size_callback);
	glfwSetCursorPosCallback(m_Window_, cursor_move_callback);

	return m_Window_;

}
GLFWwindow * WindowManager::createWindow(std::string pTitle, int pXPos, int pYPos, int pWidth, int pHeight, GLFWmonitor * pMonitor) {
	m_Window_ = glfwCreateWindow(pWidth, pHeight, pTitle.c_str(), pMonitor, NULL);
	glfwMakeContextCurrent(m_Window_);


	glfwSetWindowSizeCallback(m_Window_, window_size_callback);
	glfwSetCursorPosCallback(m_Window_, cursor_move_callback);

	return m_Window_;
}

//Add input manager to listen to feedback.

bool WindowManager::doesWindowExist() {
	if (m_Window_ == nullptr) return false;
	return true;
}

void WindowManager::toggleVSYNC(bool pToggle) {
	glfwSwapInterval(pToggle);
}

void WindowManager::setCursorPosition(double pXPos, double pYPos) {
	glfwSetCursorPos(m_Window_, pXPos, pYPos);
}

void WindowManager::destroyWindow() {
	glfwDestroyWindow(m_Window_);
}

GLFWwindow * WindowManager::getWindow() {
	return m_Window_;
}
