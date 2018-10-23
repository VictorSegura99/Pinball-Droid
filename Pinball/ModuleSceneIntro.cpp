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
	lightUp = App->textures->Load("pinball/Up_Light.png");
	lightU = App->textures->Load("pinball/U_light.png");
	lightLeft = App->textures->Load("pinball/L_Light.png");
	lightRight = App->textures->Load("pinball/R_light.png");
	circle = App->textures->Load("pinball/Bola.png"); 
	flipper = App->textures->Load("pinball/Resorte.png");
	flipper2 = App->textures->Load("pinball/Resorte2.png");
	Num0 = App->textures->Load("Pinball/Numbers0.png");
	Num1 = App->textures->Load("Pinball/Numbers1.png");
	Num2 = App->textures->Load("Pinball/Numbers2.png");
	Num3 = App->textures->Load("Pinball/Numbers3.png");
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
	App->textures->Unload(lightUp);
	App->textures->Unload(lightLeft);
	App->textures->Unload(lightU);
	App->textures->Unload(lightRight);
	App->textures->Unload(Num0);
	App->textures->Unload(Num1);
	App->textures->Unload(Num2);
	App->textures->Unload(Num3);
	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	int x, y;

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
	
	App->renderer->Blit(background, -1, 0, NULL);
	if (App->player->ball)
		App->renderer->Blit(circle, App->player->BallPosition.x, App->player->BallPosition.y, NULL, 1.0f, App->player->ball->GetRotation());
	LeftFlipper->GetPosition(x, y);
	App->renderer->Blit(flipper2, x - 43, y - 20, NULL, 1.0f, LeftFlipper->GetRotation());
	RightFlipper->GetPosition(x, y);
	App->renderer->Blit(flipper, x -35, y -20, NULL, 1.0f, RightFlipper->GetRotation());
	UpFlipper->GetPosition(x, y);
	App->renderer->Blit(flipper2, x - 43, y - 20, NULL, 1.0f, UpFlipper->GetRotation());
	if (OnLight1) {
		App->renderer->Blit(lightUp, 169, 61, NULL, 1.0f, Light1->GetRotation());
	}
	if (OnLight2) {
		App->renderer->Blit(lightLeft, 70, 343, NULL, 1.0f, Light2->GetRotation());
	}
	if (OnLight3) {
		App->renderer->Blit(lightLeft, x, y, NULL, 1.0f, Light3->GetRotation());
	}
	if (OnLight4) {
		App->renderer->Blit(lightLeft, x, y, NULL, 1.0f, Light4->GetRotation());
	}
	if (OnLight5) {
		App->renderer->Blit(lightU, x, y, NULL, 1.0f, Light5->GetRotation());
	}
	if (OnLight6) {
		App->renderer->Blit(lightU, x, y, NULL, 1.0f, Light6->GetRotation());
	}
	if (OnLight7) {
		App->renderer->Blit(lightU, x, y, NULL, 1.0f, Light7->GetRotation());
	}
	if (OnLight8) {
		App->renderer->Blit(lightRight, x, y, NULL, 1.0f, Light8->GetRotation());
	}
	if (OnLight9) {
		App->renderer->Blit(lightRight, x, y, NULL, 1.0f, Light9->GetRotation());
	}
	if (OnLight10) {
		App->renderer->Blit(lightRight, x, y, NULL, 1.0f, Light10->GetRotation());
	}
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
