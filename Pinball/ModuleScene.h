#ifndef __MODULESCENE_H__
#define __MODULESCENE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * background = nullptr;
};

#endif 