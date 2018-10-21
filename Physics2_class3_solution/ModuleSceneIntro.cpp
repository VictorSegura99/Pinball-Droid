#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	background = App->textures->Load("pinball/Background.png");
	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/Bola.png"); 

	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");

	App->physics->CreatePinballWalls();
	
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	App->textures->Unload(background);
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{

	


	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	fVector normal(0.0f, 0.0f);

	


	
		


	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) {
		time++;
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP) {
		
	}


	//RENDERER
	App->renderer->Blit(background, -1, 0, NULL);
	App->renderer->Blit(circle, App->player->BallPosition.x, App->player->BallPosition.y, NULL, 1.0f, App->player->ball->GetRotation());

	return UPDATE_CONTINUE;
}

// TODO 8: Now just define collision callback for the circle and play bonus_fx audio
void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	int x, y;

	App->audio->PlayFx(bonus_fx);
}
