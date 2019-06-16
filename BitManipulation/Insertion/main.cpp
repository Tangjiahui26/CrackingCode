#include <iostream>

using namespace std;

int updateBits(int n, int m, int i, int j){
    int allOnes = ~0;

    int right = allOnes << (j+1);
    int left = (1 << i) - 1;

    int mask = right | left;

    int n_cleared = n & mask;
    int m_shifted = m << i;

    return n_cleared | m_shifted;
}

int main()
{
    int n = 1024;
    int m = 19;
    int i = 2;
    int j = 6;

    int result = updateBits(n, m, i, j);

    // output should be 1100
    cout << "Output is: " << result << endl;

    return 0;
}
