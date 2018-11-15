#include "p2Defs.h"
#include "p2Log.h"
#include "p2Point.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1input.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "j1Collision.h"
#include "j1Audio.h"
#include "j1Choose.h"
#include "j1Map.h"
#include "j1Window.h"
#include "EntityManager.h"
#include "Player.h"
#include "Entity.h"

EntityManager::EntityManager() : j1Module()
{
	name.create("EntityManager");
	

}

EntityManager::~EntityManager()
{
}

bool EntityManager::Start()
{
	bool ret = true;
	/*p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->Start();
		item = item->next;
	}
	*/
	return ret;

}

bool EntityManager::Awake(pugi::xml_node & config)
{

	bool ret = true;
	/*p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->Awake(config);
		item = item->next;
	}
	*/
	return ret;
	
	
}

bool EntityManager::PreUpdate()
{
	bool ret = true;
	p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->PreUpdate();
		item = item->next;
	}

	


	return ret;
}

bool EntityManager::Update(float dt)
{
	bool ret = true;
	p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->Update(dt);
		item = item->next;
	}




	return ret;
}

bool EntityManager::PostUpdate()
{
	bool ret = true;
	p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->PreUpdate();
		item = item->next;
	}




	return ret;
}

bool EntityManager::CleanUp()
{
	bool ret = true;
	p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->CleanUp();
		item = item->next;
	}




	return ret;
}

bool EntityManager::Save(pugi::xml_node & file) const
{
	bool ret = true;
	p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->Save(file);
		item = item->next;
	}




	return ret;
}

bool EntityManager::Load(pugi::xml_node & file)
{
	bool ret = true;
	p2List_item<Entity*>* item;
	item = Entities.start;

	while (item != nullptr && ret == true) {
		ret = item->data->Load(file);
		item = item->next;
	}




	return ret;
}


/*Entity * EntityManager::AddEntity(Entity::EntityTypes type)
{
	static_assert(Entity::EntityTypes::NO_TYPE == (Entity::EntityTypes)3, "code needs update");
	
	Entity* NewEntity = nullptr;
	
	switch (type) {

		//case Entity::EntityTypes::NPC: 
			//NewEntity = new NPC(); break;
		case Entity::EntityTypes::PLAYER: 
			NewEntity = new Player();
			break;
	}

	if (NewEntity != nullptr)
		Entities.add(NewEntity);
	
	return NewEntity;
	
}
*/
bool EntityManager::DeleteEntity(Entity * entity)
{
	entity->CleanUp();
	Entities.del(Entities.At(Entities.find(entity)));

	return true;
}

void EntityManager::DeleteEntities()
{
	
	p2List_item <Entity*>* item_entity = Entities.start;
	
	while (item_entity != nullptr) {
		for (item_entity; item_entity; item_entity = item_entity->next) {
			Entities.del(Entities.At(Entities.find(item_entity->data)));
		}
	}
	
}


