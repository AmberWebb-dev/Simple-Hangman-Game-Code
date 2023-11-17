//-----------------------------------------------------------------------------------------------
//Program name:  HangmanGame.cpp
//Author:  Amber Webb
//Date:  12/01/2022
//Input:  requests input from user
//Output:  displays output on the console
//Description:  This program simulates the two-player game "Hangman"
//-----------------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include "Hangman.hpp"
#include "WrongGuesses.h"

using namespace std;

int main() {
    
//************************************************************************************************************

    while (1) {
        Man currentState = BEGIN;
        IncorrectLetters *head = NULL;
        string word, corrGuess;
        char guess;
        Game *newLetter, *first, *last, *current;
        first = nullptr;
        last = nullptr;
        long answerCount = 0;
        int corrAns = 0;
        int wrongChar = 0;
        int corrGuessCount = 0;
        
//************************************************************************************************************

        cout << "\n\n\t\t____________________________________" << endl;
        cout << "\t\t|                                  |" << endl;
        cout << "\t\t|          HANGMAN GAME            |" << endl;
        cout << "\t\t|                                  |" << endl;
        cout << "\t\t|__________________________________|\n\n\n" << endl;

        cout << "\tPLAYER 1:\nPLEASE ENTER A WORD OR 'QUIT' TO EXIT GAME AND HIT ENTER KEY (USE ALL CAPS!): ";
        cin >> word;
        if (word == "QUIT") {
            break;
        }
        for (int i = 0; i < word.size(); i++) {
            char(word[i]);
            newLetter = new Game;
            newLetter->setNext(NULL);
            newLetter->setWord(word[i]);
            
            if (first == NULL) {
                first = newLetter;
                last = newLetter;
            } else {
                last->setNext(newLetter);
                last = newLetter;
            }
        }
        current = first;
        while (current != NULL) {
            current = current->getNext();
        }
        
//************************************************************************************************************

        // clear function does not work on mac T_T
        for (int clr = 0; clr < 10; clr++){
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        }
        
//************************************************************************************************************

        cout << "\t\tHANGMAN GAME START!\n\n" << endl;
        for (int m = 0; m < word.size(); m++){
            corrGuess[m] = '_';
        }
        
//************************************************************************************************************

        do {
            if (corrAns == word.size()) {
                cout << "\n\t\t|---------------|" << endl;
                cout << "\t\t|\tYOU WIN!!\t|" << endl;
                cout << "\t\t|---------------|" << endl;
                cout << "\n\nThe word was: ";
                for (int w = 0; w < word.size(); w++){
                    cout << corrGuess[w] << ' ';
                }
                cout << "\n\nIncorrect letters used: ";
                printIncLetters(head);
                break;
            }
            if (currentState == HUNG) {
                cout << "\n\t\t|---------------|" << endl;
                cout << "\t\t|\tYOU LOSE!\t|" << endl;
                cout << "\t\t|---------------|" << endl;
                
                cout << "\n\tThe Word was: " << word << endl;
                
                cout << "\n\nIncorrect Letters used: ";
                printIncLetters(head);
                break;
            }
            cout << "\n\t\t";
            for (int i = 0; i < word.size(); i++){
                cout << corrGuess[i] << ' ';
            }
            cout << endl;
            
            cout << "\n\tPLAYER 2:\nENTER LETTER TO GUESS AND HIT ENTER KEY (PLEASE MAKE SURE TO USE ALL CAPS!: ";
            cin >> guess;
            
            if (guess == '@') {
                cout << "QUITTING...." << endl;
                break;
            }
            
            answerCount = count(word.begin(), word.end(), guess);
            if (answerCount == 0) {
                addLetter(&head, guess);
                cout << "\nIncorrect letters used: ";
                printIncLetters(head);
                cout << endl;
                wrongChar++;
                currentState = Man(int(currentState) + 1);
                CurrentState(currentState);
                
            } else if (answerCount > 0){
                for (int c = 0; c < word.size(); c++){
                    if (word[c] == guess) {
                        corrGuessCount = c;
                        corrGuess[corrGuessCount] = guess;
                    }
                }
                corrAns = corrAns + int(answerCount);
            } else {
                cout << "\nSomething Wrong Here!" << endl;
            }
        } while (guess != '@');
        
//************************************************************************************************************

        cout << "\n\n|---------------------|" << endl;
        cout << "| " << corrAns << " Correct answers   |" << endl;
        cout << "| " << wrongChar << " Incorrect answers |" << endl;
        cout << "|---------------------|\n" << endl;
        
//************************************************************************************************************
        int choice;
        cout << "\n\n\nWould you like to play again?" << endl;
        cout << "\t 1 -- YES" << endl;
        cout << "\t 2 -- NO\nEnter number for choice and hit enter: ";
        cin >> choice;
        if (choice == 2){
            break;
        } else if (choice != 1 || choice != 2) {
            cout << "That is not the correct input" << endl;
            cout << "\nI will assume you are playing again :) \n\n" << endl;
        }
        
        
        deleteGuess(&head);
        
    }
    cout << "\n\n\n\n\n\n\t\tTHANK YOU FOR PLAYING!\n\n" << endl;

//************************************************************************************************************

    return 0;
}
