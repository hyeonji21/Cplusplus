#include <iostream>
#include <string>
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


class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x; 
		this->y = y;
	}
	void show() {
		cout << '(' << x << ',' << y << ')' << endl;
	}

};

int main() {

	MyStack<int*> ipStack;
	
	int* p = new int[3];

	for (int i = 0; i < 3; i++) {
		p[i] = i * 10;
	}
	ipStack.push(p);
	int* q;
	ipStack.pop(q);

	for (int i = 0; i < 3; i++) {
		cout << q[i] << ' ';
	}
	cout << endl;
	delete[] p;

	MyStack<Point> pointStack;
	Point a(2, 3), b;
	pointStack.push(a);
	pointStack.pop(b);
	b.show();

	MyStack<Point*> pStack;
	pStack.push(new Point(10, 20));
	Point* pPoint;
	pStack.pop(pPoint);
	pPoint->show();

	MyStack<string> stringStack;
	string s = "C++";
	stringStack.push(s);
	stringStack.push("java");
	stringStack.pop(s);
	cout << s << endl;
	stringStack.pop(s);
	cout << s << endl;

	return 0;
}