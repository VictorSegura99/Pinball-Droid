#include "Globals.h"
#include "Application.h"
#include "ModuleUi.h"
#include "ModuleFonts.h"
#include "ModuleTextures.h"
#include "ModuleSceneIntro.h"
#include "ModulePlayer.h"



ModuleUi::ModuleUi(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleUi::~ModuleUi()
{}

// Load assets
bool ModuleUi::Start()
{
	LOG("Loading UI");
	font = App->fonts->Load("pinball/fonts.png", "0123456789", 1);

	return true;
}

// Unload assets
bool ModuleUi::CleanUp()
{
	LOG("Unloading Ui");

	return true;
}

// Update: draw background
update_status ModuleUi::Update()
{
	
	sprintf_s(score, 7, "%1d", Score);
	sprintf_s(highscore, 7, "%1d", HighScore);
	

	


	if (App->player->lives < 0)
	{
		if (Score > HighScore)
		{
			HighScore = Score;
		}
		
		//Score[cont] = 0;
	}

	return UPDATE_CONTINUE;
}

