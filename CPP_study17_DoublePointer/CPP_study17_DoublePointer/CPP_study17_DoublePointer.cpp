#include <iostream>
using namespace std;

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "Wow";
}


int main()
{
	int a = 0;
	SetNumber(&a);
	//cout << a << endl;

	// .rdata Hello주소[H][e][l][l][o][\0]
	// .rdata Bye주소[B][y][e][\0] 
	// msg[주소] = 8byte
	const char* msg = "Hello"; // 배열이 아니라 포인터이기 때문에 바구니에 불과. 별이 붙어있는 바구니 = 주소를 담는 바구니

	
	SetMessage(msg);
	//   주소2[  ] << 1바이트  = // .rdata Hello주소[H][e][l][l][o][\0]
	//  주소1[ 주소2(Hello주소) ]  << 8바이트
	// pp[ 주소1(&msg) ]  << 8바이트
	const char** pp = &msg;
	
	*pp = "Bye";
	cout << msg << endl;

	// 다중 포인터 : 혼란스럽다?
	// 그냥 양파까기라 생각하라.
	SetMessage2(msg);
	cout << msg << endl;


	return 0;
}