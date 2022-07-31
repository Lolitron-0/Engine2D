#include <iostream>
#include <GLFW/glfw3.h>
#include "Utils.hpp"
#include "RectangleShape.hpp"
#include "Window.hpp"
#include "Line.h"
#include <Dino.hpp>

void errFun(int code, const char* desc)
{
	std::cout << code << "     " << desc;
}

void initCallbacks(Window& window)
{

}

int main()
{
	glfwInit();

	glfwSetErrorCallback(errFun);

	Dino dino(100, 0);
	Line floor(0, SCREEN_HEIGHT*0.9, SCREEN_WIDTH, SCREEN_HEIGHT * 0.9);

	glLoadIdentity();
	glOrtho(0, 1, 1, 0, -1, 1);

	std::shared_ptr<Window> window(new Window(SCREEN_WIDTH, SCREEN_HEIGHT, "awd"));

	while (window->isOpen())
	{
		glfwPollEvents();

		glClearColor(0.07f, 0.13f, 0.17f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		dino.update();
		dino.draw();

		floor.draw();

		window->display();
	}

	glfwTerminate();
	return 0;
}