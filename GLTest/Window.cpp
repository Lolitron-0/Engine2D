#include "Window.hpp"

Window::Window(GLint width, GLint height, const char* name) :
	mButtonsStates(GLFW_KEY_LAST + 1),mWindowSize(width,height)
{
	this->mpWindowHandle.reset(
		glfwCreateWindow(width, height, name, NULL, NULL), //new value
		std::bind(glfwDestroyWindow, this->mpWindowHandle.get())); //deleter functor

	glfwMakeContextCurrent(this->mpWindowHandle.get());
	glLoadIdentity();
	glOrtho(0, 1, 1, 0, -1, 1);

	//we need pointer to this object in callback lambdas
	glfwSetWindowUserPointer(this->mpWindowHandle.get(), this);

	/*
	this->addOnKey([](GLFWwindow* window, int key, int, int action, int mods) {
	 
	});
	*/

	glfwSetKeyCallback(this->mpWindowHandle.get(), [](GLFWwindow* window, int key, int scan, int action, int mods) {

		//we dont want to process it yet
		if (action == GLFW_REPEAT) return;


		//extract pointer to [this]
		Window* thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));
		thisPtr->mButtonsStates[key].isPressed = (action == GLFW_PRESS);

		for (int i = 0; i < thisPtr->mKeyListeners.size(); i++)
		{
			if (action == GLFW_PRESS)
				thisPtr->mKeyListeners[i]->onKeyDown({ key, mods });
			else
				thisPtr->mKeyListeners[i]->onKeyUp({key, mods});
		}

		thisPtr->keyDeleagte.callAll(window,key,scan,action,mods);
	});

	glfwSetWindowSizeCallback(this->mpWindowHandle.get(), [](GLFWwindow*, int w, int h) 
	{
		glViewport(0, 0, w, h);
	});
}

Window::Window()
	:Window(500, 500, "window")
{
}

bool Window::isOpen()
{
	return !glfwWindowShouldClose(this->mpWindowHandle.get());
}

void Window::setSize(const Vector2<int>& size)
{
	glfwSetWindowSize(mpWindowHandle.get(), size.x, size.y);
	mWindowSize = size;
}

Vector2<int> Window::getSize()
{
	return mWindowSize;
}

void Window::addKeyListener(KeyListener* listener)
{
	mKeyListeners.push_back(std::shared_ptr<KeyListener>(listener));
}

void Window::display()
{
	glfwSwapBuffers(this->mpWindowHandle.get());
}

/*

void Window::addOnKey(const std::function<void(GLFWwindow*, int, int, int, int)>& callback)
{
	this->keyDeleagte.pushCallback(callback);
}

bool Window::isKeyPressed(int num)
{
	return mButtonsStates[num].isPressed;
}
*/
