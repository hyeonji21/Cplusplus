#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {

	string text;

	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;

	while (true) {

		srand((unsigned)time(0));
		char n;

		cout << ">>";
		getline(cin, text, '\n');

		int length = text.length();

		if (text == "exit") {
			break;
		}


		for (;;) {
			int index = rand() % length;

			if ((text[index] >= 65) && (text[index] <= 90)) {
				n = rand() % (90 - 65 + 1) + 65;
			}
			else {
				n = rand() % (122 - 97 + 1) + 97;
			}

			if (text.at(index) == ' ' || text.at(index) == '.' || text[index] == n) {

				continue;

			}
			else {

				text[index] = n;
				break;
			}
		}

		cout << text << endl;

	}

	return 0;

}