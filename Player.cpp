#include "Player.h"
#include "Bullet.h"

Player::Player(Info info)
	: Object(info)
{
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	// 총알 발사 딜레이 연산을 위해, 
	// 관련된 필드들을 초기화
	prevFireTime = GetTickCount64();
	delayTime = 100; // 약 0.1초
}

SceneType Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (info.pos.y >= 2)
			info.pos.y -= 1;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (info.pos.y <= BufferSizeY - 3)
			info.pos.y += 1;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (info.pos.x >= 2)
			info.pos.x -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (info.pos.x <= BufferSizeX - 4)
			info.pos.x += 1;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		// 마지막으로 총알을 발사했던 시간 + 딜레이 < 현재시간
		// -> 총알을 발사할 수 있다는 뜻
		if (prevFireTime + delayTime < GetTickCount64())
		{
			// 총알을 발사할 것이므로, 
			// 마지막으로 총알을 발사했던 시간을 갱신
			prevFireTime = GetTickCount64();
			Fire();
		}
	}

	return SceneType::NONE;
}

void Player::Render()
{
	Panel::SetColor(White);
	Panel::Print("->", info.pos.x -1, info.pos.y - 1);
	Panel::Print("->>", info.pos.x -1, info.pos.y);
	Panel::Print("->", info.pos.x -1, info.pos.y + 1);
}

void Player::Release()
{
}

void Player::Fire()
{
	// 총알 객체 생성에 필요한 정보 생성
	Info bulletInfo("Bullet", info.pos.x + 3, info.pos.y);
	// 총알 객체 생성
	Object* bullet = new Bullet(bulletInfo);
	// 생성한 객체 초기화
	bullet->Initialize();

	// 생성한 객체를 내가 필요한 시점에 제어하기 위해서
	// 컨테이너에 담아둬야 함

	// list 객체 넣는법
	// push_back(), push_front() 사용
	bullets.push_back(bullet);
}

