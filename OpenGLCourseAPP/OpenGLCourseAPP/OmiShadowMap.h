#pragma once
#include "ShadowMap.h"
class OmiShadowMap :
    public ShadowMap
{
public:
	OmiShadowMap();

	bool Init(GLuint width, GLuint height);

	void Write();

	void Read(GLenum textureUnit);
	
	~OmiShadowMap();
};

