#include <iostream>
using namespace std;

// 상수인건 알겠는데, 너무 따로노는 느낌?
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;


// 그 느낌을 한번에 잡아주는 역할 하나의 세트로 잡아준다.
// 그 다음 값들은 이전 값 +1
enum ENUM_SRP {
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};

// #이 붙은거 -> 전처리 지시문
// 1)전처리-준비운동 2)컴파일-본운동 3)링크

//define은 정수를 지칭하는 것이 아닌 그냥 수식을 지칭. 1+2 면 3이 아닌 1+2 그대로 선언되는 것.
#define DEFINE_SCISSORTS 1;


int main()
{
	srand(time(0)); // 시드 설정

	int wins = 0;
	int total = 0;

	/*while (true) {
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		cout << "> ";

		if (total == 0) {
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			int  winPercentage = (wins * 100) / total;
			cout << "현재 승률 : " << winPercentage << endl;
		}
	}*/

	cout << SCISSORS-1 << endl;
}