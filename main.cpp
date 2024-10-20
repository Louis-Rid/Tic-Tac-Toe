/**
 * This C++ program implements a simple Tic-Tac-Toe game. 
 * It includes functions for initializing and displaying the game board, 
 * validating user input, updating the board based on player actions, and 
 * checking for win conditions. The main function controls the game flow, 
 * switching turns and determining the winner.
 */

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

/**
 * Initializes a blank Tic-Tac-Toe board for the start of the game.
 *
 * @return A 2D array representing the game board with empty spaces.
 */
string** initializeBoard()
{
    string** boardValues = new string*[3];
    for (int i = 0; i < 3; i++) {
        boardValues[i] = new string[3];
        for (int j = 0; j < 3; j++) {
            boardValues[i][j] = " ";
        }
    }
    return boardValues;
}

/**
 * Displays the current state of the Tic-Tac-Toe board.
 *
 * @param values A 2D array representing the game board.
 */
void displayBoard(string** values)
{
    cout << "            " << endl;
    cout << "   " << values[0][0] << "  |  " << values[0][1] << "  |  " << values[0][2] << endl;
    cout << "   1  |  2  |  3" << endl;
    cout << "   ______________" << endl;
    cout << endl;
    cout << "   " << values[1][0] << "  |  " << values[1][1] << "  |  " << values[1][2] << endl;
    cout << "   4  |  5  |  6" << endl;
    cout << "   ______________" << endl;
    cout << endl;
    cout << "   " << values[2][0] << "  |  " << values[2][1] << "  |  " << values[2][2] << endl;
    cout << "   7  |  8  |  9" << endl;
    cout << endl;
}

/**
 * Updates the Tic-Tac-Toe board based on the player's input and character.
 *
 * @param values A 2D array representing the game board.
 * @param input The player's chosen position (1-9).
 * @param character The player's symbol ("X" or "O").
 * @return Updated game board.
 */
string** updateBoard(string** values, int input, string character)
{
    switch (input) {
        case 1: values[0][0] = character; break;
        case 2: values[0][1] = character; break;
        case 3: values[0][2] = character; break;
        case 4: values[1][0] = character; break;
        case 5: values[1][1] = character; break;
        case 6: values[1][2] = character; break;
        case 7: values[2][0] = character; break;
        case 8: values[2][1] = character; break;
        case 9: values[2][2] = character; break;
    }

    return values;
}

/**
 * Checks if a win condition is met on the Tic-Tac-Toe board.
 *
 * @param board A 2D array representing the game board.
 * @return True if a player has won, otherwise false.
 */
bool checkIfWon(string** board)
{
    if (board[0][0] != " " && board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return true;
    else if (board[1][0] != " " && board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return true;
    else if (board[2][0] != " " && board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return true;
    else if (board[0][0] != " " && board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return true;
    else if (board[0][1] != " " && board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return true;
    else if (board[0][2] != " " && board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return true;
    else if (board[0][0] != " " && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    else if (board[0][2] != " " && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    else
        return false;
}

/**
 * Validates the user's input to ensure it corresponds to an empty position on the board.
 *
 * @param board A 2D array representing the game board.
 * @return A valid position input from the user.
 */
int validateInput(string** board)
{
    bool isValid = false;
    int validatedInput;
    string curBoardLocation;
    do {
        cout << "   Please enter a valid input that is a whole number (1-9):" << endl;
        cin >> validatedInput;
        cin.clear();
        cin.ignore(numeric_limits
