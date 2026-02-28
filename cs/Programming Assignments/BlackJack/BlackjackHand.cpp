#include "BlackjackHand.h"

// Basic default constructor (implicitly calls the 'Hand' default constructor)
BlackjackHand::BlackjackHand() {}

/* hasBlackjack() - Check if this hand has a 'natural 21'
 * output: true if this hand is a 'blackjack', false otherwise
 */
bool BlackjackHand::hasBlackjack() const {
  // TODO: Implement this function
  return false; // TODO: Replace this temporary line
}

/* score() - Compute and return the score for this hand in a standard
 * game of blackjack.
 *
 * Keep in mind that aces count as 11 ONLY if the score is < 21.  If
 * the score is > 21 they need to be counted as worth 1 point.  See
 * the project instructions for more details.
 */
unsigned int BlackjackHand::score() const {
  // TODO: Implement this function
  return 0; // TODO: Replace this temporary line
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
  // TODO: Implement this function
  return false; // TODO: Replace this temporary line
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
  // TODO: Implement this function
  return false; // TODO: Replace this temporary line
}
