// Title: Hangman
// Author: Kevin Barone
// Date: 16 Feb. 2021

/* Description: 
 * This program allows the user to play a game of Hangman.
 * The computer picks a word at random from a list of random words.
 * The computer then asks the user for an input of letters until 
 * the word is guessed or the player has hung a completed body.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "HangmanStack.h"

using namespace std;

// structure for generated word
struct Word
{
    int length;
    string word;
};

/* This function takes in the user's letter guess and returns the number of times it is in the word.
 * Parameters: genWord - computer's word, guess - user's letter guess, numCorrect - number of correct letters (reference)
 *              letterIndices - array of whether specific letters were guessed
 * Return: numFound - number of times the letter is found in the word
*/

int correctLetter(Word genWord, char guess, int& numCorrect, bool letterIndices[])
{
    int numFound = 0;

    // looping through the word
    for (int i = 0; i < genWord.length; i++)
    {
        if (genWord.word[i] == guess)   // if letter in word matches guess
        {
            numFound++;
            letterIndices[i] = true;    // updating that this letter at this index was found
        }
    }

    numCorrect += numFound;     // updating number of correct guesses
    return numFound;
}

/* This function displays the updated hangman picture after every guess from the user.
 * Parameters: word - the word being guessed, numIncorrect - number of wrong guesses
 *              letterIndices - which letters were guess already
 * Return: none
*/

void displayMan(Word word, int numIncorrect, bool letterIndices[])
{
    // displaying the current state of word guessing
    cout << "Word: ";
    for (int i = 0; i < word.length; ++i)
    {
        if (letterIndices[i])  
        {
            cout << word.word[i] << " ";    // letter of word if it has been guessed
        }
        else
        {
            cout << "_ ";                   // blank if not guessed
        }
    }

    // displaying the top of the hanging pole
    cout << endl << endl;
    cout << "      ------------" << endl;       
    cout << "      |          |" << endl
         << "      |          |" << endl
         << "      |          |" << endl;

    // displaing appropriate number of body parts for man
    switch (numIncorrect)
    {
    case 0: // do nothing
        break;
    case 1:
        cout << "      |          O" << endl;
        break;
    case 2:
        cout << "      |          O" << endl
            << "      |          | " << endl;
        break;
    case 3:
        cout << "      |          O" << endl
            << "      |         \\| " << endl;
        break;
    case 4:
        cout << "      |          O" << endl
            << "      |         \\|/" << endl;
        break;
    case 5:
        cout << "      |          O" << endl
            << "      |         \\|/" << endl
            << "      |          |" << endl;
        break;
    case 6:
        cout << "      |          O" << endl
            << "      |         \\|/" << endl
            << "      |          |" << endl
            << "      |         /  " << endl;
        break;
    case 7:
        cout << "      |          O" << endl
            << "      |         \\|/" << endl
            << "      |          |" << endl
            << "      |         / \\" << endl;
        break;
    default: cerr << "ERROR: invalid number incorrect" << endl;
        break;
    }

    // displaying bottom of the hanging pole
    cout << "      |           " << endl
         << "      |           " << endl
         << "      |           " << endl
         << "------------      " << endl;
}

/* This function generates a random word from the given list of words to be used in the game.
 * Parameters: wordFile - file name that contains list of random words, numLines - number of lines in file
 * Return: word - random word from file to be used for game
*/

Word generateWord(string wordFile, int numLines)
{
    srand(time(NULL));

    ifstream file(wordFile);                // opening file of words
    Word gWord;
    int lineNum = rand() % numLines + 1;

    if (file.is_open())
    {
        // looping through lines until the randomly selected one is reached
        for (int i = 1; i <= lineNum; i++)
        {
            getline(file, gWord.word);
        }

        gWord.length = gWord.word.length();     // capturing word
    }
    else
    {
        // error if file can't be opened
        cerr << "ERROR: invalid file name" << endl;
        gWord.word = "ERROR";
    }

    return gWord;
}

/* This function takes array of user previous guesses and tells them if they have guesssed a letter already
 * Parameters: guesses - array of previous guesses, guess - letter being currently guessed, numGuesses - number of guesses made
 * Return: true or false
*/

bool alreadyGuessed(char guesses[], char guess, int numGuesses)
{
    for (int i = 0; i < numGuesses; ++i)
    {
        if (guesses[i] == guess)        // is letter already guessed
        {
            return true;
        }
    }

    return false;
}

