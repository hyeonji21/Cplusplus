  
#include <iostream>
#include <cstring>
using namespace std;

char* change_word(char* string, char* old_word, char* new_word);

int main()
{
    char string[30];
    char old_word[10];
    char new_word[10];

    cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
    cin.getline(string, 30, '&');

    printf("find: ");
    cin.getline(old_word, 10, '\n');

    cout << endl;

    printf("replace: ");
    cin.getline(new_word, 10, '\n');

    strcpy(string, change_word(string, old_word, new_word));
    cout << string;

    return 0;
}

char* change_word(char* string, char* old_word, char* new_word)
{
    char* token;
    char temp[30];

    memset(temp, 0, sizeof(temp));
    token = strtok(string, " ");

    while (token != NULL)
    {
        if (0 == strcmp(token, old_word))
        {
            strcat(temp, new_word);
        }
        else
        {
            strcat(temp, token);
        }
        strcat(temp, " ");
        token = strtok(NULL, " ");
    }
    temp[strlen(temp) - 1] = 0;

    return temp;
}
