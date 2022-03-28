#include <iostream>
using namespace std;

// 포인터 연산

// 1) 주소 연산자 (&)
// 2) 산술 연산자
// 3) 간접 연산자
// 4) 간접 멤버 연산자
// 
//

struct Player
{
	int hp;
	int damage;
};

int main()
{
	int number = 1;
	// 주소 연산자 (&)
	// - 해당 변수의 주소를 알려주세요~ -
	int* pointer = &number;

	// 산술 연산자 (+ -)
	number = number + 1; // 1증가!

	// int*
	// * : 포인터 타입이니까 8바이트! 주소를 담는 바구니!
	// int : 주소를 따라가면 int(4byte 정수형 바구니)가 있다고 가정해라!

	pointer += 1; // 4증가(?) -> 산술적인 1증가 X 한번의 TYPE의 크기만큼을 이동하라!! 바구니 단위의 이동이다..!

	// 간접 연산자 (*)
	// - 포탈을 타고 해당 주소로 슝~하고 이동
	number = 3;
	*pointer = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;
	
	Player* playerPtr = &player;
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 20;

	// 간접 멤버 연산자
	// * 간접 연산자 (포탈 타고 해당 주소로 GOGO)
	// . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리 언어로 까보면 . 사실상 그냥 덧셈)
	// -> 는 *와 . 을 한번에 처리 개꿀

	playerPtr->hp = 200;
	playerPtr->damage = 200;

	return 0;
}