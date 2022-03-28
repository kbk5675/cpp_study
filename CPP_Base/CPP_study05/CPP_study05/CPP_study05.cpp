#include <iostream>
using namespace std;


// const는 읽기전용 데이터다?
// 아니다. 표준적으로 정해진 것이 없다. 메모리가 실질적으로 할당이 되어 있지 않다.
// 사실상  우리 눈에만 상수명으로 보이지 컴퓨터는 상수로 보고 있다.
// 메모리 어디에 있는지 신경 쓸 필요 없다.
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVICIBLE = 3;

// 전역 변수

// [데이터 영역]
// .data (초기값이 있는 경우)
int a = 2;

// .bss (초기값이 없는 경우)
int b;

// .rodata (읽기 전용 데이터)
const char* msg = "Hello World!";

int main()
{	// [스택영역]
	int c = 3;

}