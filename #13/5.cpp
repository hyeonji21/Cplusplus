#include <iostream>
using namespace std;

class UI {
public:
	static int menu() {
		int num;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> num;
		return num;
	}
	static int shape_choose(){
		int num;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> num;
		return num;
	}
	static int del_menu() {
		int num;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> num;
		return num;
	}
};

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint() { draw(); }
	Shape* add(Shape* p) { 
		this->next = p; 
		return p; 
	}
	Shape* getNext() {
		return next;
	}
	void setnext(Shape* p) {
		this->next = p->next;
	}
};

class Circle : public Shape {
protected:
	void draw() {
		cout << "Circle" << endl;
	}
};
class Rect : public Shape {
protected:
	void draw() {
		cout << "Rectangle" << endl;
	}
};
class Line : public Shape {
protected:
	void draw() {
		cout << "Line" << endl;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	int count;
public:
	GraphicEditor() {
		pStart = NULL;
		count = 0;
	}
	void add_shape(int num) {
		while (true) {
			if (num == 1) {
				if (count == 0) {
					pStart = new Line();
					pLast = pStart;
				}
				else {
					pLast = pLast->add(new Line());
				}
				count++;
				break;
			}
			else if (num == 2) {
				if (count == 0) {
					pStart = new Circle();
					pLast = pStart;
				}
				else {
					pLast = pLast->add(new Circle());
				}
				count++;
				break;
			}
			else if (num == 3) {
				if (count == 0) {
					pStart = new Rect();
					pLast = pStart;
				}
				else {
					pLast = pLast->add(new Rect());
				}
				count++;
				break;
			}
		}
	}

	void delete_shape(int num) {
		Shape* p = pStart;
		Shape* del = pStart;
		
		if (num < count) {
			for (int i = 0; i < num; i++) {
				p = del;
				del = del->getNext();
			}
			if (num == 0) {
				pStart = p->getNext();
			}
			else {
				p->setnext(del);
			}
			count--;
			if (count == 1) {
				pLast = pStart;
			}
			delete del;
		}
		else {
			cout << "인덱스를 잘못 입력하셨습니다." << endl;
		}
	}

	void show() {
		cout << "그래픽 에디터입니다." << endl;
		bool check = true;
		while (check) {

			int sel = UI::menu();

			if (sel == 1) {
				add_shape(UI::shape_choose());
			}

			else if (sel == 2) {
				delete_shape(UI::del_menu());
				
			}

			else if (sel == 3) {
				Shape* p = pStart;
				for (int i = 0; i < count; i++) {
					cout << i << ": ";
					p->paint();
					p = p->getNext();
 				}
			}

			else if (sel == 4) {
				check = false;
				
			}
		}
	}
};



int main() {

	GraphicEditor* graphiceditor = new GraphicEditor;
	graphiceditor->show();
	delete graphiceditor;

	return 0;

}