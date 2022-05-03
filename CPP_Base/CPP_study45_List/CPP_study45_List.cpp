#include <iostream>
#include <list>
using namespace std;

// 오늘의 주제 : list


// vector : 동적 배열
// [    ] 최대메모리
// [         ] 증설
// [               ] 이사


//----------------------------------- list의 동작 원리-----------------------------------//

// [ data(4) next( data(4) next( data(4)  next( data(4) next(....)  )  ) ) ]
// Node2는 잘못된 설계.
class Node2
{
public:
	//Node2 _next;
	int _data;
}; 

// 단일 list의 동작원리이다.
// Node [  data(4) next(4~8)  ] -> Node [ data(4) next(4~8) ]
// 주소를 가르키기 때문에 다른 노드로 이동
class Node
{
public:
	Node* _next;
	int _data;
};

class Node3
{
public:
	Node* _next;
	Node* _prev;
	int _data;
};

// 단일 / 이중 / 원형
// list : 연결리스트


// [1]   -> [2]   ->     [3] ->  [4] -> [5]      => 단일 연결리스트의 개념
//  [1]   <-> [2]   <->     [3] <->  [4] <-> [5] => 이중 연결리스트의 개념

//----------------------------------- list의 동작 원리-----------------------------------//


int main()
{
	// list (연결리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;
	list<int> li2 { 1,2,3,4,5,6 };

	for (int i = 0; i < 100; i++)
	{
		li.push_back(i);
	}

	//li.push_front(10);
	int size = li.size();
	//li.capacity(); // 동적배열이 아니라 없다.

	int first = li.front();
	int last = li.back();

	//li[3] = 10; // list는 임의접근을 허용하지 않는다.

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin()); // 중간값까지 삭제가능
	
	li.pop_front(); // 처음값만 삭제가능

	li.remove(10); // 해당 value와 동일한 것을 삭제가능

	return 0;
}