#ifndef hand_hpp
#define hand_hpp
#include "deck.hpp"

/*********************************************************************
** Function: hand
** Description: hand class for each player
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: hand
*********************************************************************/ 
class hand {
private:
    card* cards;
    int n_cards;

public:
    hand(const hand&);
    hand();
    card* gethand();
    void setcard(card);
    card* addcard();
    ~hand();
    int howmany();
    void operator= (const hand&);
    void removecard(int);
};
#endif