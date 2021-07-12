#include <iostream>
using namespace std;

class BaseArray {
	int* mem;  // 정수 배열을 만들기 위한 메모리의 포인터
	int capacity;  // 배열의 크기
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() {
		delete[] mem;
	}
	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) {
		return mem[index];
	}
	int getCapacity() {
		return capacity;
	}
};

class Stack  : public BaseArray{
	int size;  // 스택의 최대 크기
	int tos; // 스택의 탑을 가리키는 인덱스
public:
	Stack();
	Stack(int size);
	//Stack(const Stack& s);  // 복사생성자
	~Stack();
	bool push(int n); // 정수 n을 스택에 푸시(저장)한다.
				 // 스택이 full일 때 false를, 아니면 true 반환
	bool pop(int& n);  // 스택의 탑에 있는 값을 n에 팝한다. (꺼낸다).
				// 만일 스택이 비어 있으면 false를, 아니면 true 반환
	int capacity();
	int length();

	/*
	bool operator!();
	bool operator>>(int& n); // (참조 필요!)
	Stack& operator<<(int n); // (입력으로만 사용되기때문에 참조를 꼭 쓸필요는 없다.)
	*/
	friend bool operator!(Stack s);
	friend bool operator>>(Stack& s, int& n);
	friend Stack& operator<<(Stack& s, int n);


};


Stack::Stack() : BaseArray()
{
	size = getCapacity();
	tos = -1;
}

Stack::Stack(int size) : BaseArray(size)
{
	this->size = size;
	tos = -1;
}

/*
Stack::Stack(const Stack& s)
{
	size = s.size;
	p = new int[size];
	tos = s.tos;

	for (int i = 0; i <= tos; i++) {
		p[i] = s.p[i];
	}
}
*/

Stack::~Stack()
{

}

bool Stack::push(int n)
{
	if (tos < size - 1) {
		put(++tos, n);
		return true;
	}
	else {
		return false;
	}
}

bool Stack::pop(int& n)
{
	if (tos < 0) {
		return false;
	}
	n = get(tos--);
	return true;
}

/*
bool Stack::operator!()
{
	return tos == -1 ? true : false;
}

bool Stack::operator>>(int& n)
{
	return pop(n);
}

Stack& Stack::operator<<(int n)
{
	push(n);

	return *this;
}
*/

bool operator!(Stack s)
{
	return s.tos == -1 ? true : false;
}

bool operator>>(Stack& s, int& n)
{
	return s.pop(n);
}

Stack& operator<<(Stack& s, int n)
{
	s.push(n);
	return s;
}

int Stack::capacity()
{
	return size;
}

int Stack::length()
{
	return tos + 1;
}


int main() {

	Stack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택용량:" << mStack.capacity() << ", 스택크기 : " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다 >> ";
	while (mStack.length() != 0) {
		mStack.pop(n);
		cout << n << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;

	return 0;
}