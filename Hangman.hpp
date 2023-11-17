//-----------------------------------------------------------------------------------------------
//Program name:  HangmanGame.cpp
//Author:  Amber Webb
//Date:  12/01/2022
//Input:  requests input from user
//Output:  displays output on the console
//Description:  This program simulates the two-player game "Hangman"
//-----------------------------------------------------------------------------------------------

#ifndef Hangman_hpp
#define Hangman_hpp

#include <stdio.h>

class Game {
public:
    //function return the value of word
    //PRE: word vsriable is filled
    //POST: value of word is returned
    char getWord();
    
    //function to set data in word
    //PRE: NONE
    //POST: value of word is set accordingly
    void setWord(char word);
    
    //function to search the word for a letter
    //PRE: word vriable is filled
    //POST: returns true if letter is found and false otherwise
    bool Search(Game *h, char x);
    
    //function to return Next
    //PRE: Next is given a vlaue
    //POST: the value of Next is returned
    Game* getNext();
    
    //function to give Next a value
    //PRE: NONE
    //POST: Next is updated with value
    void setNext(Game *Next);
    
    //constructor with parameters
    //PRE: none
    //POST: values are set
    Game(char word, bool blank, Game *Next);
    
    //Default constructor
    //PRE: NONE
    //POST: NONE
    Game();
private:
    
    char Word;
    bool Blank;
    Game *Next;
};

#endif /* Hangman_hpp */
