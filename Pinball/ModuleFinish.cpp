#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTutorial.h"
#include "SDL\include\SDL.h"
#include "ModulePhysics.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleFinish.h"



ModuleFinish::ModuleFinish(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	Finish.PushBack({ 0, 0, 477, 798 });
	Finish.loop = false;
}

ModuleFinish::~ModuleFinish()
{}


bool ModuleFinish::Start()
{
	LOG("Loading space intro");
	finish = App->textures->Load("pinball/Well_Done.png");

	App->renderer->camera.x = App->renderer->camera.y = 0;
	Finish.Reset();




	return true;
}

// UnLoad assets
bool ModuleFinish::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(finish);
	Finish.Reset();



	return true;
}


update_status ModuleFinish::Update()
{
	SDL_RenderClear(App->renderer->renderer);
	anim = &Finish;
	App->renderer->Blit(finish, 0, 0, &(anim->GetCurrentFrame()));
	if (((App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN) && App->fade->IsFading() == false))
	{
		App->finish->Disable();
		App->fade->FadeToBlack(this, (Module*)App->tutorial, 0.0f);
	}
	return UPDATE_CONTINUE;
}