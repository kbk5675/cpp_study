#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGO(int y, int x)
{
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != NULL)
		return false;
	return true;
}

void SetBoard()
{
	int dir = RIGHT;
	int x = 0;
	int y = 0;
	int num = 1;
	
	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;

		// 아래 스위치 대신 더 간단하게 배열 사용
		int nextX = x + dx[dir];
		int nextY = y + dy[dir];

		/*switch (dir)
		{
		case RIGHT:
			nextX = x + 1;
			nextY = y;
			break;
		case DOWN:
			nextX = x;
			nextY = y + 1;
			break;
		case LEFT:
			nextX = x - 1;
			nextY = y;
			break;
		case UP:
			nextX = x;
			nextY = y - 1;
			break;
		}*/

		if (CanGO(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			dir = (dir + 1) % 4;

			/*switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}*/
		}
	}
}

void PrintBoard(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}
int main()
{
	cout << "소용돌이 다차원 배열 만들기" << endl;
	cout << "원하는 정수를 입력하세요 >> ";
	cin >> N;
	SetBoard();
	PrintBoard(N);
	return 0;
}