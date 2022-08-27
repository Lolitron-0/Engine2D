#include "EventListener.hpp"
#include "Window.hpp"

EventListener::EventListener(Window& window)
{
    window.addListener(this);
}
