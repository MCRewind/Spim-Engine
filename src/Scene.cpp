#include "Scene.h"

Scene::Scene(Window* window, Camera* camera) {
	this->window = window;
	this->camera = camera;
}

int Scene::getState()
{
	return state;
}
