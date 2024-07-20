#pragma once
#include "Include.h"
#include "Panel.h"

// 인게임 액터 객체들의 베이스가 될 추상 클래스
class Object abstract
{
protected:
	Info info; // 액터들이 공통으로 갖는 데이터

public:
	Info GetInfo() { return info; }

public:
	virtual void Initialize() abstract; 
	virtual SceneType Update() abstract;
	virtual void Render() abstract;
	virtual void Release() abstract;

public:
	Object(Info info);
	virtual ~Object();
};

