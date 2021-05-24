#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char letter[100];

	cout << "문자열 입력>>";
	cin.getline(letter, 100, '\n');

	int length = strlen(letter);

	for (int i = 1; i <= length; i++) {
		for (int j = 0; j < i; j++) {
			cout << letter[j];
		}
		cout << endl;
	}
	

	return 0;

}