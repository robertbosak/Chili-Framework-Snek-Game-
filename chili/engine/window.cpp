#include <iostream>

#include "window.h"

MainWindow::MainWindow()
{
	if(!glfwInit())
		std::cout << "GLFW failed to init!" << std::endl;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(ScreenWidth, ScreenHeight, "My Window", NULL, NULL);
	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if(err != GLEW_OK)
	{
		fprintf(stderr, "ERROR: %s\n", glewGetErrorString(err));
		glfwTerminate();
	}
    
    glPointSize(2);
}

MainWindow::~MainWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void MainWindow::processEvents()
{
	glfwPollEvents();

	if(kbd.isPressed(window, GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window, true);
}

void MainWindow::show()
{
	glfwSwapBuffers(window);
}
