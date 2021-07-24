#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char song[100] = "Falling in love with you";
	char elvis[100] = "Elvis Presley";
	char singer[100];

	cout << song << "를 부를 가수는 ";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";

	cin.getline(singer, 100, '\n');

	if ( !strcmp(singer, elvis) )
		cout << "맞았습니다.";
	else
		cout << "틀렸습니다. " << elvis << "입니다." << endl;


	return 0;

}