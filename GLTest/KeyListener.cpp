#include "KeyListener.hpp"
#include <Window.hpp>

KeyListener::KeyListener()
{
	Window::getInstance().addKeyListener(this);
}
