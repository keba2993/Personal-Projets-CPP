// Title: Tic Tac Toe
// Author: Kevin Barone
// Date: 06 Feb. 2021

/* Description: 
 * This program allows the users to play a game of Tic Tac Toe.
 * The board is displayed after every turn and a winner is determined
 * when one user gets three of his/her tokens (Xs or Os) in a row.
*/

#include <iostream>
#include <sstream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

/* This function resets the game elements that need to be reset before next play through.
 * Parameters: board - char array of board elements, plays - bool array to store moves,
 *              numMoves - reference to numMoves in main, winner - reference to winner in main
 * Return: none
*/

void reset (char board[][COLS], bool plays[][COLS], int& numMoves, bool& winner)
{
    numMoves = 0;
    winner = false;
    int num = 1;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            plays[i][j] = false;
            board[i][j] = '0' + num;
            num++;
        }
    }
    cout << endl;
}

/* This function displays the game board after every turn and returns whether a valid move was given.
 * Parameters: board - char array of board elements
 * Return: none
*/

void displayBoard (char board[][COLS])
{
    for (int k = 0; k < ROWS; k++)
    {
        for (int i = 0; i < COLS; i++)
        {
            cout << board[k][i];

            if (i != COLS - 1)
            {
                cout << " | ";
            }
        }

        if (k != ROWS - 1)
        {
            cout << endl << "---------" << endl;
        }
    }

    return;
}

/* This function tests whether a user has played three in a row and therefor wins.
 * Parameters: board - char array of board elements, moves - number of moves played
 * Return: win - tells whether there was a winner or not
*/

bool hasWon (char board[][COLS], int moves)
{
    bool win = false;
    if (board[1][1] == 'X')
    {
        if ((board[0][0] == 'X' && board[2][2] == 'X') || (board[0][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X') || (board[1][0] == 'X' && board[1][2] == 'X'))
        {
            cout << "Player 1 is the winner! Congrats!" << endl;
            win = true;
            displayBoard(board);
        }
        else if ((board[0][0] == 'O' && board[2][0] == 'O' && board[1][0] == 'O') || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'))
        {
            cout << "Player 2 is the winner! Congrats!" << endl;
            win = true;
            displayBoard(board);
        }
        else if (moves == ROWS * COLS)
        {
            cout << "It was a tie! Looks like you are gonne have to play again!" << endl;
            displayBoard(board);
        }
    }
    else
    {
        if ((board[0][0] == 'O' && board[2][2] == 'O') || (board[0][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[2][0] == 'O') || (board[1][0] == 'O' && board[1][2] == 'O'))
        {
            cout << "Player 2 is the winner! Congrats!" << endl;
            win = true;
            displayBoard(board);
        }
        else if ((board[0][0] == 'X' && board[2][0] == 'X' && board[1][0] == 'X') || (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'))
        {
            cout << "Player 1 is the winner! Congrats!" << endl;
            win = true;
            displayBoard(board);
        }
        else if (moves == ROWS * COLS)
        {
            cout << "It was a tie! Looks like you are gonne have to play again!" << endl;
            displayBoard(board);
        }
    }
    return win;
}

int main (int argc, char* argv[])
{
    char gameBoard[ROWS][COLS] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
    bool plays[ROWS][COLS] = { false };

    int player1Move, player2Move;
    bool winner = false;
    char keepPlay = true;
    int numMoves = 0;

    string input = "";

    while (keepPlay)
    {
        cout << "Are you ready to play Tic Tac Toe?" << endl
            << "==================================" << endl << endl;

        while (!winner && numMoves < ROWS * COLS)
        {
            input = "";
            displayBoard(gameBoard);

            if (numMoves % 2 == 0)
            {
                cout << endl << "Player 1: Where do you want to play? (1 - 9) P.S. you are Xs: " << endl;
                getline(cin, input);
                player1Move = stoi(input);

                cout << "You played on section: " << input << endl;

                switch (player1Move)
                {
                    case 1: if (!plays[0][0])
                            {
                                gameBoard[0][0] = 'X';
                                plays[0][0] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 2: if (!plays[0][1])
                            {
                                gameBoard[0][1] = 'X';
                                plays[0][1] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 3: if (!plays[0][2])
                            {
                                gameBoard[0][2] = 'X';
                                plays[0][2] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 4: if (!plays[1][0])
                            {
                                gameBoard[1][0] = 'X';
                                plays[1][0] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 5: if (!plays[1][1])
                            {
                                gameBoard[1][1] = 'X';
                                plays[1][1] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 6: if (!plays[1][2])
                            {
                                gameBoard[1][2] = 'X';
                                plays[1][2] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 7: if (!plays[2][0])
                            {
                                gameBoard[2][0] = 'X';
                                plays[2][0] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 8: if (!plays[2][1])
                            {
                                gameBoard[2][1] = 'X';
                                plays[2][1] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 9: if (!plays[2][2])
                            {
                                gameBoard[2][2] = 'X';
                                plays[2][2] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    default: cout << "Invalid choice .... PLease try again" << endl;
                            numMoves--;
                        break;   
                }
                numMoves++;
            }
            else
            {
                cout << endl << "Player 2: Where do you want to play? (1 - 9) P.S. you are Os: " << endl;
                getline(cin, input);
                player2Move = stoi(input);

                cout << "You played on section: " << input << endl;
                input = "";

                switch (player2Move)
                {
                    case 1: if (!plays[0][0])
                            {
                                gameBoard[0][0] = 'O';
                                plays[0][0] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 2: if (!plays[0][1])
                            {
                                gameBoard[0][1] = 'O';
                                plays[0][1] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 3: if (!plays[0][2])
                            {
                                gameBoard[0][2] = 'O';
                                plays[0][2] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 4: if (!plays[1][0])
                            {
                                gameBoard[1][0] = 'O';
                                plays[1][0] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 5: if (!plays[1][1])
                            {
                                gameBoard[1][1] = 'O';
                                plays[1][1] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 6: if (!plays[1][2])
                            {
                                gameBoard[1][2] = 'O';
                                plays[1][2] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 7: if (!plays[2][0])
                            {
                                gameBoard[2][0] = 'O';
                                plays[2][0] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 8: if (!plays[2][1])
                            {
                                gameBoard[2][1] = 'O';
                                plays[2][1] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    case 9: if (!plays[2][2])
                            {
                                gameBoard[2][2] = 'O';
                                plays[2][2] = true;
                            }
                            else
                            {
                                cout << "Invalid choice: Spot already played in" << endl;
                                numMoves--;
                            }
                        break;
                    default: cout << "Invalid choice .... PLease try again" << endl;
                            numMoves--;
                        break; 
                }
               numMoves++;
            }

            cout << endl << "Press <enter> to continue" << endl;
            getchar();

            for (int l = 0; l < 35; l++)
            {
                cout << endl;
            }

            winner = hasWon(gameBoard, numMoves);
        }

        cout << endl <<  endl << "Would you like to play again? (Y/N)" << endl;
        getline(cin, input);

        if (input != "Y" && input != "y")
        {
            keepPlay = false;
        }

        reset(gameBoard, plays, numMoves, winner);
    }

    return 0;
}