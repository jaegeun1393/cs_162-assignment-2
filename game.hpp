#ifndef _game
#define _game
#include "player.hpp"
#include "hand.hpp"
#include <cstdlib>

/*********************************************************************
** Class: game class
** Description: has the function of the entire game
** Pre-Conditions: bring player and hand data
** Post-Conditions: nothing
*********************************************************************/ 
class game {
private:
    deck* deck1;
    player players[2];
    bool finished;

public:
    game();
    ~game();
    int gofish(int);
    int isgood(int);
    int searchhand(int, int);
    void stealcards(int, int, int);
    void pause(int i);
    void playerbooks(int);
    void gprinthand(int);
    void gamestart();
    void playerstatus(int n);
    bool cputurn(int);
    bool playerbase();
    bool cpubase();
    bool playerturn(int);
    
};
#endif

