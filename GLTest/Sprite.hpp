//@format
#pragma once
#include <iostream>
#include <memory>
#include "Texture.hpp"

class Sprite
{
				public:
								Sprite();
								void setTexture();
				private:
								std::shared_ptr<Texture> mTexture;
};

