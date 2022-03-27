#include <iostream>
#include <vector>
using namespace std;

// Vector 함수 모방해보기.

template<typename T>
class Iterator
{
public:
    Iterator() : _ptr(nullptr){ }

    Iterator(T* ptr) : _ptr(ptr) {  }

    // ++a
    Iterator& operator++()
    {
        _ptr++;
        return *this;
    }
    // a++
    Iterator& operator++(int)
    {
        Iterator tmp = *this;
        _ptr++;
        return tmp;
    }
    // --a
    Iterator& operator--()
    {
        _ptr--;
        return *this;
    }

    // a--
    Iterator& operator--(int)
    {
        Iterator tmp = *this;
        _ptr--;
        return tmp;
    }

    Iterator operator+(const int count)
    {
        Iterator temp = *this;
        temp._ptr += count;
        return temp;
    }
    Iterator operator-(const int count)
    {
        Iterator temp = *this;
        temp._ptr -= count;
        return temp;
    }

    bool operator==(const Iterator& right)
    {
        return _ptr == right.ptr;
    }

    bool operator!=(const Iterator& right)
    {
        return _ptr != right._ptr; // or return !(*this == right);
    }

    T& operator*()
    {
        return *_ptr;
    }

public:
    T* _ptr;
};

template<typename T>
class Vector
{
public:
    Vector() : _data(nullptr), _size(0), _capacity(0)
    {

    }

    ~Vector()
    {
        if (_data)
            delete[] _data;
    }

    void push_back(const T& val)
    {
        if (_size == _capacity)
        {
            // 증설 작업
            int newCapacity = static_cast<int>(_capacity * 1.5);

            // _capacity가 0 일때는 +1을 해준다.
            if (newCapacity == _capacity)
                newCapacity++;
            
            reserve(newCapacity);
        }

        // 데이터 저장
        _data[_size] = val;

        // 데이터 개수 증가
        _size++;
    }

    // 원래 있던 Vector 메모리 영역보다 더 큰 메모리 영역으로 이사시켜주고 기존 데이터 날린다.
    // [        ] = 예전 데이터 영역
    //      ㅣ
    //      ㅣ
    //      ▼
    // [              ] = 바꾸려는 데이터 영역
    void reserve(int capacity)
    {
        _capacity = capacity;
        
        T* newData = new T[_capacity];

        // 데이터 복사
        for (int i = 0; i < _size; i++)
            newData[i] = _data[i];
        
        // 기존 데이터 삭제
        if (_data)
            delete[] _data;

        _data = newData;
    }

    // v[i] 데이터 읽고쓰기
    T& operator[](const int pos) { return _data[pos]; }

    int size() { return _size; }
    int capacity() { return _capacity; }

public:
    typedef Iterator<T> iterator;

    void clear() { _size = 0; }
    iterator begin() { return iterator(&_data[0]); }
    iterator end() { return begin() + _size; }

private:
    T* _data;
    int _size;
    int _capacity;
};

int main()
{
    Vector<int> v;

    v.reserve(100);
    
    // vector에 데이터 넣기
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        cout << v.size() << " " << v.capacity() << endl;
    }

    // 배열같이 이용하여 vector 데이터 출력하기
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    cout << "=====================\nIterator" << endl;


    // 1.iterator 라는 class 생성
    // 2. class안에 begin(), end() 함수 생성
    // 3. 데이터 비교, 다음 위치로 이동 구현
    // 4. 역참조 통해 데이터 접근해서 수정이나 읽기 가능하게 구현..
    for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it) << endl;
    }
        
    v.clear();


    return 0;
}
