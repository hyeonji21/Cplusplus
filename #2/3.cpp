#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string secure;
	string secure2;


	cout << "새 암호를 입력하세요>>";
	cin >> secure;

	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> secure2;
	
	if (secure == secure2) {
		cout << "같습니다";
	}
	else {
		cout << "같지 않습니다";
	}


	return 0;

}