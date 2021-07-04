#include <iostream>
using namespace std;

class Circle {
	static int numCircle;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numCircle--; }
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircle() { return numCircle; }
};

Circle::Circle(int r)
{
	radius = r;
	numCircle++;
}

int Circle::numCircle = 0;

int main() {

	Circle* p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
	cout << "생존하고 있는 원의 개수 = " << p->getNumOfCircle() << endl;
	cout << "생존하고 있는 원의 개수 = " << p[0].getNumOfCircle() << endl;



	delete[] p;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;

	Circle a;
	cout << "생존하고 있는 원의 개수 = " << a.getNumOfCircle() << endl;

	Circle b;
	cout << "생존하고 있는 원의 개수 = " << a.getNumOfCircle() << endl;
	cout << "생존하고 있는 원의 개수 = " << b.getNumOfCircle() << endl;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;

}