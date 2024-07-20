#pragma once
#include "Scene.h"
class Title :
    public Scene
{
public:
	// Scene을(를) 통해 상속됨
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	Title();
	virtual ~Title();
};

