#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Flechas.h"
#include "ModuleInput.h"
#include <stdio.h>

Flecha::Flecha()
{
	idle.PushBack({ 16,0,74,45 });

	hit.PushBack({ 14,45,76,45 });
	hit.PushBack({ 10, 90, 80,45 });
	/*hit.PushBack({ 2, 126, 88,22 });
	hit.PushBack({ 1, 148, 90,24 });
	hit.PushBack({ 9, 172, 81,38 });
	hit.PushBack({ 18, 211, 72,47 });
	hit.PushBack({ 9, 172, 81,38 });
	hit.PushBack({ 1, 148, 90,24 });
	hit.PushBack({ 2, 126, 88,22 });
	hit.PushBack({ 10, 87, 80,38 });
	hit.PushBack({ 14,45,76,42 });*/
	hit.speed = 0.5f;

	/*p.PushBack({ 18,211,72,47 });
	rep.speed = 0.5f;
	rep.loop = false;*/
}

Flecha::~Flecha()
{
}

bool Flecha::Start()
{
	texture = App->textures->Load("Assets/Sprites/Nuevo Resorte.png");
	current_animation = &idle;
	position.x = 50;
	position.y = 50;
	return true;
}

bool Flecha::CleanUp()
{
	App->textures->Unload(texture);

	return true;
}

update_status Flecha::Update()
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
	/* if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (current_animation != &rep) {
			current_animation = &rep;
		}
	}*/
	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}