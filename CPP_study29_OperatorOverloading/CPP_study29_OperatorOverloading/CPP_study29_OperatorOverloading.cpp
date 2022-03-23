#include <iostream>
using namespace std;

// 오늘의 주제 : 연산자 오버로딩(Operator Overloading) 

// 연산자 vs 함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽 기준으로 실행됨 (a가 클래스여야 가능. a를 '기준 피연산자'라고 함)
// -- 한계) a가 클래스가 아니면 사용 못함

// 그럼 무엇이 더 좋은가? -> 그런거 없음. 심지어 둘 중 하나만 지원하는 경우도 있기 때문.
// - 대표적으로 대입 연산자 ( a = b )는 전역 연산자 version으로는 못 만든다.

// 복사 대입 연산자
// - 대입 연산자가 나온 김에 [복사 대입 연산자]에 대해 알아보자
// - 용어가 좀 헷갈린다. [복사 생성자] [대입 연산자] [복사 대입 연산자] @_@
// - 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것

// 기타
// - 모든 연산자를 다 오버로딩 할 수 있는 것은 아니다(::, ., .* 이런것)
// - 전위형 operator++()
// - 후위형 operator++(int)

class Position
{
public:
	
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x = arg._x && _y == arg._y;
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		//Position* this = 내자신의주소;
		return *this;
	}

	// [복사 생성자] [복사 대입 연산자] 등 특별 대우를 받는 이유는,
	// 말 그대로 객체가 '복사' 되길 원하는 특징 때문이다.
	Position& operator=(Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		return *this;
	}

public:
	int _x;
	int _y;
};

Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x + b._x + a;
	ret._y + b._y + a;
}

int main()
{
	Position pos;
	pos._x = 1;
	pos._y = 1;

	Position pos2;
	pos2._x = 2;
	pos2._y = 2;

	Position pos3 = pos + pos2; 

	cout << pos._x << endl;
	cout << pos2._x << endl;
	cout << pos3._x << endl;

	Position pos4 = pos3 + 1;
	cout << pos4._x << endl;

	Position pos5 = 1 + pos3; //전역으로 operator+ 선언하면 클래스가 꼭 왼쪽으로 안와도 된다.

	bool isSame = (pos3 == pos4);
	cout << isSame << endl;

	return 0;
}