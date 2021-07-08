#include <iostream>
using namespace std;

class Shape {	// Abstract class
	Shape* next;
protected:
	virtual void draw() = 0;		// 순수가상함수
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

//void Shape::draw() {
//	cout << "--Shape--" << endl;
//}

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
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() {
		cout << "그래픽 에디터입니다." << endl;
		pStart = pLast = NULL;
		run();
	}
	~GraphicEditor();	// 소멸자, 생성해서 삭제하지 않은 도형 삭제
	void run();
	void insert();
	void del();
	void draw();
};

//class UI {
//	static void insert();
//	static void del();
//	static void draw();
//};

void GraphicEditor::run()
{
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

void GraphicEditor::del()
{
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	int index;
	cin >> index;

	Shape* p = pStart;
	Shape* prevP = pStart;
	for (int i = 0; i < index; i++) {	// 지울 도형까지 찾아감.
		if (p == NULL) {
			cout << "리스트에 지울 인덱스를 갖는 도형이 없음" << endl;
			return;
		}
		prevP = p;
		p = p->getNext();
	}
	// p에 지울 도형의 포인터 저장됨.
	Shape* pNext = prevP->add(p->getNext());
	//지워질 도형 이전에 있는 곳에 지워질 도형 다음 도형을 연결시켜줌.

	// pStart와 pLast 포인터 조정
	if (p == pStart) // 삭제한 도형이 첫 도형인 경우
		pStart = pNext;

	if (p == pLast) { // 삭제한 도형이 마지막 도형인 경우
		if (pStart == NULL) // 삭제한 도형이 처음이자 마지막인 경우
			pLast = NULL;
		else
			pLast = prevP;
	}
	delete p;	// 도형을 지움.		
}

void GraphicEditor::draw()
{
	Shape* p = pStart;
	int i = 0;
	while (p != NULL) {
		cout << i << ": ";
		p->paint();
		p = p->getNext();
		i++;
	}
}

void GraphicEditor::insert()
{
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
			pLast = pLast->add(new Line()); // 선 객체 생성
			break;
		case 2:
			pLast = pLast->add(new Circle()); // 원 객체 생성
			break;
		case 3:
			pLast = pLast->add(new Rect()); // 사각형 객체 생성
			break;
		}
	}
}

GraphicEditor::~GraphicEditor() { // 소멸자
	// 현재 생성된 모든 객체를 삭제한다.
	Shape* p = pStart;
	while (p != NULL) {
		Shape* q = p->getNext(); // 다음 객체위치를 저장한다.
		delete p; // 현재 객체를 삭제한다.
		p = q; // 다음 객체를 가리킨다.
	}
}

int main()
{
	GraphicEditor g;	// 생성자에서 run() 함수 실행

	return 0;
}