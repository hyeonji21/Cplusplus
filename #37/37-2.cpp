#include <iostream>
using namespace std;

class Rectangle {

	int width, height;
public:
	Rectangle();
	Rectangle(int n);
	Rectangle(int w, int h);
	~Rectangle();
	bool isSquare();
};

Rectangle::~Rectangle() {
	cout << "너비: " << width << ", 높이: " << height << "인 사각형 소멸\n";

}

Rectangle::Rectangle() {
	width = 1;
	height = 1;
	cout << "너비: " << width << ", 높이: " << height << "인 사각형 생성\n";

}
Rectangle::Rectangle(int n) {
	width = height = n;
	cout << "너비: " << width << ", 높이: " << height << "인 사각형 생성\n";
}
Rectangle::Rectangle(int w, int h) {
	width = w;
	height = h;
	cout << "너비: " << width << ", 높이: " << height << "인 사각형 생성\n";
}
bool Rectangle::isSquare() {

	return (width == height);

}
Rectangle grect1(10); 
Rectangle grect2(20);

int main(void) {

	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2은 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3은 정사각형이다." << endl;




	return 0;

}