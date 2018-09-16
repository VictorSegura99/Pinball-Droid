#ifndef __MODULETUTORIAL_H__
#define __MODULETUTORIAL_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleTutorial : public Module
{
public:
	ModuleTutorial();
	~ModuleTutorial();
	Animation* anim = nullptr;
	Animation* anim2 = nullptr;
	Animation* anim3 = nullptr;
	Animation* anim4 = nullptr;
	Animation* anim5 = nullptr;
	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * tuto = nullptr;
	Animation Neogeo;
	uint fx = 0;
	Mix_Music * music = nullptr;
};

#endif
