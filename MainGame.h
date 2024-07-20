#pragma once
#include "Panel.h"

// ���� �� �������� ���� ó���� ����� Ŭ����
class MainGame
{
private:
	Panel* panel; // ������� ��ü�� ��Ƶ� �ʵ�

public:
	// ���ΰ��� ��ü�� �����ǰ�, ó�� �� �� �ʿ��� �ʱ�ȭ �۾�
	void Initialize();
	// ���� �� �ʿ��� ���� ó��
	void Update();
	// ���� �� �׸��� �۾�
	void Render();
	// ���ΰ��� ��ü�� �ı��� ��, �����Ҵ��ؼ� ����ߴ� ��ü��
	// �ִٸ� �� ������ �޸� ����
	void Release();

	MainGame();
	~MainGame();
};

