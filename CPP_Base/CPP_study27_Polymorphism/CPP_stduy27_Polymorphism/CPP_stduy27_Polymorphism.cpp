#include <iostream>
using namespace std;

// 오늘의 주제 : 다형성

// 다형성(Polymorphism = poly + morph) = 겉은 똑같은데, 기능이 다르게 동작한다.
// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용
// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다.
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Static Binding) : 실행 시점에 결정

// 일반 함수는 정적 바인딩 사용.
// 동적 바인딩을 원한다면? -> 가상 함수 (Virtual function)
// 그런데 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해준걸까?
// -> 가상 함수 테이블 생성! (vftable)

// .vftable [] 4바이트(32) 8바이트(64)

// [VMove] [ ]

// 순수 가상 함수 : 구현은 없고 '인터페이스'만 전달하는 용도로 사용하고 싶을 때 사용.

class Player
{
public:

	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }

	void Move(int a) { cout << "Move Player (int) !" << endl; }

	virtual void VMove() { cout << "Move Player (virtual) !" << endl; }
	virtual void VDie() { cout << "Die Player (virtual) !" << endl; }

	// 순수 가상 함수 (= 0;)
	virtual void VAttack() = 0;

public:
	int _hp;
};

class Knight : public Player
{
public:

	Knight()
	{
		_stamina = 100;
	}

	void Move() { cout << "Move Knight !" << endl; }

	//가상함수는 재정의를 하더라도 가상함수다!
	virtual void VMove() { cout << "Move Knight (virtual) !" << endl; }
	virtual void VDie() { cout << "Die Knight (virtual) !" << endl; }

	virtual void VAttack() { cout << "VAttack knight" << endl; }


public:
	int _stamina;
};




// [ [ player ] ]
// [   knight   ]
void MovePlayer(Player* player)
{
	player->VMove();
	player->VDie();
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

int main()
{
	/*Player p;
	p.Move();
	p.Move(10);*/

	Player p; // 순수가상함수를 포함하면 해당 클래스를 독단적으로 사용할 수 없다!
	//MovePlayer(&p); // 플레이어는 플레이어다? Yes
	//MoveKnight(&p); // 플레이어는 기사다? No --> 알 수 있는것 : 부모클래스에선 자식클래스로 넘어갈 수 없다.

	Knight k;
	//MoveKnight(&k); // 기사는 기사다? Yes
	MovePlayer(&k); // 기사는 플레이어다? Yes
	return 0;
}