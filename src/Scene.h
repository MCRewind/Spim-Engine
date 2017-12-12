#ifndef __SCENE_H_
#define __SCENE_H_

#include "Window.h"
#include "Camera.h"

class Scene {
	public:
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void setActive() = 0;
		int getState();
	protected:	
		Window* window;
		Camera* camera;
		int state;
		Scene(Window* window, Camera* camera);
};

#endif
