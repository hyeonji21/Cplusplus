#include <iostream>
using namespace std;

int main(void) {

	cout << "5 개의 실수를 입력하라>>";

	double compare;


	double num[5] = {};

	for (int j = 0; j < 5; j++) {

		cin >> num[j];

		compare = num[0];

	}


	for (int j = 0; j < 5; j++) {

		if (num[j] > compare) {
			compare = num[j];
		}

	}


	cout << "제일 큰 수 = " << compare << endl;

	return 0;

}