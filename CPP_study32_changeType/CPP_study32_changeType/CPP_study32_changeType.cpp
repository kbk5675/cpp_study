#include <iostream>
using namespace std;

// 타입 변환

// malloc -> void*을 반환하고, 이를 우리가 (타입 변환)을 통해 사용했었음

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog() // 기본 생성자
	{

	}
	
	// 타입 변환 생성자
	Dog(const Knight& knight)
	{
		_age = knight._hp;
	}

	// 타입 변환 연산자
	operator Knight()
	{
		return (Knight)(*this);
	}

public:
	int _age = 1;
	int _cuteness = 2;
};

class Bulldog : public Dog
{
public:
	bool _french;  // 프렌치불독
	
};

int main()
{
	// --------------- 타입 변환 유형 (비트열 재구성 여부) -------------------

	// [1] 값 타입 변환
	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성
	{
		int a = 123456789; // 2의 보수
		float b = (float)a; // 부동소수점(지수 + 유효숫자)
		cout << b << endl;
	}

	// [2] 참조 타입 변환
	// 특징) 비트열을 재구성하지 않고, '관점'만 바꾸는 것
	// 거의 쓸일은 없지만, 포인터 타입 변환도 '참조 타입 변환' 동일한 룰을 따르니까 일석이조로 공부하자!
	int a = 123456789; // 2의 보수
	float b = (float&)a; // 부동소수점(지수 + 유효숫자)
	cout << b << endl;


	// --------------- 안전도 분류 -------------------
	
	// [1] 안전한 변환
	// 특징) 의미가 항상 100% 완전히 일치하는 경우
	// 같은 타입이면서 크기만 더 큰 바구니로 이동
	// ex) char -> short, short -> int, int -> _int64
	{
		int a = 123456789;
		__int64 b = a;
		cout << b << endl;
	}

	// [2] 불안전한 변환
	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
	// 타입이 다르거나
	// 같은 타입이지만 큰 바구니 -> 작은 바구니 이동 (다운캐스팅) -> 데이터손실 생김
	{
		int a = 123456789;
		float b = a;
		short c = a;
		cout << b << endl;
		cout << c << endl;
	}

	// --------------- 프로그래머 의도에 따라 분류 -------------------

	// [1] 암시적 변환
	// 특징) 이미 알려진 타입 변환 규칙에 따라 컴파일러 '자동'으로 타입 변환
	{
		int a = 123456789;
		float b = a; //암시적
	}

	// [2] 명시적 변환
	{
		int a = 123456789;
		int* b = (int*)a;
		cout << b << endl;
	}

	// --------------- 아무런 연관 없는 클래스 사이의 반환 -------------------
	
	// [1] 연관없는 클래스 사이의 '값 타입' 변환
	// 특징) 일반적으로 안됨
	{
		Knight knight;
		Dog dog = (Dog)knight;
	}

	// [2] 연관없는 클래스 사이의 참조 타입 변환
	// 특징) 명시적으로는 OK
	{
		Knight knight;
		Dog& dog = (Dog&)knight;
		dog._cuteness = 12;
	}

	// ----------------- 상속 관계에 있는 클래스 사이의 변환 ------------------
	// 특징) 자식이 부모에게 상속 받는다 = OK		/	부모가 자식에게 상속을 받으려한다. = NO

	// [1] 상속 관계 클래스의 값 타입 변환
	{
		Bulldog bulldog;
		Dog dog = bulldog;

	}

	// [2] 상속 관계 클래스의 참조 타입 변환
	// 특징) 자식에서 부모로 = OK	/	부모에서 자식 = (암시적NO), (명시적OK)
	{
		Dog dog;
		Bulldog& bulldog = (Bulldog&)dog;

		Bulldog bulldog;
		Dog& dog = bulldog;
	}

	// 결론
	// [값 타입 변환] : 진짜 비트열도 바꾸고 ~ 논리적으로 말이 되게 바꾸는 변환
	// - 논리적으로 말이 된다? (ex. Bulldog-> Dog) OK
	// - 논리적으로 말 안된다. (ex. Dod -> Bulldog), Dog -> Knight) 안되지..
	// [참조 타입 변환] : 비트열은 냅두고 우리의 '관점'만 바꾸는 변환.
	// - 땡깡 부리면(명시적 요구) 해주긴하는데 , 말 안해도 '그냥'(암시적)으로 해주는지는 안전성 여부를 연관 지어 선택적 허가.
	// -- 안전하다! (ex. Bulldog -> Dog&) '그냥' (암시적으로) OK
	// -- 위험하다! (ex. Dog -> Bulldog&)
	// --- 메모리 침범 위험이 있음 암시적으로 안해줌.
	// --- but 명시적으로 해달라고 할 시, 해줌. (ex. (Bulldog&)dog )
	return 0;
}