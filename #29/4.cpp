#include <iostream>
using namespace std;

/*다음 AbstractStack은 정수 스택 클래스로서 추상클래스이다.
이를 상속받아 정수를 푸시, 팝할 수 있는 Stack 클래스를 만들고 사용 사례를 보여라.*/

class AbstractStack {
public:
	virtual bool push(int n) = 0;	// 스택에 n을 푸시한다. 스택이 full이면 false 리턴
	virtual bool pop(int& n) = 0;	// 스택에서 팝한 정수를 n에 저장하고, 
					// 스택이 empty이면 false 리턴
	virtual int length() = 0;	// 현재 스택에 저장된 정수의 개수 리턴, size()  함수 이름 수정
};

class Stack : public AbstractStack {
	int* p;
	int tos;
	int capacity;

public:

	Stack(int size);
	~Stack();
	bool push(int n);
	bool pop(int& n);
	int length();
	int size() {
		return tos;
	}
};

Stack::Stack(int size) {
	this->capacity = size;
	p = new int[size];
	tos = -1;
}

Stack::~Stack() {
	delete[] p;
}

bool Stack::push(int n) {
	if (tos < capacity - 1) {
		p[++tos] = n;
		return true;
	}
	else {
		return false;
	}
}
bool Stack::pop(int& n) {
	if (tos < 0) {
		return false;
	}
	else {
		n = p[tos--];
		return true;
	}
}
int Stack::length() {
	return size();
}

int main() {
	Stack a(5);
	for (int i = 0; i < 10; i++) { // 처음 5 개를 성공적으로 push되고 다음 5 개는 스택 full로 push 실패
		if (a.push(i)) cout << "push 성공" << endl;
		else cout << "스택 full" << endl;
	}

	int n;
	for (int i = 0; i < 10; i++) { // 처음 5 개를 성공적으로 pop되고 다음 5 개는 스택 empty로 pop 실패
		if (a.pop(n)) cout << "pop 성공 " << n << endl;
		else cout << "스택 empty" << endl;
	}
}