#include "Light.h"

Light::Light()
{
	colour = glm::vec3(1.0f, 1.0f, 1.0f); // how much of a color in each pixel should be shown
	ambientIntensity = 1.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity)
{
	colour = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;
}

void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation)
{
	glUniform3f(ambientColorLocation, colour.x, colour.y, colour.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);
}


Light::~Light()
{

}
