#include <iostream>
using namespace std;



bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;
int hp = 100;
bool isInvincible = true;

bool stunned;
bool polymorph;

unsigned char flag; //음수 주의위해 unsigned.

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙힘 (변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함

const int AIR = 0; // 에어본
const int STUN = 1; // 스턴
const int POLYNOPH = 2; // 변이
const int INVINCIBLE = 3; // 무적
const int FEAR = 4; //공포

int main() {

	// 비교연산자
	// 언제 필요한가?
	// ex) 체력이 0이 된 상황
	// ex) 체력이 30% 이하면 궁극기를 발동 (100*hp / maxHp)
	// ex) 경험치가 100 이상이면 레벨업

	// a == b : a와 b의 값이 같은가?
	// 같으면 1, 다르면 0
	isSame == (a == b);

	// a != b : a와 b의 값이 다른가?
	isDifferent = (a != b);

	// a > b   a >= b
	isGreater = (a > b);

	// a < b a <= b
	isSmaller = (a < b);

	// 논리연산자
	// 언제필요한가? 
	// 조건에 대한 논리적 사고가 필요할 때
	// ex) 로그인할 때 아이디도 같고 AND 비밀번호도 같아야 한다.
	// ex) 길드 마스터거나 OR 운영자 계정이면 길드 해산

	// 0이면 1, 그 이외엔 0
	test = !isSame;

	//&& and
	// a && b -> 둘다 1이면 1, 그 외 0
	test = (hp <= 0 && isInvincible == false); // 죽음
	

	// || or
	// a || b -> 둘 중 하나라도 1이면 1
	test = (hp > 0 || isInvincible == false); // 살았음

	// 데이터 연산자

	//0b0000 [무적][변이][스턴][공중부양]

	// 무적상태로 만든다.
	flag = (1 << INVINCIBLE);

	// 변이 상태를 만든다. (무적 + 변이)
	flag |= (1 << POLYNOPH);

	// 무적인지 확인하고싶다 ( 다른 상태는 관심 없음)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// 무적이거나 스턴상태인지 확인하고 싶다.
	bool stunOrInvincible = ((flag & 0b1010) != 0);
	
}