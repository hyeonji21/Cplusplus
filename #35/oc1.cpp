#include <iostream>
#include <string>
using namespace std;

int main(void) {

	cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요.\n";
	cout << "로미오>>";
	string romio;
	cin >> romio;
	cout << "줄리엣>>";
	string juliet;
	cin >> juliet;

	if (romio == "가위") {
		if (juliet == "가위")
			cout << "비겼습니다.\n";
		else if (juliet == "바위")
			cout << "줄리엣이 이겼습니다.\n";
		else
			cout << "로미오가 이겼습니다.\n";
	}

	else if (romio == "바위") {
		if (juliet == "바위")
			cout << "비겼습니다.\n";
		else if (juliet == "가위")
			cout << "로미엣이 이겼습니다.\n";
		else
			cout << "줄리엣이 이겼습니다.\n";
	}

	else {
		if (juliet == "보")
			cout << "비겼습니다.\n";
		else if (juliet == "가위")
			cout << "줄리엣이 이겼습니다.\n";
		else
			cout << "로미엣이 이겼습니다.\n";
	}

	return 0;

}