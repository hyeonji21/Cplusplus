#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : protected Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void setAB(int a, int b) {
		this->b = b;
		setA(a);
	}
	void showAB() {
		showA();
		cout << endl << b << endl;
	}
	void showB() { cout << b; }
};

int main() {

	Derived x;

	x.setAB(5, 10);
	x.showAB();

	Base y;
	y.showA();

}