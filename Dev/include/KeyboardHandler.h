#ifndef _KEY_HANDLER_H_
#define _KEY_HANDLER_H_


class KeyboardHandler {

public:
	static bool keys[65536];


	static void invoke(int key, int scancode, int action, int mods);

	static bool isKeyDown(int key);
	
private:
	KeyboardHandler() {}

};





#endif // !_REALM_KEY_HANDLER_H_
