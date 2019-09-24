#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// given a string 'str' of digits, find the length of the longest substring of 'str',
// such that the length of the substring is 2k digits and sum of left k digits is equal
// to the sum of right k digits

// simple solution: O(N^3) brute force

int findLongestEvenSubstring(char* str){
    int n = strlen(str);

    int maxLen = 0;

    // check all the substring
    // choose starting point of every substring
    for (int i = 0; i < n; i++){
        // choose ending point pf even length substring
        for (int j = i + 1; j < n; j += 2){
            int length = j - i + 1;
            int leftSum = 0;
            int rightSum = 0;

            for (int k = 0; k < length/2; k++){
                leftSum += (str[i+k] - '0');
                rightSum += (str[i+k+length/2] - '0');
            }

            if (leftSum == rightSum && maxLen < length){
                maxLen = length;
            }
        }
    }
    return maxLen;
}

// optimal solution using Dynamic Programming - O(N^2) runtime + O(N^2) extra space
// build a 2D table where sum[i][j] stores sum of digits from str[i] to str[j].

int findLongestEvenSubstringOptimal(char* str){
    int n = strlen(str);

    int maxLen = 0;

    // only filled entries are the entries where j >= i
    int sum[n][n];

    // fill the diagonal values for substrings of length 1
    for (int i = 0; i < n; i++){
        sum[i][i] = str[i] - '0';
    }

    // fill entries for substring of length 2 to n
    for (int len = 2; len <= n; len++){
        for (int i = 0; i < n - len + 1; i++){
            int j = i + len - 1;
            int k = len /2;

            // calculate value of sum[i][j]
            sum[i][j] = sum[i][j- k] + sum[j-k+1][j];

            if (len %2 == 0 && sum[i][j-k] == sum[j-k+1][j] && len > maxLen){
                maxLen = len;
            }
        }
    }
    return maxLen;
}

// optimal solution - O(N^2) + O(1) extra space
// consider all possible mid points (of even length substrings) and keep expanding
// on both sides to get and update optimal length

int findLongestEvenSubstringOptimal2(string str, int n){
    int maxLen = 0;

    for (int i = 0; i <= n - 2; i++){
        int left = i;
        int right = i + 1;

        int leftSum = 0;
        int rightSum = 0;

        while(right < n && left >= 0){
            leftSum += str[left] - '0';
            rightSum += str[right] - '0';

            if (leftSum == rightSum){
                maxLen = max(maxLen, right - left + 1);
            }
            left--;
            right++;
        }
    }
    return maxLen;
}


int main()
{
    char str[] = "153803";
    // "5380" - 4
    cout << "Length of the substring is " << findLongestEvenSubstring(str) << endl;
    cout << "Length of the substring is " << findLongestEvenSubstringOptimal(str) << endl;
    string str2 = "123123";
    cout << "Length of the substring is " << findLongestEvenSubstringOptimal2(str2, str2.size()) << endl;
    return 0;
}
