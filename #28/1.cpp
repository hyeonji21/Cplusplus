#include <iostream>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0; // 순수가상함수
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }

};

void Shape::paint() {
	draw();
}
// 인터페이스 함수
//(외부로 사용할 수 없는 함수를 사용할 수 있도록 만들어줌)

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}

class Circle : public Shape {
protected:
	virtual void draw();
};

void Circle::draw() {
	cout << "Circle" << endl;
}

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class GraphicEditor {
	Shape* pStart = NULL;
	Shape* pLast;

public:
	GraphicEditor() { 
		cout << "그래픽 에디터입니다." << endl;
		pStart = NULL;
	}
	void run();
	void insert();
	void del();
	void draw();
};

void GraphicEditor::run() {

	while (true) {
		cout << "삽입: 1, 삭제:2, 모두보기: 3, 종료: 4 >> ";
		int choice;
		cin >> choice;
		if (choice == 4) break;
		switch (choice) {
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			draw();
			break;
		}
	}
}
void GraphicEditor::del() {

	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	int index;
	cin >> index;

	Shape* p = pStart;
	Shape** pp = &pStart;

	for (int i = 0; p != NULL; i++) {
		if (i == index) {
			Shape* q = p->getNext();
			delete p;
			*pp = q;
			break;
		}
		else {
			p = p->getNext();
			pp = &p;
		}
	}
}


void GraphicEditor::draw() {

	Shape* p = pStart;
	int i = 0;
	while (p != NULL) {
		cout << i << ": ";
		p->paint();
		p = p->getNext();
		i++;
	}
}

void GraphicEditor::insert() {
	
	cout << "선: 1, 원: 2, 사각형: 3 >> ";
	int choice;
	cin >> choice;
	if (pStart == NULL) {
		switch (choice) {
		case 1:
			pStart = new Line();
			break;
		case 2:
			pStart = new Circle();
			break;
		case 3:
			pStart = new Rect();
			break;
		}
		pLast = pStart;
	}
	else {
		switch (choice) {
		case 1:
			pLast = pLast->add(new Line());
			break;
		case 2:
			pLast = pLast->add(new Circle());
			break;
		case 3:
			pLast = pLast->add(new Rect());
			break;
		}
	}

}


int main() {

	GraphicEditor g;

	g.run();

	
	return 0;

}