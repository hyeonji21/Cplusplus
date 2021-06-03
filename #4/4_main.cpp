#include <iostream>
using namespace std;

#include "4_Box.h"

int main() {

	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();

}