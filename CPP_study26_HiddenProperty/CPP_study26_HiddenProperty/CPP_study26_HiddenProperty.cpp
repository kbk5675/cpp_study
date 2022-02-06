#include <iostream>
using namespace std;

// 오늘의 주제 : 은닉성

// 은닉성(Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다!
// 숨기는 이유?
// - 정말 위험하고 건드리면 안되는 경우
// - 다른 경로로 접근하길 원하는 경우

// 자동창
// -핸들
// -페달
// -엔진
// -문
// -각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// -핸들/페달/문
// 몰라도되는부분
// -엔진/각종 전기선

// public(공개적) protected(보호받는) private(개인의)
// - public : 누구나 쓰세요.
// - protected : 나의 자손들에게만 허락(상속클래스만 사용가능)
// - private : 나만 사용할꺼! << class Car 내부에서만 사용

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테 똑같이 물려줘야 하진 않음
// - public : 공개적 상속 -> 부모님의 유산 설계 그대로(public -> public, protected -> protected)
// - protected : 보호받는 상속 -> 내 자손들한테만 물려줄거야(public -> protected, protected -> protected)
// - private : 개인적인 상속 -> 나까지만 잘 쓰고 자손들한텐 안물려줄거야(public -> private, protected -> private)

class Car
{
public: // 멤버 접근 지정자
	void MoveHandle() {}
	void PushRedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		RunEngine();
	}

//private: // 상속 클래스도 사용불가.
protected:
	void DisassembleCar() {} // 차를 분해한다
	void RunEngine() {} // 엔진을 구동시킨다
	void ConnectCircuit() {} // 전기선 연결

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선
};

class SuperCar : private Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : SuperCar 
{
public:
	void Test()
	{
		DisassembleCar(); // 사용 못함 SuperCar가 Car를 private으로 상속 받았기 때문이다.
	}
};


// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:

	int GetHp() { return _hp; }

	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp < 50)
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode()
	{
		cout << "Berserker Mode On" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	Car car;
	car.OpenDoor();
	// car.RunEngine(); //엑세스 불가에러 -> private이기 때문.

	Berserker b;
	// b._hp = 20; // _hp를 public으로 설정하게 두어서 버서커모드 똑바로 작동 안함. 설계 오류! -> 캡슐화 필요
	b.SetHp(30);

	return 0;
}