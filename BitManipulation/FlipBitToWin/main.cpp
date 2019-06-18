#include <iostream>
#include <algorithm>

using namespace std;

int flipOneBit(int num){
    if (~num == 0) {
        return sizeof(num) * 8;
    }

    int currentLength = 0;
    int previousLength = 0;
    int maxLength = 1;

    while (num != 0) {
        if ((num & 1) == 1) {
            currentLength++;
        } else if ((num & 1) == 0) {
            // next bit after a '0'
            previousLength = (num & 2) == 0 ? 0 : currentLength;
            currentLength = 0;
        }
        maxLength = max(previousLength + currentLength + 1, maxLength);
        // logical right shift by 1 bit
        num = (int)((unsigned int) num >> 1);
    }
    return maxLength;
}

int main()
{
    int test = 1775;
    cout << "Flip one bit to win: " << flipOneBit(test) << endl;
    return 0;
}
