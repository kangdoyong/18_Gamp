#pragma once
#include "Scene.h"

class Object;

class Ingame :
    public Scene
{
private:
	ULONGLONG prevSpawnTime; // 이전 스폰 시간
	ULONGLONG spawnDelayTime; // 스폰 딜레이 시간

	Object* player; // 플레이어 객체를 담을 필드
	// 플레이어 객체가 갖는 총알리스트 주소를 담을 필드
	list<Object*>* bullets;
	// 몬스터 객체를 담을 필드
	list<Object*> monsters;

private:
	void SpawnMonster(); 

public:
	// Scene을(를) 통해 상속됨
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	Ingame();
	virtual ~Ingame();
};

