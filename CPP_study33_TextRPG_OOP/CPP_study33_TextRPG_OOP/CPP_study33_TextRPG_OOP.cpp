#include <iostream> // 공식 라이브러리는 < > 사용!
using namespace std;
#include "Game.h" // 커스텀 라이브러리는 " " 사용!

// TextRPG#4 OOP 객체지향적으로 제작해보자.
// 가상의 공간 자체도 객체로 생각해라.




int main()
{
	srand((unsigned int)time(nullptr));

	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return 0;
}