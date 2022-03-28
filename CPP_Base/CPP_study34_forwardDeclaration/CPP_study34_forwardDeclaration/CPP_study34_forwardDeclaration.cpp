#include <iostream>
using namespace std;
#include "Player.h"
#include "Monster.h"

// 전방선언!

int main()
{
	// 오늘의 핵심 : player는 몇 byte인가?
	// int 2개 + sizeof(Player*) + sizeof(Monster*)= 16바이트

	// sizeof(Monster*) = 4 or 8byte

	Player p1; // 지역변수(Stack)

	Player* p2 = new Player(); // 동적할당 (Heap)

	p1._target = p2;

	return 0;
}