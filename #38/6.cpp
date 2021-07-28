#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	Circle(int r) {
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	~Circle() {
		cout << "소멸자 실행 radius = " << radius << endl;
	}
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }

};


int main(void) {

	cout << "생성하고자 하는 원의 개수?";
	int n, radius;
	cin >> n;

	if (n <= 0) return 0;

	Circle* p = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << "원" << i + 1 << ": ";
		cin >> radius;
		p[i].setRadius(radius);
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		cout << p->getArea() << " ";
		if (p->getArea() >= 100 && p->getArea() <= 200) {
			count++;
		}
		p++;
	}
	p -= n;

	cout << endl << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;
	delete[] p;



	return 0;

}