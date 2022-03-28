#include <iostream>
using namespace std;

// TEXT RPG use Pointer

// main
// - EnterLobby (PlayerInfo)
// -- CreatePlayer
// -- EnterGame (MosterInfo)
// --- CreateMonsters
// --- EnterBattle

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};
enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp = 0;
	int attack = 0;
	int denfence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);

void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* platerInfo, StatInfo* monsterInfo);


int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();

	return 0;
}

void EnterLobby() {
	while (true)
	{
		PrintMessage("로비에 입장했습니다.");

		//PLAYER!
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo);

		EnterGame(&playerInfo);
	}
}

void PrintMessage(const char* msg)
{
	cout << "**************************" << endl;
	cout << msg << endl;
	cout << "**************************" << endl;
}

void CreatePlayer(StatInfo* playerInfo) {
	
	bool ready = false;
	
	while (ready == false)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사  [2] 궁수  [3] 법사");
		cout << ">> ";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_Knight:
			playerInfo->hp = 100;
			(*playerInfo).attack = 15;
			playerInfo->denfence = 10;
			ready = true;
			break;
		case PT_Archer:
			playerInfo->hp = 90;
			(*playerInfo).attack = 20;
			playerInfo->denfence = 7;
			ready = true;
			break;
		case PT_Mage:
			playerInfo->hp = 80;
			(*playerInfo).attack = 25;
			playerInfo->denfence = 5;
			ready = true;
			break;

		default:
			break;
		}
	}
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "*********************" << endl;
	cout << name << " : HP=" << info.hp << " ATT=" << info.attack << " DEF=" << info.denfence << endl;
	cout << "*********************" << endl;
}

void EnterGame(StatInfo* playerInfo) {
	
	const int MONSTER_COUNT = 2;

	PrintMessage("게임에 입장했습니다.");

	while (true)
	{
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int i = 0; i < MONSTER_COUNT; i++)
			PrintStatInfo("Monster", monsterInfo[i]);

		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] 전투  [2] 전투 [3] 도망");

		int input;
		cin >> input;

		if (input == 1 || input == 2) {
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &(monsterInfo[index]) );
			if (victory == false)
				break;
		}
	}
}

void CreateMonsters(StatInfo monsterinfo[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int randValue = 1 + rand() % 3;

		switch (randValue)
		{
		case MT_Slime:
			monsterinfo[i].hp = 30;
			monsterinfo[i].attack = 5;
			monsterinfo[i].denfence = 1;
			break;

		case MT_Orc:
			monsterinfo[i].hp = 40;
			monsterinfo[i].attack = 8;
			monsterinfo[i].denfence = 2;
			break;

		case MT_Skeleton:
			monsterinfo[i].hp = 50;
			monsterinfo[i].attack = 10;
			monsterinfo[i].denfence = 3;
			break;

		default:
			break;
		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
	while (true)
	{
		int damage = 1 + rand() % (playerInfo->attack - monsterInfo->denfence); // 최대 최소 랜덤 데미지.
		// 데미지 음수 오류 예방.
		if (damage < 0)
			damage = 0;

		monsterInfo->hp -= damage;
		// 몬스터 피통 음수 오류 예방.
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0)
		{
			PrintMessage("몬스터를 처치했습니다.");
			return true;
		}
		//몬스터 안죽었으면 반격.
		damage = 1 + rand() % (monsterInfo->denfence - playerInfo->attack);
		if (damage < 0)
			damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0)
		{
			PrintMessage("Game Over");
			return false;
		}
	}
}

