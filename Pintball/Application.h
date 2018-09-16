#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 2

class ModuleWindow;
class ModuleRender;

class Module;

class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;


public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

extern Application* App;

#endif 
