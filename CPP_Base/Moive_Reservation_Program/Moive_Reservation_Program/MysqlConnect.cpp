#include "MysqlConnect.h"
#include <iostream>
using namespace std;


MysqlConnect::MysqlConnect()
{
	conn = mysql_init(NULL); //변수를 초기화 해준다.

	// DB와 연결해주는 함수.
	conn = mysql_real_connect(conn, "localhost", "root", "0000", "userinfo_db", 3306, NULL, 0);
	// 한글문자 안깨지게 해주는 함수
	mysql_set_character_set(conn, "euckr");

	if (conn) 
		puts("Successful connection to userinfo_db\n");
	else
		puts("info Connection to database has failed!");
	
	
}

void MysqlConnect::ShowUserInfo()
{
	if (conn) {
		string query = "SELECT * FROM info"; //세미콜론을 제외한 쿼리문 작성
		const char* q = query.c_str();
		qstate = mysql_query(conn, q); // 쿼리 요청 및 성공여부 받아오기

		if (!qstate)
		{
			res = mysql_store_result(conn); // 접속한 결과값을 res에 넣는다.

			// 결과 출력하기
			while (row = mysql_fetch_row(res))
			{
				cout << "ID: " << row[0];
				cout << "\tPW: " << row[1];
				cout << "\t이름: " << row[2];
				cout << "\t나이: " << row[3];
				cout << "\t이메일: " << row[4];
				cout << "\t전화번호: " << row[5] << endl;
			}

			mysql_free_result(res);
		}
		else
		{
			cout << "info Query failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("info Connection to database has failed!");
	}
}


