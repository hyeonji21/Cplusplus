#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요.\n";
	cout << "로미오>>";
	char romio[10];
	cin >> romio;
	cout << "줄리엣>>";
	char juliet[10];
	cin >> juliet;

	if (!strcmp(romio, "가위")) {
		if (!strcmp(juliet, "가위"))
			cout << "비겼습니다.\n";
		else if (!strcmp(juliet, "바위"))
			cout << "줄리엣이 이겼습니다.\n";
		else
			cout << "로미오가 이겼습니다.\n";
	}

	else if (!strcmp(romio , "바위")) {
		if (!strcmp(juliet , "바위"))
			cout << "비겼습니다.\n";
		else if (!strcmp(juliet , "가위"))
			cout << "로미엣이 이겼습니다.\n";
		else
			cout << "줄리엣이 이겼습니다.\n";
	}

	else {
		if (!strcmp(juliet , "보"))
			cout << "비겼습니다.\n";
		else if (!strcmp(juliet , "가위"))
			cout << "줄리엣이 이겼습니다.\n";
		else
			cout << "로미엣이 이겼습니다.\n";
	}

	return 0;

}