#include <iostream>
using namespace std;

// 문자와 문자열
// 사실 char도 마찬가지. 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다.

char ch = 97;
char ch2 = 'a' + 1;

// 유니코드는 표기 방식이 여러가지가 있는데 대표적으로 UTF8 UTF16
// UTF8
// - 알파벳, 숫자 1바이트(ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트

// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매--우 예외적인 고대 문자만 4바이트(사실상 무시)

// 문자열
// 정수 (1 ~ 8바이트) 고정 길이로
// 끝은 NULL(0)



int main()
{
    cout << ch << endl;
    cout << ch2 << endl;


    char str1[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // 끝이 0으로 끝나지않으면 문자열로 인식 못한다.
    char str2[] = { 'h', 'e', 'l', 'l', 'o' };
    char str3[] = "HelloWorld";
    wchar_t str4[] = L"HelloWorld";

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
}

