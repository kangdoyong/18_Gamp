#pragma once
#include "Object.h"
class Monster :
    public Object
{
public:
	// Object��(��) ���� ��ӵ�
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;

	Monster(Info info);
	virtual ~Monster();
};

