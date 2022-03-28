#include <iostream>
using namespace std;
#include "SignUp.h"


void SignUp::SetInput(string name, int age, 
	string email, string phone, string id, string pw)
{
	_age = age;
	_id = id;
	_pw = pw;
	_name = name;
	_email = email;
	_phone = phone;
}

void SignUp::ShowInput()
{
	cout << "\n-- 입력하신 정보 --" << endl;
	cout << "ID : " << _id << "\nPW : " << _pw 
		<< "\n이름 : " << _name << "\n나이 : " 
		<< _age << "\n이메일주소 : " << _email
		<< "\n전화번호 : " << _phone << endl;

	cout << "\n\n회원가입이 완료되었습니다.\n\n" << endl;
}
