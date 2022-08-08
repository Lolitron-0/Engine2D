#include "Window.hpp"
#include "Utils.hpp"

Window::Window(GLint width, GLint height, const char* name) :
	mButtonsStates(GLFW_KEY_LAST + 1)
{
	this->mpWindowHandle.reset(
		glfwCreateWindow(width, height, name, NULL, NULL), //new value
		std::bind(glfwDestroyWindow, this->mpWindowHandle.get())); //deleter functor

	glfwMakeContextCurrent(this->mpWindowHandle.get());
	glLoadIdentity();
	glOrtho(0, 1, 1, 0, -1, 1);

	//we need pointer to this object in callback lambdas
	glfwSetWindowUserPointer(this->mpWindowHandle.get(), this);

	this->addOnKey([](GLFWwindow* window, int key, int, int action, int mods) {
		//we dont want to process it yet
		if (action == GLFW_REPEAT) return;

		//extract pointer to [this]
		Window* thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));
		thisPtr->mButtonsStates[key].isPressed = (action == GLFW_PRESS);
		std::cout << thisPtr->mButtonsStates[key].isPressed << std::endl;
	});

	glfwSetKeyCallback(this->mpWindowHandle.get(), [](GLFWwindow* window, int key, int scan, int action, int mods) {
		//extract pointer to [this]
		Window* thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));
		thisPtr->keyDeleagte.callAll(window,key,scan,action,mods);
	});

	glfwSetWindowSizeCallback(this->mpWindowHandle.get(), [](GLFWwindow*, int w, int h) {
		glViewport(0,0, w,h);
	});
}

bool Window::isOpen()
{
	return !glfwWindowShouldClose(this->mpWindowHandle.get());
}

void Window::addOnKey(const std::function<void(GLFWwindow*, int, int, int, int)>& callback)
{
	this->keyDeleagte.pushCallback(callback);
}

void Window::display()
{
	glfwSwapBuffers(this->mpWindowHandle.get());
}

bool Window::isKeyPressed(int num)
{
	return mButtonsStates[num].isPressed;
}
