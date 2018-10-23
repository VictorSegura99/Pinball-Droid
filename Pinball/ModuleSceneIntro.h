#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "ModuleTextures.h"
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
	void ContinueAfterHole();

public:
	
	PhysBody* pivote;
	PhysBody* pivote2;
	PhysBody* pivote3;
	PhysBody* pivote4;
	PhysBody* BarraL;
	PhysBody* BarraR;
	PhysBody* Background;
	PhysBody* BackgroundU;
	PhysBody* BackgroundL;
	PhysBody* BackgroundR;
	PhysBody* BackgroundLine;
	PhysBody* ChainL;
	PhysBody* ChainR;
	PhysBody* RightCircle;
	PhysBody* RightFlipper;
	PhysBody* LeftCircle;
	PhysBody* LeftFlipper;
	PhysBody* Hole1;
	PhysBody* Hole2;
	PhysBody* Hole3;
	PhysBody* Hole4;

	PhysBody* Light1;
	PhysBody* Light2;
	PhysBody* Light3;
	PhysBody* Light4;
	PhysBody* Light5;
	PhysBody* Light6;
	PhysBody* Light7;
	PhysBody* Light8;
	PhysBody* Light9;
	PhysBody* Light10;

	SDL_Texture* circle;
	SDL_Texture* background;
	SDL_Texture* flipper;
	SDL_Texture* flipper2;

	float velocity = 5.0f;
	bool StartVelocity = false;
	bool BallIsStopped = false;
	
	uint bonus_fx;
	uint time = 0;
	uint StopTime = 2000;


};
