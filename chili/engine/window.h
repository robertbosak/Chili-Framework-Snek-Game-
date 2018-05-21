#define GLEW_STATIC

#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "keyboard.h"
#include "mouse.h"

class MainWindow
{
	public:
		MainWindow();

		~MainWindow();

		void processEvents();
		void show();
		
		GLFWwindow* getWindow() {return window; }

		static constexpr int ScreenWidth = 800;
		static constexpr int ScreenHeight = 600;

		Keyboard kbd;
        Mouse mouse;

	private:
		GLFWwindow* window;
};

#endif//WINDOW_H
