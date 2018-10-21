#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = false);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	
	PhysBody* pivote;
	PhysBody* pivote2;
	PhysBody* pivote3;
	PhysBody* pivote4;
	PhysBody* Background;
	PhysBody* RightCircle;
	PhysBody* RightFlipper;
	PhysBody* LeftCircle;
	PhysBody* LeftFlipper;
	
	SDL_Texture* circle;
	SDL_Texture* background;
	float velocity = 5.0f;
	bool StartVelocity = false;
	
	
	uint bonus_fx;
	uint time = 0;
};
