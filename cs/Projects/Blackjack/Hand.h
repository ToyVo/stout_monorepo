#pragma once // Guard against multiple inclusions

#include <vector>
// We choose NOT to say 'using namespace std' in the header

#include "PrintableCard.h"

/* Hand - A collection of playing cards that functions as a player's hand
 * used in many standard card games.  Supports taking cards from a deck,
 * hiding cards from printing (or showing), counting the cards in the hand
 * and printing to the console using curses
 */
class Hand {
public:
  // Default constructor (makes an empty hand)
  Hand();

  // Return the number of cards in this hand
  unsigned int cardCount() const;

  // Remove all cards from this hand
  void clear();

  // Add 'card' to this hand
  void takeCard(PrintableCard card);

  // Set all cards in this hand to be face-down
  void hideCards();

  // Set all cards in this hand to be face-up
  void showCards();

  // Output this hand using PDcurses
  // This displays all cards in the hand at the current window
  // position in a single line
  void printCurses() const;

protected:
  // The cards currently in this hand
  std::vector<PrintableCard> mCards;
};
