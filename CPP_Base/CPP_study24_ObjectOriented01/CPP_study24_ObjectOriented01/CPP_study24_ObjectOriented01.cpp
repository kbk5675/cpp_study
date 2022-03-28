#include <iostream>
using namespace std;

// 주제 : 객체지향 프로그래밍 & 생성자와 소멸자

// 절차(procedural)지향 프로그래밍
// - procedure = 함수

// 절차지향은 데이터를 중심으로 함수를 구현합니다. 이에 반해 객체지향은 기능을 중심으로 메서드를 구현

// 데이터 + 가공 = 프로그램,게임

// Knight를 설계해보자
// - 속성(데이터) : hp, attack, y, x
// - 기능(동작) : Move, Attack, Die;

// [생성자(Constructor)와 소멸자(Destructor)]
// 클래스에 '소속'된 함수들은 멤버 함수라고 함
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 존재 가능)
// - 끝(소멸) -> 소멸자( 오직 1개만)

// [암시적(Implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어진다.
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음!


class Knight
{
public:
	// 기본 생성자(인자가 없음)
	Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	// 복사 생성자
	// 일반적으로 똑같은 데이터를 지닌 객체가 생성되길 기대한다.
	Knight(const Knight& Knight)
	{
		cout << "Knight(&Knight) 복사 생성자 호출" << endl;
		_hp = Knight._hp;
		attack = Knight.attack;
		posY = Knight.posY;
		posX = Knight.posX;
	}

	// int 인수를 받는 기타생성자
	// 인자를 1개만 받는 생성자는 [타입 변환 생성자]라 부르기도함
	// explicit -> 명시적인 용도로만 사용할 것!
	explicit Knight(int hp)
	{
		cout << "Knight(int) 기타생성자 호출" << endl;
		_hp = hp;
		attack = 0;
		posY = 0;
		posX = 0;

	}

	// 기타 생성자
	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = _hp;
		attack = attack;
		posY = posY;
		posX = posX;
	}

	// 소멸자 Knight()가 소멸 될 때 실행됨.
	~Knight()
	{
		cout << "Knight() 기본 생성자 소멸" << endl;
	}

	// 멤버함수 선언
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버변수 
	int _hp; // or m_hp, mHp 멤버변수인것을 표시하는게 좋음.
	int attack;
	int posY;
	int posX;
};

void Knight::Move(int y, int x) {

	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// instantiate 객체를 만든다.

int main()
{
	Knight(100, 10, 1, 1); // 기타생성자 이용!

	Knight k1;
	k1._hp = 100;
	k1.attack = 10;
	k1.posX = 0;
	k1.posY = 0;

	Knight k2(k1); // 복사 생성자 이용!

	Knight k3 = k1; // 복사 생성자 이용!


	// 기본 생성자 이용!
	Knight k4;
	k4 = k1; 

	// k1과 k2는 메모리주소가 다르다 서로 16byte
	k1.Move(2, 2);
	k1.Attack();
	k1.Die();
	 

	// 암시적 형번환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;

	float f = (float)num; // 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문하고 있음
	double d = num; // 암시적 << 별말 안했는데 컴파일러가 알아서 처리하고 있음
	

	Knight k5;


	return 0;
}