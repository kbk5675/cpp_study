#include <iostream>
using namespace std;

int start = 0;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume() { size--; };
	int getSize() { return size; }
};

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
};



void CoffeeVendingMachine::run() {
	int num;
	if (start == 0)
		cout << "******************** 커피자판기를 작동합니다. ********************" << endl;
	start++;
	while (true)
	{
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >> ";
		cin >> num;
		switch (num)
		{
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		}
	}
}

void CoffeeVendingMachine::selectEspresso() {
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
	tong[0].consume();
	tong[1].consume();
	cout << "에스프레소 드세요" << endl;
}

void CoffeeVendingMachine::selectAmericano() {
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
	tong[0].consume();
	tong[1].consume(); tong[1].consume();
	cout << "아메리카노 드세요\n";
}

void CoffeeVendingMachine::selectSugarCoffee() {
	for (int i = 0; i < 3; i++) {
		if (tong[i].getSize() == 0) {
			cout << "원료가 부족합니다.\n";
			run();
		}
	}
	tong[0].consume();
	tong[1].consume(); tong[1].consume();
	tong[2].consume();
	cout << "설탕커피 드세요\n";
}

void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize();
	cout << ", 물  " << tong[1].getSize();
	cout << ", 설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill();
	}
	show();
	cout << "원료를 다 채웠습니다!" << endl;
}

int main()
{
	CoffeeVendingMachine* coffee = new CoffeeVendingMachine;
	coffee->run();
	delete coffee;
}