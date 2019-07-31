#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

#define COMPUTER 1
#define HUMAN 2
#define BOARDSIZE 3

#define COMPUTERLABEL 'O'
#define HUMANLABEL 'X'

// Here, instead, I implemented a tic-tac-toe game (3X3)
// So, to know the winner, I am using the hard coded checker

void showBoard(char board[][BOARDSIZE]){
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

}

void showInstructions(){
    printf("\t\t Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below and play \n\n");
    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");

}

void initialize(char board[][BOARDSIZE], int moves[]){
    srand(time(NULL));

    for (int i = 0; i < BOARDSIZE; i++){
        for (int j = 0; j < BOARDSIZE; j++) {
            board[i][j] = ' ';
        }
    }

    for (int i = 0; i < BOARDSIZE*BOARDSIZE; i++){
        moves[i] = i;
    }

    // shuffle the moves
    random_shuffle(moves, moves+BOARDSIZE*BOARDSIZE);
}

bool rowChecker(char board[][BOARDSIZE]){
    for (int i = 0; i < BOARDSIZE; i++){
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
                board[i][0] != ' '){
            return true;
        }
    }
    return false;
}

bool columnChecker(char board[][BOARDSIZE]){
    for (int i = 0; i < BOARDSIZE; i++){
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
                board[0][i] != ' '){
            return true;
        }
    }
    return false;
}

bool diagonalChecker(char board[][BOARDSIZE]){
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
            board[0][0] != ' '){
        return true;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
            board[0][2] != ' '){
        return true;
    }
    return false;
}

void declareWinner(int whoseTurn){
    if (whoseTurn == COMPUTER){
        printf("COMPUTER has won\n");
    } else {
        printf("HUMAN has won\n");
    }
}

bool gameOver(char board[][BOARDSIZE]){
    return (rowChecker(board) || columnChecker(board) ||
            diagonalChecker(board));
}

void playTicTacToe(int whoseTurn){
    char board[BOARDSIZE][BOARDSIZE];
    int moves[BOARDSIZE*BOARDSIZE];

    initialize(board, moves);
    showInstructions();

    int moveIndex = 0, x, y;

    while(gameOver(board) == false && moveIndex != BOARDSIZE*BOARDSIZE){
        if (whoseTurn == COMPUTER){
            x = moves[moveIndex] / BOARDSIZE;
            y = moves[moveIndex] % BOARDSIZE;
            board[x][y] = COMPUTERLABEL;
            printf("COMPUTER has put a %c in cell %d\n", COMPUTERLABEL, moves[moveIndex]+1);
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        } else if (whoseTurn == HUMAN){
            x = moves[moveIndex] / BOARDSIZE;
            y = moves[moveIndex] % BOARDSIZE;
            board[x][y] = HUMANLABEL;
            printf("HUMAN has put a %c in cell %d\n", HUMANLABEL, moves[moveIndex]+1);
            showBoard(board);
            moveIndex++;
            whoseTurn = COMPUTER;
        }
    }

    if (gameOver(board) == false && moveIndex == BOARDSIZE*BOARDSIZE){
        printf("It's a draw\n");
    } else {
        if (whoseTurn == COMPUTER){
            whoseTurn = HUMAN;
        } else if (whoseTurn == HUMAN){
            whoseTurn = COMPUTER;
        }
    }

    declareWinner(whoseTurn);
}

int main()
{
    playTicTacToe(COMPUTER);
    return 0;
}
