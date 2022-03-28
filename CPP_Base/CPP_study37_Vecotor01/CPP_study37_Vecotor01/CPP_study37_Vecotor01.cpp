#include <iostream>
#include <vector>
using namespace std;

void 동작원리();
void 반복자();
void 데이터삽입및임의접근();

// 오늘의 주제 : vector
// 
// STL(Standard Template Library)
    // 프로그래밍할 때 필요한 자료구조/알고리즘을
    // 템플릿으로 제공하는 라이브러리

    // 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

    // vector (동적 배열)
    // - vector의 동작 원리 (size/capacity)
    // - 반복자(Iterator)
    // - 중간 삽입/삭제  **중요**
    // - 처음/끝 삽입/삭제  **중요**
    // - 임의 접근  **중요**


int main()
{
    동작원리();
    반복자();
    데이터삽입및임의접근();

    return 0;
}

void 동작원리()
{
    // 배열
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE] = {}; // 접속자의 수가 정해지지 않을때 선언할때 크기가 정해진 배열을 쓰는 것은 적합하지 않다!

    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = i;

    // 동적 배열
    // 아주 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용하는 것인가..?

    // 1) (여유분을 두고) 메모리를 할당한다
    // 2) 여유분까지 데이터가 꽉 차면, 메모리를 증설한다!

    // Q1) 여유분의 정확한 할당량?
    // Q2) 증설을 얼만큼 해야하나? -> 데이터가 초과될때마다 capacity값의 1.5배 2배씩 늘어남
    // Q3) 기존 데이터와 증설 데이터는 어떻게 연결되는가?

    // vector<int> v(/*size*/,/*특정값*/);
    // vector<int> v2 = v; 

    vector<int> v;

    // const int size = v.size();  // 사이즈를 따로 선언해주는것이 효율적'

    // size(실제 사용 데이터 개수)
    // capacity (여유분을 포함한 용량 개수)
    // v.reserve(1000); // 여유데이터분을 1000개로 잡아주세요.

    v.resize(1000); // 기본 데이터를 1000으로 잡아줌.
    cout << v.size() << " " << v.capacity() << endl;

    for (int i = 0; i < 1000; i++)
    {
        v[i] = 100; // 기존의 잡혀있는 영역을 접근해서 활용한다는 느낌
        //v.push_back(100); // 데이터를 추가한다는 느낌
        cout << v.size() << " " << v.capacity() << endl;
    }

    v.pop_back(); // 마지막부터 있던 데이터 꺼내기
    v.back(); // 마지막 데이터 꺼내기
    v.front(); // 처음 데이터 꺼내기


    v.clear(); // data는 0으로 초기화되고 capacity는 그대로 할당되어있다.
    cout << v.size() << " " << v.capacity() << endl;

    // capacity도 없애고싶어요!
    vector<int>().swap(v);
    cout << v.size() << " " << v.capacity() << endl;
}

void 반복자()
{
    // 반복자(Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
    vector<int> v(10);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }

    vector<int>::iterator it;
    int* ptr;

    it = v.begin();
    ptr = &v[0];

    cout << (*it) << endl;
    cout << (*ptr) << endl;

    // 다음 데이터로 이동
    it++;
    ++it;
    ptr++;
    ++ptr;

    // 크게 이동
    it += 2;
    it = it - 2;
    ptr += 2;
    ptr -= 2;


    // 더 복잡해보이는데 쓰는이유
    // 다른 컨테이너는 v[i]와 같은 익덱스 접근이 안 될 수도 있음
    // iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념이다.
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end(); // 유효한 마지막 데이터 바로 다음 쓰레기값 가리킨다. 끝을 가리킬 때 사용

    // 유효하지않을 포인터가 나올때까지 앞으로 이동하겠다. it++보다 ++it이 미세하게나마 성능이 좋다.
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it) << endl;
    }

    int* ptrBegin = &v[0]; // v.begin()._Ptr;
    int* ptrEnd = ptrBegin + 10; // v.End()._Ptr;

    for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
    {
        cout << (*ptr) << endl;
    }

    vector<int>::const_iterator cit1 = v.cbegin();
    // *cit1 = 100; // const라서 못바꿈

    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << (*it) << endl;
    }
}

void 데이터삽입및임의접근()
{
    vector<int> v(10);
    v.reserve(1000);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
        v[i] = i;

    int* ptrBegin = &v[0];


    // - 중간 삽입/삭제 (BAD)
    // - 처음/끝 삽입/삭제  (BAD / Good )
    // - 임의 접근  

    // 중간삽입은 비효율적이다. 배열중간에 데이터 삽입하면 원래있던 데이터가 나비효과로 한칸씩 뒤로 밀린다.

    // vector = 동적 배열 = 동적으로 커지는 배열 = 배열
    // 원소가 하나의 메모리 블록에 연속하게 저장된다 !!! (데이터를 찾기 쉽게하기위해)

    // [                   ]
    // [0][1][2][3][4][ ][ ]

    // v.push_back(1);
    // v.pop_back();

    // v.insert(v.begin() + 2, 5); // 3번 주소에 5 넣자



    vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
    vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
    vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); // v.begin()+4 위치 전까지 삭제.

    // 쭉~ 스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고싶다.
    for (vector<int>::iterator it = v.begin(); it < v.end();)
    {
        int data = *it;
        if (data == 3)
            it = v.erase(it);
        else
            ++it;
    }

}