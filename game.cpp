#include "game.hpp"

/*********************************************************************
** Function: game
** Description: make player datas (0 ~ 1), player and ai
** Parameters: NONE
** Pre-Conditions: deck, player informations
** Post-Conditions: NONE
*********************************************************************/ 
game::game() {
    finished = false;
    deck1 = new deck;
    deck1->shuffledeck();
    players[0].playermakehand(deck1);
    players[1].playermakehand(deck1);
}

/*********************************************************************
** Function: game printhand
** Description: print the user informations from the player information
** Parameters: n; 0 = player, 1 = ai
** Pre-Conditions: int n
** Post-Conditions: void print hand
*********************************************************************/ 
void game::gprinthand(int n) {
    players[n].printhand();
}

/*********************************************************************
** Function: ~game
** Description: handle leaking memory
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: delete deck informations
*********************************************************************/ 
game::~game() {
    delete deck1;
}

/*********************************************************************
** Function: pause
** Description: computer's  turn
** Parameters: int
** Pre-Conditions: i
** Post-Conditions: none
*********************************************************************/ 
void game::pause(int i) {
    char pause;
    string prompt[2] = { "the ai's", "your" };
    cout << "Press enter to continue to " << prompt[i] << " turn" << endl;
    cin.ignore(!i);
    pause = cin.get();
}

/*********************************************************************
** Function: playerbase
** Description: has the base of the player
** Parameters: NONE
** Pre-Conditions: none
** Post-Conditions: bring the player's(not ai) data
*********************************************************************/ 
bool game::playerbase() {
    bool turn = true;
    while (turn) {
        turn = this->playerturn(0);
        this->playerbooks(0);
        this->playerstatus(0);
        if (players[0].getn_books() + players[1].getn_books() == 13) {
            return true;
        }
    }
}

/*********************************************************************
** Function: cpubase
** Description: showing the computer 
** Parameters: NONE
** Pre-Conditions: deck, player informations
** Post-Conditions: NONE
*********************************************************************/ 
bool game::cpubase() {
    bool turn = true;
    while (turn) {
        turn = this->cputurn(1);
        this->playerbooks(1);
        cout << "|| The AI has " << players[1].getn_books() << " book(s)" << endl;
        if (players[0].getn_books() + players[1].getn_books() == 13)
            return true;
    }
}

/*********************************************************************
** Function: gamestart
** Description: start the game
** Parameters: NONE
** Pre-Conditions: none
** Post-Conditions: playing the game
*********************************************************************/ 
void game::gamestart() {
    cout << "||AIDEN'S GO FISH||" << endl;
    while (!finished) {
        if (this->playerbase())
            break;
        this->pause(0);
        if (this->cpubase())
            break;
        this->pause(1);

    }
    if (players[0].getn_books() > players[1].getn_books()) {
        cout << "Congratulations, you win with " << players[0].getn_books() << " books!!" << endl;
    }
    else {
        cout << "The AI win with " << players[1].getn_books() << " books!!" << endl; }

}

/*********************************************************************
** Function: computer turn
** Description: computer's turn
** Parameters: int
** Pre-Conditions: n
** Post-Conditions: computer's turn
*********************************************************************/ 
bool game::cputurn(int n) {
    cout << "It is the Ai's turn!" << endl;
    int search = players[n].randomcard();
    cout << "||The computer searched for " << search << endl;
    cout << "You had " << searchhand(!n, search) << endl;
    if (searchhand(!n, search) == 0) {
        int fished = gofish(n);
        if (fished == search) {
            cout << "The AI drew a " << search << endl;
            return true;
        }
    }
    else {
        cout << "You gave the Ai " << searchhand(!n, search) << " " << search << "(s)" << endl;
        stealcards(n, search, searchhand(!n, search));
        return true;
    }
    return false;
}

