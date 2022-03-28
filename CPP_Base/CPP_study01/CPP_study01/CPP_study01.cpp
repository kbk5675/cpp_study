﻿#include <iostream>

using namespace std;

// 0이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;

// 초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역

char a; // 1바이트(-128 ~ 127)
short b; // 2바이트(-32768 ~ 32767)
int c; // 4바이트(-21.4억 ~ 21.4억) 가장 일반적인 4바이트
__int64 d; // 8바이트 (long long) (어마어마하게 큼)

unsigned char ua; // 1바이트 (0~255)
unsigned short ub; // 2바이트(0~65536)
unsigned int uc; // 4바이트 (0~42.9억)
unsigned __int64 ud; // 8바이트 (long long)(0~ 어마어마하게 큼)

// 참고) 무조건 unsigned를 사용할지 의견이 갈림 
// - 레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾는게 낫다. (의견1)
// - unsigned / signed 사이의 변환 

// 콘솔/모바일 게임은 항상 메모리가 부족하다. -> 다양한 타입을 써서 최적화를 해야한다.
// ex) 체력을 바뀔 때 int형으로 보내면 4byte 손해.

int main()
{
	//정수 오버플로우
	b = 32767;
	b += 1;
	cout << b << endl; // -32768
	//결과 이유 -> 2진수로 32767은 0111 1111 1111 1111 이지만, +1 하게되면 1000 0000 0000 0000 되므로 -32768이 되어버림.

	//정수 언더플로우
	ub = 0;
	ub -= 1;
	cout << ub << endl;
	//위와 같은 이유

	return 0;
}
