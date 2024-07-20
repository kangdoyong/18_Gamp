#pragma once
#include "Include.h"

// ���� ���� ����� ������ Ŭ����
class Panel
{
private:
	static HANDLE buffer[2]; // 2���� ��� ����
	// ���� �迭���� Ư�� ���� ���� ��, ����� �ε���
	static int bufferIdx;

public:
	void Initialize(); // ���� ���� �� �ʱ�ȭ �۾�
	void Clear(); // ���� �����
	void Flip(); // ���� ��ü
	void Release(); // ���� ���� ��ü �ı� ��, �޸� ����

	// ���������� ���� ����ϰ� �� ������� ��ɵ�
	// -> ���� ���� ��� ��, �Ϲ����� �ܼ� ��� �̿� �Ұ���
	//    ����, �Ʒ� ���ǵ� ��� ���� ��ɵ��� �̿��ϸ� ��
public:
	// ��� Ŀ�� ��ġ�� x, y ��ǥ�� ����
	static void Goto(int x, int y);
	// Ŀ���� x, y ��ǥ�� ���� ��, ���ڿ��� ����ϴ� ���
	static void Print(const char* str, int x, int y);
	// ��� ��, ���� ���� ���
	// -> �� �� ���� ��, �ٸ� ���� �����ϱ� ������ ������ ����
	static void SetColor(Color color);

public:
	Panel();
	~Panel();
};

