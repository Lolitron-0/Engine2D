//@format
#pragma once
#include <iostream>
#include <memory>
#include "../Utils/Texture.hpp"
#include "../Utils/Utils.hpp"
#include "../Utils/Shape.hpp"

class Sprite : public Shape
{
    typedef int PixelType;
public:
    Sprite(PixelType x, PixelType y, PixelType width, PixelType height, std::string source);
	void setTexture(Texture);
    void setPosition(const Vector2<PixelType>&);
	void draw() override;

    Rect<PixelType> getRect();
private:
	void recountGlCoords();

	Texture mTexture;
    Rect<PixelType> mRect;


};


