#include <iostream>
using namespace std;

// 다음과 같이 정수를 저장하는 스택 클래스 Stack을 구현하라.
// 스택에 저장할 수 있는 정수의 최대 기수는 생성자에서 주어지고
// size 멤버에 유지된다.
// Stack 클래스를 작성하라.

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


int main() {

	// frist in, last out.

	Stack a(10);
	a.push(10);
	a.push(20);
	Stack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;

	if (!a.pop(n))
		cout << "스택 a에 저장된 값이 없습니다." << endl;
	else
		cout << "스택 a에서 팝한 값 " << n << endl;

	if (!b.pop(n))
		cout << "스택 b에 저장된 값이 없습니다." << endl;
	else
		cout << "스택 b에서 팝한 값 " << n << endl;

	for (int i = 0; i < 11; i++) {
		if (!a.push(i))
			cout << "스택 a가 full입니다." << endl;
		else
			cout << "스택 a에 " << i << " push했습니다." << endl;
	}

	for (int i = 0; i < 11; i++) {
		if (!a.pop(n))
			cout << "스택 a가 empty입니다." << endl;
		else
			cout << "스택 a에서 " << n << " pop했습니다." << endl;
	}

	return 0;
}