#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

class Mouse
{
public:
	Mouse();
	~Mouse();

	bool isPressed(GLFWwindow* window, int btn);

	float x() { return (float)posX;}
	float y() { return (float)posY;}
private:
	double posX, posY;
};

#endif