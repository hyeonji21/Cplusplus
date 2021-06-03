#include <iostream>
#include <string>
using namespace std;

int main() {

	string note;

	cout << "문자열 입력>> ";
	getline(cin, note, '\n');

	int count = 0;

	int index = -1;
	while (true) {
		
		index = note.find('a', index + 1);
		
		if (index == -1) {
			break;
		}
		count += 1;
	}


	cout << "문자 a는 " << count << "개 있습니다.";

	return 0;

}