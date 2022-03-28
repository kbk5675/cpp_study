#include <iostream>
using namespace std;

// 오늘의 주제 : 동적 할당 ★★★★★

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)과 정적(static) 변수 -> 데이터 영역
// - 지역변수 / 매개변수 -> 스택 영역
// - 동적할당 -> 힙 영역!

// 지금까지 데이터영역, 스택영역을 이용해서 공부했다면
// 굳이 다른 힙 영역이 왜 필요한가??
// EX)실제 상황 
// - MMORPG 동접 1명~5만명, 몬스터 1마리~500만마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴


// - 스택 영역
// 함수가 끝나면 같이 정리되는 휘발성 메모리
// 잠시 함수에 매개변수 넘긴다는 용도 OK!

// - 메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는 영역!

// 희망사항)
// - 필요할때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과 다르게) 우리가 생성/소멸 시점을 관리할 수 있는!
// - 그런 아름다운 메모리 영역 없나? -> HEAP영역!
// - 동적할당과 연관된 함수/연산자 : malloc / free, new / delete, new[] / delete[]

// malloc
// - 할당한 메모리 크기를 건네준다.
// - 메모리 할당후 시작 주소를 가르키는 포인터를 반환해준다.(아주 예외적으로 메모리 부족시 NULL)

// free
// - malloc (혹은 기타 calloc, realloc 등의 사촌) 을 통해 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new / delete
// - C++에 추가됨
// - malloc/free 는 함수! new/delete는 연산자(operator)

// new[] / delete[]
// - new가 malloc에 비해 좋긴한데~ 배열과 함께 N개의 데이터를 가이 할당하려면?

// malloc//free VS new/delete
// - 사용 편의성 -> new/delete 승!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면? -> malloc/free 승!

// 근본적으로 중요한 차이는? -> new/delete는 (생성타입이 클래스인 경우) 생성자/소멸자를 호출해준다!!!


class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}

	~Monster()
	{
		cout << "~Monster()" << endl;
	}

public:
	int _hp;
	int _x;
	int _y;
};

Monster monster[500 * 10000];


int main()
{
	// 유저 영역() ex) [메모장] [LOL] [곰플레이어]
	// ----------------------
	// 커널 영역 (windows 등의 핵심코드) 

	// 동적할당의 흐름
	// 1. 유저 영역) 운영체제에서 제공하는 API 호출
	// 2. 커널 영역) 메모리 할당해서 건내줌
	// 3. 유저 영역) ㄳㄳ 잘쓸게요~

	// [                      받은 메모리                            ]
	
	// C++에서는 ㄱ본적으로 CRT(C런타임 라이브러리)의 [ 힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)
	

// size_t 헤더파일
//#ifdef _WIN64
//	typedef unsigned __int64 size_t;
//
//#else
//	typedef unsigned int     size_t; // size_t라는 이름으로도 사용가능하게 하라.
//
//#endif

	// 그런데 잠깐! void* ?? 무엇일까?
	//  *가 있으니 주소를 담는 바구니 
	// 타고 가면 void 아무것도 없다? --> NO!
	// 타고 가면 void 뭐가 있을지 모르니까 너가 적당히 변환해서 사용해라~ --> OK!
	void* pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow
	// - 유효안 힙 범위를 초과해서 사용하는 문제

	// 만약 free를 안해주면? -> 메모리 누수현상..메모리 여유분이 없어서 프로그램이 뻗는다!
	// 프로그램이 바로 crash 나지는 않는다!
	free(pointer);

	// Double Free -> 대부분 crash 난다.

	// Use-After-Free -> free한 메모리를 다시 사용..! 매우 심각한 문제 crash가 나는지도 모른다..!
	/*
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;
	*/

	Monster* m2 = new Monster;
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;

	delete m2;

	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;
	delete[] m3;


	return 0;
}