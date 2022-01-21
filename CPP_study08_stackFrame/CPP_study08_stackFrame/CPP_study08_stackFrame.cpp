#include <iostream>
using namespace std;

// 오늘 주제 : 스택프레임, 지역 변수와 값 전달

//스택란 거대한 메모장. 함수들끼리 데이터를 주고 받을 수 있는 공용 메모장이라 생각하면 된다. 

// F5 - 디버깅모드 트랩걸어준 곳까지 실행
// F10 - 프로시져 단위 실행 함수안까지 실행 안시키고 뛰어넘고 main함수 내에서만 실행
// F11 - 한단계씩 실행

// 전역 변수 - 데이터 영역
// 참고) 초기화 여부, const 등 .rodata .data .bss
int globalValue = 0;

void Test() {
	cout << "전역 변수의 값은 : " << globalValue << endl;
}

void IncreaseHp(int hp) {
	hp += 1;
	cout << hp << endl;
}

int main()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;

	Test();

	//지역 변수 - 스택 영역
	int localValue = 1;
	
	int hp = 1;

	cout << "Increase 호출 전 : " << hp << endl; // 결과 : 1
	IncreaseHp(hp);
	cout << "Increase 호출 후 : " << hp << endl; // 결과 : 1 이유 :지역변수hp의 메모리 주소와 매개변수hp의 메모리주소는 영역자체가 다르다.(지역변수영역과 매개변수영역이 따로 있음)

	return 0;
}