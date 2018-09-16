#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePintball.h"


ModulePintball::ModulePintball()
{}

ModulePintball::~ModulePintball()
{}


bool ModulePintball::Start()
{
	LOG("Loading space scene");





	return true;
}

// UnLoad assets
bool ModulePintball::CleanUp()
{
	LOG("Unloading space scene");

	

	return true;
}

// Update: draw background
update_status ModulePintball::Update()
{

	
	return UPDATE_CONTINUE;
}