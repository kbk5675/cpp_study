#include <iostream>
using namespace std;
// 오늘의 주제 : 함수 포인터

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

class Item
{
public:
    Item() : _itemId(0), _rarity(0), _ownerId(0)
    {

    }

public:
    int _itemId; // 아이템 구별 ID
    int _rarity; // 희귀도
    int _ownerId; // 소지자 ID
};

typedef bool(ITEM_SELECTOR)(Item* item, int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        if (selector(item, value))
            return item;
    }
    return nullptr;
}

bool IsRareItem(Item* item, int value)
{
    return item->_rarity >= value;
}


bool IsOwnerItem(Item* item, int ownerId)
{
    return item->_ownerId == ownerId;
}

int main()
{
    int a = 10;

    typedef int DATA;

    DATA* ptr = &a;
    
    //함수
    typedef int(FUNC_TYPE) (int , int );
    FUNC_TYPE* fn;
    // 함수 포인터
    fn = Sub; // or Add 

    // 함수의 이름은 함수의 시작 주소 (배열과 유사)
    int result = fn(1, 2); //기본 문법
    cout << result << endl;

    int result2 = (*fn)(1, 2); // *(접근 연산자) 붙어도 함수 주소!
    cout << result2 << endl;

    Item items[10] = {};
    items[3]._rarity = 2; //RARE

    Item* rereItem = FindItem(items, 10, IsRareItem, 2);

    return 0;
}

