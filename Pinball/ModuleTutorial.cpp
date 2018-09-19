#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTutorial.h"
#include "ModuleFadeToBlack.h"
#include "SDL\include\SDL.h"
#include "Flechas.h"



ModuleTutorial::ModuleTutorial()
{
	Tutorial.PushBack({ 0, 0, 477, 798 });
	Tutorial.loop = false;
}

ModuleTutorial::~ModuleTutorial()
{}


bool ModuleTutorial::Start()
{
	LOG("Loading space intro");
	tuto = App->textures->Load("Assets/Sprites/Tutorial.png");

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
	App->render->Blit(tuto, 0, 0, &(anim->GetCurrentFrame()));
	if (((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_M] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_Z] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_H] == KEY_DOWN) && App->fade->IsFading() == false))
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 0.0f);
	}
	return UPDATE_CONTINUE;
}