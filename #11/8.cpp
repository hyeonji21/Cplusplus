#include <iostream>
using namespace std;

class Statistics {

	int* p;
	int check = 0;

public:
	Statistics();
	~Statistics();
	bool operator! ();
	Statistics& operator<<(int op1);
	void operator~();
	Statistics& operator>>(int& op2);

};

Statistics::Statistics() {
	p = new int[10];
}

Statistics::~Statistics() {
	delete[] p;
}

bool Statistics::operator!() {
	if (check == 0) {
		return true;
	}
	return false;
}

Statistics& Statistics::operator<<(int op1) {

	p[check] = op1;
	check++;
	return*this;
}

void Statistics::operator~() {
	for (int i = 0; i < check; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}

Statistics& Statistics::operator>>(int& op2) {
	int sum = 0;
	for (int i = 0; i < check; i++) {
		sum += p[i];
	}
	op2 = sum / check;
	return*this;
}


int main() {

	Statistics stat;
	if (!stat) {
		cout << "현재 통계 데이타가 없습니다." << endl;
	}

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < 5; i++) {
		stat << x[i];
	}
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;

	return 0;
}