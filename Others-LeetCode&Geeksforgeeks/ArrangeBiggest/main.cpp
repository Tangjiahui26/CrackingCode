#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Given an array of numbers, arrange them in a way that yields
// the largest value.

// For example, if the given numbers are {54, 546, 548, 60}, the
// arrangement 6054854654 gives the largest value.

// solution: comparison based sorting

int myCompare(string X, string Y){
    string XY = X.append(Y);
    string YX = Y.append(X);

    return XY.compare(YX) > 0 ? 1 : 0;
}

void printArrangeBiggest(vector<string> arr){
    sort(arr.begin(), arr.end(), myCompare);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i];
    }
}

int main()
{
    // here we used vector<string> for simplification
    vector<string> arr;
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    printArrangeBiggest(arr);
    return 0;
}
