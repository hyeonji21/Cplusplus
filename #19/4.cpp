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
	Power operator+(const Power& a);
	Power operator+(int n);
	Power& operator+=(Power& a);
	bool operator==(Power& a);

};

Power Power::operator+(int n)
{
	Power tmp;
	tmp.kick = this->kick + n;
	tmp.punch = this->punch + n;

	return tmp;
}


Power Power::operator+(const Power& a)
{
	Power tmp;
	tmp.kick = this->kick + a.kick;
	tmp.punch = this->punch + a.punch;

	return tmp;
}

Power& Power::operator+=(Power& a)
{
	kick += a.kick;
	punch += a.punch;

	return *this;
}

bool Power::operator==(Power& a)
{
	if (kick == a.kick && punch == a.punch) {
		return true;
	}
	else {
		return false;
	}
}


int main(void) {

	Power a(3, 5), b(4, 6), c;

	c = a + b;  // c = a.operator+(b) 
	a.show();
	b.show();
	c.show();

	c = a;
	a.show();
	c.show();

	if (a == c) {
		cout << "두 파워가 같다." << endl;
	}
	else {
		cout << "두 파워가 같지 않다." << endl;
	}

	c = a += b;

	a.show();
	b.show();
	c.show();

	b = a + 2;
	a.show();
	b.show();


}