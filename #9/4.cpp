#include <iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector() { delete[] mem; }
};

MyVector::MyVector(int n = 100, int val = 0) {
	mem = new int[n];
	size = n;

	for (int i = 0; i < size; i++) {
		mem[i] = val;
	}

	for (int i = 0; i < size; i++) {
		cout << mem[i] << ' ';
 	}
	cout << endl;
}

int main() {

	MyVector myvector1;
	MyVector myvector2(5, 5);

}