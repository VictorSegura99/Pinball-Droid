#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"

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

	return true;
}

void ModulePlayer::StartBall()
{

	ball = App->physics->CreateCircle(454, 421, 15, b2BodyType::b2_dynamicBody);
	ball->listener = this;
	ball->body->SetBullet(false);
	

}



// Update: draw background
update_status ModulePlayer::Update()
{

	if (DesappearBall) {
		
		App->physics->DestroyBall();
		DesappearBall = false;
	}
		

	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(PhysBody * bodyA, PhysBody * bodyB)
{
	if (bodyB == App->scene_intro->Hole1) {
		DesappearBall = true;
		App->scene_intro->BallIsStopped = true;
		App->scene_intro->BallStopped = true;
		App->scene_intro->time = SDL_GetTicks();
		
	}


}
