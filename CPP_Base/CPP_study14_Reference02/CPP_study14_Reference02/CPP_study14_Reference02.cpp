#include <iostream>
using namespace std;

struct StatInfo {
	int hp;
	int attack;
	int defence;
};

void setplayerStat(StatInfo* info) {
	info->hp = 100;
	info->attack = 8;
	info->defence = 2;
}

// const를 * 앞에 붙히는가 뒤에
// 붙히는가에 따라 의미가 달라진다. 

// 별 뒤에 붙힌다면?
//StatInfo* const info
//info라는 바구니의 내용물(주소)을 바꿀 수 없음
//ex) info = &globalInfo;와 같은 수정불가 

// 별 앞에 붙힌다면?
//const StatInfo* info / statInfo const* info
//info가 가르키고 있는 바구니의 내용물을 바꿀 수 없음 
//ex) info->hp = 100000;와 같은 수정불가 


// info[주소값]		주소값[데이터] 

void PrintByPointer(const StatInfo* info) {

	if (info == nullptr)
		return;


	cout << "포인터를 이용한 값 가져오기" << endl;
	cout << "--------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATK : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "--------------------" << endl;

}

void PrintByReference(StatInfo& info) {
	cout << "참조 연산자를 이용한 값 가져오기" << endl;
	cout << "--------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATK : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "--------------------" << endl;
}



int main()
{
	// 초기화 여부
	//참조 타입은 바구니의 2버째 이름(별칭?느낌)
	//-> 참조하는 대상이 없으면 안됨 

	StatInfo info;
	setplayerStat(&info);
	PrintByPointer(&info);
	PrintByReference(info);


	StatInfo* pointer = nullptr; // nullptr 아무것도 가르키고있지않다. 
	pointer = &info;
	// StatInfo* pointer = &info; 와 같다.
	// 변수에 값이 없어도 주소지정 가능하다. 

	StatInfo& reference;
	reference = info;
	// 중요)포인터와 다르게 값이나 대상  없으면 주소지정불가! 

	// 결론
	// 값이 없는 부분을 고려해야한다 => 포인터 사용
	// 바뀌지않고 읽는 용도(readonly) => const ref& 

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	PrintByReference(*pointer);

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	PrintByPointer(&reference);