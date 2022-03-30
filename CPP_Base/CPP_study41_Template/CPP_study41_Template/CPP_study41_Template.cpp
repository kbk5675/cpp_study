#include <iostream>
using namespace std;

// Template 기초

class Knight
{
public:

public:
	int _hp = 100;
};


template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
	cout << "Knight !!!!!!" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 연산자 오버로딩 (전역변수 버전)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}




int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀이다.
	// 1) 함수 템플릿 ( 인수의 타입에 따라 다른 함수를 만들어낸다)
	// 2) 클래스 템플릿

	Print<int>(50.0f); // <int> 해주면 다른타입값 들어가도 무조건 int로 출력. 
	Print(50.0f);
	Print("Hello world");

	Print("Hello", 100);

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.1f, 2.2f);

	Knight k1;
	Print(k1);

	return 0;
}