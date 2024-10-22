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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (validatedInput >= 1 && validatedInput <= 9)
        {
            switch (validatedInput) {
                case 1: curBoardLocation = board[0][0]; break;
                case 2: curBoardLocation = board[0][1]; break;
                case 3: curBoardLocation = board[0][2]; break;
                case 4: curBoardLocation = board[1][0]; break;
                case 5: curBoardLocation = board[1][1]; break;
                case 6: curBoardLocation = board[1][2]; break;
                case 7: curBoardLocation = board[2][0]; break;
                case 8: curBoardLocation = board[2][1]; break;
                case 9: curBoardLocation = board[2][2]; break;
            }

            if (curBoardLocation == " ") {
                isValid = true;
                return floor(validatedInput);
            } else {
                cout << "Input Error: ";
            }
        } else {
            cout << "Input Error: ";
        }

    } while (!isValid);
    
    return 0;
}

/**
 * The main function that controls the game flow from start to finish.
 * 
 * @return Exit status of the program.
 */
int main()
{
    cout << "Game started!" << endl;
    string** board = initializeBoard();
    displayBoard(board);
    int turnCount = 0;
    int curPlayersTurn = 2;
    bool hasWon = false;

    while (turnCount < 9 && !hasWon) {
        curPlayersTurn = curPlayersTurn == 1 ? 2 : 1;
        cout << "   It is player " << curPlayersTurn << " turn!" << endl;
        
        int position = validateInput(board);
        
        turnCount++;
        updateBoard(board, position, curPlayersTurn == 1 ? "O" : "X");
        
        displayBoard(board);
        hasWon = checkIfWon(board);
    }

    if (hasWon) cout << "Player " << curPlayersTurn << " has won!" << endl;
    else cout << "No more spaces are available." << endl;

    return 0;
}
