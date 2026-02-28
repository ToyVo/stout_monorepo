#pragma once // Guard against multiple inclusions

#include <vector>
// We choose NOT to say 'using namespace std' in the header

// Decks have playing cards in them so we need to know about this class
#include "PrintableCard.h"

/*
 * Deck : A complete deck of 52 cards (PrintableCard) for use in playing
 * standard card games like Blackjack or Poker.  There are no Jokers.
 *
 * Supports standard actions you would use with a real deck like shuffling,
 * sorting and dealing of cards.
 */
class Deck {
public:
  // Make a new deck of playing cards (sorted)
  Deck();

  // Sort the deck (actually just makes a fresh deck of 52 cards)
  void sortDeck();

  // Randomly shuffle the deck
  void shuffle();

  // Take a card from the top of the deck
  PrintableCard dealCard();

private:
  // The deck of 52 playing cards
  std::vector<PrintableCard> mCards;

  // The current card on the 'top' of the deck
  unsigned int mCurrentCard;
};
