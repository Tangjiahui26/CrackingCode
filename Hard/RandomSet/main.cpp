#include <iostream>
#include <random>
#include <vector>

using namespace std;

// similar to question(shuffle), here we need a generator to get random numbers in range

int generateRandom(int min, int max){
    random_device rd;
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> dis(min, max);
    return dis(eng);
}

vector<int> getRandomSet(vector<int> arr, int m){
    vector<int> res(m);
    for(int i = 0; i < m; i++){
        res[i] = arr[i];
    }

    for(int i = m; i < arr.size(); i++){
        int k = generateRandom(0, i);
        if (k < m){
            res[k] = arr[i];
        }
    }
    return res;
}

int main()
{
    vector<int> test = {1, 2, 3, 4, 5, 6};
    vector<int> res = getRandomSet(test, 3);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
