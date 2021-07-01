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
	friend Matrix& operator >> (Matrix& op1, int arr[]);
	friend Matrix& operator << (Matrix& op1, int arr[]);
};

void Matrix::show() {
	cout << "Matrix = { ";
	for (int i = 0; i < 4; i++) {
		cout << a[i] << ' ';
	}
	cout << "}" << endl;
}

Matrix& operator >> (Matrix& op1, int arr[]) {
	
	for (int i = 0; i < 4; i++) {
		arr[i] = op1.a[i];
	}
	return op1;
}

Matrix& operator << (Matrix& op1, int arr[]) {
	
	for (int i = 0; i < 4; i++) {
		op1.a[i] = arr[i];
	}
	return op1;
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