#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Deck.h"

Deck::Deck() {
  // Initialize random number generation for shuffling deck
  srand(static_cast<unsigned int>(time(NULL)));

  // Add cards to deck in standard sorted order
  sortDeck();
}

/* sortDeck() - Make this a sorted deck of 52 playing cards
 *
 * Note that despite the name of this function it does not sort
 * the deck in place.  Instead it just makes a brand new deck
 * of 52 cards frcom scratch
 */
void Deck::sortDeck() {
  // Remove all cards
  mCards.clear();

  // Re-build the deck from scratch in order
  for (unsigned int i = 0; i < 4; i++) // Move through the 4 suits
  {
    for (unsigned int j = 1; j <= 13; j++) // Move through the 13 face values
    {
      // Make a card by casing our integers to enums
      eCardSuit suit = static_cast<eCardSuit>(i);
      eCardValue value = static_cast<eCardValue>(j);
      mCards.push_back(PrintableCard(suit, value));
    }
  }

  // Reset current card
  mCurrentCard = 0;
}

/* shuffle() - Shuffle the deck into a random order
 *
 * TODO: Implement this function.  You must used the Standard C++
 * random_shuffle() method on the mCards vector.  Also, be sure to
 * set the top of the deck (mCurrentCard) back to zero.
 */
void Deck::shuffle() {
  // TODO: Implement this function using stl::random_shuffle()
}

/* dealCard() - Return the card from the top of the deck and then
 * move forward one.
 *
 * mCurrentCard represents the 'top' of the deck so use this index
 * to get the top card and return it.  Make sure you move the 'top'
 * forward one card too but DONT let it go past the end of the deck.
 */
PrintableCard Deck::dealCard() {
  // Retrieve current card
  PrintableCard lCard = mCards[mCurrentCard];

  // Advance current card pointer (wraps around to 0 after 51)
  mCurrentCard = ((mCurrentCard + 1) % mCards.size());

  // Return card
  return lCard;
}
