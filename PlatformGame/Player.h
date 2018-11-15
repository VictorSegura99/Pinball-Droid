#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include "j1Timer.h"
#include "PugiXml/src/pugixml.hpp"
#include "Entity.h"

struct SDL_Texture;
struct SDL_Rect;


struct Laser {
	fPoint position;
	fPoint velocity;
	Animation anim;
	int life;
	int timelife;
	Collider* coll = nullptr;
	int time = 0;
	bool StartShooting = false;
	bool IsShooting = false;

};

struct BottomHit {
	Animation anim;
	float speed = 0.0f;
	bool IsFalling = false;
};

struct Dash {
	Animation StartDash;
	Animation Dashing;
	Animation FinishDash;
	int DashTime = 8;
	int DashCont = 0;
	bool DashLeft = false;
	bool DashRight = false;
	void ResetDashAnims();
};


class Player : public Entity {
public:
	Player();

	// Destructor
	~Player();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	//Called before the first frame
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called each loop iteration

	bool Load(pugi::xml_node& file);
	bool Save(pugi::xml_node& file) const;

	// Called before quitting
	bool CleanUp();
	
	void OnCollision(Collider* c1, Collider* c2);

	void Die();
	void Fall();
	void Spawn();
	Animation LoadPushbacks(int playernumber, pugi::xml_node&, p2SString NameAnim) const;
	void ChangePlayer(const int playernumber);
	void GoJump(float dt);
	void GoSwim(float dt);
	void GoClimb(float dt);
	void Move_Left_Right(float dt);
	void Camera(float dt);
	void DoDash(float dt);
	void ShootLaser(float dt);
	void DoubleJump(float dt);
	void BottomFall(float dt);
	void Gravity(float dt);
	void SetCamera();


public:
	bool cameraon = false;
	float auxGravity;
	//float TIME;
	j1Timer time;
	float starttime;
	SDL_Rect CamRect;

	Animation* current_animation = nullptr;
	Animation idle[3];
	Animation idle2[3];
	Animation GoLeft[3];
	Animation GoRight[3];
	Animation jumpR[3];
	Animation jumpL[3];
	Animation SwimRight[3];
	Animation SwimLeft[3];
	Animation Climb[3];
	Animation ClimbIdle[3];
	Animation Death[3];
	Animation doubleJump;


	SDL_Texture* texture;
	SDL_Texture* ParticlesTex;

	p2SString sprites_name[3];
	p2SString	JumpFx;
	p2SString	WaterFx;
	p2SString DeathFx;
	p2SString DeathFx2;
	p2SString LadderFx;
	p2SString LaserFx;
	p2SString DashFx;

	Collider* coll = nullptr;

	fPoint position;
	fPoint velocity;
	fPoint acceleration;
	iPoint initialmap1;
	iPoint initialmap2;

	bool AnimDoubleJump = false;
	bool WalkLeft = false;
	bool WalkRight = false;
	bool GoUp = false;
	bool GoDown = false;
	bool Idle = false;
	bool Hability = false;
	bool Jump = false;
	bool IsJumping = false;
	bool CanJump = true;
	bool CanClimb = false;
	bool Falling = false;
	bool CanSwim = false;
	bool death = false;
	bool fall = false;
	bool God = false;
	bool NextMap = false;
	bool NoInput = false;
	bool dashing = false;
	bool dashright = false;
	bool StopDash = false;
	bool CanDash = false;
	bool CanJump2 = false;
	bool IsJumping2 = false;
	bool Jump2Complete = false;
	bool CanDoAnotherJump = true;
	bool FallingJump2 = false;
	bool TouchingGround = false;

	float gravity = 0.0f;
	float JumpSpeed = 0.0f;
	float SpeedWalk = 0.0f;
	float SpeedClimb = 0.0f;
	float SpeedSwimUp = 0.0f;
	float SpeedSwimDown = 0.0f;
	float SpeedSwimLeftRight = 0.0f;
	float DT = 0.0f;
	float AuxJumpSpeed = 0.0f;

	int startmap2 = 0;
	int maxYcam = 0;
	int minYcam = 0;
	int lowcam = 0;
	int positionWinMap1 = 0;
	int startpointcameramap2 = 0;
	int JumpTime = 0;
	int playerwidth = 0;
	int playerHeight = 0;
	int playerheight = 0;
	int finalmapplayer = 0;
	int finalmap = 0;
	int NumPlayer = 900;


	unsigned int jumpfx;
	unsigned int waterfx;
	unsigned int deathfx;
	unsigned int deathfx2;
	unsigned int ladderfx;
	unsigned int laserfx;
	unsigned int dashfx;
	uint Time = 0;

	int cont = 0;

	Laser laserR;
	Laser laserL;

	BottomHit BottomLeft;
	BottomHit BottomRight;

	Dash dashR;
	Dash dashL;
};




#endif // 

