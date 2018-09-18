#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Flecha2.h"
#include "ModuleInput.h"
#include <stdio.h>

Flecha2::Flecha2()
{
	idle.PushBack({ 150,0,73,45 });

	hit.PushBack({ 76,0,74,42 });
	hit.PushBack({ 0, 0, 75,38 });
	hit.speed = 0.5f;

	rep.PushBack({ 76,0,74,42 });
	rep.PushBack({ 0, 0, 75,38 });
	rep.speed = 0.5f;
	rep.loop = false;
}

Flecha2::~Flecha2()
{
}

bool Flecha2::Start()
{
	texture = App->textures->Load("Assets/Sprites/Resorte_Derecho.png");
	current_animation = &idle;
	position.x = 250;
	position.y = 250;
	return true;
}

bool Flecha2::CleanUp()
{
	App->textures->Unload(texture);

	return true;
}

update_status Flecha2::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN)
	{
		if (current_animation != &hit) {
			current_animation = &hit;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP)
	{
		if (current_animation != &idle) {
			current_animation = &idle;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (current_animation != &rep) {
			current_animation = &rep;
		}
	}
	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}