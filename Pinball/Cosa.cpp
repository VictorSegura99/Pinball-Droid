#include "Application.h"
#include "Cosa.h"

Cosa::Cosa(int x, int y) : position(x, y), collider(nullptr)
{}

Cosa::~Cosa()
{
	//if (collider != nullptr)
		//collider->to_delete = true;
}

/*const Collider* Flecha::GetCollider() const
{
	return collider;
}*/

void Cosa::Draw(SDL_Texture* sprites)
{
	/*if (collider != nullptr)
		collider->SetPos(position.x, position.y);*/

	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

