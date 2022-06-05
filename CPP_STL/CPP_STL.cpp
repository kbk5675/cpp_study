#include <iostream>
#include <deque>

int main()
{
	std::deque<int> dq;

	for (int i = 0; i < 5; i++)
		dq.push_back((i + 1) * 10);

	// 반복자 선언
	std::deque<int>::iterator iter;

	std::cout << "기본 deque 값 : ";
	for (iter = dq.begin(); iter != dq.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl << std::endl;

	// test1. 앞뒤 삽입하기
	std::cout << "[Test1] push_front & end" << std::endl;
	dq.push_front(1);
	dq.push_front(2);
	dq.push_back(100);
	dq.push_back(200);
	
	std::cout << "[Test1] deque 값 : ";
	for (iter = dq.begin(); iter != dq.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	//[test2] : 역으로 출력
	std::cout << "[Test2] reverse_iterator" << std::endl;

	std::deque<int>::reverse_iterator rlter;

	for (rlter = dq.rbegin(); rlter != dq.rend(); rlter++)
		std::cout << *rlter << " ";
	std::cout << std::endl << std::endl;

	std::cout << "[Test3] insert(conlter ++ 두번, 2, INSERT)" << std::endl;
	std::deque<int>::const_iterator conlter = dq.begin();
	conlter += 2; // 두번째 자리에.
	dq.insert(conlter, 1, 333); // conlter반복자 333 원소 1개 삽입
	for (conlter =dq.begin(); conlter != dq.end(); conlter++)
	{
		std::cout << *conlter << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << dq[0];

	return 0;
}