#include <iostream>
using namespace std;
#include <string.h>

int main()

{

    char str[] = "This is a simple string";

    char* pos;



    // StrStr() 대신에 C 표준 함수 strstr() 사용해도 같은 결과 나옴

    pos = strstr(str, "simple");  // simple이 존재하는 위치를 찾음



    if (pos) {

        strncpy(pos, "sample", 6);  // sample로 변경함

        puts(str);

    }
    else

        puts("None!");



    return 0;

}