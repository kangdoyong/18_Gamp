#include "SceneManager.h"
#include "Title.h"
#include "Ingame.h"
#include "GameOver.h"

// 클래스 내에 정적 필드가 존재한다면
// 클래스 외부 전역공간에서 정적 필드를 초기화해야 함
// 지금처럼 클래스 .h랑 .cpp로 분리할 경우
// .cpp 전역공간에서 초기화를 진행하면 됨
SceneManager* SceneManager::instance = nullptr;

Scene* SceneManager::GetScene()
{
    return currentScene;
}

void SceneManager::SetScene(SceneType type)
{
	// 현재 씬을 새로운 씬으로 변경하기  전에
	// 현재 씬 객체가 존재하는지 확인 후, 해제
	if (currentScene)
	{
		delete currentScene;
		currentScene = nullptr;
	}

	switch (type)
	{
	case TITLE:// 타이틀 씬 객체 할당
		currentScene = new Title();
		break;
	case INGAME:
		currentScene = new Ingame();
		break;
	case GAMEOVER:
		currentScene = new GameOver();
		break;
	}

	// 위의 과정을 통해서, 결과적으로 currentScene에
	// 새로운 씬을 할당하였으므로, 새로운 씬을 초기화
	currentScene->Initialize();
}

SceneManager::SceneManager()
	:currentScene(nullptr)
{
}

SceneManager::~SceneManager()
{
	// 씬 매니저 객체 파괴 시, 현재 씬 필드에
	// 객체가 존재한다면 메모리 해제
	if (currentScene)
	{
		delete currentScene;
		currentScene = nullptr;
	}
}
