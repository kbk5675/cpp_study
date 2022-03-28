#include <mysql.h>
#include <iostream>

using namespace std;
#include "MysqlConnect.h"
#include "SignUp.h"
#include "Login.h"
#include "Reservation.h"

/*
	넣어야할 기능
	1. 로그인 및 회원가입 기능 DB연결
	2. 현재 상영중인 영화 목록 및 상영 시간
	3. 영화 예매/취소 DB 연동
	4. 어떤 영화 예매했는지 DB연동
*/

class MysqlConnect db;
class SignUp;
class Login;
class Reservation rserv;


void Login();
void SignUpfunction();
void Screening();
void ReservationFunction();

int qstate;

int main()
{
	rserv.SetBoard();

	char n = '1';
	while (n != '0')
	{

		cout << "\nl--------------------l" << endl;
		cout << "l 영화 예매 프로그램 l" << endl;
		cout << "l--------------------l\n" << endl;
		cout << "1. 로그인\n2. 회원가입\n3. 상영중인 영화\n4. 영화예매\n0. 나가기" << endl;
		cin >> n;

		switch (n)
		{
		case '1':
			Login();
			break;
		case '2':
			SignUpfunction();
			break;
		case '3':
			Screening();
			break;
		case '4':
			ReservationFunction();
			break;
		case '0':
			break;
		}
	}
	return 0;
}

void Login()
{
	cout << "로그인 기능";
}

void SignUpfunction()
{
	string name, phone, email, id, pw;
	int age;

	cout << "이름 : ";
	cin >> name;
	cout << "나이 : ";
	cin >> age;
	cout << "이메일주소 : ";
	cin >> email;
	cout << "전화번호 : ";
	cin >> phone;
	cout << "ID : ";
	cin >> id;
	cout << "PW : ";
	cin >> pw;

	SignUp signup;
	signup.SetInput(name, age, email, phone, id, pw);
	signup.ShowInput();
	
	Login();
}

void Screening()
{
	cout << "상영중인 영화";
}

void ReservationFunction()
{
	Reservation rserv;

	int seat = 0;
	int n;
	cout << "1. 영화예매\n2. 좌석현황\n >> " << endl;
	cin >> n;

	switch (n)
	{
	case 1:
		cout << "영화 예매" << endl;
		cout << "예약하실 좌석을 선택해주십시오(ex.18 이면 10-8번 자리)\n>> ";
		cin >> seat;

		rserv.Reservate(seat);
		break;

	case 2:
		cout << "좌석 현황" << endl;
		rserv.ShowSeats();
		break;

	default:
		cout << "'1'과 '2' 중에서 선택해주십시오." << endl;
		break;
	}
}

