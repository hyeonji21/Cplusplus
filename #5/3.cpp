#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {

	string words;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;

	/*
	while (1) {

		cout << ">>";

		getline(cin, words, '\n');
		
		if (words == "exit") {
			break;
		}
		
		int size = words.length();
		int size1 = size / 2;

		char change;
		for (int i = 0; i < size1; i++) {
			change = words[i];
			words[i] = words[size - i - 1];
			words[size - i - 1] = change;
		}

		cout << words << endl;

	}
	*/


	
	while (true) {
		cout << endl << ">>";
		getline(cin, words, '\n');

		if (words == "exit")
			break;

		for (int i = words.length() - 1; i >= 0; i--) {
			cout << words[i];
		}
			
	}
	

	return 0;

}