#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTutorial.h"
#include "SDL\include\SDL.h"




ModuleTutorial::ModuleTutorial()
{
	Tutorial.PushBack({ 8, 68, 208, 144 });
	Tutorial.loop = false;
}

ModuleTutorial::~ModuleTutorial()
{}


bool ModuleTutorial::Start()
{
	LOG("Loading space intro");
	tuto = App->textures->Load("Assets/sprites/Tutorial.png");

	App->render->camera.x = App->render->camera.y = 0;
	Tutorial.Reset();




	return true;
}

// UnLoad assets
bool ModuleTutorial::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(tuto);
	Tutorial.Reset();



	return true;
}





update_status ModuleTutorial::Update()
{
	SDL_RenderClear(App->render->renderer);
	anim = &Tutorial;
	App->render->Blit(tuto, 8, 68, &(anim->GetCurrentFrame()));
	return UPDATE_CONTINUE;
}