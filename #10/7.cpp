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
	Matrix& operator>> (int arr[]);
	Matrix& operator<< (int arr[]);

};

void Matrix::show() {
	cout << "Matrix = { ";
	for (int i = 0; i < 4; i++) {
		cout << a[i] << ' ';
	}
	cout << "}" << endl;
}

Matrix& Matrix::operator>> (int arr[]) {

	for (int i = 0; i < 4; i++) {
		arr[i] = a[i];
	}
	return*this;
}

Matrix& Matrix::operator<< (int arr[]) {
	for (int i = 0; i < 4; i++) {
		a[i] = arr[i];
	}
	return*this;
}


int main() {

	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	
	for (int i = 0; i < 4; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
	b.show();

	return 0;

}