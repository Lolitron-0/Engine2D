//@format
#pragma once
#include <iostream>
#include <memory>
#include "Texture.hpp"
#include "Utils.hpp"
#include "Shape.hpp"

class Sprite : public Shape
{
public:
	Sprite(float x, float y, float width, float height, std::string source);
	void setTexture(Texture);
	void setPosition(const Vector2<float>&);
	void draw() override;
private:
	void recountGlCoords();

	Texture mTexture;
	Rect<float> mRect;


};


