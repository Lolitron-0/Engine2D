#pragma once
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include <iostream>
#include "EventListener.hpp"
#include "Window.hpp"


class Shape : public EventListener
{
public:
    Shape(int pointCount): EventListener()
        ,mGlVertices(pointCount*2, .0f)
    {}
    void handle(const Event& event) override
    {
        if(event.type == Event::EventType::ResizeWindow)
            recountGlCoords();
    }
    virtual void draw() = 0;
    virtual void recountGlCoords()=0;
protected:
    std::vector<float> mGlVertices;
};

#endif
