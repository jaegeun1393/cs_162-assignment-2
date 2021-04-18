#include "deck.hpp"

/*********************************************************************
** Function: deck
** Description: deck set 52 cards
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 52 cards in a deck
*********************************************************************/ 
deck::deck() {
    n_cards = 52;
    cardplace = 0;
    int i = 0;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 13; k++) {
            cards[i].setcard(k, j);
            i++;

        }
    }
}

/*********************************************************************
** Function: dealcard
** Description: return the number of cards
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the number of cards
*********************************************************************/ 
card deck::dealcard() {
    cardplace++;
    return cards[cardplace-1];
}

/*********************************************************************
** Function: shuffledeck
** Description: shuffle the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: re-ramdomize the deck array
*********************************************************************/ 
void deck::shuffledeck() {
    int index, cardleft = n_cards - cardplace;
    srand(time(NULL));
    for (int i = cardplace; i < n_cards; i++) {
        index = rand() % cardleft + cardplace;
        card temp = cards[index];
        cards[index] = cards[i];
        cards[i] = temp;
    }
}

/*********************************************************************
** Function: getcard
** Description: get the card information
** Parameters: int
** Pre-Conditions: i
** Post-Conditions: return the card information
*********************************************************************/ 
card deck::getcard(int i) {
    return cards[i];

}