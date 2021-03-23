// This is the header file for the Hangman Stack
// Author: Kevin Barone
// Date: 13 Mar. 2021

/* Description: 
 * This program defines and sets up the stack class to be used in the Hangman game.
 * It is a stack implemented as a linked list and with have the basic  stack functions
*/

#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define DEFAULT_SIZE 7

// defining the node structure for the stack to be implemented as a linked list
struct PartNode
{
    string part;
    PartNode* next;
};

class HangmanStack
{
    private:
        PartNode* top;  // pointer to top of the stack
        int capacity;   // capacity of stack - max number of body parts
        int size;       // number of parts in stack currently
    
    public:
        HangmanStack();             // constructor with no parameters
        HangmanStack(int cap);      // constructor with defined capacity
        ~HangmanStack();            // destructor to free memory

        string peek();              // returns the top element of the stack
        void pop();                 // pops off the top element of the stack
        void push(string part);     // pushes element onto the stack

        bool isEmpty();             // true when the stack is empty
        bool isFull();              // true when stack if full

        void printStack();          // prints the contents of the stack
        int getstackSize() { return size; }     // returns size of stack

};
