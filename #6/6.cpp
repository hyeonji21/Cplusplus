#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	char count[100];
	
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	cin.getline(count, 100, '\n');

	char* tok;

	int sum = 0;

	tok = strtok(count, "+");
	while (tok != NULL) {
		cout << tok << endl;
		sum += atoi(tok);
		tok = strtok(NULL, "+");
	}

	cout << "숫자들의 합은 " << sum;

	
	return 0;

}