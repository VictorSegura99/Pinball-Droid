#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Flechas.h"
#include "ModuleInput.h"
#include <stdio.h>

Flecha::Flecha()
{
	idle.PushBack({ 0,0,100,90 });

	hit.PushBack({ 0,0,100,90 });
	hit.PushBack({ 100, 90, 200,180 });
	hit.PushBack({ 200, 180, 300,270 });
	hit.PushBack({ 300, 270, 400,360 });
	hit.speed = 0.5f;
}

Flecha::~Flecha()
{
}

bool Flecha::Start()
{
	texture = App->textures->Load("Assets/Sprites/Resorte_Derecho.png");
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
	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}