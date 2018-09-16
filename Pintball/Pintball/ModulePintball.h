#ifndef __MODULEPINTBALL_H__
#define __MODULEPINTBALL_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "SDL_mixer/include/SDL_mixer.h"



struct SDL_Texture;
struct SDL_Rect;

class ModulePintball : public Module
{
public:
	ModulePintball();
	~ModulePintball();
	Animation* anim = nullptr;
	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * Pintball = nullptr;
	Animation pin;




};

#endif // __MODULESTAGE2_H__
