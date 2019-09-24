#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// given a fraction, find recurring sequence of digits if exists,
// otherwise print "No recurring sequence".

// solution:
// how to covert fraction to decimal:
// The integer part is floor (numerator/denominator)
// then we left with (remainder = numerator%denominator)/denominator
// then at each step we do followings to convert to decimal
// 1. multiple the remainder by 10
// 2. append remainder / denominator to result
// 3. Remainder = remainder % denominator

// if remainder becomes 0, then there is no recurring sequence.

// we can use a map to store seen remainders. Whenever a remainder repeats,
// return the sequence before the next occurence.

string simpleFraction(int numerator, int denominator){
    // store the result
    string res;

    map<int, int> mp;
    mp.clear();

    // get the first remainder
    int remainder = numerator%denominator;

    // if remainder is 0, then no recurring sequence
    // if remainder repeats, then return
    while((remainder!=0) && (mp.find(remainder) == mp.end())){
        // store the remainder
        mp[remainder] = res.length();

        remainder = remainder*10;
        int res_part = remainder/denominator;
        res += to_string(res_part);

        remainder = remainder % denominator;
    }

    return (remainder == 0) ? "" : res.substr(mp[remainder]);
}

int main()
{
    int numerator = 50, denominator = 22;
    string res = simpleFraction(numerator, denominator);
    if (res == ""){
        cout << "No recurring sequence";
    } else {
        cout << "Recurring sequence is " << res;
    }
    return 0;
}
