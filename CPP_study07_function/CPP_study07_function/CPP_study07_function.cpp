#include <iostream>
using namespace std;

// 오늘의 내용 : 함수(function)

/*
	input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다.

	반환타입 함수이름([인자타입 매개변수])
	{
		함수 내용

		return ~~~;
	}
*/

void PrintHelloWorld() {
	cout << "Hello World!" << endl;
	return; // return 선언시 함수 빠져나감. 이후 코드는 작동 안함
	cout << "after return" << endl;
}


// input : int / output : 없음
void PrintNumber(int number) {
	cout << "넘겨주신 숫자는 " << number << "입니다." << endl;
}

//input : int / output : int
int MultiplyBy2(int a) {

	int result = a * 2;
	return result;
}

// input : int, int / output : int
int MultiplyBy(int a, int b) {
	return a * b;
}

int main()
{
	PrintHelloWorld();
	PrintNumber(2);
	MultiplyBy2(3);
	PrintNumber(MultiplyBy2(3));
	int result = MultiplyBy(3, 3);
	PrintNumber(result);
	
	return 0;
}