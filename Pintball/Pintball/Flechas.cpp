#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Flechas.h"
#include "ModuleInput.h"
#include <stdio.h>

Flecha::Flecha()
{
	idle.PushBack({0, 0, 240,135});

	hit.PushBack({ 241,0,203,134 });
}

Flecha::~Flecha()
{
}

bool Flecha::Start()
{
	texture = App->textures->Load("Assets/Sprites/Resorte_Derecho.png");

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
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (current_animation != &hit) {
			hit.Reset();
			current_animation = &hit;
		}
	}
	
	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}