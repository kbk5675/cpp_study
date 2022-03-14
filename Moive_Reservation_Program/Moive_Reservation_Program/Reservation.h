#pragma once
class Reservation
{
public:

	void Reservate(int seat);
	void SetBoard();
	void ShowSeats();

public:
	static int _board[10][10];
	int _seat = 0;
	static bool _reserved_seat;
};

