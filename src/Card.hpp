#pragma once

#include <array>
#include <string>
#include "Poker.hpp"

#define SUIT_MAX 4
#define RANK_MAX 14

/*
 * !! Refactor and make Card a class instead of a struct !!
 */
class Card {
public:
    Card(int rank, int suit);
    Card() = default;
    int rank = 0;
    int suit = 0;
    [[nodiscard]] bool isValid() const;
    bool operator == (const Card& other) const;
    bool operator == (const Card *other) const;
    bool operator != (const Card& other) const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string toShortString() const;
    [[nodiscard]] bool alradyPulled() const;
private:
    [[nodiscard]] char suitToChar() const;
    [[nodiscard]] char rankToChar() const;
    [[nodiscard]] std::string rankToString() const;
    [[nodiscard]] std::string suitToString() const;
    [[nodiscard]] std::string suitToUnicodeSymbol() const;
};

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


inline std::array<Card, 7> cards {}; //maybe make this a vector? //no need, just needed to add default constructor

Card askCard(GameState gameState);
void getCardFromUser(GameState gameStage);

// func that accepts a varible amount(called ellipsis) of Card& and prints their string value. depends on cardToString fix
// func that takes the whole cards array and prints the board (hopefully as a nice table. std::format should be able to format predefined strings, its 4AM I don't want to test that rn)

void printHand();
void printBoard (const std::array<Card, 7>& cards);

