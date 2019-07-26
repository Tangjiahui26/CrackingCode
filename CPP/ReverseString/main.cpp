#include <iostream>

using namespace std;

void reverseString(char * str){
    char* end = str;
    char temp;
    if (str){
        while(*end){
            ++end;
        }
        // last char is null
        --end;
    }

    // swap characters from start of string with the end of the string untik
    // the pointers meet in middle
    while(str < end){
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

int main()
{
    char s[] = "testString";
    reverseString(s);
    cout << s << endl;
    return 0;
}
