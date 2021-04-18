#include "hand.hpp"

/*********************************************************************
** Function: howmany
** Description: shows howmany cards the player has
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: return n_cards
*********************************************************************/ 
int hand::howmany() {
    return n_cards;
}

/*********************************************************************
** Function: hand
** Description: make hand
** Parameters: int 
** Pre-Conditions: hand& other
** Post-Conditions: NONE
*********************************************************************/ 
hand::hand(const hand& other) {
    this->n_cards = other.n_cards;
    this->cards = new card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++) {
        this->cards[i] = other.cards[i];
    }
}

/*********************************************************************
** Function operator
** Description: hand
** Parameters: NONE
** Pre-Conditions: deck, player informations
** Post-Conditions: NONE
*********************************************************************/ 
void hand::operator=(const hand& other) {
    this->n_cards = other.n_cards;
    this->cards = new card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++) {
        this->cards[i] = other.cards[i];
    }
}

hand::hand() {
    n_cards = 0;
}

/*********************************************************************
** Function: gethand
** Description: return the cards
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: return cards;
*********************************************************************/ 
card* hand::gethand() {
    return cards;
}

/*********************************************************************
** Function: setcard
** Description: cards get add from the deck
** Parameters: NONE
** Pre-Conditions: none
** Post-Conditions: NONE
*********************************************************************/ 
void hand::setcard(card deal) {
    cards = addcard();
    cards[n_cards] = deal;
    n_cards++;
}

/*********************************************************************
** Function: addcard
** Description: add card from the deck
** Parameters: NONE
** Pre-Conditions: none
** Post-Conditions: return temp with deleting leaking data
*********************************************************************/ 
card* hand::addcard() {
    card* temp;
    temp = new card[n_cards + 1];
    for (int i = 0; i < n_cards; i++) {
        temp[i] = cards[i];
    }
    if (n_cards > 0) {
        delete[] cards;
    }
    return temp;
}

/*********************************************************************
** Function: removecard
** Description: remove the card when the user make the book
** Parameters: int
** Pre-Conditions: bcard
** Post-Conditions: none
*********************************************************************/ 
void hand::removecard(int bcard) {
    n_cards--;
    card* temp = new card[n_cards];
    int j = 0;
    for (int i = 0; i < n_cards+1; i++) {
        if (i != bcard) {
            temp[j] = this->cards[i];
            j++;
        }
    }
    delete[] cards;
    cards = temp;
}

/*********************************************************************
** Function: leakinghand
** Description: prevent leaking memory
** Parameters: NONE
** Pre-Conditions: None
** Post-Conditions: NONE
*********************************************************************/ 
hand::~hand() {
    if (n_cards > 0) {
        delete[] cards;
    }
}