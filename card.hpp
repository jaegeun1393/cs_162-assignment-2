#ifndef card_
#define card_

using namespace std;

/*********************************************************************
** Function: card
** Description: the card inforamtion suit and the rank
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
class card {
private:
    int rank;
    int suit;
public:
    card();
    void setcard(int r, int s);
    int getsuit();
    int getrank();
};

#endif