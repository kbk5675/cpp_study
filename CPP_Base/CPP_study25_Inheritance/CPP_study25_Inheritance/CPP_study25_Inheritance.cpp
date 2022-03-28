#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성 =  부모 -> 자식
// - 은닉성 
// - 다형성

// class는 일종의 설계도!

// 생성자(N)/소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight를 생성하면 -> Player의 생성자 호출? Knight의 생성자를 호출??
//   -> 둘다 호출한다 ^^. (생성자는 상속에서 제외)

//GameObject
// - Creature
// - Player, Monster, NPC, Pet
// - Projectile
// - Arrow, Fireball
// - Env

//Item
// - Weapon
// - Sword, Bow
// - Armor
// - Helmet, Boots
// - consumable
// - Potion, Scroll


//Player는 부모클래스
class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};
// Knight뿐만 아니라 많은 직업이 있는데 하나하나 클래스 만들기 부담스러움. ==> 객체지향의 [상속]을 사용하자!
// 
// 메모리 구성
// [ [ Player ] ]
// [    Knight  ]
// 
// 
// Knight는 자식클래스
class Knight : public Player
{
public:
	Knight()
	{
		/* 생성자 호출순서
		-선처리 영역
		--..
		---...
		----.... 처리 마지막쯤  Player() 생성자 호출
		*/
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
	{
		/* 생성자 호출순서
				-선처리 영역
				--..
				---...
				----.... 처리 마지막쯤  Player(int hp) 생성자 호출
				*/
		_stamina = stamina;
		cout << "Knight(_stamina)  생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/* 소멸자 호출순서
		-후처리 영역
		- ~Player() 소멸자 호출
		*/



	// 재정의 : 부모님의 유산을 거부하고 새로은 이름으로 새로운 기능 만든?
	void Move() { cout << "Knight Move 호출" << endl; }
public:
	int _stamina;
};

// Mage는 자식클래스
class Mage : public Player
{
public:

public:
	int _mp;
};


int main()
{
	Knight k(100);

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Attack();
	k.Die();
	k.Move();


	return 0;
}