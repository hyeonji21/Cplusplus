#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPrint();
};

void ColorPoint::showColorPrint() {
	cout << color << ":";
	showPoint();
}

int main(void) {

	Point p;
	ColorPoint cp;
	
	p.set(5, 5);
	p.showPoint();

	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPrint();

	return 0;
}