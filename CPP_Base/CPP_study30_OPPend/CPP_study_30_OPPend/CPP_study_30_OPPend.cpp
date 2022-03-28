#include <iostream>
using namespace std;

// 객체지향 마무리

// 1) struct vs class

// C++에서는 struct나 class나 종이 한 장 차이다.
// struct는 기본접근 지정자가 public이고, class는 private이다.
// -> struct는 그냥 구조체 (데이터묶음)을 표현하는 용도로 사용해라!
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도로 사용..!

struct TestStruct
{
public:
	int _a;
	int _b;
};

class TestClass
{
private:
	int _a;
	int _b;
};

// 2) static 변수,함수
// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 초기화 안하면 .bss

class Player
{
public:
	int _hp;
};

int GenerateId()
{
	// 생명주기: 프로그램 시작/종료 (메모리에 항상 올라가 있다~)
	// 가시범위: 해당 클래스를 호출한 영역만

	// 정적 지역 객체
	static int s_id = 1;
	
	return s_id++;
}

class Marine
{
public:
	int _hp;
	
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도상으로만 존재
};

int Marine::s_attack = 0;

int main()
{
	Marine m1;
	m1._hp = 50;
	Marine::s_attack = 5;
	m1.TakeDamage(10);

	Marine::s_attack = 6;


	// 스택 아님.
	static int id = 10;

	return 0;
}