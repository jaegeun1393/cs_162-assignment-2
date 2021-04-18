#include "card.hpp"

/*********************************************************************
** Function: card
** Description: set the rank and the suit each card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: raank, and suit
*********************************************************************/ 
card::card() {
    rank = 0;
    suit = 0;
}

/*********************************************************************
** Function: setcard
** Description: set the rank and suit
** Parameters: int, int
** Pre-Conditions: r = rank, s = suit
** Post-Conditions: none
*********************************************************************/ 
void card::setcard(int r, int s) {
    rank = r;
    suit = s;
}

/*********************************************************************
** Function: getrank
** Description: get the value of the rank
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the value rank
*********************************************************************/ 
int card::getrank() {
    return rank;
}

/*********************************************************************
** Function: getsuit
** Description: get the value suit from the fucntion
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the value suit 
*********************************************************************/ 
int card::getsuit() {
    return suit;
}