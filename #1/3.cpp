#include <iostream>

int main() {

	int result = 0;

	for (int i = 1; i <= 10; i++) {
		result += i;
	}

	std::cout << "1에서 10까지 더한 결과는 " << result << "입니다";



	return 0;

}