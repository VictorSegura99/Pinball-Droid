#include "Application.h"
#include "ModuleCosas.h"
//#include "ModuleCollision.h"
#include "ModuleRender.h"

ModuleCosas::ModuleCosas()
{}

bool ModuleCosas::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	flecha_d_texture = App->textures->Load("sprites/Resorte_Derecho.png");
	flecha_i_texture = App->textures->Load("sprites/Resorte_Izquierdo.png");
	return true;
}
bool ModuleCosas::CleanUp()
{
	App->textures->Unload(flecha_d_texture);
	App->textures->Unload(flecha_i_texture);
}

