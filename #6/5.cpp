#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char note[100];
	char new_note;

	cout << "아래에 문자열을 입력하세요. 빈 칸이 있어도 됩니다.(한글 안됨) " << endl;
	cin.getline(note, 100, '\n');
	int length = strlen(note);

	for (int i = 0; i < length; i++) {
		
		new_note = note[0];

		for (int j = 0; j < length - 1; j++) {

			note[j] = note[j+1];
		}

		note[length-1] = new_note;
		cout << note << endl;

	}

	return 0;

}