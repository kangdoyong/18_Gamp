#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	// ������ �Ѿ� ��ü�� ���� �ʵ�
	// stl �ڷᱸ�� ��, list ���
	// �迭�� ����ѵ�, �迭 ��� �� ����� ���������� �����ؾ�������
	// ����Ʈ�� ����� �������� �ʾƵ� ��, ��ü�� �߰����� ��
	// ������ �����ϸ� �˾Ƽ� ������ �ø�
	// ��ü�� �߰�/���� ���� ����� �߻��Ѵٸ� list�� ����ϴ� ���� ����
	list<Object*> bullets;

	ULONGLONG prevFireTime; // ���� �߻� �ð�
	ULONGLONG delayTime; // �߻� ������ �ð�

public:
	// �Ѿ� ����Ʈ�� �ּҸ� ��ȯ�ϴ� �޼���
	list<Object*>* GetBullets() { return &bullets; }


public:
	// Object��(��) ���� ��ӵ�
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;
	void Fire();

	Player(Info info);
	virtual ~Player();
};

