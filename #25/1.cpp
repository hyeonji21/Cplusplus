#include <iostream>
using namespace std;

class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};



int main() {

	Base b;
	Derived d;

	b.f();
	d.f();


	Base* bp = &b;
	Derived* dp = &d;

	bp->f();
	dp->f();

	bp = &d;    // upcasting
	bp->f();    // Base::f() »£√‚


	return 0;

}