#include <iostream>
#include <string>
using namespace std;

class Integer {
	int num;
public:
	Integer(int n);
	Integer(string n3);
	int get();
	void set(int n2);
	bool isEven();

};

Integer::Integer(int n) {
	num = n;
}
Integer::Integer(string n3) {
	num = stoi(n3);
}
int Integer::get() {
	return num;
}
void Integer::set(int n2) {
	num = n2;
}
bool Integer::isEven() {
	return true;
}



int main(void) {

	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();

	return 0;

}