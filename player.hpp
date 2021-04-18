#ifndef player_
#define player_
#include "hand.hpp"
#include <iostream>

/*********************************************************************
** Function: player
** Description: make the player with the class hand to contain the card data
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
class player {
private:
    hand myhand;
    int* books;
    int n_books;

public:
    player();
    void playermakehand(deck*);
    ~player();
    hand pgethand();
    void psethand(hand);
    void printhand();
    void bookset(int book);
    int* getbooks();
    int getn_books();
    void newhand(hand*);
    void copyhand(hand*);
    void addhand(card*, int);
    int addcard(card, int);
    void removebook(int book);
    int randomcard();
};
#endif