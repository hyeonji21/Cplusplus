#include <iostream>
using namespace std;

class Stack {
	int* p;
	int size;
	int tos;
public:
	Stack();
	Stack(int size);
	Stack(const Stack& s);
	~Stack();
	bool push(int n);
	bool pop(int& n);
	Stack& operator++();
	friend Stack operator++(Stack& op, int x);
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

Stack& Stack::operator++() {

	for (int i = 0; i < size; i++) {
		p[i] += 1;
	}
	return*this;
}

Stack operator++(Stack& op, int x) {
	Stack tmp = op;
	for (int i = 0; i < op.size; i++) {
		op.p[i] += 1;
 	}
	return tmp;
}

int main(void) {

	Stack a(5);
	for (int i = 0; i < 6; i++) {
		if (!a.push(i)) {
			cout << endl << "스택 a가 full입니다." << endl;
		}
		else {
			cout << "push(" << i << ") ";
		}
	}
	cout << endl;
	++a;

	Stack b = a++;

	for (int i = 0, n; i < 6; i++) {
		if (!a.pop(n)) {
			cout << endl << "스택 a에 저장된 값이 없습니다." << endl;
			break;
		}
		else {
			cout << "pop(" << n << ") ";
		}
	}
	cout << endl;

	for (int i = 0, n; i < 6; i++) {
		if (!b.pop(n)) {
			cout << endl << "스택 b에 저장된 값이 없습니다." << endl;
			break;
		}
		else {
			cout << "pop(" << n << ") ";
		}
	}
	cout << endl;

	return 0;
}