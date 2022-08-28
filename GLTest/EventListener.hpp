#ifndef EVENTLISTENER_HPP
#define EVENTLISTENER_HPP
#include "../Utils/Event.hpp"


class EventListener
{
public:
    EventListener();

    virtual void handle(const Event&) = 0;
private:
};

#endif // EVENTLISTENER_HPP
