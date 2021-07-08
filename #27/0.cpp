#include <iostream>
using namespace std;

void myswap(int& a, int& b) {
	
	int tmp;
	tmp = a;
	a = b;
	b = tmp;

}

void myswap(double& a, double& b) {

	double tmp;
	tmp = a;
	a = b;
	b = tmp;

}

int main(void) {

	int a = 4, b = 5;
	myswap(a, b);
	cout << a << '\t' << b << endl;

	double c = 0.4, d = 0.5;
	myswap(c, d);
	cout << c << '\t' << d << endl;

	return 0;
}



