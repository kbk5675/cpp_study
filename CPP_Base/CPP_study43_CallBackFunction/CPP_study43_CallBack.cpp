#include <iostream>
using namespace std;

// 오늘으 주제 : 콜백 (CallBack)

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];

		if (selector(item))
			return item;
	}
	return nullptr;
}

class FindByOwnerId
{
public:
	bool operator()(const Item* item)
	{
		return (item->_ownerId == _ownerId);
	}

public:
	int _ownerId;
};

class FindByRarity
{
public:
	bool operator()(const Item* item)
	{
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity;
};

int main()
{
	// 함수 포인터 + 함수 객체 + 템플릿
	// 콜백 함수란 무엇인가? - 다시 호출하다? --> 나중에 뭔가를 실행시켜줘 라는 느낌

	// 게임을 만들 때 이런 콜백의 개념이 자주 등장한다!
	// ex) MoveTask 실습 등

	// 어떤 상황이 일어나면 -> 이 기능을 호출해줘
	// ex) UI 스킬 버턴을 누르면 -> 스킬을 쓰는 함수를 호출
	
	Item items[10];
	items[3]._ownerId = 100;
	items[8]._rarity = 2;

	// Id일치하는지 
	FindByOwnerId functor1;
	functor1._ownerId = 100;

	// 아이템 rarity 판별
	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1);
	Item* item2 = FindItem(items, 10, functor2);



	return 0;
}