#pragma once // Guard against multiple inclusion

#include "hand.h"

/* BlackjackHand - A specialization of the 'Hand' object to add functions
 * usefull for playing a round of Blackjack (aka 21).  It adds the ability
 * to recognize a 'Natural 21' (aka Blackjack), to compute the score of
 * the hand in blackjack, to tell if there are 'soft' aces in the hand
 * and to query the standard vegas dealer rules for hitting.
 */
class BlackjackHand : public Hand {
public:
  // Basic default constructor
  BlackjackHand();

  // Does this hand have a value of 21 with only two cards?
  bool hasBlackjack() const;

  // Determine the score of this hand in blackjack (with variable aces)
  unsigned int score() const;

  // Does this hand have a hard ace
  bool hasSoftAce() const;

  // Would a standard vegas dealer hit?
  bool vegasDealerWouldHit() const;
};
