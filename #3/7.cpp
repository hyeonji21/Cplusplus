#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SelecttableRandom {
	int num;
public:
	SelecttableRandom(int n);
	int next();
	int nextInRange(int a, int b);

};

SelecttableRandom::SelecttableRandom(int num2) {
	num = num2;
	srand((unsigned)time(0));
}

int SelecttableRandom::next() {
	int n = rand();

	if (num % 2 == 0) {
		if (n % 2 == 0 || n == 0) {
			return n;
		}
		else {
			return --n;
		}
	}
	else {
		if (n % 2 == 0 || n == 0) {
			return ++n;
		}
		else {
			return n;
		}
	}
}

int SelecttableRandom::nextInRange(int a, int b) {
	int n = rand() % (b - a + 1) + a;
	
	if (num % 2 == 0) {
		if (n % 2 == 0 || n == 0) {
			return n;
		}
		else {
			return ++n;
		}
	}
	else {
		if (n % 2 == 0 || n == 0) {
			return ++n;
		}
		else {
			return n;
		}
	}
}

int main(void) {

	SelecttableRandom r1(0);
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r1.next();
		cout << n << ' ';
	}

	SelecttableRandom r2(1);
	cout << endl << endl << "-- 2에서 " << "9 까지의 홀수 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r2.nextInRange(2, 9);
		cout << n << ' ';
	}

	cout << endl;

	return 0;

}