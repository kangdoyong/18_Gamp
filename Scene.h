#pragma once
#include "Include.h"
#include "Panel.h"

// 모든 씬의 베이스가 되는 클래스
// 모든 씬들이 공통적으로 갖는 기능들이 선언됨
class Scene abstract
{
public:
	virtual void Initialize() abstract; // 씬 초기화
	virtual SceneType Update() abstract; // 씬 업데이트
	virtual void Render() abstract; // 씬 그리기
	virtual void Release() abstract; // 씬 파괴 시, 메모리 해제

	Scene();
	virtual ~Scene();
};

