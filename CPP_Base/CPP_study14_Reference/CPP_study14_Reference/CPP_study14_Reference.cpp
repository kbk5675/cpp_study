#include <iostream>
using namespace std;

// 오늘의  주제는..		참조 전달 방식

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info) {
	info->hp = 100;
	info->attack = 20;
	info->defence = 5;
}



// 1) 값 전달 방식(복사붙여넣기) 방식
void PrintInfoByCopy(StatInfo info) {
	cout << "---------------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATTACK : " << info.attack << endl;
	cout << "DEFENCE : " << info.defence << endl;
	cout << "---------------------------" << endl;
}


// 2) 주소 전달 방식
void PrintInfoByPointer(StatInfo* info) {
	cout << "---------------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATTACK : " << info->attack << endl;
	cout << "DEFENCE : " << info->defence << endl;
	cout << "---------------------------" << endl;
}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는..
// - (주소 전달) StatInfo*는 (64비트 운영체제시)8바이트 or (32비트 운영체제시)4바이트
// - (참조 전달) StatInfo&는 (64비트 운영체제시)8바이트 or (32비트 운영체제시)4바이트
// 참조 장점 - 값 전달처럼 편리하게 사용하고! 주소 전달처럼 주소값을 이용해 진퉁을 건드리는! 일석이조의 방식!

// 3) 참조 전달 방식
void PrintInfoByReference(StatInfo& info) {
	cout << "---------------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATTACK : " << info.attack << endl;
	cout << "DEFENCE : " << info.defence << endl;
	cout << "---------------------------" << endl;
}

int main()
{
	// 참조 전달 방식

	// 4바이트 정수형 바구니를 만들었어.
	// 앞으로 이 바구니를 number라고 부를게!
	// 그니까 number에서 뭘 꺼내거나 or number에 뭘 넣는다고 하면!
	// 찰떡같이 알아듣고 해당 주소에 1을 넣어주면 돼! 컴퓨터놈아!
	int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 데이터(바구니)가 있음
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 실제로 실행해보면 동작방식이 포인터랑 100% 똑같다.
	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것. (2번째 이름임)
	// number라는 바구니에 reference 라는 다른 이름을 지어줄게~~
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(진퉁에다가) 그 값을 꺼내거나 넣으면 됌.
	reference = 3;

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPointer(&info);
	PrintInfoByReference(info);
	
	return 0;
}