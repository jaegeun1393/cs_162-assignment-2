#ifndef deck_
#define deck_
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "card.hpp"
using namespace std;

/*********************************************************************
** Function: deck
** Description: deck from the card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
class deck {
private:
    card cards[52];
    int n_cards;
    int cardplace;
public:
    deck();
    card dealcard();
    void shuffledeck();
    card getcard(int);
};
#endif
