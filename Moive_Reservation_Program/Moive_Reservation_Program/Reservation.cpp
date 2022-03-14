#include "Reservation.h"
#include <iostream>
using namespace std;

int Reservation::_board[10][10];
bool Reservation::_reserved_seat = 0;

void Reservation::Reservate(int seat)
{
	cout << "Reservation(bool) 호출됨." << endl;
	_reserved_seat = 1;
	_seat = seat - 1;

	_board[_seat / 10][_seat % 10] = _reserved_seat;

	cout << "     ***** 예매되었습니다. *****     " << endl;
	_reserved_seat = 0;
	ShowSeats();
}

void Reservation::SetBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			_board[i][j] = _reserved_seat;
	}

	cout << endl;
}

void Reservation::ShowSeats()
{
	cout << "===============================================" << endl;
	cout << "||                 --Screen--                ||" << endl;
	cout << "||                                           ||" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "||   ";
		for (int j = 0; j < 10; j++)
			cout << _board[i][j] << "   ";

		cout << "||" << endl;
	}
	cout << "===============================================\n" << endl;
}


