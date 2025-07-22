#pragma once

enum class Suit {
    SPADES = 1,
    HEARTS = 2,
    DIAMONDS = 3,
    CLUBS = 4
};

enum class Rank {
    ONE = 1, TWO = 2, THREE = 3,
    FOUR = 4, FIVE = 5,SIX = 6,
    SEVEN = 7, EIGHT = 8, NINE = 9,
    TEN = 10, JACK = 11, QUEEN = 12,
    KING = 13, ACE = 14
};

enum class GameState {
    START = 1,
    FLOP = 2,
    TURN = 3,
    RIVER = 4
};

enum class CardArrayLocation {
    HAND1 = 0,
    HAND2 = 1,
    FLOP1 = 2,
    FLOP2 = 3,
    FLOP3 = 4,
    TURN = 5,
    RIVER = 6
};

inline bool isUnicodeSupported = false;
inline bool postFlopState = false;

void waitForNextCard(bool postFlop);
void exit();
int askUser(std::string_view question, std::string_view options, std::string_view selection, int max);
void getHandAndFlop();
void checkUnicode();

