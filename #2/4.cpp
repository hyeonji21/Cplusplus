#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	while (true) {
		char writing[50];

		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(writing, 50, '\n');


		if (strcmp(writing, "yes") == 0) {
			cout << "종료합니다...";
			break;
		}

	}

	return 0;

}