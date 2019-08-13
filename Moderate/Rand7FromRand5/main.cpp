#include <iostream>
#include <stdlib.h>

using namespace std;

int random5(){
    return rand() % 5;
}

// Approach 1: 5 * rand(5) + rand(5)
int random7(){
    while(true){
        int num = 5 * random5() + random5();
        if (num < 21){
            return num % 7;
        }
    }
}

// Approach 2: 2 * rand(5) + rand(5)
int rand7(){
    while(true){
        int r1 = 2 * random5();
        int r2 = random5();
        if (r2 != 4){
            // get 0 and 1
            int rand2 = r2 % 2;
            int num = r1 + rand2;
            if (num < 7){
                return num;
            }
        }
    }
}

int main()
{
    cout << random7() << endl;
    return 0;
}
