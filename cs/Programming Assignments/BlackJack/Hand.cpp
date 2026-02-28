#include "Hand.h"
using namespace std; // For 'vector' in the header

// The library used to make a nice text based interface
#include <curses.h>

// Normal text color for PDCurses (defined in main)
#define NORM_TEXT 1

// Simple default constructor (does nothing)
Hand::Hand() {}

/* clear() - remove all cards from this hand
 *
 * You must implement this to clear the vector of
 * cards in this instance.
 */
void Hand::clear() {
  // TODO: Implement this function
}

/* cardCount() - return the number of cards in this hand
 *
 * You must implement this to return the number of items
 * in the vector of cards for this instance.
 */
unsigned int Hand::cardCount() const {
  // TODO: Implement this function
  return 0; // TODO: Remove this temporary line
}

/* takeCard(card) - add the given card to your hand
 *
 * You must insert the parameter 'card' into the vector.
 */
void Hand::takeCard(PrintableCard card) {
  // TODO: Implement this function
}

/* hideCards() - Set all cards in this hand as face down. */
void Hand::hideCards() {
  for (unsigned int i = 0; i < mCards.size(); i++) {
    mCards[i].hideCard();
  }
}

/* showCards() - Set all cards in this hand as face UP.
 *
 * For every card in the vector, set it to be face up by
 * calling showCard().  Follow the example of 'hideCards()'
 * above.
 */
void Hand::showCards() {
  // TODO: Implement this function
}

/* printCurses() - Display this hand using the curses library */
void Hand::printCurses() const {
  // For every card in this hand
  for (unsigned int i = 0; i < mCards.size(); i++) {
    // Call that card's printCurses() method
    mCards[i].printCurses();

    // Switch back to normal text and output a space
    attron(COLOR_PAIR(NORM_TEXT));
    printw(" ");
  }
}
