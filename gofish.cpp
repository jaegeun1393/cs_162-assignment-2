/*********************************************************************
** Program Filename: assignment 2 GO fish card game
** Author: jaegeun oh
** Date: 2/4/2019
** Description: Let's play go fish card game!
** Input: user inputs
** Output: cards with suit and numbers
*********************************************************************/
#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

int main() {
    int again = 0;
    while (again == 0) {
        game game1;
        game1.gamestart();
        cout << "Playagain? (1.yes 2.no): ";
        cin >> again;
    }
    return 0;
}