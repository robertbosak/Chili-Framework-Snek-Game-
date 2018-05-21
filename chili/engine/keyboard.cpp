#include "keyboard.h"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{

}

bool Keyboard::isPressed(GLFWwindow* window, int key)
{
	if(glfwGetKey(window, key) == GLFW_PRESS)
		return true;
	return false;
}
