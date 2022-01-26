#include <iostream>
using namespace std;

// 오늘의 주제 ; 배열

struct StatInfo{
	int hp;
	int attack;
	int defence;
};
 

int main()
{
	// 데이터 많아지면 하나씩 추가하기 어려움..
	StatInfo monster;
	StatInfo monster_2;
	StatInfo monster_3;

	// 배열은?
	// TYPE 이름[개수];

	// 배열 크기는 상수여야함
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	int a = 10;
	int b = a;

	// 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAml = monsters;

	// StatInfo[(100,10,1)] StatInfo[] StatInfo[] StatInfo[] StatInfo[]...
	// monster_0[주소]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 20;
	monster_0->defence = 5;

	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 150;
	monster_1->attack = 15;
	monster_1->defence = 3;

	// 포인터와 참조는 자유자재로 변환 가능
	//StatInfo& monster_2 = *(monsters + 2);
	//monster_2.hp = 80;
	//monster_2.attack = 50;
	//monster_2.defence = 1;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 20 * (i + 1);
		monster.defence = 5 * (i + 1);
	}

	// 근데 *(monsters + i) 너무 불편하고 가독성 떨어진다
	// 인덱스 사용!
	// 배열은 0번부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i)  = monsters[i]

	monsters[0].hp = 100;
	monsters[0].attack = 20;
	monsters[0].defence = 4;

	int hp = monsters[0].hp;
	cout << hp << endl;

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 20 * (i + 1);
		monsters[i].defence = 5 * (i + 1);
	}

	// 배열 초기화 몇가지 문법
	int number[5] = {}; // 다 0으로 밀어버린다.
	int number2[10] = { 1,2,3,4,5 }; // 1,2,3,4,5,0,0,...
	int number3[] = { 1,3,4,12,42,51,56,77 }; // 데이터 개수만큼 배열 만든다.

	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	return 0;
}