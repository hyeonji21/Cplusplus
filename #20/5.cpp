#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show() { cout << "kick=" << kick << "," << "punch=" << punch << endl; }
	friend Power operator+(int op1, Power op2);
	friend Power operator+(Power op1, Power op2);
	friend Power& operator++(Power& op);
	friend Power operator++(Power& op, int x);
};

Power& operator++(Power& op)
{
	op.kick++, op.punch++;

	return op;
}

Power operator++(Power& op, int x)
{
	Power tmp = op;

	op.kick++, op.punch++;

	return tmp;
}

Power operator+(int op1, Power op2) {

	Power tmp;

	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;

	return tmp;

}
Power operator+(Power op1, Power op2) {

	Power tmp;

	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;

	return tmp;

}

int main()
{
	Power a(3, 5), b;

	a.show();
	b.show();

	b = 2 + a;
	a.show();
	b.show();

	Power c;
	c = a + b;
	a.show();
	b.show();
	c.show();

	c = ++a;
	a.show();
	c.show();

	c = a++;
	a.show();
	c.show();
}
