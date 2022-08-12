#pragma once
#include <Color.hpp>
#include <vector>


class PrimitiveShape
{
public:
	PrimitiveShape(const Color& color, int pointCount);

	void setColor(const Color& color);
	Color getColor();

	void draw();
protected:
	Color mColor;
	std::vector<float> mGlVertices;
};