// start of main
int main(int argc, char* argv[])
{
    if (argc == 3)      // ensure correct number of command arguments
    {
        // introduction to game
        string input = "";
        cout << "Welcome to Hangman! Are you ready to play?" << endl;
        getline(cin, input);

        cout << endl;

        if (input == "y" || input == "yes" || input == "Yes" || input == "Y" || input == "YES")
        {
            while (input != "N" && input != "n")
            {
                Word randWord = generateWord(argv[1], stoi(argv[2]));   // generate word from file
                HangmanStack hangStack;                                 // define stack object

                int numCorrectLetters = 0;  // to see if they guess the right word
                int numLettersFound = 0;    // how many times each letter is found
                int numIncorrect = 0;       // how many times user guessed wrong

                char allGuesses[26];                    // implemented so user is not guessing same letters 
                int count = 0;                          // number of quesses made
                bool letterIndices[randWord.length];    // helps to display the word parts

                char letterGuess = '0';     // user's letter guess

                for (int i = 0; i < randWord.length; ++i)   // looping to set all indices to false
                {
                    letterIndices[i] = false;
                }

                if (randWord.word == "ERROR")   // exiting program if file not found
                {
                    return -1;
                }

                // looping until man is fully hung or word is guessed
                while (numCorrectLetters < randWord.length && !hangStack.isFull()) 
                {
                    displayMan(randWord, numIncorrect, letterIndices);    // displaying hangman diagram

                    cout << endl << "Previous Guesses: ";
                    for (int l = 0; l < count; ++l)
                    {
                        cout << allGuesses[l] << " ";
                    }
                    // hangStack.printStack();

                    // asking user for their guess
                    cout << endl << endl << "Guess a lowercase letter: " << endl;
                    getline(cin, input);
                    letterGuess = input[0];

                    allGuesses[count] = letterGuess;

                    // printing a bunch of new lines to push old text out of window
                    for (int i = 0; i < 25; ++i)
                    {
                        cout << endl;
                    }

                    if (letterGuess >= 97 && letterGuess <= 122 && !alreadyGuessed(allGuesses, letterGuess, count))    // ensure that a lowercase letter was inputted
                    {
                        numLettersFound = correctLetter(randWord, letterGuess, numCorrectLetters, letterIndices);   // checking if letter is in word

                        if (numLettersFound > 0)    // letter was found in word
                        {
                            cout << "The letter '" << letterGuess << "' was found " << numLettersFound << " times." << endl;
                            numIncorrect--;                             // each correct guess removes one part of the man

                            if (numIncorrect >= 0)
                            {
                                hangStack.pop();                 // removing part from stack
                            }
                            else
                            {
                                numIncorrect = 0;                // ensuring that numIncorrect >= 0 at all times
                            }
                        }
                        else
                        {
                            cout << "The letter '" << letterGuess << "' was not found." << endl;  // letter not found in the word
                            numIncorrect++;         // adding 1 to number of incorrect guesses

                            // pushing new part onto stack based on number of incorrect guesses
                            switch (numIncorrect)
                            {
                            case 0: // do nothing
                                break;
                            case 1:
                                hangStack.push("O");
                                break;
                            case 2:
                                hangStack.push("|");
                                break;
                            case 3:
                                hangStack.push("\\");
                                break;
                            case 4:
                                hangStack.push("/");
                                break;
                            case 5:
                                hangStack.push("|");
                                break;
                            case 6:
                                hangStack.push("/");
                                break;
                            case 7:
                                hangStack.push("\\");
                                break;
                            default:
                                cerr << "ERROR: invalid number incorrect" << endl;  // should never be displayed
                                break;
                            }
                        }
                        count++;
                    }
                    else
                    {
                        // error meesage when lowercase letter isn't inputted
                        cerr << "ERROR: invalid guess" << endl;
                    }
                }

                // deciding whether the user has guessed the word or not - displaying win or loss
                if (numCorrectLetters == randWord.length)
                {
                    cout << "Congrajulations! You correctly guessed the word '" << randWord.word << "'." << endl;
                }
                else
                {
                    cout << "Sorry but you have hung the man! The word was '" << randWord.word << "'." << endl;
                }

                // asking user if they want to play again
                cout << endl << "Would you like to play again? (Y/N)" << endl;            
                getline(cin, input);
            } 
        }
        else
        {
            cout << "I just wanted to play :'(" << endl;    // sad times
        }

    }
    else
    {
        // error message if user fails to provide file of random words
        cerr << "ERROR: provide a file name with command line" << endl;
    }

    return 0;
}