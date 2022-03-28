#pragma once


class Player
{
public:
	void KillMonster();

	void KillMonster2();
public:
	int _hp;
	int attack;

	class Monster* _target2; // 앞에 class 붙히면 전방선언.

	Player* _target;
};

