#ifndef _PROXY_H_
#define _PROXY_H_


#include "WindowManager.h"

#include <GLFW\glfw3.h>


//Acts as a representative for other classes to allow them to interface with areas they have no specific access to.
class Proxy {

private:
	static Proxy * s_Instance_;

	WindowManager * m_WindowManager_;
	
	Proxy() { }
public:
	static Proxy *getInstance()
	{

		if (s_Instance_ == 0) {

			Proxy * temp = new Proxy();
			s_Instance_ = temp;



		}
		// Instantiated on first use.
		return s_Instance_;
	}

	void AssignWindowManager(WindowManager * pWindowManager) {
		m_WindowManager_ = pWindowManager;
	}

	//TODO add other request methods.
	//TODO Ensure checks that a request is valid or perhaps move to a different thread to allow them to run asyncronously alongside the main thread?
	void requestCursorPositionChange(double pX, double pY);
	void requestWindowSize(int &pWidth, int &pHeight);
	void requestCursorPos(double &pX, double &pY);
	void setUIFocus(bool pToggle);
	void requestCursorDrawChange(bool ptoggle);
};

#endif