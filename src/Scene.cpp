#include "Scene.h"

Scene::Scene(Window* window, Camera* camera) 
:
	window(window), 
	camera(camera)
{}

int Scene::getState() const
{
	return state;
}
