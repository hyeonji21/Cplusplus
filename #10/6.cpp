#include <iostream>
using namespace std;

class Matrix {
	int a[4];
public:
	Matrix() {
		for (int i = 0; i < 4; i++) {
			a[i] = 0;
		}
	}
	Matrix(int a1, int a2, int a3, int a4) {
		a[0] = a1;
		a[1] = a2;
		a[2] = a3;
		a[3] = a4;
	}
	void show();
	Matrix operator+ (Matrix op2);
	Matrix& operator+= (Matrix op2);
	bool operator==(Matrix op2);
};

void Matrix::show() {
	cout << "Matrix = { ";
	for (int i = 0; i < 4; i++) {
		cout << a[i] << ' ';
	}
	cout << "}" << endl;
}

Matrix Matrix::operator+(Matrix op2) {
	Matrix tmp;
	for (int i = 0; i < 4; i++) {
		tmp.a[i] = a[i] + op2.a[i];
	}
	return tmp;
}

Matrix& Matrix::operator+= (Matrix op2) {

	for (int i = 0; i < 4; i++) {
		a[i] = a[i] + op2.a[i];
	}
	return*this;
}

bool Matrix::operator== (Matrix op2) {

	for (int i = 0; i < 4; i++) {
		if (a[i] != op2.a[i]) {
			return false;
		}
	}
	return true;
}

int main() {

	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;

	return 0;

}