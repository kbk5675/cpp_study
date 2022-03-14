#pragma once

class SignUp
{
public:
	void SetInput(string name, int age, string email, 
		string phone, string id, string pw);
	void ShowInput();
public:
	string _id;
	string _pw;
	string _name;
	int _age;
	string _email;
	string _phone;
};

