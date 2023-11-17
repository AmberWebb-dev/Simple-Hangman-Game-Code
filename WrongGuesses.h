//-----------------------------------------------------------------------------------------------
//Program name:  HangmanGame.cpp
//Author:  Amber Webb
//Date:  12/01/2022
//Input:  requests input from user
//Output:  displays output on the console
//Description:  This program simulates the two-player game "Hangman"
//-----------------------------------------------------------------------------------------------

#ifndef WrongGuesses_h
#define WrongGuesses_h
#include <iostream>
#include "Hangman.hpp"

using namespace std;

//****************************************************************************************************


enum Man {BEGIN = 0, PLATFORM, HEAD, BODY, LEFT_ARM, RIGHT_ARM, LEFT_LEG, RIGHT_LEG, HUNG};

//****************************************************************************************************

struct IncorrectLetters {
    char incGuesses;
    IncorrectLetters *next;
};

//****************************************************************************************************

//function to put the incorrect guesses characters into the linked list
//PRE: letter entered is incorrect
//POST: incorrect value is entered into the list
void addLetter (IncorrectLetters **head, char incNew);

//function to print the incorrect guessed letters
//PRE: NONE
//POST: values are printed to console
void printIncLetters (IncorrectLetters *inc);

//function to delete the linked list
//PRE: NONE
//POST: the linked list is emptied
void deleteGuess (IncorrectLetters **h);

//function to return the state of the enum
//PRE: variable currentState is filled
//POST: corresponding string is outputted to screen
void CurrentState (Man currentState);

//****************************************************************************************************

void addLetter (IncorrectLetters **head, char incNew){
    IncorrectLetters *newNode = new IncorrectLetters;
    newNode->incGuesses = incNew;
    newNode->next = *head;
    *head = newNode;
}

//****************************************************************************************************

void printIncLetters (IncorrectLetters *inc){
    while (inc != NULL) {
        cout << inc->incGuesses << ' ';
        inc = inc->next;
    }
}

//****************************************************************************************************

void deleteGuess (IncorrectLetters **h){

    IncorrectLetters *curr = *h;
    IncorrectLetters *next = NULL;

    while (curr != NULL){
        next = curr->next;
        delete curr;
        curr = next;
    }
    *h = NULL;
}

//****************************************************************************************************

void CurrentState (Man currentState) {
    
    switch (currentState) {
        case BEGIN:
            break;
        case PLATFORM:
            cout << "\n\t\tPLATFORM" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "         | " << endl;
            cout << "         | " << endl;
            cout << "         | " << endl;
            cout << "         | " << endl;
            cout << "  _______|______" << endl;
            break;
        case HEAD:
            cout << "\n\t\tHEAD" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "      O  | " << endl;
            cout << "         | " << endl;
            cout << "         | " << endl;
            cout << "         | " << endl;
            cout << "  _______|______" << endl;
            break;
        case BODY:
            cout << "\n\t\tBODY" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "      O  | " << endl;
            cout << "      |  | " << endl;
            cout << "      |  | " << endl;
            cout << "         | " << endl;
            cout << "  _______|______" << endl;
            break;
        case LEFT_ARM:
            cout << "\n\t\tLEFT ARM" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "      O  | " << endl;
            cout << "     /|  | " << endl;
            cout << "      |  | " << endl;
            cout << "         | " << endl;
            cout << "  _______|______" << endl;
            break;
        case RIGHT_ARM:
            cout << "\n\t\tRIGHT ARM" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "      O  | " << endl;
            cout << "     /|L | " << endl;
            cout << "      |  | " << endl;
            cout << "         | " << endl;
            cout << "  _______|______" << endl;
            break;
        case LEFT_LEG:
            cout << "\n\t\tLEFT LEG" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "      O  | " << endl;
            cout << "     /|L | " << endl;
            cout << "      |  | " << endl;
            cout << "     /   | " << endl;
            cout << "  _______|______" << endl;
            break;
        case RIGHT_LEG:
            cout << "\n\t\tRIGHT LEG" << endl;
            cout << "   _______ " << endl;
            cout << "         | " << endl;
            cout << "      O  | " << endl;
            cout << "     /|L | " << endl;
            cout << "      |  | " << endl;
            cout << "     / / | " << endl;
            cout << "  _______|______" << endl;
            break;
        case HUNG:
            cout << "\n\t\tHUNG" << endl;
            cout << "   _______ " << endl;
            cout << "      |  | " << endl;
            cout << "      O  | " << endl;
            cout << "     /|L | " << endl;
            cout << "      |  | " << endl;
            cout << "     / / | " << endl;
            cout << "  _______|______" << endl;
            break;
            
    }
}

//****************************************************************************************************

#endif /* WrongGuesses_h */
