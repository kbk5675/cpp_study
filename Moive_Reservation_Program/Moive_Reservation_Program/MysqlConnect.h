#pragma once
#include <mysql.h>



class MysqlConnect
{
public:
	MysqlConnect();
	void ShowUserInfo();

public:
	int qstate; // 쿼리요청 후 결과(성공, 실패)
	MYSQL* conn; // MySQL 정보를 담을 구조체
	MYSQL_ROW row; // 쿼리성공시 결과로 나온 행의 정보를 담는 구조체
	MYSQL_RES* res; // 쿼리성공시 결과를 담는 구조체포인터
};

