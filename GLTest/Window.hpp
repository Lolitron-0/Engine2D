#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include "Utils.hpp"
#include "CallbackDelegate.h"
#include "KeyListener.hpp"


class Window : public Singleton<Window> //TODO
{
private:
	class Button
	{
	public:
		Button(){}

		bool isPressed = false;
	};

public:

	~Window() = default;
	Window();

	bool isOpen();
	void pollEvents(); //TODO: glfwPollEvents should be in game as it proceses all windows
	void display();

	void setSize(const Vector2<int>&);
	Vector2<int> getSize();

	void addKeyListener(KeyListener*);

	/*
	//methods to add callbacks to some events
	void addOnKey(const std::function<void(GLFWwindow*, int, int, int, int)>& callback);
	bool isKeyPressed(int num);

	void addOnMouseButton(const std::function<void(GLFWwindow*, int, int, int)>& callback);
	void addOnMouseMove(const std::function<void(GLFWwindow*, int, int)>& callback);

	*/

	//convert screen coords to gl coords (0..1)
	template<class T> Vector2<T> screenToGl(Vector2<T>const& p) {
		return Vector2<T>(p.x / mWindowSize.x, p.y / mWindowSize.y);
	}
	//convert screen x to gl x (0..1)
	float screenToGlX(float v) {
		return v / mWindowSize.x;
	}
	//convert screen y to gl y (0..1)
	float screenToGlY(float v) {
		return v / mWindowSize.y;
	}

private:

	Window(GLint width, GLint height, const char* name);

	CallbackDelegate<GLFWwindow*,int,int,int,int> keyDeleagte;
	std::vector<Button> mButtonsStates;//to store codes 0..last+1
	std::shared_ptr<GLFWwindow> mpWindowHandle;
	Vector2<int> mWindowSize;
	std::vector<std::shared_ptr<KeyListener>> mKeyListeners;

};
