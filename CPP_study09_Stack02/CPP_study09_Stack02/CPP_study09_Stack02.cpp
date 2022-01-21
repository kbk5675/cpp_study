#include <iostream>
using namespace std;

// 오늘의 주제 : 호출 스택, 함수 마무리

// 함수 선언
void Func1();
void Func2(int a, int b);
void Func3(float a);

void Func1() {
	cout << "Func1" << endl;

	Func2(1, 2);
}

void Func2(int a, int b) {
	cout << "Func2" << endl;
	
	Func3(10);
}

void Func3(float a) {
	cout << "Func3" << endl;
}


// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나( 순서가 다른걸 포함)

int Add(int a, int b) {
	int result = a + b;
	return result;
}

float Add(float a, float b) {
	float result = a + b;
	return result;
}

// 예제
// 게임 캐릭터 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 0) //매개변수 guildId를 0으로 설정(주의:무조건 끝쪽으로 해야함)
{
	
}

// 스택 오버플로우 - 함수를 너무 많이 호출해서 생기는 문제 

//재귀함수
int Factorial(int n) {
	return n * Factorial(n - 1);
}

int main()
{
	cout << "main" << endl;
	Func1();

	int result1 = Add(3.6,  3);
	cout << result1 << endl;
	
	float result2 = Add(1.5f, 2.1f);
	cout << result2 << endl;

	SetPlayerInfo(100, 40, 10);
	SetPlayerInfo(100, 40, 10, 1, 2);

	

	return 0;
}