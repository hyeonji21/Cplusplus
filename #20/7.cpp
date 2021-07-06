#include <iostream>
using namespace std;
#include <string>

class Histogram {
	string str;
public:
	Histogram(const char s[]) {
		str = s;
	}
	/*
	char* str;
	Histogram(const char s[]) {
		this->str = new char[strlen(s) + 1];
		strcpy(this->str, s);
	}
	*/
	Histogram& operator<<(const char s[]);
	Histogram& operator<<(char c);
	void operator!();

};

void Histogram::operator!()
{
	int len = str.length();
	int i, j, n, acnt;

	cout << str << endl << endl;

	for (j = 0, acnt = 0; j < len; j++) {
		if (isalpha(str[j])) acnt++;
		if (isupper(str[j])) {
			str[j] = tolower(str[j]);
		}
	}

	cout << "총 알파벳 수 " << acnt << endl;

	for (i = 'a'; i <= 'z'; i++) {
		n = 0;
		for (j = 0; j < len; j++) {
			if (str[j] == i) n++;
		}
		cout << (char)i << ":";
		for (j = 0; j < n; j++) {
			cout << '*';
		}
		cout << endl;
	}
}

Histogram& Histogram::operator<<(const char s[])
{
	str += s;
	return*this;

}
Histogram& Histogram::operator<<(char c)
{
	char s[2];
	s[0] = c, s[1] = 0;

	str.append(s);

	return*this;
}

int main(void) {

	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");  ///song(char* s)

	song << "falling" << " in love with you. " << "- by ";
	song << 'k' << 'i' << 't';

	!song;  // 히스토그램 그리기

}