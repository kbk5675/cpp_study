#include <iostream>
using namespace std;

// 다차원 배열

int main()
{
	int a[10] = { 1, 2, 3, 4, 5 };

	//아파트로 예를 들어보자.
	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층
	
	int first[5] = { 4, 2, 3, 4, 1 };
	int second[5] = { 1, 1, 5, 2, 2 };
	// ..무한정 설정해주기 어렵다.

	int apartment2D[2][5] = { {4, 2, 3, 4, 1 }, {1, 1, 5, 2, 2 } };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int num = apartment2D[i][j];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2차원 배열도 메모리에선 1차원배열처럼 나열되어있다.
	int apartment1D[10] = { 4, 2, 3, 4, 1, 1, 1, 5, 2, 2 };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int index = (i * 5) + j;
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2차 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵
	int map[5][5] =
	{
		{1, 0, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 1, 1, 0, 1},
	};

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			int info = map[x][y];
			cout << info;
		}
		cout << endl;
	}

	return 0;
}