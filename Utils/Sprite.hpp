//@format
#pragma once
#include <iostream>
#include <memory>
#include "../Utils/Texture.hpp"
#include "../Utils/Utils.hpp"
#include "../Utils/Shape.hpp"

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


