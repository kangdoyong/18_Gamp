#include "MainGame.h"
#include "SceneManager.h"

void MainGame::Initialize()
{
	// ���� ���� ��ü ����
	panel = new Panel();
	// ���� ���� �ʱ�ȭ
	panel->Initialize();

	// ���� ���� ����
	SceneManager::GetInstance()->SetScene(SceneType::TITLE);
}

void MainGame::Update()
{
	// ���� �� ������Ʈ
	// �� ��, ���� ������Ʈ�� ��ȯ Ÿ���� SceneType ��
	// ��ȯ�Ǵ� �� Ÿ���� ����, �����ϰ��� �ϴ� ���� �ִٸ�
	// �ش� ���� Ÿ���� ��ȯ�ϰԲ�, ������ ������ ����
	auto t = SceneManager::GetInstance()->GetScene()->Update();

	// ��ȯ ���� �� Ÿ�� none���� ũ�ٸ�, ���� �����Ѵٴ� �ǹ�
	if (t > SceneType::NONE)
	{
		// �����ϰ��� �ϴ� ������ ����
		SceneManager::GetInstance()->SetScene(t);
	}
}

void MainGame::Render()
{
	// ȭ�� �����
	panel->Clear();

	// ���� �� �׸���
	SceneManager::GetInstance()->GetScene()->Render();

	// ȭ�� ��ȯ
	panel->Flip();
}

void MainGame::Release()
{
	// ���� ���� ��ü �ı�
	if (panel)
	{
		delete panel;
		panel = nullptr;
	}

	// �� �Ŵ��� �ı�
	SceneManager::Destroy();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
