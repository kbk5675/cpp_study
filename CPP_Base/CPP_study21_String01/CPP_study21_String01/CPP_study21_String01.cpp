#include <iostream>
#pragma warning(disable: 4996)
using namespace std;


// 문제1) str이라는 문자열의 길이를 반환
int StrLen(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

// 문제2) 문자열 복사 함수
// [H][e][l][l][o]['\0'][][][][[][][][][][][][][][] src
// [H][e][l][l][o]['\0'][][][][[][][][][][][][][][] dest
char* StrCpy(char* dest, char* src)
{
	/*NO Pointer*/
	 
	//int i = 0;

	//while (dest[i] != '\0') // dest[i]로 두어도 된다. 데이터가 없는 자리는 0이니까.
	//{
	//	dest[i] = src[i];
	//	i++;
	//}
	//cout << dest << endl;

	/*Use Pointer*/

	char* ret = dest;

	while (*src != '\0')
	{
		//*dest = *src; // 주소데이터 복사
		//dest++; // 주소증가
		//src++;  // 주소증가
		*dest++ = *src++;
	}
	*dest = '\0';

	return ret;
}

// 문제3) 문자열 덧붙히는 함수
char* StrCat(char* dest, char* src)
{
	/*No Pointer*/

	//내가 푼 방법.

	/*int d_len = StrLen(dest);
	int s_len = StrLen(src);
	int s = 0;
	for (int i = d_len; i < d_len+s_len; i++)
	{
		dest[i] = src[s];
		s++;
	}*/
	

	//선생님이 푼 방법

	/*int len = StrLen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';

	return dest;
	*/

	/*Use Pointer*/

	char* ret = dest;

	// 여기서 dest = 5까지 나온겨.
	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';

	return ret;
}

// 문제4) 두 문자열을 비교하는 함수.
int StrCmp(char* a, char* b)
{
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}

	return 0;
}

// 문제5) 문자열을 뒤집는 함수.
void ReversStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len/2; i++)
	{
		int temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	cout << str << endl;
}

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	if (a == b)
	{
		cout << "같다." << endl;
	}
	else
		cout << "다르다." << endl;
	// 다르다가 나오는 이유. 배열의 데이터는 같으나 배열의 주소는 다르다. 데이터가 같은지 보기위해선? 142번째줄

	int len = sizeof(a);
	cout << len << endl;


	len = StrLen(a);
	cout << len << endl;
	 
	cout << StrCpy(b, a) << endl;
	cout << StrCat(a, b) << endl;

	char a2[BUF_SIZE] = "a";
	char b2[BUF_SIZE] = "a";

	int value = strcmp(a2, b2);
	cout << value << endl;

	StrCmp(a2, b2);
	ReversStr(a);

	return 0;
}