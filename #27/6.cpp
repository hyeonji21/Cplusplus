#include <iostream>
using namespace std;

template <class T> class MyStack {
	int tos; // top of stack
	T data[100];
public:
	MyStack();
	bool push(T element);
	bool pop(T& r);
};

template <class T> MyStack<T>::MyStack() {
	tos = -1;
}

template <class T> bool MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full" << endl;
		return false;
	}
	data[++tos] = element;
	return true;
}

template <class T> bool MyStack<T>::pop(T& r) {

	if (tos == -1) {
		cout << "stack empty" << endl;
		return false;
	}
	r = data[tos--];
	return true;
}

int main(void) {

	MyStack<int> iStack;
	for (int i = 0; i < 101; i++) {
		iStack.push(i);
	}
	int d;
	for (int i = 0; i < 6; i++) {
		if (iStack.pop(d))
			cout << d << ' ';
	}
	cout << endl;


	MyStack<double> dStack;
	for (int i = 0; i < 101; i++) {
		dStack.push(i * 0.1);
	}
	double x;
	for (int i = 0; i < 6; i++) {
		if (dStack.pop(x))
			cout << x << ' ';
	}
	cout << endl;


	MyStack<char>* p = new MyStack<char>();
	for (int i = 0; i < 10; i++) {
		p->push(i + 'a');
	}

	char c;
	for (int i = 0; i < 11; i++) {
		if (p->pop(c))
			cout << c;
	}
	cout << endl;

	return 0;

}

