#ifndef __GAMESCENE_H_
#define __GAMESCENE_H_

#include "Scene.h"
#include "Shader.h"
#include "Vao.h"
#include "SSBO.h"

class GameScene : public Scene
{
public:
	GameScene(Window*, Camera*);
	~GameScene();
	void update();
	void render();
	void setActive();
	Vao* vao;
	Shader_C* shader;
	SSBO* ssbo;
};

#endif