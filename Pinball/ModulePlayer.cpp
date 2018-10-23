#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFinish.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	BallPosition.x = 454;
	BallPosition.y = 421;
	lives = 3;
	DesappearBall = false;
	Hole1 = false;

	return true;
}

update_status ModulePlayer::PreUpdate()
{

	ball->GetPosition(BallPosition.x, BallPosition.y);
	
	return UPDATE_CONTINUE;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	BallPosition.x = 454;
	BallPosition.y = 421;
	lives = 3;
	DesappearBall = false;
	Hole1 = false;
	return true;
}

void ModulePlayer::StartBall()
{
	if (Hole1) {
		ball = App->physics->CreateCircle(210, 60, 15, b2BodyType::b2_dynamicBody);
		ball->listener = this;
		ball->body->ApplyLinearImpulse({ 0,5 }, { 0,0 }, true, false);
		ball->body->SetBullet(false);
		Hole1 = false;
	}
	else {
		ball = App->physics->CreateCircle(454, 421, 15, b2BodyType::b2_dynamicBody);
		ball->listener = this;
		ball->body->SetBullet(false);
	}
}

void ModulePlayer::SpawnNextBall()
{
	lives--;
	App->physics->DestroyBall();
	if (lives > 0) {
		StartBall();
	}
	else {
		App->finish->Enable();
		App->fade->FadeToBlack(this, (Module*)App->finish, 0.0f);
	}


}



// Update: draw background
update_status ModulePlayer::Update()
{

	if (DesappearBall) {
		App->physics->DestroyBall();
		DesappearBall = false;
	}
		
	if (BallPosition.x >= 169 && BallPosition.x <= 308 && BallPosition.y >= 766) {
		SpawnNextBall();
	}

	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(PhysBody * bodyA, PhysBody * bodyB)
{
	if (bodyB == App->scene_intro->Hole1|| bodyB == App->scene_intro->Hole2|| bodyB == App->scene_intro->Hole3|| bodyB == App->scene_intro->Hole4) {
		Hole1 = true;
		DesappearBall = true;
		App->scene_intro->BallIsStopped = true;
		App->scene_intro->time = SDL_GetTicks();
		
	}


}
