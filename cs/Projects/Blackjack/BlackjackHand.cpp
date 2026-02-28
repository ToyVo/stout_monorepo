#include "BlackjackHand.h"

// Basic default constructor (implicitly calls the 'Hand' default constructor)
BlackjackHand::BlackjackHand() { Hand(); }

/* hasBlackjack() - Check if this hand has a 'natural 21'
 * output: true if this hand is a 'blackjack', false otherwise
 */
bool BlackjackHand::hasBlackjack() const {
  if (score() == 21 && mCards.size() == 2) {
    return true;
  } else {
    return false;
  }
}

/* score() - Compute and return the score for this hand in a standard
 * game of blackjack.
 *
 * Keep in mind that aces count as 11 ONLY if the score is < 21.  If
 * the score is > 21 they need to be counted as worth 1 point.  See
 * the project instructions for more details.
 */
unsigned int BlackjackHand::score() const {
  int score = 0;

  if (hasSoftAce()) {
    for (int i = 0; i < mCards.size(); i++) {
      if (mCards[i].getFaceValue() == VALUE_ACE) {
        score += 11;
      } else if (mCards[i].getFaceValue() == VALUE_JACK ||
                 mCards[i].getFaceValue() == VALUE_QUEEN ||
                 mCards[i].getFaceValue() == VALUE_KING) {
        score += 10;
      } else {
        score += mCards[i].getFaceValue();
      }
    }
    return score;
  } else {
    for (int i = 0; i < mCards.size(); i++) {
      if (mCards[i].getFaceValue() == VALUE_ACE) {
        score += 1;
      } else if (mCards[i].getFaceValue() == VALUE_JACK ||
                 mCards[i].getFaceValue() == VALUE_QUEEN ||
                 mCards[i].getFaceValue() == VALUE_KING) {
        score += 10;
      } else {
        score += mCards[i].getFaceValue();
      }
    }
    return score;
  }
}

/* hasSoftAce() - Determine if this hand has one or more aces that are
 * worth 11 points (high aces).
 * output: If there are 0 aces worth 11 points returns false, true otherwise.
 *
 * Note that answering this question will require work VERY similar to
 * computing the score for this hand (like score() above).  You may want
 * to make a separate private function for this so that you do not
 * duplicate code.
 */

bool BlackjackHand::hasSoftAce() const {
  // DECIDE HOW TO SCORE ACES
  // Determine Necessary Variables
  int score = 0, aceTotal = 0;

  // Add up the intial hand score, assuming aces are high
  for (int i = 0; i < mCards.size(); i++) {
    if (mCards[i].getFaceValue() == VALUE_ACE) {
      score += mCards[i].getFaceValue();
      aceTotal += 1;
    } else if (mCards[i].getFaceValue() == VALUE_JACK ||
               mCards[i].getFaceValue() == VALUE_QUEEN ||
               mCards[i].getFaceValue() == VALUE_KING) {
      score += 10;
    } else {
      score += mCards[i].getFaceValue();
    }
  }

  // Check if the aces could be counted as high and not bust
  if (score + (aceTotal * 10) <= 21)
    return true;
  else
    return false;
}

/* vegasDealerWouldHit() - Determine if normal Vegas rules would require a
 * dealer with this hand to hit (as opposed to standing).
 * output: If a Vegas dealer would hit returns true, otherwise returns false.
 *
 * You should make use of score() and hasSoftAce() to implement this method!
 * Rules for a Vegas dealer:
 *    - If the score is < 17 you must hit
 *    - If the score is > 17 you must stand
 *    - If the score == 17 and you have a soft ace you must hit
 *    - If the score == 17 and you DON'T have a soft ace you must stand
 */
bool BlackjackHand::vegasDealerWouldHit() const {
  if (score() < 17 || (score() == 17 && hasSoftAce())) {
    return true;
  } else {
    return false;
  }
}