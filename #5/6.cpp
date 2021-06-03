#include <iostream>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

void Circle::setCircle(string name, int radius) {
	this->radius = radius;
	this->name = name;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

string Circle::getName() {
	return name;
}


class CircleManager {
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};

CircleManager::CircleManager(int size) {
	p = new Circle[size];
	this->size = size;

	string name;
	int radius;

	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}

}

CircleManager::~CircleManager() {
	delete[] p;
}

void CircleManager::searchByName() {

	cout << "검색하고자 하는 원의 이름 >> ";
	string name;
	cin >> name;

	for (int i = 0; i < size; i++) {
		if (name == p[i].getName()) {
			cout << name << "의 면적은 ";
			cout << p[i].getArea() << endl;
		}
	}

}

void CircleManager::searchByArea() {

	int area = 0;

	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> area;

	cout << area << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > 10) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
		}
	}
}


int main() {

	int size = 0;

	cout << "원의 개수 >> ";
	cin >> size;

	CircleManager new_class(size);
	new_class.searchByName();
	new_class.searchByArea();


	return 0;

}