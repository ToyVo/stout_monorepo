#include "PrintableCard.h"

// Library for simple text-based graphical interface
#include <curses.h>

// Normal text color for PDCurses (defined in main)
#define NORM_TEXT 1

// Our static bad card (uses the default constructor)
PrintableCard PrintableCard::badCard;

// Default constructor (with default values of UNKNOWN)
PrintableCard::PrintableCard(eCardSuit pSuit, eCardValue pValue) {
  // Set the suit and value using the parameters
  mSuit = pSuit;
  mValue = pValue;

  // All cards start face up
  mFaceDown = false;
}

// Flip a card to be hidden or shown
void PrintableCard::hideCard() { mFaceDown = true; }
void PrintableCard::showCard() { mFaceDown = false; }

// Getters for the two properties (read-only)
eCardSuit PrintableCard::getSuit() const { return mSuit; }
eCardValue PrintableCard::getFaceValue() const { return mValue; }

// Print this card to the console using PDCurses
void PrintableCard::printCurses() const {
  // Is this card face down?
  if (mFaceDown) {
    attron(COLOR_PAIR(NORM_TEXT));
    printw("XXX");
    return;
  }

  // It's not face-down so output value and suit

  // Pick color according to suit
  switch (mSuit) {
  case SUIT_HEARTS:
  case SUIT_DIAMONDS:
    attron(COLOR_PAIR(RED_CARD));
    break;
  case SUIT_CLUBS:
  case SUIT_SPADES:
    attron(COLOR_PAIR(BLACK_CARD));
    break;
  }

  // Output the face value first
  switch (mValue) {
  // Ace and face cards
  case VALUE_ACE:
    printw("A");
    break;
  case VALUE_JACK:
    printw("J");
    break;
  case VALUE_QUEEN:
    printw("Q");
    break;
  case VALUE_KING:
    printw("K");
    break;

  // Sepcial case for the two-digit card 10
  case VALUE_TEN:
    printw("10");
    break;

  // Other Number Cards (can just use the value of the 'enum')
  case VALUE_TWO:
  case VALUE_THREE:
  case VALUE_FOUR:
  case VALUE_FIVE:
  case VALUE_SIX:
  case VALUE_SEVEN:
  case VALUE_EIGHT:
  case VALUE_NINE:
    printw("%c", static_cast<char>('0' + mValue));
    break;

  // Something else (only used with bad cards)
  default:
    printw("?");
    break;
  }

  // Output the suit
  switch (mSuit) {
  // WARNING: These extended character codes are only confirmed to
  // work with PDCurses on windows. Probably won't work with ncurses.
  case SUIT_HEARTS:
    addch(ACS_PICK(3, 0));
    break;
  case SUIT_DIAMONDS:
    addch(ACS_PICK(4, 0));
    break;
  case SUIT_CLUBS:
    addch(ACS_PICK(5, 0));
    break;
  case SUIT_SPADES:
    addch(ACS_PICK(6, 0));
    break;

  // Something else (only used with bad cards)
  default:
    printw("?");
    break;
  }
}
