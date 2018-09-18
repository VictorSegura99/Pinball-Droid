#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "Flechas.h"
#include "ModuleRender.h"
#include "ModuleTutorial.h"


ModuleScene::ModuleScene()
{}

ModuleScene::~ModuleScene()
{}

bool ModuleScene::Start()
{
	background = App->textures->Load("Assets/Sprites/Background.png");

	App->flecha->Enable();
	if (App->tutorial->IsEnabled() == true) {
		App->scene->Disable();
	}
	return true;
}

bool ModuleScene::CleanUp()
{
	App->textures->Unload(background);

	App->flecha->Disable();

	return true;
}

update_status ModuleScene::Update()
{
	App->render->Blit(background, -1, 0, NULL);
	
	return UPDATE_CONTINUE;
}
