#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <GLFW/glfw3.h>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	bool isPressed(GLFWwindow* window, int key);
private:
};

#endif//KEYBOARD_H