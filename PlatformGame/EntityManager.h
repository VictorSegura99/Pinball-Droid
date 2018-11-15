#ifndef __ENTITYMANAGER_H__
#define __ENTITYMANAGER_H__

#include "j1Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Player.h"



class Entity;

class EntityManager : public j1Module {
public:
	EntityManager();
	~EntityManager();

	bool Start();
	bool Awake(pugi::xml_node & config);
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();
	bool Save(pugi::xml_node&) const;
	bool Load(pugi::xml_node&);

	//Entity* AddEntity(Entity::EntityTypes type);

	bool DeleteEntity(Entity* entity);
	void DeleteEntities();

	
public:
	p2List<Entity*> Entities;

};

#endif

