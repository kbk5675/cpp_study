#include <iostream>
using namespace std;

// 클래스 템플릿

// typename T를 붙이면 '조커카드' (어떤 타입도 다 넣을 수 있음)
// 그런데 무조건 tpyename을 붙여야 하는 것은 아니다.
// template <  > 안에 들어가는건 [골라줘야하는 목록] 이라 볼 수 있다.

template<typename T, int SIZE> // SIZE : 데이터 크기
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	T _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>
class RandomBox<double , SIZE>
{
public:
	double GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	double _data[SIZE];
};


void Hello(int number)
{
	Hello(10);
	Hello(20);
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	// int 버전
	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	// float 버전
	RandomBox<float, 20> rb2;
	for (int i = 0; i < 20; i++)
	{
		rb2._data[i] = i + 0.5f;
	}
	float value2 = rb2.GetRandomData();
	cout << value2 << endl;

	// template 특수화 한것
	RandomBox<double, 15> rb3;
	for (int i = 0; i < 15; i++)
	{
		rb3._data[i] = i + 0.3f;
	}
	float value3 = rb3.GetRandomData();
	cout << value3 << endl;




	return 0;
}