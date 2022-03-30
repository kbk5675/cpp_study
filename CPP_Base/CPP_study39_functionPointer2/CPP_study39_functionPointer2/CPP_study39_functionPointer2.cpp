#include <iostream>
using namespace std;

//관습적으로 typedef 별칭은 "_t" 접미사를 사용하여 선언

// typedef의 진실
// typedef 왼쪽 오른쪽값 -> 오른쪽 (커스텀 타입 정의)

// 어떤 함수타입을 의미할건데, 그 함수값이 인자는 int,int 출력은 int로 해주는 함수타입을 이제 FUNC()라고 부를거야.
typedef int(*PFUNC)(int, int); // 함수 포인터



int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

class Knight
{
public:
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp;
};

typedef int(Knight::* PMEMFUNC)(int, int); // 멤버함수 포인터

int main()
{
	// 함수 포인터
	// 1) 포인터		*
	// 2) 변수의 이름	fn
	// 3) 타입			함수(인자로 int 2개 받고, int 1개를 반환)

	//int (*fn)(int, int);
		
	//참고
	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;
	
	PFUNC fn;

	fn = &Test;
	fn(1, 2);
	(*fn)(1, 2);

	// 위 문법으로 [전역 함수 / 정적함수]만 담을 수 있다. ( 호출 규약이 동일한 애들 )
	
	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp;
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}