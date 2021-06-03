#include <iostream>
#include <string>
using namespace std;

int main() {

	string note;

	cout << "문자열 입력>> ";
	getline(cin, note, '\n');

	int length = note.length();

	int count = 0;

	for (int i = 0; i < length; i++) {
		if (note.at(i) == 'a') {
			count += 1;
		}
	}

	cout << "문자 a는 " << count << "개 있습니다.";


	return 0;

}