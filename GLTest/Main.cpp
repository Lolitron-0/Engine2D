#define STB_IMAGE_IMPLEMENTATION
#include "./Includes/stb_image.h"
#undef STB_IMAGE_IMPLEMENTATION
#include <./Includes/GLFW/glfw3.h>
#include <iostream>
#include <utility>
#include <EngineHeader.hpp>
#include <Dino.hpp>
#include <Floor.hpp>
#include <Cactus.hpp>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500

void errFun(int code, const char* desc)
{
	std::cout << code << "     " << desc;
}


int main()
{
	glfwInit();

	glfwSetErrorCallback(errFun);

	Dino dino(100, 0);
	Cactus cactus(SCREEN_WIDTH, 0);
	Floor floor(Rect<float>(0,SCREEN_HEIGHT*0.9,SCREEN_WIDTH, 100));
	Window::getInstance().setSize(Vector2<int>(SCREEN_WIDTH, SCREEN_HEIGHT)); //TODO: everything must recount glcoords idk how to (listener wtf)

	glLoadIdentity();
	glOrtho(0, 1, 1, 0, -1, 1);

	//std::shared_ptr<Window> window(new Window(SCREEN_WIDTH, SCREEN_HEIGHT, "awd"));

	while (Window::getInstance().isOpen())
	{
		glfwPollEvents();

		glClearColor(0.07f, 0.13f, 0.17f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);


		dino.update();
		cactus.update();
		GameObjectSystem::getInstance().processAll();
		PhysicBodySystem::getInstance().processAll();
		ColliderSystem::getInstance().processAll();

		dino.draw();
		cactus.draw();

		floor.draw();

		Window::getInstance().display();
		IterationTimer::getInstance().reset();//must be in the end
	}

	glfwTerminate();
	return 0;
}
