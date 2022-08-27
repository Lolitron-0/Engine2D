#include "Window.hpp"

Window::Window(GLint width, GLint height, const char* name) :
    mWindowSize(width,height)
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

    glfwSetCursorPosCallback(mpWindowHandle.get(),[](GLFWwindow* window, double x, double y){
        Window* thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));

        thisPtr->mCursorPos = {(int)x,(int)y};

        Event event(Event::EventType::MouseMove);
        event.mouseMove = {(int)x,(int)y};

        for(int i=0;i<thisPtr->mListeners.size();i++)
        {
            thisPtr->mListeners[i]->handle(event);
        }
    });

    glfwSetMouseButtonCallback(mpWindowHandle.get(), [](GLFWwindow* window, int button, int action, int mods){
        Window* thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));

        Event event;
        if(action == GLFW_PRESS)
            event.type = Event::EventType::MouseDown;
        else
            event.type = Event::EventType::MouseUp;

        event.mouseButton = {button, thisPtr->mCursorPos.x, thisPtr->mCursorPos.y};

        for(int i=0;i<thisPtr->mListeners.size();i++)
        {
            thisPtr->mListeners[i]->handle(event);
        }
    });

	glfwSetKeyCallback(this->mpWindowHandle.get(), [](GLFWwindow* window, int key, int scan, int action, int mods) {

		//we dont want to process it yet
		if (action == GLFW_REPEAT) return;


		//extract pointer to [this]
        Window* thisPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));
        Event event;
        if (action == GLFW_PRESS)
            event.type = Event::EventType::KeyDown;
        else
            event.type = Event::EventType::KeyUp;

        event.key = {key,mods};

        for (int i = 0; i < thisPtr->mListeners.size(); i++)
		{
            thisPtr->mListeners[i]->handle(event);
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

void Window::addListener(EventListener* listener)
{
    mListeners.push_back(std::shared_ptr<EventListener>(listener));
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
