#ifndef BLACKJACK_GAME
#define BLACKJACK_GAME

// A game of blackjack has a deck and two hands
#include "BlackjackHand.h"
#include "Deck.h"

// Different ways the game can end.  The first states take precedence over
// over the latter states so check for the early ones first (like blackjack)!
// Note that a "natural 21" is when you are delt two cards totaling 21.
enum eGameState {
  GAME_BLACKJACK_PUSH,   // Both player and dealer have a natural 21
  GAME_DEALER_BLACKJACK, // Dealer has a natural 21
  GAME_PLAYER_BLACKJACK, // Player has a natural 21
  GAME_DEALER_BUST,      // The dealer has more than 21
  GAME_PLAYER_BUST,      // The player has more than 21
  GAME_DEALER_WIN,       // The dealer's score is higher than players
  GAME_PLAYER_WIN,       // The player's score is higher than dealers
  GAME_PUSH              // The scores are tied
};

class BlackjackGame {
public:
  BlackjackGame();

  // Clear the players hands and shuffle the deck
  void newGame();

  // Play a single round of blackjack showing the output using
  // the 'PDcurses' library (for color and card suits).
  void playGameCurses();

  // Display the deck on the screen (for debugging purposes)
  void printDeckCurses();

  // Print both players hands to the screen using 'PDCurses'
  // If pShowDealerScore is true then the dealer's score is printed
  // Otherwise, the dealer's score is shown as '??'
  void printHandsCurses(bool pShowDealerScore = false) const;

  // Determine the state of the game.  Note that if you have not yet
  // played a round since you constructed this object or called newGame()
  // Then the state returned is not accurate.
  eGameState getGameState() const;

private:
  // A deck of cards for shufflying and dealing hands
  Deck mDeck;

  // The two hands for the player and the dealer
  BlackjackHand mPlayer, mDealer;

  // A helper function for prompting the player (internal use only)
  char promptPlayerCurses();

  // A helper function to quit the game (internal use only)
  void quitGameCurses();
};

#endif
