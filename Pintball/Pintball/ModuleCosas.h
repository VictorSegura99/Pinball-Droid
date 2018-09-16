#ifndef __MODULECOSAS_H__
#define __MODULECOSAS_H__

enum COSAS_TYPES
{
	NO_TYPE,
	FLECHA,
	BOLA,
};

class Cosa;
	
struct CosaInfo
{
	COSAS_TYPES type = COSAS_TYPES::NO_TYPE;
	int x, y;
	
};

class ModuleCosas : public Module
{
public:

	ModuleCosas();
	~ModuleCosas();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	//void OnCollision(Collider* c1, Collider* c2);

	bool AddCosa(COSAS_TYPES type, int x, int y);

	//textures
	SDL_Texture* flecha_d_texture = nullptr;
	SDL_Texture* flecha_i_texture = nullptr;


private:

	void SpawnCosa(const CosaInfo& info);

private:

	SDL_Texture* sprites;
};

#endif