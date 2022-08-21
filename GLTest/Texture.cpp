#include "Texture.hpp"

Texture::Texture(std::string source)
{

	int width, height, count;
	unsigned char* data = stbi_load(source.data(), &width, &height, &count, 0);
	glGenTextures(1, &mTextureHandle);
		glBindTexture(GL_TEXTURE_2D, mTextureHandle);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
			count > 3 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

float* Texture::getTexCoordsPointer()
{
	return mTexCoords.data();
}

unsigned int Texture::getTextureHandle()
{
	return mTextureHandle;
}
