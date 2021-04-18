#include "player.hpp"

/*********************************************************************
** Function: player
** Description: set the value book each player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
player::player() {
    books = new int[1];
    n_books = 0;
}

/*********************************************************************
** Function: playermakehand
** Description: make 7 cards on the player's hand
** Parameters: deck1 from the deck
** Pre-Conditions: deck1
** Post-Conditions: set seven cards on the player's hand
*********************************************************************/ 
void player::playermakehand(deck* deck1) {
    for (int i = 0; i < 7; i++) {
        myhand.setcard(deck1->dealcard());
    }

}

/*********************************************************************
** Function: player set hand (psethand)
** Description: hold the card tempaority
** Parameters: hand -> temp
** Pre-Conditions: temp
** Post-Conditions: none
*********************************************************************/ 
void player::psethand(hand temp) {
    myhand = temp;
}

/*********************************************************************
** Function: pgethand (player get hand)
** Description: get the player hand information
** Parameters: None
** Pre-Conditions: none
** Post-Conditions: return the value myhand
*********************************************************************/ 
hand player::pgethand() {
    return myhand;
}

/*********************************************************************
** Function: ~player
** Description: memory leak
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prevent the player's book meory leak
*********************************************************************/ 
player::~player() {
    delete[] books;
}

/*********************************************************************
** Function: addcard
** Description:  get the rank for the new card
** Parameters: card, in
** Pre-Conditions: newcard, n
** Post-Conditions: get the rank for the new card
*********************************************************************/ 
int player::addcard(card newcard, int n) {
    myhand.setcard(newcard);
    if (n == 0) {
        cout << "You drew a " << newcard.getrank() << endl;
    }
    return newcard.getrank();
}

/*********************************************************************
** Function: stealcards
** Description: print the card data the player has
** Parameters: noting
** Pre-Conditions: nothing
** Post-Conditions: print cards in player's hand
*********************************************************************/ 
void player::printhand() {
    int suit_logo;
    string logo;
    for (int i = 0; i < myhand.howmany() ; i++) {
        cout << i + 1 << ". card is rank: ";
        suit_logo = myhand.gethand()[i].getsuit();
        switch(suit_logo) {
            case 0: logo = "❤"; break;
            case 1: logo = "◆"; break;
            case 2: logo = "♣"; break;
            case 3: logo = "♠"; break;
        }
        cout << myhand.gethand()[i].getrank() << " and suit: " << logo << endl;
    }
}

/*********************************************************************
** Function: bookset
** Description: set the book
** Parameters: int
** Pre-Conditions: book
** Post-Conditions: delete for leaking memory and card remove for book
*********************************************************************/ 
void player::bookset(int book) {
    int* temp = new int[n_books + 1];
    for (int i = 0; i < n_books; i++) {
        temp[i] = books[i];
    }
    temp[n_books] = book;
    n_books++;
    delete[] books;
    books = temp;
    removebook(book);
}

/*********************************************************************
** Function: removebook
** Description: when the user has book in the hand, remove them into the book
** Parameters: int
** Pre-Conditions: book
** Post-Conditions: none
*********************************************************************/ 
void player::removebook(int book) {
    for (int i = 0; i < myhand.howmany(); i++) {
        if (myhand.gethand()[i].getrank() == book) {
            myhand.removecard(i);
            i--;
        }
    }
}

/*********************************************************************
** Function: getbooks
** Description: get book information
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the book information
*********************************************************************/ 
int* player::getbooks() {
    return books;
}

/*********************************************************************
** Function: getn_books
** Description: get number of books
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return the number of book the player has
*********************************************************************/ 
int player::getn_books() {
    return n_books;
}

/*********************************************************************
** Function: new hand
** Description: take out the new hand
** Parameters: hand*
** Pre-Conditions: temphand
** Post-Conditions: hand
*********************************************************************/ 
void player::newhand(hand* temphand) {
    *temphand = myhand;
}

/*********************************************************************
** Function: copyhand
** Description: delete the hand currently have and copy temp hand
** Parameters: hand*
** Pre-Conditions: temp
** Post-Conditions: nothing
*********************************************************************/ 
void player::copyhand(hand* temp) {
    myhand.~hand();
    myhand = *temp;
}

/*********************************************************************
** Function: addhand
** Description: set the card to the hand
** Parameters: card*, int
** Pre-Conditions: stolen, numcards
** Post-Conditions: add the hand
*********************************************************************/ 
void player::addhand(card* stolen, int numcards) {
    for (int i = 0; i < numcards; i++) {
        myhand.setcard(stolen[i]);
    }
}

/*********************************************************************
** Function: randomcard
** Description: randomize the card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
int player::randomcard() {
    srand(time(NULL));
    int randcard = rand() % myhand.howmany();
    return myhand.gethand()[randcard].getrank();
}