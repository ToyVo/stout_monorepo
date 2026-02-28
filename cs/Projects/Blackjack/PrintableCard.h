#pragma once // Guard against multiple inclusions

// Two kinds of text colors used with PDCurses
// These get set in main.cpp
#define BLACK_CARD 4
#define RED_CARD 5

// The four standard suits for playing cards
// (used with the PrintableCard constructor)
enum eCardSuit {
  SUIT_HEARTS,
  SUIT_DIAMONDS,
  SUIT_CLUBS,
  SUIT_SPADES,

  // Reserved for a 'bad' card
  SUIT_UNKNOWN
};

// The thirteen standard face values for playing cards
// (used with the PrintableCard constructor)
//
// Note: for face values of 2 to 10, cast this enum to
// an unsigned integer to get a reasonable 'score' for
// that card in most card games.
enum eCardValue {
  VALUE_ACE = 1,
  VALUE_TWO = 2,
  VALUE_THREE,
  VALUE_FOUR,
  VALUE_FIVE,
  VALUE_SIX,
  VALUE_SEVEN,
  VALUE_EIGHT,
  VALUE_NINE,
  VALUE_TEN,
  VALUE_JACK,
  VALUE_QUEEN,
  VALUE_KING,

  // Reserved for a 'bad' card
  VALUE_UNKNOWN
};

/* PrintableCard - A playing card that can be printed to the screen */
class PrintableCard {
public:
  // Constructors
  PrintableCard(eCardSuit pSuit = SUIT_UNKNOWN,
                eCardValue pValue = VALUE_UNKNOWN);

  // Accessors for the two properties
  eCardSuit getSuit() const;
  eCardValue getFaceValue() const;

  // Turn this card over
  void hideCard();
  void showCard();

  // Output this card for PDcurses
  void printCurses() const;

  // A bad card (compare to this to see if you have a 'bad' card)
  static PrintableCard badCard;

private:
  // This card's suit and face value
  eCardSuit mSuit;
  eCardValue mValue;

  // Is this card currently face down?
  bool mFaceDown;
};
