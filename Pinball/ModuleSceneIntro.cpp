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
	flipper = App->textures->Load("pinball/Resorte.png");
	flipper2 = App->textures->Load("pinball/Resorte2.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");

	App->physics->CreatePinballWalls();
	RightCircle = new PhysBody;
	RightFlipper = new PhysBody;
	App->physics->CreateFlipper(RightFlipper, RightCircle, true, false);
	LeftCircle = new PhysBody;
	LeftFlipper = new PhysBody;
	App->physics->CreateFlipper(LeftFlipper, LeftCircle, false, false);
	UpCircle = new PhysBody;
	UpFlipper = new PhysBody;
	App->physics->CreateFlipper(UpFlipper, UpCircle, false, true);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	App->textures->Unload(background);
	App->textures->Unload(circle);
	App->textures->Unload(flipper);
	App->textures->Unload(flipper2);
	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_REPEAT || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) 
		RightFlipper->body->ApplyTorque(500, true);
	if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
		LeftFlipper->body->ApplyTorque(-500, true);
		UpFlipper->body->ApplyTorque(-500, true);
	}
		
	


	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	
	fVector normal(0.0f, 0.0f);

	
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) {
		App->player->ball->body->ApplyLinearImpulse({ 0, -0.5f }, { 0,0 }, true, false);
	}



	if (BallIsStopped)
	{
		ContinueAfterHole();
	}
	//RENDERER
	int x, y;
	App->renderer->Blit(background, -1, 0, NULL);
	if (App->player->ball)
		App->renderer->Blit(circle, App->player->BallPosition.x, App->player->BallPosition.y, NULL, 1.0f, App->player->ball->GetRotation());
	LeftFlipper->GetPosition(x, y);
	App->renderer->Blit(flipper2, x - 43, y - 20, NULL, 1.0f, LeftFlipper->GetRotation());
	RightFlipper->GetPosition(x, y);
	App->renderer->Blit(flipper, x -35, y -20, NULL, 1.0f, RightFlipper->GetRotation());
	UpFlipper->GetPosition(x, y);
	App->renderer->Blit(flipper2, x - 43, y - 20, NULL, 1.0f, UpFlipper->GetRotation());
	return UPDATE_CONTINUE;
}

// TODO 8: Now just define collision callback for the circle and play bonus_fx audio
void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	int x, y;

	App->audio->PlayFx(bonus_fx);
}

void ModuleSceneIntro::ContinueAfterHole()
{
	if (SDL_GetTicks() - time >= StopTime && (App->player->Hole1 || App->player->Hole2 || App->player->Hole3 || App->player->Hole4)) {
		BallIsStopped = false;
		App->player->StartBall();
		}
	

}
