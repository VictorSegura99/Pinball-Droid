#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "p2Point.h"
#include "p2Animation.h"
#include "p2Log.h"
#include "j1Map.h"
#include "j1App.h"
#include "EntityManager.h"


class Entity  {
public:

	enum class EntityTypes {
	
		NPC,
		PLAYER,
		MOVING_PLATFORM,

		NO_TYPE,
	};

public:

	Entity();
	Entity(EntityTypes type);
	virtual ~Entity();

	virtual bool Start();
	virtual bool Awake(pugi::xml_node & config);
	virtual bool PreUpdate();
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp();
	virtual bool Save(pugi::xml_node&) const;
	virtual bool Load(pugi::xml_node&);

public:

	EntityTypes type;


};

#endif
