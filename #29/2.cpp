#include <iostream>
using namespace std;

// 스택 클래스 Stack을 만들고 푸시(push)용으로 << 연산자를,
// 팝(pop)을 위해 >> 연산자를, 
// 비어 있는 스택인지를 알기 위해 ! 연산자를 작성하라.
// 다음 코드를 main()으로 작성하라.

class Stack {
	int* p;  // 스택 메모리로 사용할 포인터
	int size;  // 스택의 최대 크기
	int tos; // 스택의 탑을 가리키는 인덱스
public:
	Stack();
	Stack(int size);
	Stack(const Stack& s);  // 복사생성자
	~Stack();
	bool push(int n); // 정수 n을 스택에 푸시(저장)한다.
				 // 스택이 full일 때 false를, 아니면 true 반환
	bool pop(int& n);  // 스택의 탑에 있는 값을 n에 팝한다. (꺼낸다).
				// 만일 스택이 비어 있으면 false를, 아니면 true 반환
	/*
	bool operator!();
	bool operator>>(int& n); // (참조 필요!)
	Stack& operator<<(int n); // (입력으로만 사용되기때문에 참조를 꼭 쓸필요는 없다.)
	*/
	friend bool operator!(Stack s);
	friend bool operator>>(Stack& s, int& n);
	friend Stack& operator<<(Stack& s, int n);
};

Stack::Stack()
{
	size = 10;
	p = new int[size];
	tos = -1;
}
Stack::Stack(const Stack& s)
{
	size = s.size;
	p = new int[size];
	tos = s.tos;

	for (int i = 0; i <= tos; i++) {
		p[i] = s.p[i];
	}
}

Stack::~Stack()
{
	delete[] p;
}


Stack::Stack(int size)
{
	this->size = size;
	p = new int[size];
	tos = -1;

}

bool Stack::push(int n)
{
	if (tos < size - 1) {
		p[++tos] = n;
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
	n = p[tos--];
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

// (연산자 왼쪽 -> 객체이면 friend함수, 멤버함수 모두 가능)
// (연산자 왼쪽 -> 객체 아니면 friend 함수만 가능)

int main() {
	
	Stack stack;
	stack << 3 << 5 << 10;  // 3, 5, 10을 순서대로 푸시
	while (true) {
		if (!stack) break;  // 스택 empty
		int x;
		stack >> x;  // 스택에 있는 정수 팝
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}