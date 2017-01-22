#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_


class InputHandler {

public:
	static bool keys[65536];
	static bool buttons[8]; //GLFW can only record 8 individual mouse buttons.


	static void invokeKey(int key, int scancode, int action, int mods);
	static void invokeButton(int button, int action, int mods);

	static bool isKeyDown(int key);
	static bool isButtonDown(int button);
	
private:
	InputHandler() {}

};





#endif 
