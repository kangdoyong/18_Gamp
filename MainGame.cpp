#include "MainGame.h"
#include "SceneManager.h"

void MainGame::Initialize()
{
	// 더블 버퍼 객체 생성
	panel = new Panel();
	// 더블 버퍼 초기화
	panel->Initialize();

	// 시작 씬을 설정
	SceneManager::GetInstance()->SetScene(SceneType::TITLE);
}

void MainGame::Update()
{
	// 현재 씬 업데이트
	// 이 때, 씬의 업데이트의 반환 타입이 SceneType 임
	// 반환되는 씬 타입을 통해, 변경하고자 하는 씬이 있다면
	// 해당 씬의 타입을 반환하게끔, 앞으로 구현할 것임
	auto t = SceneManager::GetInstance()->GetScene()->Update();

	// 반환 값이 씬 타입 none보다 크다면, 씬을 변경한다는 의미
	if (t > SceneType::NONE)
	{
		// 변경하고자 하는 씬으로 변경
		SceneManager::GetInstance()->SetScene(t);
	}
}

void MainGame::Render()
{
	// 화면 지우기
	panel->Clear();

	// 현재 씬 그리기
	SceneManager::GetInstance()->GetScene()->Render();

	// 화면 전환
	panel->Flip();
}

void MainGame::Release()
{
	// 더블 버퍼 객체 파괴
	if (panel)
	{
		delete panel;
		panel = nullptr;
	}

	// 씬 매니저 파괴
	SceneManager::Destroy();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
