#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <iostream>
#include <GLFW/glfw3.h>
#include "./stb_image.h"
#include <vector>

class Texture
{
public: 
	Texture(std::string source);

	float* getTexCoordsPointer();
	unsigned int getTextureHandle();
private:
	unsigned int mTextureHandle;
	std::vector<float> mTexCoords = { 0,0, 1,0, 1,1, 0,1 };
};
#endif
