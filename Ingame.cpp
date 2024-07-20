#include "Ingame.h"
#include "Player.h"
#include "Monster.h"

void Ingame::SpawnMonster()
{
	if (prevSpawnTime + spawnDelayTime < GetTickCount64())
	{
		prevSpawnTime = GetTickCount64();

		Info monsterInfo("Monster", BufferSizeX - 5, rand() % BufferSizeY);
		Object* monster = new Monster(monsterInfo);
		monster->Initialize();

		monsters.push_back(monster);
	}
}

void Ingame::Initialize()
{
	// �÷��̾� ��ü ������ ���� ������ ����
	Info playerInfo("Player", 5, BufferSizeY / 2);
	// �÷��̾� ��ü ����
	player = new Player(playerInfo);
	// ������ �÷��̾� ��ü�� �ʱ�ȭ
	player->Initialize();

	// �÷��̾� ��ü�� ���� �Ѿ˸���Ʈ �ּҸ� ������
	bullets = ((Player*)player)->GetBullets();

	prevSpawnTime = GetTickCount64();
	spawnDelayTime = 500;
}

SceneType Ingame::Update()
{
	SpawnMonster();
	player->Update();

	// �Ѿ� ����Ʈ �ȿ� �ִ� �Ѿ� ��ü���� ������Ʈ
	// �迭 ��� �ÿ��� �ε����� ���� ���ҿ� ��������
	// list�� ���ҿ� ������ ��, iterator(�ݺ���)�� ���� ������
	for (list<Object*>::iterator i = bullets->begin();
		i != bullets->end(); )
	{
		(*i)->Update();

		// �Ѿ��� ȭ���� ����ٸ�, �ı�
		if ((*i)->GetInfo().pos.x >= BufferSizeX - 2)
		{
			// list.erase() �� �Ķ���ͷ� �ѱ� ������
			// ����Ʈ �ȿ��� ���� ��, ���� �ش� ������ ����Ű��
			// �ִ� ������ ���� ��ġ�� iterator ���·� ��ȯ�� ���ݴϴ�.
			i = bullets->erase(i);
		}
		else
			++i;
	}

	for (auto i = monsters.begin(); i != monsters.end();)
	{
		(*i)->Update();

		if ((*i)->GetInfo().pos.x < 3)
		{
			i = monsters.erase(i);
		}
		else
			++i;
	}

	// ���Ϳ� �Ѿ��� �浹 ó��
	for (auto i = monsters.begin(); i != monsters.end();)
	{
		// �浹 ���θ� ��Ÿ���� ����
		bool isColl = false;

		// ���� ��ǥ�� �޾Ƶ�
		int monsterPosX = (*i)->GetInfo().pos.x;
		int monsterPosY = (*i)->GetInfo().pos.y;

		for (auto j = bullets->begin(); j != bullets->end(); ++j)
		{
			int distanceX = monsterPosX - (*j)->GetInfo().pos.x;
			int distanceY = monsterPosY - (*j)->GetInfo().pos.y;

			if ((distanceX <= 2 && distanceX >= -2)
				&& (distanceY <= 2 && distanceY >= -2))
			{
				isColl = true;

				bullets->erase(j);
				break;

				// �̹� �� ����� ���Ͱ� �Ѿ˸���Ʈ��
				// Ư�� �Ѿ� ��ü �ϳ��� �浹����
				// �� ����� ���Ͱ� ���ŵǹǷ�,
				// �� �̻� �Ѿ˸���Ʈ�� ��ȸ�� �ʿ䰡 ����
				// ����, �Ѿ˸���Ʈ�� ��ü �� ���� ���� ��,
				// ���� ������ ��ġ�� ���� �ʿ� ����, ���� for���� Ż��
			}
		}

		// ���Ͱ� Ư�� �Ѿ˰� �浹�ߴ���
		if (isColl)
		{
			// �浹�� ���͸� �����, ���� ���ͷ� �Ѿ
			i = monsters.erase(i);
		}
		// �浹���� �ʾҴٸ�, ���� ���ͷ� �Ѿ
		else
		{
			++i;
		}
	}

	// ���Ϳ� �÷��̾� ���� �浹 ó��
	// �� �������� �Ÿ��� 2 ���϶�� �浹�̶�� ����
	// -> ���� ���� ���� ������ 
	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		// x, y�� �� �Ÿ�
		int distanceX = player->GetInfo().pos.x - (*i)->GetInfo().pos.x;
		int distanceY = player->GetInfo().pos.y - (*i)->GetInfo().pos.y;

		// �浹 üũ
		if ((distanceX <= 2 && distanceX >= -2) &&
			(distanceY <= 2 && distanceY >= -2))
		{
			return SceneType::GAMEOVER;
		}
	}

    return SceneType::NONE;
}

void Ingame::Render()
{
	player->Render();

	for (list<Object*>::iterator i = bullets->begin();
		i != bullets->end(); ++i)
	{
		(*i)->Render();
	}

	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		(*i)->Render();
	}
}

void Ingame::Release()
{
	for (list<Object*>::iterator i = bullets->begin();
		i != bullets->end(); ++i)
	{
		if (*i)
		{
			delete* i;
			*i = nullptr;
		}
	}

	if (player)
	{
		delete player;
		player = nullptr;
	}

	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		if (*i)
		{
			delete* i;
			*i = nullptr;
		}
	}
}

Ingame::Ingame()
{
}

Ingame::~Ingame()
{
	Release();
}
