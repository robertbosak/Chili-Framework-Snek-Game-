#include "mouse.h"

Mouse::Mouse()
{
	posX = 0;
	posY = 0;
}

Mouse::~Mouse()
{

}

bool Mouse::isPressed(GLFWwindow* window, int btn)
{
	if(glfwGetMouseButton(window, btn) == GLFW_PRESS)
	{
		glfwGetCursorPos(window, &posX, &posY);
		return true;
	}
	return false;
}


