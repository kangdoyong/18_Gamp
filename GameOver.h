#pragma once
#include "Scene.h"
class GameOver :
    public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	GameOver();
	virtual ~GameOver();
};

