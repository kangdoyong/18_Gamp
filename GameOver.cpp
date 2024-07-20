#include "GameOver.h"

void GameOver::Initialize()
{
}

SceneType GameOver::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		return SceneType::INGAME;
	}
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		isRun = false;
	}

	return SceneType::NONE;
}

void GameOver::Render()
{
	Panel::Print("Enter - 재도전, ESC - 게임 종료", 5, BufferSizeY / 2);
}

void GameOver::Release()
{
}

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}
