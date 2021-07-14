#include <iostream>
using namespace std;

#include "oc3 EXP.h"

int main() {

	Exp a(3, 2);    // base: 3, exp: 2
	Exp b(9);       // base: 9, exp: 1
	Exp c;          // 

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;
	cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << endl;

	if (a.equals(b))
		cout << "same" << endl;
	else
		cout << "not same" << endl;

}