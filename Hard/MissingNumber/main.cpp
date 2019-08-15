#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

// Here since the integers are represented in binary, so we want to create a class BitInteger
// @geeksforgeeks

class BitInteger{
private:
    bool* bits;
public:
    static const int INTEGER_SIZE = 32;

    // default consturctor
    BitInteger(){
        bits = new bool[INTEGER_SIZE];
    }

    // convert a int to BitInteger
    BitInteger(int value){
        bits = new bool[INTEGER_SIZE];

        // (INTEGER_SIZE -1 - j)th bit for all j=0 to INTEGER_SIZE - 1 corresponds
        // to LSB to MSB respectively
        for (int j = 0; j < INTEGER_SIZE; j++){

            if(((value >> j) & 1) == 1){
                bits[INTEGER_SIZE - j - 1] = true;
            } else {
                bits[INTEGER_SIZE - j - 1] = false;
            }
        }
    }

    // convert a string into BitIntegr
    // suppose the string only has '0' or '1'
    BitInteger(string str){
        int len = str.length();
        int x = INTEGER_SIZE - len;
        bits = new bool[INTEGER_SIZE];
        int i = 0;

        for (int j = x; j < INTEGER_SIZE && i < len; j++, i++){
            if (str[i] == '1'){
                bits[j] = true;
            } else {
                bits[j] = false;
            }
        }
    }

    int fetch(int k){
        if (bits[k]) {
            return 1;
        } else {
            return 0;
        }
    }

    void set(int k, int bitValue){
        if (bitValue == 0){
            bits[k] = false;
        } else {
            bits[k] = true;
        }
    }

    int toInt(){
        int n = 0;
        for (int i = 0; i < INTEGER_SIZE; i++){
            n = n << 1;
            if (bits[i]){
                n = n | 1;
            }
        }
        return n;
    }
};

int findMissingNumber(list<BitInteger>& myList, int column){
    if (column < 0){
        return 0;
    }

    list<BitInteger> oddIndices;
    list<BitInteger> evenIndices;

    for (BitInteger t : myList){
        if (t.fetch(column) == 0){
            evenIndices.push_back(t);
        } else {
            oddIndices.push_back(t);
        }
    }

    if (oddIndices.size() >= evenIndices.size()){
        // LSB of the missing number is 0
        // discarding all odd numbers
        return (findMissingNumber(evenIndices, column - 1)) << 1 | 0;
    } else {
        // discarding all even numbers
        return (findMissingNumber(oddIndices, column - 1)) << 1 | 1;
    }
}

int findMissing(list<BitInteger>& myList){
    return findMissingNumber(myList, BitInteger::INTEGER_SIZE - 1);
}

int main()
{
    list<BitInteger> a = { BitInteger("0000"), BitInteger("0001"),
                           BitInteger("0010"), BitInteger("0011"),
                           BitInteger("0100"), BitInteger("0110") };
    int missing1 = findMissing(a);
    cout << missing1 << "\n";

    return 0;
}
