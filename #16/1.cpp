#include <iostream>
using namespace std;

float square(float a) {
	
	cout << "float" << endl;
	return a * a;
}

double square(double a) {
	
	cout << "double" << endl;
	return a * a;
}

int main(void) {

	cout << square(3.0) << endl;
	cout << square(3.0f) << endl;
	cout << square((float)3) << endl;

	return 0;

}