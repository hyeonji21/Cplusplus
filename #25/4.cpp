#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle : public Shape {
	int radius;
public:
	Circle(int radius = 1) {
		this->radius = radius;
	}
	virtual void draw() {
		Shape::draw();
		cout << "Circle" << "(" << radius << ")" << endl;
	}
};


int main() {

	Circle circle;
	Shape* pShape = &circle;

	pShape->draw();
	pShape->Shape::draw();



}
