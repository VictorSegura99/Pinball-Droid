#ifndef __COSA_H__
#define __COSA_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Cosa
{
protected:
	Animation* animation;
	Collider* collider;

public:
	iPoint position;
	SDL_Texture* tex = nullptr;

public:
	Cosa(int x, int y);
	virtual ~Cosa();

	//const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
};

#endif