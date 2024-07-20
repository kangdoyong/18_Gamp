#include "Panel.h"

// 정적 필드 초기화
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
	// 생성할 버퍼 크기 설정
	COORD size = { BufferSizeX, BufferSizeY };
	// 버퍼를 생성할 때, 사용할 사각형 영역 설정
	SMALL_RECT rc;
	rc.Left = 0;
	rc.Right = BufferSizeX - 1;
	rc.Top = 0;
	rc.Bottom = BufferSizeY - 1;

	// 커서에 관한 설정 (안 보이게끔)
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;

	// 위의 설정값에 따라 2개의 버퍼를 생성
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
	// 콘솔에서 출력 작업 시, 현재 커서 위치를 기준으로 작업
	// 화면 전체가 지워질 수 있게 사용하고 있던 커서의 위치를
	// 0, 0으로 옮기고, 공백 문자로 버퍼 전체를 덮어쓰기
	Goto(0, 0);
	COORD coord = { 0, 0 };
	DWORD dw;
	
	FillConsoleOutputCharacter(buffer[bufferIdx], ' ',
		BufferSizeX * BufferSizeY, coord, &dw);
}

void Panel::Flip()
{
	// 2개 버퍼 중에 출력에 사용할 버퍼를 활성화
	SetConsoleActiveScreenBuffer(buffer[bufferIdx]);
	// bufferIdx 번째 버퍼를 활성화 시켰으니, 버퍼 인덱스를 변경
	bufferIdx = !bufferIdx; // 0, 1, 0, 1 형식으로 반전되면서 인덱스가 바뀜
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

