#include <iostream>
using namespace std;

#include "Circle.h";


Circle gDonut(1000), gPizza(2000);

void f() {
	Circle fDonut(100), fPizza(200);
}


int main(void)
{
	Circle mDonut;
	Circle mPizza(10);
	f();

	return 0;
}