#ifndef __ModulePhysics_H__
#define __ModulePhysics_H__
#include "Module.h"
#include "Globals.h"
#include "Application.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL 0.02f // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

class b2World;
class b2Body;




class ModulePhysics : public Module
{
public:
	ModulePhysics();
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();


private:

	bool debug;
	b2World* world;
};
#endif
