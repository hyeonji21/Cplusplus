#include <iostream>
using namespace std;

class Rectangle {

	int width, height;
public:
	Rectangle();
	Rectangle(int n);
	Rectangle(int w, int h);
	bool isSquare();
};

Rectangle::Rectangle() {
	width = 1;
	height = 1;

}
Rectangle::Rectangle(int n) {
	width = height = n;
}
Rectangle::Rectangle(int w, int h) {
	width = w;
	height = h;
}
bool Rectangle::isSquare() {
	
	return (width == height);

}


int main(void) {

	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2은 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3은 정사각형이다." << endl;

	return 0;

}