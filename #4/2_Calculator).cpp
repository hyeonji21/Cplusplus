#include <iostream>
using namespace std;

class Add {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();

};

void Add::setValue(int x, int y) {
	a = x;
	b = y;
}

int Add::calculate() {
	return a + b;
}

class Sub {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();

};

void Sub::setValue(int x, int y) {
	a = x;
	b = y;
}

int Sub::calculate() {
	return a - b;
}

class Mul {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();

};

void Mul::setValue(int x, int y) {
	a = x;
	b = y;
}

int Mul::calculate() {
	return a * b;
}


class Div {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();

};

void Div::setValue(int x, int y) {
	a = x;
	b = y;
}

int Div::calculate() {
	return a / b;
}

int check = 0;

int main(void) {

	Add a;
	Sub b;
	Mul c;
	Div d;

	int num1, num2;
	char ch;

	int result = 0;

	while (1) {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> num1 >> num2 >> ch;

		switch (ch) {
		case '+':
			a.setValue(num1, num2);
			result = a.calculate();
			break;

		case '-':
			b.setValue(num1, num2);
			result = b.calculate();
			break;

		case '*':
			c.setValue(num1, num2);
			result = c.calculate();
			break;

		case '/':
			d.setValue(num1, num2);
			if (num2 == 0) {
				check = 1;
			}
			else {
				result = d.calculate();
			}
			break;
		}

		if (check == 0)
			cout << result << endl;
		else
			cout << "연산불가" << endl;

		check = 0;

	}
	 
	return 0;
}