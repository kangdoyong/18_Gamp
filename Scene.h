#pragma once
#include "Include.h"
#include "Panel.h"

// ��� ���� ���̽��� �Ǵ� Ŭ����
// ��� ������ ���������� ���� ��ɵ��� �����
class Scene abstract
{
public:
	virtual void Initialize() abstract; // �� �ʱ�ȭ
	virtual SceneType Update() abstract; // �� ������Ʈ
	virtual void Render() abstract; // �� �׸���
	virtual void Release() abstract; // �� �ı� ��, �޸� ����

	Scene();
	virtual ~Scene();
};

