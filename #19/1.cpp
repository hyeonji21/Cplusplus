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
	Power operator+(Power& a);
};

Power Power::operator+(Power& a)
{
	Power tmp;
	tmp.kick = this->kick + a.kick;
	tmp.punch = this->punch + a.punch;

	return tmp;
}

int main(void) {
	
	Power a(3, 5), b(4, 6), c;

	c = a + b;  // c = a.operator+(b) 
	a.show();
	b.show();
	c.show();

}