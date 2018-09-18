#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 8

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleTutorial;
class ModuleFadeToBlack;
class Flecha;
class ModuleScene;
class Module;


class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr; 
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	Flecha* flecha = nullptr;
	ModuleTutorial* tutorial = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleScene* scene = nullptr;
	//ModulePintball* pintball = nullptr;
	

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__
