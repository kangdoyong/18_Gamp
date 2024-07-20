#pragma once
#include "Object.h"
class Bullet :
    public Object
{
public:
	// Object을(를) 통해 상속됨
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	Bullet(Info info);
	virtual ~Bullet();
};

