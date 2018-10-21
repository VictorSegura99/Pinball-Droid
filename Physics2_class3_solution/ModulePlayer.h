#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = false);
	virtual ~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();

	bool CleanUp();

	void StartBall();

public:

	PhysBody * ball;
	iPoint BallPosition;
	
};