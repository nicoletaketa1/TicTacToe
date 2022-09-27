//Tic Tac Toe Game in C++

//Importing the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
using namespace std;
//3x3 array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
// global variables
int box, row, column;
char turn = 'X';
bool draw = false;

void reset_board(){
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
}


//display next move

void display_board(){

    cout<<"PLAYER 1 [X]\t PLAYER 2 [O]\n\n";
    cout<<"\t      * * * * * * * * * * * * *\n";
    cout<<"\t      *       |      |        *\n";
    cout<<"\t      *    "<<board[0][0]<<"  |  "<<board[0][1]<<"   |  "<<board[0][2]<<"     *\n";
    cout<<"\t      *  _____|______|_____   *\n";
    cout<<"\t      *       |      |        *\n";
    cout<<"\t      *    "<<board[1][0]<<"  |  "<<board[1][1]<<"   |  "<<board[1][2]<<"     *\n";
    cout<<"\t      *  _____|______|_____   *\n";
    cout<<"\t      *       |      |        *\n";
    cout<<"\t      *    "<<board[2][0]<<"  |  "<<board[2][1]<<"   |  "<<board[2][2]<<"     *\n";
    cout<<"\t      *       |      |        *\n";
    cout<<"\t      * * * * * * * * * * * * *\n";
}

//get next move and update board

void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer 2 [O] turn : ";
    }

    cin >> box;

    //switch case to get which row and column will be updated

    switch(box){
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!\n Please choose another!!\n\n";
        player_turn();
    }
    /* Ends */
    display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    bool play_again = true;
    while(play_again) {
        cout << "\t        T I C  -- T A C -- T O E \t\t\t";
        cout << "\n\t\t      2 PLAYERS\n\t    ";
        while (gameover()) {
            display_board();
            player_turn();
            gameover();
        }
        if (turn == 'X' && draw == false) {
            cout << "\n\nCongratulations! Player 2 won the game";
        } else if (turn == 'O' && draw == false) {
            cout << "\n\nCongratulations! Player 1 won the game";
        } else
            cout << "\n\nIT'S A DRAW!\n\n";

        cout << "Would you like to play again? Yes [1]  No [2]:\n ";
        int again;
        cin >> again;
        if (again == 1) {
            play_again = true;
            draw = false;
            reset_board();
            turn = 'X';
        }
        else if (again == 2) play_again = false;

    }
} 