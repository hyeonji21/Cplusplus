#include <iostream>
using namespace std;

int main(void) {

	cout << "주소를 입력하세요>> ";

	char addr[100];
	//cin.getline(addr, 100, '\n');
	// cin.getline(addr, 100);
	cin.getline(addr, 100, ':');


	cout << "주소는 " << addr << "입니다\n";


	return 0;
}