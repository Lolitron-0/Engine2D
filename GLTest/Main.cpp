#include <iostream>
#include <GLFW/glfw3.h>
#include <EngineHeader.hpp>
#include <Dino.hpp>
#include <Floor.hpp>
#include <Cactus.hpp>

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
	Cactus cactus(SCREEN_WIDTH - 200, 0);
	Floor floor;

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
	}

	glfwTerminate();
	return 0;
}
