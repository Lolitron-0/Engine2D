#pragma once
#include "Color.h"

class Drawable 
{
private:
	typedef unsigned __int8 ColorType;

public:
	Drawable(Color<ColorType> color) : mColor(color) {
	}

	virtual void draw() = 0;

	void setColor(const Color<ColorType>& newColor) {
		this->mColor = newColor;
	}

protected:
	Color<ColorType> mColor;
};