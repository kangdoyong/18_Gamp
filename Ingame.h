#pragma once
#include "Scene.h"

class Object;

class Ingame :
    public Scene
{
private:
	ULONGLONG prevSpawnTime; // ���� ���� �ð�
	ULONGLONG spawnDelayTime; // ���� ������ �ð�

	Object* player; // �÷��̾� ��ü�� ���� �ʵ�
	// �÷��̾� ��ü�� ���� �Ѿ˸���Ʈ �ּҸ� ���� �ʵ�
	list<Object*>* bullets;
	// ���� ��ü�� ���� �ʵ�
	list<Object*> monsters;

private:
	void SpawnMonster(); 

public:
	// Scene��(��) ���� ��ӵ�
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	Ingame();
	virtual ~Ingame();
};

