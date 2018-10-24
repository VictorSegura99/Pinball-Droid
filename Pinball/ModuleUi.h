#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

class ModuleUi : public Module
{
public:
	ModuleUi(Application* app, bool start_enabled = true);
	virtual ~ModuleUi();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	int font = 0;
	int Score = 0;
	int HighScore = 00000;
	char score[7];
	char highscore[7];
};
