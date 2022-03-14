#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

int qstate;
string id;
string pw;
string name;
string age;
string email;
string phone;



int main()
{
	
	conn = mysql_init(0);
	mysql_set_character_set(conn, "euckr");

	conn = mysql_real_connect(conn, "localhost", "root", "0000", "userinfo_db", 3306, NULL, 0);

	

	cin >> id;
	cin >> pw;
	cin >> name;
	cin >> age;
	cin >> email;
	cin >> phone;


	if (conn) {
		puts("Successful connection to database!");


		string query = "insert into info  values('" + id + "', '" + pw + "','" + name + "', '" + age + "', '" + email + "', '" + phone + "')";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		string query2 = "select * from info";
		const char* q2 = query2.c_str();
		qstate = mysql_query(conn, q2);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				printf("\nID: %s \tPW : %s Name : %s \tAge : %s \tEmail : %s", row[0], row[1], row[2], row[3], row[4]);
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("Connection to database has failed!");
	}
	return 0;
}