/*********************************************************************
** Function: playerbooks
** Description: shows how many boks the player has
** Parameters: int
** Pre-Conditions: n 
** Post-Conditions: print out how many player has the book
*********************************************************************/ 
void game::playerbooks(int n) {
    for (int i = 0; i < 13; i++) {
        if (searchhand(n, i) == 4) {
            players[n].bookset(i);
            if (n == 0) {
                cout << "You created a book of " << i << "'s" << endl << endl;
            }
            else
                cout << "|| The computer created a book of " << i << "'s" << endl << endl;
        }
    }
}

/*********************************************************************
** Function: playerturn
** Description: player's turn functions
** Parameters: int
** Pre-Conditions: n
** Post-Conditions: print out the player's go fish playing
*********************************************************************/ 
bool game::playerturn(int n) {
    cout << "Your turn! "<< endl;
    if (players[n].pgethand().howmany() == 0) {
        cout << "Draw a card!" << endl;
        gofish(n);
    }
    this->playerstatus(n);
    cout << "Enter the card you want to search: ";
    int search = isgood(n);
    cout << endl << "You searched for " << search << endl;
    cout << "your opponent had " << searchhand(!n, search) << endl << endl;
    if (searchhand(!n, search) == 0) {
        cout << "Go Fish-o---|"<< endl;
        cout << "            L" << endl;
        int fished = gofish(n);
        if (fished == search) {
            return true;
        }
    }
    else {
        stealcards(n, search, searchhand(!n, search));
        return true;
    }
    return false;
}

/*********************************************************************
** Function: gofish
** Description: go fish! add the card to the player
** Parameters: int
** Pre-Conditions: n
** Post-Conditions: add the card to the player or ai's hand
*********************************************************************/ 
int game::gofish(int n) {
    int fished = players[n].addcard(deck1->dealcard(), n);
    return fished;
}

/*********************************************************************
** Function: stealcards
** Description: steal the card from the player
** Parameters: int, int, int
** Pre-Conditions: n, search, numcards
** Post-Conditions: add the card to the player or to the ai
*********************************************************************/ 
void game::stealcards(int n, int search, int numcards) {
    hand* temphand = new hand;
    players[!n].newhand(temphand);
    card* stolen = new card[numcards];
    int j = 0;
    for (int i = 0; i < temphand->howmany(); i++) {
        if (search == temphand->gethand()[i].getrank()){
            stolen[j] = temphand->gethand()[i];
            j++;
            temphand->removecard(i);
            i--;
        }
    }
    players[!n].copyhand(temphand);
    players[n].addhand(stolen, numcards);
    delete[] stolen;
    delete temphand;
}

/*********************************************************************
** Function: isgood
** Description: when the user has the ai's rank card
** Parameters: int
** Pre-Conditions: n
** Post-Conditions: player's card
*********************************************************************/ 
int game::isgood(int n) {
    bool bad = true;
    string temp;
    while (bad) {
        cin >> temp;
        if (searchhand(n, atoi(temp.c_str())) == 0) { 
            cout << "Please re-enter a rank in your hand: ";
        }
        else
            bad = false;
    }
    return atoi(temp.c_str());
}

/*********************************************************************
** Function: searchhand
** Description: search the card the hand's have
** Parameters: int int
** Pre-Conditions: n, search
** Post-Conditions: none
*********************************************************************/ 
int game::searchhand(int n, int search) {
    int searchnum = 0;
    hand* temphand = new hand;
    this->players[n].newhand(temphand);
    for (int i = 0; i < temphand->howmany(); i++) {
        if (search == temphand->gethand()[i].getrank()) {
            searchnum++;
        }
    }
    delete temphand;
    return searchnum;
}

/*********************************************************************
** Function: playerstatus
** Description: print player game status
** Parameters: int
** Pre-Conditions: n
** Post-Conditions: NONE
*********************************************************************/ 
void game::playerstatus(int n) {
    cout << "Your hand is: " << endl;
    this->gprinthand(n);
    cout << "You have " << players[n].getn_books() << " book" << endl;
    if (players[n].getn_books() > 0) {
        cout << "Your books are: ";
        for (int i = 0; i < players[n].getn_books(); i++) {
            cout << players[n].getbooks()[i];
            if (i != players[n].getn_books() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}