#pragma once

#include <GL\glew.h>

class Material
{
public:
	Material();
	Material(GLfloat sIntensity, GLfloat shine);

	void useMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

	~Material();
private:
	GLfloat specularIntensity;	// reflectiveness of the object - how bright it is
	GLfloat shininess;			// how collected it is
};

