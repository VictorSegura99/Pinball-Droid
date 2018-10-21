#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
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
	//ball->body->SetBullet(false);
}

// Update: draw background
update_status ModulePlayer::Update()
{



	return UPDATE_CONTINUE;
}



