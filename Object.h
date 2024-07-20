#pragma once
#include "Include.h"
#include "Panel.h"

// �ΰ��� ���� ��ü���� ���̽��� �� �߻� Ŭ����
class Object abstract
{
protected:
	Info info; // ���͵��� �������� ���� ������

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

