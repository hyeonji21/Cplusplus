#include <iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void show() {
		cout << "반지름이 " << getRadius() << "인 원" <<  endl;
	}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle() : Circle(0) {
		name = "";
	}
	NamedCircle(int radius, const char name[]) : Circle(radius) {
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

int main() {

	NamedCircle pizza[5];

	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;

	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">> ";
		int radius;
		string name;
		cin >> radius >> name;
		pizza[i].setRadius(radius);
		pizza[i].setName(name);
		pizza[i].show();
	}

	Circle donut;
	donut.show();

	int max = 0;
	for (int i = 1; i < 5; i++) {
		if (pizza[max].getArea() < pizza[i].getArea()) {
			max = i;
		 }
	}

	cout << "가장 면적이 큰 피자는 " << pizza[max].getName() << "입니다" << endl;

	return 0;
}