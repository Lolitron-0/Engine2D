#pragma once
#include "Color.hpp"
#include "Shape.hpp"
#include <vector>


class PrimitiveShape : public Shape
{
public:
	PrimitiveShape(const Color& color, int pointCount);

	void setColor(const Color& color);
	Color getColor();

	void draw() override;
protected:
	Color mColor;
};

