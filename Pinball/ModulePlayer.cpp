#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFinish.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

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
	App->scene_intro->ActiveHole1 = false;
	App->scene_intro->ActiveHole2 = false;
	App->scene_intro->ActiveHole3 = false;
	App->scene_intro->ActiveHole4 = false;
	if (Hole1) {
		ball = App->physics->CreateCircle(210, 40, 15, b2BodyType::b2_dynamicBody);
		ball->listener = this;
		ball->body->ApplyLinearImpulse({ 0,5 }, { 0,0 }, true, false);
		ball->body->SetBullet(false);
		Hole1 = false;
	}
	else if (Hole2) {
		ball = App->physics->CreateCircle(395, 80, 15, b2BodyType::b2_dynamicBody);
		ball->listener = this;
		ball->body->ApplyLinearImpulse({ 2,6 }, { 0,0 }, true, false);
		ball->body->SetBullet(false);
		Hole2 = false;
	}
	else if (Hole3) {
		ball = App->physics->CreateCircle(400, 270, 15, b2BodyType::b2_dynamicBody);
		ball->listener = this;
		ball->body->ApplyLinearImpulse({ -3,5 }, { 0,0 }, true, false);
		ball->body->SetBullet(false);
		Hole3 = false;
	}
	else if (Hole4) {
		ball = App->physics->CreateCircle(23, 700, 15, b2BodyType::b2_dynamicBody);
		ball->listener = this;
		ball->body->ApplyLinearImpulse({ 13,0 }, { 0,0 }, true, true);
		ball->body->SetBullet(false);
		Hole4 = false;
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
	App->physics->DestroyBody(ball);
	if (lives >= 0) {
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
	if (lives == 3) {
		App->renderer->Blit(App->scene_intro->Num3, 455, 710,NULL);
	}
	else if (lives == 2) {
		App->renderer->Blit(App->scene_intro->Num2, 457, 710, NULL);
	}
	else if (lives == 1) {
		App->renderer->Blit(App->scene_intro->Num1, 457, 710, NULL);
	}
	else if (lives == 0) {
		App->renderer->Blit(App->scene_intro->Num0, 458, 710, NULL);
	}
	if (DesappearBall) {
		App->physics->DestroyBody(ball);
		DesappearBall = false;
	}
		
	if (BallPosition.x >= 169 && BallPosition.x <= 308 && BallPosition.y >= 766) {
		SpawnNextBall();
	}
	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(PhysBody * bodyA, PhysBody * bodyB)
{
	if (bodyB == App->scene_intro->Hole1) {
		Hole1 = true;
		DesappearBall = true;
		App->scene_intro->BallIsStopped = true;
		App->scene_intro->time = SDL_GetTicks();
		App->scene_intro->ActiveHole1 = true;
		
	}

	if (bodyB == App->scene_intro->Hole2) {
		Hole2 = true;
		DesappearBall = true;
		App->scene_intro->BallIsStopped = true;
		App->scene_intro->time = SDL_GetTicks();
		App->scene_intro->ActiveHole2 = true;
	}
	if (bodyB == App->scene_intro->Hole3) {
		Hole3 = true;
		DesappearBall = true;
		App->scene_intro->BallIsStopped = true;
		App->scene_intro->time = SDL_GetTicks();
		App->scene_intro->ActiveHole3 = true;
	}
	if (bodyB == App->scene_intro->Hole4) {
		Hole4 = true;
		DesappearBall = true;
		App->scene_intro->BallIsStopped = true;
		App->scene_intro->time = SDL_GetTicks();
		App->scene_intro->ActiveHole4 = true;

	}
	if (bodyB == App->scene_intro->BouncyL) {
		ball->body->ApplyLinearImpulse({ 2,-2.5f }, { 0,0 }, false, false);
		
	}
	if (bodyB == App->scene_intro->BouncyR) {
		ball->body->ApplyLinearImpulse({ -2,-2.5f }, { 0,0 }, false, false);

	}
	if (bodyB == App->scene_intro->Light1) {
 		App->scene_intro->OnLight1 = true;
	}
	if (bodyB == App->scene_intro->Light2) {
		App->scene_intro->OnLight2 = true;
	}
	if (bodyB == App->scene_intro->Light3) {
		App->scene_intro->OnLight3 = true;
	}
	if (bodyB == App->scene_intro->Light4) {
		App->scene_intro->OnLight4 = true;
	}
	if (bodyB == App->scene_intro->Light5) {
		App->scene_intro->OnLight5 = true;
	}
	if (bodyB == App->scene_intro->Light6) {
		App->scene_intro->OnLight6 = true;
	}
	if (bodyB == App->scene_intro->Light7) {
		App->scene_intro->OnLight7 = true;
	}
	if (bodyB == App->scene_intro->Light8) {
		App->scene_intro->OnLight8 = true;
	}
	if (bodyB == App->scene_intro->Light9) {
		App->scene_intro->OnLight9 = true;
	}
	if (bodyB == App->scene_intro->Light10) {
		App->scene_intro->OnLight10 = true;
	}
	if (bodyB == App->scene_intro->CircleUp) {
		App->scene_intro->Circleup1 = true;
	}
	if (bodyB == App->scene_intro->CircleUp2) {
		App->scene_intro->Circleup2 = true;
	}
	if (bodyB == App->scene_intro->CircleUp3) {
		App->scene_intro->Circleup3 = true;
	}
	if (bodyB == App->scene_intro->SensorUp) {
		int x, y;
		App->scene_intro->SensorUp->GetPosition(x, y);
		if (x > BallPosition.x) {
			App->scene_intro->Left = true;
			App->scene_intro->TimeLeft = 1;
		}
		if (x < BallPosition.x) {
			App->scene_intro->Right = true;
			App->scene_intro->TimeRight = 1;
		}
	}
	if (bodyB == App->scene_intro->SensorUp2) {
		int x, y;
		App->scene_intro->SensorUp2->GetPosition(x, y);
		if (y < BallPosition.y) {
			App->scene_intro->TimeUp = 1;
			App->scene_intro->Up = true;
		}
	}
}
