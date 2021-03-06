#include <iostream>

#include "Camera.h"

Camera::Camera(int width, int height)
{
	rotation = 0;
	setDims(width, height);
	setPosition(glm::vec3(0, 0, 0));
	scale = 1;
}

Camera::~Camera()
{

}

void Camera::setDims(int width, int height)
{
	this->width = width;
	this->height = height;
	projection = glm::ortho(0.0f, (float) width, (float) height, 0.0f, 0.0f, 100.0f);
}

int Camera::getWidth() const
{
	return width;
}

int Camera::getHeight() const
{
	return height;
}

float Camera::getScale() const
{
	return scale;
}

void Camera::zoomi()
{
	scale+=0.1f;
}

void Camera::zoomo()
{
	scale-=0.1;
}


float Camera::getRotation() const
{
	return -rotation;
}

void Camera::rotate(float angle)
{
	rotation -= angle;
}

void Camera::setRotation(float angle)
{
	rotation = -angle;
}

glm::mat4 Camera::getProjection() const
{
	return projection;
}

glm::mat4 Camera::getView() const
{
	glm::mat4 temp;
	temp = glm::translate(temp, getPosition());
	temp = glm::translate(temp, glm::vec3(-(width*scale / 2), -(height*scale / 2), 0));
	temp = glm::rotate(temp, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	temp = glm::scale(temp, glm::vec3(scale, scale, 1));
	temp = glm::translate(temp, glm::vec3((width / 2), (height / 2), 0));
	return temp;
}