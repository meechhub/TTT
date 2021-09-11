#include <iostream>
#include "ttt.hpp"

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void intro(){

    std::cout << "Press [Enter] to begin!";
    std::cin.ignore();

    std::cout << "\n";

    std::cout << "============\n";
    std::cout << "Tic\n";
    std::cout << "   Tac\n";
    std::cout << "       Toe\n";
    std::cout << "============\n";
    std::cout << "The object of this TWO player game is to connect your symbol ";
    std::cout << "three times in a row in any direction.\n";
    std::cout << "\n";

    std::cout << "PLAYER 1: ✘\n";
    std::cout << "PLAYER 2: ⦿\n";

    std::cout << "Here is the grid: \n";

    std::cout << "       |       |       \n";
    std::cout << "   1   |   2   |   3   \n";
    std::cout << " _____ | _____ | _____ \n";
    std::cout << "       |       |       \n";
    std::cout << "   4   |   5   |   6   \n";
    std::cout << " _____ | _____ | _____ \n";
    std::cout << "       |       |       \n";
    std::cout << "   7   |   8   |   9   \n";
    std::cout << "       |       |       \n";


}

bool is_winner(){
    bool winner = false;

    //rows
    if((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " "){
        winner = true;
    }
    else if((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " "){
        winner = true;
    }
    else if((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " "){
        winner = true;
    }

    //columns
    else if((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " "){
        winner = true;
    }
    else if((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " "){
        winner = true;
    }
    else if((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " "){
        winner = true;
    }

    //diagonal
    else if((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " "){
        winner = true;
    }
    else if((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " "){
        winner = true;
    }
    return winner;
}

bool filled(){
    bool filled = true;

    for(int i = 0; i < 9; i++){
        if(board[i] == " "){
            filled = false;
        }
    }
    return filled;
}

void draw_board(){
    std::cout << "       |       |       \n";
    std::cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   \n";
    std::cout << " _____ | _____ | _____ \n";
    std::cout << "       |       |       \n";
    std::cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   \n";
    std::cout << " _____ | _____ | _____ \n";
    std::cout << "       |       |       \n";
    std::cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   \n";
    std::cout << "       |       |       \n";

    std::cout << "\n";
}

void input_position(){
    std::cout << "PLAYER " << player << "'s turn (Enter number 1-9): ";
    std::cin >> position;
    std::cout << "\n";

    while(board[position -1] != " "){
        std::cout << "This space is occupied!\n";

        std::cout << "PLAYER " << player << " turn (Enter number 1-9): ";
        std::cin >> position;
        std::cout << "\n";
    }
}

void update_board(){
    if(player % 2 == 1){
        board[position - 1] = "✘";
    }
    else{
        board[position - 1] = "⦿";
    }
}

void change_player(){
    if(player == 1){
        player++;
    }
    else{
        player--;
    }
}

void take_turn(){
    while(!is_winner() && !filled()){
        input_position();
        update_board();
        change_player();
        draw_board();
    }
}

void end_game(){
    if(is_winner()){
        std::cout << "There is a winner :D\n";
    }
    else if(filled()){
        std::cout << "Looks like a draw :(\n";
    }
}
