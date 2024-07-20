#pragma once
#include "Object.h"
class Bullet :
    public Object
{
public:
	// Object��(��) ���� ��ӵ�
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	Bullet(Info info);
	virtual ~Bullet();
};

