#ifndef EVENT_HPP
#define EVENT_HPP
#include <memory>
#include "../Utils/Vector2.hpp"
class Event
{
public:
    enum class EventType
    {
        MouseDown,
        MouseUp,
        MouseMove,
        KeyDown,
        KeyUp,
        ResizeWindow
    };

    struct KeyboardEvent
    {
        int keyCode;
        int mods;
    };

    struct MouseButtonEvent
    {
        Vector2<int> getPositionVector()const {return Vector2(x,y);}
        int button;
        int x;
        int y;
    };


    struct MouseMoveEvent
    {
        Vector2<int> getPositionVector()const {return Vector2(x,y);}
        int x;
        int y;
    };

    struct ResizeWindowEvent
    {
        int w;
        int h;
    };

    Event(EventType t)
        :type(t)
    {}

    Event(){}

    EventType type;

    union{
      KeyboardEvent key;
      MouseButtonEvent mouseButton;
      MouseMoveEvent mouseMove;
      ResizeWindowEvent resize;
    };
};

#endif // EVENT_HPP
