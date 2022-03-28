#pragma once


// is - a 관계냐
// has - a 관계냐 생각해라


// 전방선언 -> 나중에 가서 등장할테니까 일단은 통과시켜줘식 선언.
class Player;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	
	//Player _player; // 이렇게 선언할 시, Knight같은 player클래스를 상속하는
					  // 경우에 데이터 짤림 현상 일어날 수 있다!
					  // ex) Knight 클래스의 메모리 [   [Player]   ] 
					  //     Player 클래스의 메모리     [Player] 
					  // 이기 때문이다.

	Player* _player;
	// [ 4~8 ] --->> [       ]
	// 포인터로 선언시,
	// 실제 플레이어와 무관하게 게임안에 
	// 플레이어를 찾아가기 위한 주소값만 선언.
	
	Field* _field;

};

