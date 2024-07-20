#include "Monster.h"

Monster::Monster(Info info)
	: Object(info)
{
}

Monster::~Monster()
{
}

void Monster::Initialize()
{
}

SceneType Monster::Update()
{
	--info.pos.x;

    return SceneType::NONE;
}

void Monster::Render()
{
	Panel::SetColor(Red);
	Panel::Print("<<-0-<", info.pos.x - 3, info.pos.y);
}

void Monster::Release()
{
}


