#include <iostream>
using namespace std;

struct StatInfo
{
	int hp; // 주소0
	int damage; // 주소0+4
	int defence; // 주소0+8
};

void EnterLobby();
StatInfo CreatePlayer(); // no pointer
void CreateMonster(StatInfo* info); // use pointer
bool StartBattle(StatInfo* player, StatInfo* monster); // 플레이어 승리시 true

int main()
{
	EnterLobby();
	return 0;
}

void EnterLobby() {
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.damage = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(temp(100, 10, 2), player(100, 10, 2))] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.damage = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;
	// [매개변수][RET][지역변수(monster(40, 10, 2))] [매개변수(&monster)][RET][지역변수()]
	CreateMonster(&monster);

	// 번외편1)
	// 구조체끼리 복사할 때 무슨 일이 벌어질까? -> 콤퓨타가 한땀한땀 복붙한다 ㅋㅋ.
	//player = monster;

	bool victory =StartBattle(&player, &monster);

	if (victory)
		cout << "승리!!" << endl;
	else
		cout << "패배.." << endl;
}

StatInfo CreatePlayer() {
	StatInfo ret;
	cout << "플레이어 생성" << endl;
	ret.hp = 100;
	ret.damage = 10;
	ret.defence = 2;
	return ret;
}

void CreateMonster(StatInfo* info) {
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->damage = 10;
	info->defence = 2;
}

bool StartBattle(StatInfo* player, StatInfo* monster) {
	while (true)
	{
		int damage = (*player).damage - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp <= 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->damage - player->defence;
		if (damage < 0)
			damage = 0;

		cout << "플레이어의 HP : " << (*player).hp << endl;

		player->hp -= damage;
		if (player->hp <= 0)
			player->hp = 0;

		if (player->hp == 0)
			return false;

	}
}