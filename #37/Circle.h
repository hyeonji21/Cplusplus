#ifndef CIRCLE_H
#define CIRCLE_H


class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

#endif