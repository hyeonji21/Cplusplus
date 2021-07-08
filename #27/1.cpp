#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }

};

template <class T>
void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {

	int a = 10, b = 20;
	myswap(a, b);
	cout << "a=" << a << ", " << "b=" << b << endl;

	double c = 1.0, d = 2.0;
	myswap(a, b);
	cout << "c=" << c << ", " << "d=" << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	cout << "donut반지름=" << donut.getRadius() << ", ";
	cout << "pizza반지름=" << pizza.getRadius() << endl;

	return 0;
}