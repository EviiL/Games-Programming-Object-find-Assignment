#include "KeyboardHandler.h"
#include <iostream>
#include <GLFW\glfw3.h>


bool KeyboardHandler::keys[65536];

void KeyboardHandler::invoke(int key, int scancode, int action, int mods) {
		keys[key] = action != GLFW_RELEASE;
}

bool KeyboardHandler::isKeyDown(int key) {
	return keys[key];
}
