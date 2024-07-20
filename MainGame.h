#pragma once
#include "Panel.h"

// 게임 내 전반적인 로직 처리를 담당할 클래스
class MainGame
{
private:
	Panel* panel; // 더블버퍼 객체를 담아둘 필드

public:
	// 메인게임 객체가 생성되고, 처음 한 번 필요한 초기화 작업
	void Initialize();
	// 게임 내 필요한 연산 처리
	void Update();
	// 게임 내 그리기 작업
	void Render();
	// 메인게임 객체가 파괴될 때, 동적할당해서 사용했던 객체가
	// 있다면 이 곳에서 메모리 해제
	void Release();

	MainGame();
	~MainGame();
};

