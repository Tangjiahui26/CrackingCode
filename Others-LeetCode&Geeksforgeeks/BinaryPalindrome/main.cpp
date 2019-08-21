#include <iostream>

using namespace std;

// returns true if kth bit in x is set
bool isKthBitSet(unsigned int x, unsigned int k){
    return (x & (1 << (k -1))) ? true : false;
}

// if we want to ingore the leading zeros
int leftmostSetBit(int x){
    int count = 0;
    while(x){
        count++;
        x >>= 1;
    }
    return count;
}

bool isBinaryPalindrome(unsigned int x){
//    int left = 1;
    int left = leftmostSetBit(x);
    int right = 1;

    while (left > right){
        if (isKthBitSet(x, left) != isKthBitSet(x, right)){
            return false;
        }
        left--;
        right++;
    }
    return true;
}

// if input is an integer
unsigned int reverseBits(unsigned int n){
    unsigned int rev = 0;
    while(n > 0){
        rev <<= 1;

        // if current bit is '1'
        if (n & 1 == 1){
            rev ^= 1;
        }
        n >>= 1;
    }
    return rev;
}

bool isPalindrome(unsigned int n){
    unsigned int rev = reverseBits(n);
    return (n == rev);
}

// if want to find the nth number whose binary representation is a palindrome
// Naive approach: start from 1 and traverse through all the integers
// runtime: O(n)

int findNthPalindrome(int n){
    int pal_count = 0;
    unsigned int i = 0;
    for (i = 1; i <= INT_MAX; i++){
        if (isBinaryPalindrome(i)){
            pal_count++;
        }
        if (pal_count == n){
            break;
        }
    }
    return i;
}

// Given a number N, find the count of numbers from 1 to N whose binary representation is a palindrome.

int countBinaryPalindrome(int n){
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (isPalindrome(i)) {
            count++;
        }
    }
    return count;
}

int main()
{
    unsigned int x = 1 << 15 + 1 << 16;
    cout << isBinaryPalindrome(x) << endl;
    x = 1 << 31 + 1;
    cout << isBinaryPalindrome(x) << endl;

    unsigned int test = 9;
    if (isPalindrome(test)){
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;

    cout << findNthPalindrome(9) << endl;
    cout << countBinaryPalindrome(27) << endl;
    return 0;
}
