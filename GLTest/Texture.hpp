#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <vector>

class Texture
{
public: 
	Texture(std::string source);
private:
	unsigned int mTextureHandle;
	std::vector<float> mTexCoords = { 0,0, 1,0, 1,1, 0,1 };
};

