#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePintball.h"
#include "ModuleTutorial.h"
#include "SDL\include\SDL.h"

ModulePintball::ModulePintball()
{
	pin.PushBack({ 0, 0, 477, 798 });
	pin.loop = false;
}

ModulePintball::~ModulePintball()
{}


bool ModulePintball::Start()
{
	LOG("Loading space scene");

	

	Pintball = App->textures->Load("Assets/Sprites/Background.png");

	
	pin.Reset();

	if (App->tutorial->IsEnabled() == true) {
		App->pintball->Disable();
	}


	return true;
}

// UnLoad assets
bool ModulePintball::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(Pintball);
	pin.Reset();

	return true;
}

// Update: draw background
update_status ModulePintball::Update()
{

	anim = &pin;
	App->render->Blit(Pintball, 0,0, &(anim->GetCurrentFrame()));
	
	return UPDATE_CONTINUE;
}