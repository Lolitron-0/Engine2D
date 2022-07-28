#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <functional>
#include <CallbackDelegate.h>


class Window
{
private:
	class Button
	{
	public:
		Button(){}

		bool isPressed = false;
	};

public:

	Window(GLint width, GLint height, const char* name);
	~Window() = default;

	bool isOpen();
	void pollEvents(); //TODO: glfwPollEvents should be in game as in proceses all windows

	//methods to add callbacks to some events
	void addOnKey(const std::function<void(GLFWwindow*, int, int, int, int)>& callback);
	void addOnMouseButton(const std::function<void(GLFWwindow*, int, int, int)>& callback);
	void addOnMouseMove(const std::function<void(GLFWwindow*, int, int)>& callback);

	void display();

	bool isKeyPressed(int num);

private:
	CallbackDelegate<GLFWwindow*,int,int,int,int> keyDeleagte;
	std::vector<Button> mButtonsStates;//to store codes 0..last+1
	std::shared_ptr<GLFWwindow> mpWindowHandle;

};