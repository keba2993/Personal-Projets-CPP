// This is the implementation of the HangmanStack class
// Author: Kevin Barone
// Date: 13 Mar. 2021

/* Description: 
 * This program defines and sets up the stack class to be used in the Hangman game.
 * It is a stack implemented as a linked list and with have the basic  stack functions
*/

#include "HangmanStack.h"

HangmanStack::HangmanStack()             // constructor with no parameters
{
    top = nullptr;
    capacity = DEFAULT_SIZE;
    size = 0;
}
HangmanStack::HangmanStack(int cap)      // constructor with defined capacity
{
    top = nullptr;
    capacity = cap;
    size = 0;
}
HangmanStack::~HangmanStack()            // destructor to free memory
{
    PartNode* tmp = top;

    while (top != nullptr)
    {
        top = top->next;
        delete tmp;
        tmp = top;
    }
}

string HangmanStack::peek()          // returns the top element of the stack
{
    if (isEmpty())
    {
        cerr << "ERROR: stack is empty. can not peek" << endl;
        return "";
    }

    return top->part;
}
void HangmanStack::pop()            // pops off the top element of the stack
{
    if (isEmpty())
    {
        cerr << "ERROR: stack is empty. can not pop" << endl;
        return;
    }

    PartNode* tmp = top;
    top = top->next;
    delete tmp;
    tmp = nullptr;

    size--;
}
void HangmanStack::push(string part) // pushes element onto the stack
{
    if (isFull())
    {
        cerr << "ERROR: stack is full. can not push" << endl;
        return;
    }

    PartNode* newNode = new PartNode;
    newNode->next = top;
    newNode->part = part;

    top = newNode;
    size++;
}

bool HangmanStack::isEmpty() // true when the stack is empty
{
    return (size == 0);
}
bool HangmanStack::isFull() // true when stack if full
{
    return (size == capacity);
}

void HangmanStack::printStack() // prints the contents of the stack
{
    int stackPart = 0;
    PartNode* tmp = top;

    while (tmp != nullptr)
    {
        cout << "Stack Part " << stackPart << ": " << tmp->part << endl;

        tmp = tmp->next;
        stackPart++;
    }
}