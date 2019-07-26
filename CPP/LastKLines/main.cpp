#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void getLastKLines(char* filename, const int K){
    ifstream file (filename);
    string Lines[K];
    int size = 0;

    // read file line by line until an EOF
    while(file.peek() != EOF){
        getline(file, Lines[size % K]);
        size++;
    }

    // get the start (oldest line) and the line count
    int start = size > K ? (size % K) : 0;
    int count = min(size, K);

    for (int i = 0; i < count; i++){
        cout << Lines[(start + i) % K] << endl;
    }
}

int main()
{
    char * name = "/Users/tangjiahui/Desktop/CC/CPP/LastKLines/test.txt";
    getLastKLines(name, 5);
    return 0;
}
