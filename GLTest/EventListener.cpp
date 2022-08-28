#include "EventListener.hpp"
#include "Window.hpp"

EventListener::EventListener()
{
    Window::getInstance().addListener(this);
}
