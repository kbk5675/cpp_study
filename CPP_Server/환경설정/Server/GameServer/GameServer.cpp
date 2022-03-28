#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include "thread"
#include <vector>
#include <mutex>

vector<int32> v;

// lock, unlock
//mutual Exclusive (상호배타적)
mutex m; 

// std::mutex
// void lock() : mutex를 잠근다. 다른 스레드가 소유중이라면 lock 풀릴때까지 블로킹
// void unlock() : 잠금풀기

//RAII(Resource Acquisition Is Initialization)
template<typename T>
// 자동잠금 클래스 만들어보기
class LockGuard
{
public:
	LockGuard(T& m)
	{
		_mutex = &m;
		_mutex->lock();
	}

	~LockGuard()
	{
		_mutex->unlock();
	}

private:
	T* _mutex;
};

void Push()
{
	for (int32 i = 0; i < 10000; i++)
	{
		//자물쇠잠그기
		//std::lock_guard<std::mutex> lock_guard(m);
		LockGuard<std::mutex> lockGuard(m);

		//  unique_lock 잠그는 시점을 미룰 수 있다.
		//std::unique_lock<std::mutex> unique_lock(m, std::defer_lock);

		v.push_back(i);

		// unlock에 도달하기 전에 for문이 끝나 영영 잠긴다.
		if (i == 5000)
			break;


		//자물쇠열기
		m.unlock();
	}
}



int main()
{
	std::thread t1(Push);
	std::thread t2(Push);

	t1.join();
	t2.join();

	cout << v.size() << endl;

	// 결과 : 크러쉬가 난다 
	// 이유 : 백터의 원리를 생각하면 원래있던 메모리가 초과되면 기존의
	// 메모리를 삭제하고 더 큰 메모리영역으로 이사가기때문에 t1이 먼저
	// 이사를 가고 기존 메모리를 삭제하려할때 t2는 사용중이기 때문에
	// 오류가 난다! 
}