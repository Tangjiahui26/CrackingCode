#include <iostream>
#include <algorithm>

using namespace std;

// @github: oskargustafsson

int number_solutions = 0;

// board structure
template<int S>
struct Board {
    int squares[S * S] = { 0 };
    int & operator() (int x, int y) {
        return squares[S * y + x];
    }

    void print() {
        for (int i = 0; i < S * S; i++){
            int val = squares[i];
            if (val == -1){
                cout << "Q ";
            } else {
                cout << ". ";
            }

            if (i % S == S - 1) {
                cout << endl;
            }
        }
        cout << endl;
    }
};

template <int S>
void buildBoard(Board<S>& board, int x, int y, int delta){
    board(x, y) += delta * -1;
    for (int i = 1; y + i < S; i++){
        // same column
        board(x, y + i) += delta;
        // diagonal
        if (x - i >= 0){
            board(x - i, y + i) += delta;
        }

        if (x + i < S){
            board(x + i, y + i) += delta;
        }
    }
}

template<int S>

void eightQueens(Board<S>& board, int y){
    for (int x = 0; x < S; x++){
        if (board(x, y) != 0){
            continue;
        }

        buildBoard(board, x, y, 1);
        if (y == S - 1){
            cout << number_solutions++ << endl;
            board.print();
        } else {
            eightQueens(board, y + 1);
        }
        buildBoard(board, x, y, -1);
    }
}

int main()
{
    Board<8> board;
    eightQueens(board,0);
    return 0;
}
