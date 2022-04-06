#include <iostream>
using namespace std;

// 매우 중요하니 잘 외우자.
// 타입 변환 (포인터)

class Knight
{
public:
	int _hp = 0;
};

class Item // 항상 최상위 부모 클래스 소멸자에는 virtual을 붙여줘라!!!
{
public:
	Item()
	{
		cout << "item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "item(int itemType)" << endl;
	}

	Item(const Item& item) // 복사 생성자
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbld = 0; // 데이터베이스 아이디

	char _dummy[4096] = {}; // 이런저런 정보들로 인해 비대해진
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}
	
public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
		_defence = rand() % 100;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// 복습
	//{
	//	// Stack [ type(4) dbid(4) dummy(4096) ]
	//	Item item;

	//	// Stack [ 주소(4~8) ] -> Heap [ type(4) dbid(4) dummy(4096) ]
	//	Item* item2 = new Item();

	//	TestItem(item);
	//	TestItem(*item2);

	//	TestItemPtr(&item);
	//	TestItemPtr(item2);

	//	// 메모리 누수(Memory Leak) -> 점점 가용 메모리가 줄어들어 crash..
	//	delete item2; // new 와 delete는 세트..

	//}

	//// 배열
	//{
	//	cout << "-------------------------------------" << endl;

	//	// 진짜 아이템이 100개 있는 것 (스택 메모리에 올라와 있는)
	//	Item item3[100] = {};

	//	cout << "-------------------------------------" << endl;


	//	// 아이템이 100개 있을까요?
	//	// -> 아이템을 가리키는 바구나가 100개. 실제 아이템은 1개도 없을 수도 있다!
	//	Item* item4[100] = {};

	//	for (int i = 0; i < 100; i++)
	//	{
	//		item4[i] = new Item();
	//	}

	//	for (int i = 0; i < 100; i++)
	//	{
	//		delete item4[i];
	//	}
	//}

	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [주소] -> Heap [ _hp(4) ]
		/*Knight* knight = new Knight();
		
		// 암시적으로는 NO
		// 명시적으로는 OK

		// Stac [ 주소 ] 
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbld = 1;

		delete knight;
		*/
	}

	// 부모 -> 자식 변환 테스트
	// -> 큰메모리를 작은 메모리에 넣으려고하니 메모리 오염이 난다. 부모->자식 변환은 좋지못하다.
	{
		/*Item* item = new Item();

		Weapon* weapon = (Weapon*)item;
		weapon->_damage = 10;

		delete item;*/
	}


	// 자식 -> 부모 변환 테스트
	{
		//Weapon* weapon = new Weapon();

		//Item* item = weapon;

		//// 암시적으로도 된다.
		//delete weapon;

	}

	// 결론
	// 명시적으로 타입 변환할 때는 항상 항상 조심해야 한다..!
	// 암시적으로 될 떄는 안전한가?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안하면되는거 아니냐?
	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0~1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;

		case 1:
			inventory[i] = new Armor();
			break;

		default:
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON) // 자식 -> 부모지만 웨펀이라는 가정하에 하면 안전.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}

		if (item->_itemType == IT_ARMOR) // 자식 -> 부모지만 웨펀이라는 가정하에 하면 안전.
		{
			Armor* armor= (Armor*)item;
			cout << "Armor defence : " << armor->_defence << endl;
		}
	}

	//********************** 조오오온시나 중요하다! ***********************//
	// 최상위 부모 클래스 소멸자에는 반드시 virtual을 붙여줘라..!!!!!!!!
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;
	}

	// [결론]
	// - 포인터 vs 일반 타입 : 차이를 이해하자..!
	// - 포인터 사이의 타입 변환(캐스팅)을 할 때는 매우 매우 조심할 것..!(굳이 써야한다면 213줄처럼)
	// - 부모-자식 관계에서 부모 클래스의 소멸자에는 꺼먹지 말고 virtual을 붙이자!!!


	return 0;
}