#pragma once
#include "Scene.h"

// �� ��ü���� ������ Ŭ����
// ���� �� ��ü�� �ʵ�� ������ �ְ�,
// ���� ���� ���� ���ϴ� ������ �����ϴ� ����� ����

// ����, �� ������ ���ؼ��� �ش� Ŭ���� ��ü�� �����Ͽ��߸� ��
// �� ���� �ܺο��� ������ ����ϴٴ� �ǹ�

// ������ ���� ��, �̱��� ����
// �̱��� : ��ü�� �ν��Ͻ��� �� �ϳ��� ����, �ܺο��� ������ ���ϰ� ��
// 1. ���� ������ ���ؼ� -> �ܺο��� ����ϰ� ����
// 2. �Ŵ��� Ŭ�����̹Ƿ�, �ν��Ͻ��� ���� �� ������ �ʿ䰡 ����, �� �ϳ��� ������ ��

class SceneManager
{
private:
	Scene* currentScene; // ���� ���� �ν��Ͻ��� ���� �ʵ�

public:
	// ���� �� �ν��Ͻ��� ��ȯ�ϴ� ���
	Scene* GetScene();
	// ���� ���� �����ϴ� ���
	// -> �Ķ���ͷ� ���� �� Ÿ�Կ� ����, Ÿ�Կ� �´� ������ ����
	void SetScene(SceneType type);

	// �� �Ŵ��� �̱��� ����
private:
	// �����ڸ� private���� ���������ν�
	// �ܺο��� ��ü�� �ν��Ͻ��� ������ �� ����
	SceneManager();
public:
	~SceneManager();

private:
	static SceneManager* instance; // �� �Ŵ����� �ν��Ͻ��� ���� �ʵ�

public:
	// �� �Ŵ����� �ν��Ͻ��� ���ٸ� �����ϰ�, �ִٸ� ��ȯ�ϴ� ���
	static SceneManager* GetInstance()
	{
		// �ν��Ͻ��� �ִ��� Ȯ��
		if (instance == nullptr)
			// ������ ����
			instance = new SceneManager();

		// ���� or �̹� ���� ��� ����
		return instance;
	}

	static void Destroy()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

