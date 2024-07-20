#pragma once

// ������Ʈ�� ���� ���� ���, ������, ����ü ���� ����

extern bool isRun;

// ����� ��� ���� ������
const int BufferSizeX = 100;
const int BufferSizeY = 30;

enum Color
{
	Black, // ����
	DarkBlue, // �Ķ�
	Green, // ���
	BlueGreen, // �ϴ�
	Blood, // ����
	Purple, // ����
	Gold, // ����
	Original, // ��ȸ��
	Gray, // ��ȸ��
	Blue, // ���Ķ�
	HighGreen, // ����
	SkyBlue, // ���ϴ�
	Red, // ������
	Plum, // ����ȫ
	Yellow, // ���
	White, // ���
};

// �ʿ��� ������ �ʿ��� �ڿ����� �޸𸮿� �÷��α� ����
// �� �ý����� ����� ������

// ���� �� ���Ǵ� ������ ����
enum SceneType
{
	NONE = -1,
	TITLE, // Ÿ��Ʋ ��
	INGAME, // �ΰ��� ��
	GAMEOVER, // ���ӿ��� ��
	END,
};

// 2���� ��ǥ�� ��Ÿ���� ����ü
typedef struct tagPoint
{
	int x;
	int y;
	tagPoint() : x(0), y(0) {}
	tagPoint(int x, int y) : x(x), y(y) {}
}Point;

// �ΰ��ӿ��� �����̴� ���͵��� ���������� ���� �����͸� �����ص� ����ü
typedef struct tagInfo
{
	const char* name;
	Point pos;

	tagInfo() {}
	tagInfo(const char* name, int x, int y)
		: name(name), pos(Point(x, y)) {}
}Info;

