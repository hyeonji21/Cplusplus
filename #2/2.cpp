#include <iostream>
using namespace std;

int main(void) {

	cout << "문자들을 입력하라(100개 미만)." << endl;

	char note[100];
	cin.getline(note, 100, '\n');

	int count = 0;

	for (int i = 0; i <= 100; i++) {
		if (note[i] == 'x') {
			count += 1;
		}
		if (note[i] == '\n') {
			return 1;
		}
	}

	cout << "x의 개수는 " << count;


	return 0;

}