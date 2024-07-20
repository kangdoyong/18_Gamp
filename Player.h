#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	// 복수의 총알 객체를 담을 필드
	// stl 자료구조 중, list 사용
	// 배열과 비슷한데, 배열 사용 시 사이즈를 고정적으로 설정해야하지만
	// 리스트는 사이즈를 지정하지 않아도 됨, 객체를 추가했을 때
	// 공간이 부족하면 알아서 공간을 늘림
	// 객체의 추가/제거 등이 빈번히 발생한다면 list를 사용하는 것이 좋음
	list<Object*> bullets;

	ULONGLONG prevFireTime; // 이전 발사 시간
	ULONGLONG delayTime; // 발사 딜레이 시간

public:
	// 총알 리스트의 주소를 반환하는 메서드
	list<Object*>* GetBullets() { return &bullets; }


public:
	// Object을(를) 통해 상속됨
	void Initialize() override;
	SceneType Update() override;
	void Render() override;
	void Release() override;
	void Fire();

	Player(Info info);
	virtual ~Player();
};

