#include "BlackjackGame.h"

// The library used for our text based user interface
#include <curses.h>

// Normal text color for PDCurses (defined in main)
#define NORM_TEXT 1

// Default constructor (does nothing)
BlackjackGame::BlackjackGame() {}

/* newGame() - Clear the two hands so we are ready for a new game */
void BlackjackGame::newGame() {
  mDealer.clear();
  mPlayer.clear();
}

/* playGameCurses() - Play a single round of poker with one human player and one
 * dealer following standard Vegas rules.  Uses PDCurses for input and output to
 * the console.
 *
 * You must implement this method but you do not need to worry about curses.
 * Call 'promptPlayerCurses() to show the hands and prompt the human player to
 * hit, stand or quit.  This method will return the key they pressed.  You can
 * also use quitGameCurses() to exit properly if the user chose to 'quit'.
 */
void BlackjackGame::playGameCurses() {
  // TODO: Shuffle the deck and deal the cards (make sure dealer's first card is
  // hidden).
  mDeck.shuffle();
  mPlayer.takeCard(mDeck.dealCard());
  mDealer.takeCard(mDeck.dealCard());
  mDealer.hideCards();
  mPlayer.takeCard(mDeck.dealCard());
  mDealer.takeCard(mDeck.dealCard());

  // TODO: Check for a 'natural 21' (blackjack) before playing
  if (mPlayer.hasBlackjack() || mDealer.hasBlackjack()) {
    return;
  }

  // TODO: Allower human player to hit, stand and quit as needed (repeat until
  // player is done)
  char input =
      promptPlayerCurses(); // This line is an example only, a placeholder
  while (input == 'h' && mPlayer.score() < 21) {
    mPlayer.takeCard(mDeck.dealCard());
    input = promptPlayerCurses();
  }
  if (input == 'q')
    quitGameCurses();

  while (mDealer.vegasDealerWouldHit()) {
    mDealer.takeCard(mDeck.dealCard());
  }

  mDealer.showCards();
  return;
  // TODO: Play the 'dealer' hand according to vegas rules
  // TODO: Remember to reveal all the dealer's cards before returning
}

/* promptPlayerCurses() - Show the hands and prompt the human player to hit,
 * stand or quit. output: returns the single character entered by the player at
 * the prompt.
 *    - 'h' means hit, 's' means stand
 *    - 'q' means you should immediatly quit (call 'quitGameCurses()')
 */
char BlackjackGame::promptPlayerCurses() {
  // Show the hands
  printHandsCurses();

  // Hit or stand?
  attron(COLOR_PAIR(NORM_TEXT));
  mvprintw(3, 0, "Hit, stand or Quit ('h', 's', 'q'): ");
  refresh();

  // Read and return a single character
  return getch();
}

/* quitGameCurses() - End curses output and exit the program immediately */
void BlackjackGame::quitGameCurses() {
  // End curses output, then pause and exit
  endwin();
  system("pause");
  exit(0);
}

/* printDeckCurses() - A handy function that displays the content of the game
 * deck using curses.
 *
 * This can be handy for debugging your deck and making sure it is getting
 * properly shuffled.  It is presently used for the fancy opening screen.
 */
void BlackjackGame::printDeckCurses() {
  // Start at the upper left corner of the screen
  move(0, 0);

  // For all 52 cards
  for (int i = 1; i <= 52; i++) {
    // Get the next card and print it
    PrintableCard lCard = mDeck.dealCard();
    lCard.printCurses();

    // If we've output 13 cards then move down a row
    if (i % 13 == 0) {
      move(2 * (i / 13), 0);
    } else {
      // Switch back to normal text color and output ' ' characters
      attron(COLOR_PAIR(NORM_TEXT));
      if (lCard.getFaceValue() == VALUE_TEN)
        printw(" ");
      else
        printw("  ");
    }
  }
}

/* printHandsCurses() - A function to display the current scores and hands for
 * this game using curses.
 *
 * This function is used in promptPlayerCurses() to show the hands before asking
 * them if they want to hit or stand.  Note that it alsways clears the window
 * before drawing.
 */
void BlackjackGame::printHandsCurses(bool pShowDealerScore) const {
  // Clear window
  erase();

  // Show dealer and player hands
  attron(COLOR_PAIR(NORM_TEXT));
  mvprintw(0, 0, "Player: %d\n", mPlayer.score());
  move(1, 0);
  mPlayer.printCurses();

  attron(COLOR_PAIR(NORM_TEXT));
  if (pShowDealerScore) {
    mvprintw(0, 50, "Dealer: %d\n", mDealer.score());
  } else {
    mvprintw(0, 50, "Dealer: ??\n");
  }
  move(1, 50);
  mDealer.printCurses();

  refresh();
}

/* getGameStat() - Examine the hands of both players and return the current
 * state of the game using the eGameState enum.
 *
 * You must examine the state of the game by comparing the two hands (their
 * scores and their number of cards) and return the appropriate constant from
 * the eGameState enum.  Assume that the game is over (i.e. the player and
 * dealer have both either gone bust or decided to stand).
 */
eGameState BlackjackGame::getGameState() const {
  // returns the state of the game
  if (mPlayer.hasBlackjack() && mDealer.hasBlackjack())
    return GAME_BLACKJACK_PUSH;
  if (!mPlayer.hasBlackjack() && mDealer.hasBlackjack())
    return GAME_DEALER_BLACKJACK;
  if (mPlayer.hasBlackjack() && !mDealer.hasBlackjack())
    return GAME_PLAYER_BLACKJACK;
  if (mDealer.score() > 21)
    return GAME_DEALER_BUST;
  if (mPlayer.score() > 21)
    return GAME_PLAYER_BUST;
  if (mDealer.score() > mPlayer.score())
    return GAME_DEALER_WIN;
  if (mDealer.score() < mPlayer.score())
    return GAME_PLAYER_WIN;
  if (mDealer.score() == mPlayer.score())
    return GAME_PUSH;
}
