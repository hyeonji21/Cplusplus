#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

int main(void) {

	cout << "이름을 입력하시오 >> ";

	char name[20];
	//cin >> name;  // scanf("%s", name);
	//fgets(name, 20, stdin);  
	gets_s(name);

	cout << "이름은 " << name << "입니다\n";

	return 0;
}