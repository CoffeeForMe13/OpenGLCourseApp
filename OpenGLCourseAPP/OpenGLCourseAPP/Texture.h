#pragma once

#include <GL\glew.h>

#include "stb_image.h"

class Texture
{
public:
	Texture();
	Texture(char* fileLoc);

	bool loadTexture();
	bool loadTextureA();
	void useTexture();
	void clearTexture();

	~Texture();

private:
	GLuint textureID;
	int width, height, bitDepth;

	char* fileLocation;
};

