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
	// �Ѿ� �߻� ������ ������ ����, 
	// ���õ� �ʵ���� �ʱ�ȭ
	prevFireTime = GetTickCount64();
	delayTime = 100; // �� 0.1��
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
		// ���������� �Ѿ��� �߻��ߴ� �ð� + ������ < ����ð�
		// -> �Ѿ��� �߻��� �� �ִٴ� ��
		if (prevFireTime + delayTime < GetTickCount64())
		{
			// �Ѿ��� �߻��� ���̹Ƿ�, 
			// ���������� �Ѿ��� �߻��ߴ� �ð��� ����
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
	// �Ѿ� ��ü ������ �ʿ��� ���� ����
	Info bulletInfo("Bullet", info.pos.x + 3, info.pos.y);
	// �Ѿ� ��ü ����
	Object* bullet = new Bullet(bulletInfo);
	// ������ ��ü �ʱ�ȭ
	bullet->Initialize();

	// ������ ��ü�� ���� �ʿ��� ������ �����ϱ� ���ؼ�
	// �����̳ʿ� ��Ƶ־� ��

	// list ��ü �ִ¹�
	// push_back(), push_front() ���
	bullets.push_back(bullet);
}

