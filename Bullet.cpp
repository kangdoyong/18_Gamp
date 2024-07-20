#include "Bullet.h"

Bullet::Bullet(Info info)
	: Object(info)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
}

SceneType Bullet::Update()
{
	++info.pos.x;

	return SceneType::NONE;
}

void Bullet::Render()
{
	Panel::SetColor(Yellow);

	Panel::Print("@", info.pos.x - 1, info.pos.y-1);
	Panel::Print("@", info.pos.x - 1, info.pos.y);
	Panel::Print("@", info.pos.x - 1, info.pos.y+1);
}

void Bullet::Release()
{
}


