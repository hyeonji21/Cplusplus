
class Circle {

	int radius;
public:
	double getArea() {
		return 3.14 * radius * radius; 
	};
};

// 구현부를 안 만들어도 무방
/*
double Circle::getArea() {
	return 3.14 * radius * radius;
}
*/