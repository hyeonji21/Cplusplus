#include <iostream>

using namespace std;

int main(void) {

	cout << "너비를 입력하세요>> ";

	int width;
	cin >> width;   // scanf("%d", &width);

	cout << "높이를 입력하세요>> ";

	int height;
	cin >> height;

	int area = width * height;
	cout << "면적은 " << area << "\n";

	return 0;
}