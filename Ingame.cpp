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
	// 플레이어 객체 생성을 위해 정보를 생성
	Info playerInfo("Player", 5, BufferSizeY / 2);
	// 플레이어 객체 생성
	player = new Player(playerInfo);
	// 생성한 플레이어 객체를 초기화
	player->Initialize();

	// 플레이어 객체가 갖는 총알리스트 주소를 가져옴
	bullets = ((Player*)player)->GetBullets();

	prevSpawnTime = GetTickCount64();
	spawnDelayTime = 500;
}

SceneType Ingame::Update()
{
	SpawnMonster();
	player->Update();

	// 총알 리스트 안에 있는 총알 객체들을 업데이트
	// 배열 사용 시에는 인덱스를 통해 원소에 접근했음
	// list는 원소에 접근할 때, iterator(반복자)를 통해 접근함
	for (list<Object*>::iterator i = bullets->begin();
		i != bullets->end(); )
	{
		(*i)->Update();

		// 총알이 화면을 벗어났다면, 파괴
		if ((*i)->GetInfo().pos.x >= BufferSizeX - 2)
		{
			// list.erase() 에 파라미터로 넘긴 공간을
			// 리스트 안에서 지운 후, 원래 해당 공간이 가리키고
			// 있던 공간의 다음 위치를 iterator 형태로 반환을 해줍니다.
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

	// 몬스터와 총알의 충돌 처리
	for (auto i = monsters.begin(); i != monsters.end();)
	{
		// 충돌 여부를 나타내는 변수
		bool isColl = false;

		// 몬스터 좌표를 받아둠
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

				// 이미 비교 대상인 몬스터가 총알리스트의
				// 특정 총알 객체 하나와 충돌했음
				// 비교 대상인 몬스터가 제거되므로,
				// 더 이상 총알리스트를 순회할 필요가 없음
				// 따라서, 총알리스트의 객체 및 공간 제거 시,
				// 다음 공간의 위치를 받을 필요 없이, 안쪽 for문을 탈출
			}
		}

		// 몬스터가 특정 총알과 충돌했는지
		if (isColl)
		{
			// 충돌한 몬스터를 지우고, 다음 몬스터로 넘어감
			i = monsters.erase(i);
		}
		// 충돌하지 않았다면, 다음 몬스터로 넘어감
		else
		{
			++i;
		}
	}

	// 몬스터와 플레이어 간의 충돌 처리
	// 각 축으로의 거리가 2 이하라면 충돌이라고 판정
	// -> 씬을 게임 오버 씬으로 
	for (auto i = monsters.begin(); i != monsters.end(); ++i)
	{
		// x, y축 별 거리
		int distanceX = player->GetInfo().pos.x - (*i)->GetInfo().pos.x;
		int distanceY = player->GetInfo().pos.y - (*i)->GetInfo().pos.y;

		// 충돌 체크
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
