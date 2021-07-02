#include <iostream>
#include <cstring>
using namespace std;


int main()

{
    char str[] = "This is a simple string";

    /*
    cout << "여러 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
    char str[100];
    cin.getline(str, 100, '&');
    */

    char* pos;

   //C 표준 함수 strstr() 사용해도 같은 결과 나옴

    
    /*
    char find[50];
    cout << "find: ";
    cin.getline(find, 50, '\n');
    */

    //pos = strstr(str, find);
    pos = strstr(str, "simple");  // simple이 존재하는 위치를 찾음

    /*
    char replace[100];
    cout << "replace: ";
    cin.getline(replace, 100, '\n');
   */
    

    if (pos) {

        //strncpy(pos, replace, strlen(replace));
        strncpy(pos, "sample", 6);  // sample로 변경함

        puts(str);

    }
    else

        puts("None!");

    return 0;

}