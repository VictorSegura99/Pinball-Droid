#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTutorial.h"
#include "SDL\include\SDL.h"




ModuleTutorial::ModuleTutorial()
{

}

ModuleTutorial::~ModuleTutorial()
{}


bool ModuleTutorial::Start()
{
	LOG("Loading space intro");
	tuto = App->textures->Load("assets/Intro/Neogeo.png");

	App->render->camera.x = App->render->camera.y = 0;





	return true;
}

// UnLoad assets
bool ModuleTutorial::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(tuto);




	return true;
}





update_status ModuleTutorial::Update()
{
	

	return UPDATE_CONTINUE;
}