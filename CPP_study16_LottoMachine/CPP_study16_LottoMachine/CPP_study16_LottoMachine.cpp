#include <iostream>
using namespace std;

// 로또 번호 생성기           

void Swap(int& a, int& b) {
	int temp = a;
	 a = b;
	 b = temp;
}

void Sort(int numbers[], int count) 
{
	int temp;
	for (int i = 0; i < count; i++)
	{
		for (int i = 0; i < count - 1; i++)
		{
			if (numbers[i] > numbers[i + 1]) {
				/*temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;*/
				Swap(numbers[i], numbers[i + 1]);
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << numbers[i] << " ";
 	}
}

void ChooseLotto(int numbers[])
{
	// 랜덤으로 1~45 사이의 숫자 6개를 골라주세요!
	srand((unsigned)time(0));

	rand();
	int count = 0;
	while (count != 6)
	{
		int randValue = (rand() % 45) + 1; // 0~44
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
			
		}
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);

	// 2) 정렬 함수 만들기(작은 숫자가 먼저 오도록 만들기)
	int numbers[6] = { };
	int count = sizeof(numbers) / sizeof(int); // 배열의 길이 :  sizeof(numbers) / sizeof(int)

	// 3) 로또 번호 생성
	ChooseLotto(numbers);

	return 0;
}