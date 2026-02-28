#include <cstdlib>
#include <iostream> // Standard input and output
#include <string>
using namespace std;

#include "BlackjackGame.h"
#include <curses.h>

// Three different types of text colors used with PDCurses
#define NORM_TEXT 1
#define WIN_TEXT 2
#define LOSE_TEXT 3

int main() {
  // Setup 'PDcurses'
  initscr();
  start_color();

  // Define our colors text colors (foreground, background)
  init_pair(NORM_TEXT, COLOR_WHITE, COLOR_BLACK);
  init_pair(WIN_TEXT, COLOR_YELLOW, COLOR_BLACK);
  init_pair(LOSE_TEXT, COLOR_RED, COLOR_BLACK);

  // Define our card colors (these are declared in PrintableCard.h)
  init_pair(BLACK_CARD, COLOR_BLACK, COLOR_WHITE);
  init_pair(RED_CARD, COLOR_RED, COLOR_WHITE);

  // Input from the user and a game object
  char ch = '\0';
  BlackjackGame myGame;

  // Output a 'fancy' welcome screen
  myGame.printDeckCurses();
  attron(COLOR_PAIR(WIN_TEXT));
  mvprintw(1, 13, "Welcome to Blackjack!");
  mvprintw(5, 11, "Press any key to play ...");
  refresh();

  // Wait for input (the 'press any key to begin' thing)
  ch = getch();

  // Back to normal text to start the game
  attron(COLOR_PAIR(NORM_TEXT));

  do // Loop to play a new game until the user exits
  {
    // Restart and play a game (using curses)
    myGame.newGame();

    // Play a round of blackjack (most of the magic happens here!)
    myGame.playGameCurses();

    // Print the final status of the game
    myGame.printHandsCurses(true);

    // Print a game results message (use BOLD and the appropriate text color)
    attron(A_BOLD);
    switch (myGame.getGameState()) {
    case GAME_BLACKJACK_PUSH:
      attron(COLOR_PAIR(WIN_TEXT));
      mvprintw(10, 25, "BLACKJACK TIE!!");
      break;

    case GAME_DEALER_BLACKJACK:
      attron(COLOR_PAIR(LOSE_TEXT));
      mvprintw(10, 25, "Dealer Blackjack. You lose.");
      break;

    case GAME_PLAYER_BLACKJACK:
      attron(COLOR_PAIR(WIN_TEXT));
      mvprintw(10, 25, "BLACKJACK! You win!");
      break;

    case GAME_DEALER_BUST:
      attron(COLOR_PAIR(WIN_TEXT));
      mvprintw(10, 25, "Dealer Bust. You Win!");
      break;
    case GAME_PLAYER_BUST:
      attron(COLOR_PAIR(LOSE_TEXT));
      mvprintw(10, 25, "BUST. You lose.");
      break;

    case GAME_DEALER_WIN:
      attron(COLOR_PAIR(LOSE_TEXT));
      mvprintw(10, 25, "You lose.");
      break;

    case GAME_PLAYER_WIN:
      attron(COLOR_PAIR(WIN_TEXT));
      mvprintw(10, 25, "You Win!");
      break;

    case GAME_PUSH:
      attron(COLOR_PAIR(WIN_TEXT));
      mvprintw(10, 25, "It's a tie!");
      break;
    }

    // Turn off bold and return to normal text color
    attroff(A_BOLD);
    attron(COLOR_PAIR(NORM_TEXT));

    // Prompt user to play again
    mvprintw(20, 0, "Play again (y/n): ");
    refresh();
    ch = getch();
  } while (ch != 'n');

  // Close out 'PDCurses' and pause before exiting
  endwin();
  system("pause");
  return 0;
}
