#include <iostream>
#include <random>

using namespace std;

// There are few ways to generate random number in range using C/C++
// but some of them are not strictly random (do not generate equally-ikely numbers)
// such as: MIN + ( std::rand() % ( MAX - MIN + 1 ) )
// Here we use C++ to do this job:

int generateRandom(int min, int max){
    random_device rd;
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> dis(min, max);
    return dis(eng);
}

// shuffle the cards iteratively

void shuffleArrayIteractively(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
        int k = generateRandom(0, i);
        int temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

void printArr(vector<int> arr){
    for (auto val : arr){
        cout << val << " ";
    }
    cout << endl;
}

int gen()
{
    static int i = 0;
    return i++;
}

int main()
{
    vector<int> cards(52);
    generate(cards.begin(), cards.end(), gen);
    printArr(cards);
    shuffleArrayIteractively(cards);
    printArr(cards);
    return 0;
}
