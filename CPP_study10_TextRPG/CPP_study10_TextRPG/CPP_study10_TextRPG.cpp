#include <iostream>
using namespace std;

// 포인터를 안쓰고 만드는 TextRPG

enum MonsterType {
	MT_slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

enum PlayerType {
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

struct ObjectInfo
{
	// 플레이어 변수
	short type;
	int hp;
	char attack;
	int defence;
	// 2 + 4 + 1 + 4 = 11bytes..? NO! padding값을 생각해야한다!
	// 모든 타입을 4byte로 컴퓨터가 계산하기 편하게 바꾼다!
};

class Game {
	ObjectInfo playerInfo;  // 플레이어 변수
	ObjectInfo monsterInfo; // 몬스터 변수
	bool backToField = false;
public:
	void EnterLobby();
	void SelectPlayer();
	void EnterField();
	void EnterBattle();
	void CreateRandomMonster();
};

int main()
{
	// 랜덤 시드 설정
	srand(time(0));

	// 게임 시작
	Game game;
	game.EnterLobby();
	return 0;
}

void Game::EnterLobby() {
	int input = 0;
	while (true)
	{
		cout << "------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "------------------" << endl;
		cout << "(1) 필드 입장  (2) 게임 종료" << endl;
		cout << "------------------" << endl;
		cin >> input;

		if (input == 1) {
			EnterField();
		}
		else if (input == 2) {

		}
		else
			return;
	}
	
}

void Game::SelectPlayer() {
	while (true)
	{
		cout << "---------------" << endl;
		cout << "직업을 선택하십시오" << endl;
		cout << "1)전사\t2)궁수\t3)마법사\t" << endl;
		cout << ">> ";
		cin >> playerInfo.type;

		if (playerInfo.type == PT_Knight) {
			cout << "기사 생성중..." << endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.type == PT_Archer) {
			cout << "궁수 생성중..." << endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defence = 3;
			break;
		}
		else if (playerInfo.type == PT_Mage) {
			cout << "마법사 생성중..." << endl;
			playerInfo.hp = 80;
			playerInfo.attack = 30;
			playerInfo.defence = 1;
			break;
		}
		else
			cout << "다른 직업을 선택해주세요!" << endl;
	}
}

void Game::EnterField() {
	int input = 0;

	if (backToField == false)
	{
		cout << "------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "------------------" << endl;
	}

	while (true)
	{
		if (backToField == true)
		{
			cout << "------------------" << endl;
			cout << "필드에 돌아왔습니다!" << endl;
			cout << "------------------" << endl;
		}
		
		cout << "[PLAYER] HP : " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF : " << playerInfo.defence << endl;

		CreateRandomMonster();

		cout << "------------------" << endl;
		cout << "(1) 전투\t (2) 도주" << endl;
		cin >> input;

		if (input == 1) {
			backToField = true;
			EnterBattle();
			if (playerInfo.hp == 0)
				return;
			
		}
		else if (input == 2) {
			backToField = true;
			EnterField();
		}
		else {
			backToField = true;
			cout << "Test" << endl;	
		}
			
	}
}

void Game::CreateRandomMonster() {
	monsterInfo.type = 1 + (rand() % 3);
	
	switch (monsterInfo.type)
	{
	case MT_slime:
		cout << "슬라임 생성중...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterInfo.hp = 15;
		monsterInfo.attack = 5;
		monsterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defence = 5;
		break;
	default:
		break;
	}
}

void Game::EnterBattle() {

	int i = 1;

	while (true)
	{
		while (monsterInfo.hp != 0 || playerInfo.hp != 0)
		{
			
			int damage = playerInfo.attack - monsterInfo.defence;
			if (damage < 0)
				damage = 0;
			// 선빵
			monsterInfo.hp -= damage;
			if (monsterInfo.hp < 0)
				monsterInfo.hp = 0;

			cout << i << "턴) 몬스터 남은 체력 : " << monsterInfo.hp << endl;
			if (monsterInfo.hp == 0) {
				cout << "몬스터를 처치했습니다." << endl;
				return;
			}
			damage = playerInfo.attack - monsterInfo.defence;
			if (damage < 0)
				damage = 0;
			// 반격
			playerInfo.hp -= damage;
			if (playerInfo.hp < 0)
				playerInfo.hp = 0;

			cout << i << "턴) 플레이어 남은 체력 : " << playerInfo.hp << endl;
			i++;

			if (playerInfo.hp == 0) {
				cout << "당신의 캐릭터는 사망하였습니다...GAME OVER\n================================\n" << endl;
				return;
			}
		}
	} 
}

