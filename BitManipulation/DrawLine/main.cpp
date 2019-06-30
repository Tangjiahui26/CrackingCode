#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

// Using the implementation of @oskargustafsson

template<typename T>
void printBits(T val, bool add_newline = false){
    bitset<8 * sizeof(T)> bits(*reinterpret_cast<unsigned long*>(&val));
    cout << bits;
    if (add_newline){
        cout << endl;
    }
}

void drawLine(char * bytes, int width, int x1, int x2, int y){
    int byte_width = width / 8;
    int offset = y * byte_width + x1 /8;
    int n_bits_to_set = x2 - x1;

    int leading_bits_to_set = min(8 - (x1 % 8), n_bits_to_set);
    bytes[offset] = (1 << leading_bits_to_set) - 1;

    n_bits_to_set -= leading_bits_to_set;

    if (n_bits_to_set == 0){
        bytes[offset] << (8 - (x1 % 8) - (x2 - x1));
    }

    offset++;

    while(n_bits_to_set > 0){
        bytes[offset++] = n_bits_to_set > 7 ? 0b11111111 : (((1<< n_bits_to_set) - 1) << (8 - n_bits_to_set));
        n_bits_to_set -= 8;
    }
}

int main()
{
    constexpr int screen_width = 32;
    constexpr int screen_height = 8;
    constexpr int n_screen_bytes = screen_width * screen_height / 8;
    char bytes[n_screen_bytes] = {0};
    drawLine(bytes, screen_width, 3, 27, 3);
    for(int i = 0; i < n_screen_bytes; i++){
        printBits(bytes[i], ((i + 1) % 4) == 0);
    }
    return 0;
}
