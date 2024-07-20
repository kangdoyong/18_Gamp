#include "Panel.h"

// ���� �ʵ� �ʱ�ȭ
int Panel::bufferIdx = 0;
HANDLE Panel::buffer[2];

Panel::Panel()
{
	memset(buffer, 0, sizeof(buffer));
}

Panel::~Panel()
{
	Release();
}

void Panel::Initialize()
{
	// ������ ���� ũ�� ����
	COORD size = { BufferSizeX, BufferSizeY };
	// ���۸� ������ ��, ����� �簢�� ���� ����
	SMALL_RECT rc;
	rc.Left = 0;
	rc.Right = BufferSizeX - 1;
	rc.Top = 0;
	rc.Bottom = BufferSizeY - 1;

	// Ŀ���� ���� ���� (�� ���̰Բ�)
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;

	// ���� �������� ���� 2���� ���۸� ����
	for (int i = 0; i < 2; ++i)
	{
		buffer[i] = CreateConsoleScreenBuffer
		(GENERIC_READ | GENERIC_WRITE, NULL, NULL,
			CONSOLE_TEXTMODE_BUFFER, NULL);

		SetConsoleScreenBufferSize(buffer[i], size);
		SetConsoleWindowInfo(buffer[i], TRUE, &rc);
		SetConsoleCursorInfo(buffer[i], &cursorInfo);
	}
}

void Panel::Clear()
{
	// �ֿܼ��� ��� �۾� ��, ���� Ŀ�� ��ġ�� �������� �۾�
	// ȭ�� ��ü�� ������ �� �ְ� ����ϰ� �ִ� Ŀ���� ��ġ��
	// 0, 0���� �ű��, ���� ���ڷ� ���� ��ü�� �����
	Goto(0, 0);
	COORD coord = { 0, 0 };
	DWORD dw;
	
	FillConsoleOutputCharacter(buffer[bufferIdx], ' ',
		BufferSizeX * BufferSizeY, coord, &dw);
}

void Panel::Flip()
{
	// 2�� ���� �߿� ��¿� ����� ���۸� Ȱ��ȭ
	SetConsoleActiveScreenBuffer(buffer[bufferIdx]);
	// bufferIdx ��° ���۸� Ȱ��ȭ ��������, ���� �ε����� ����
	bufferIdx = !bufferIdx; // 0, 1, 0, 1 �������� �����Ǹ鼭 �ε����� �ٲ�
}

void Panel::Release()
{
}

void Panel::Goto(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(buffer[bufferIdx], pos);
}

void Panel::Print(const char* str, int x, int y)
{
	Goto(x, y);
	DWORD dw;
	WriteFile(buffer[bufferIdx], str, strlen(str), &dw, NULL);
}

void Panel::SetColor(Color color)
{
	SetConsoleTextAttribute(buffer[bufferIdx], color);
}

