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
    int rank = 0;
    int suit = 0;
    [[nodiscard]] bool isValid() const;
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string toShortString() const;
private:
    [[nodiscard]] char suitToChar() const;
    [[nodiscard]] char rankToChar() const;
    [[nodiscard]] std::string rankToString() const;
    [[nodiscard]] std::string suitToString() const;
    [[nodiscard]] std::string suitToUnicodeSymbol() const;
};

inline std::array<Card, 7> cards {}; //maybe make this a vector?

Card askCard(GameState gameState, int arrayLocation);
void getCardFromUser(GameState gameStage, CardArrayLocation arrayLocation);

// func that accepts a varible amount(called ellipsis) of Card& and prints their string value. depends on cardToString fix
// func that takes the whole cards array and prints the board (hopefully as a nice table. std::format should be able to format predefined strings, its 4AM I don't want to test that rn)

void printHand(const Card& card1, const Card& card2);
void printBoard (const std::array<Card, 7>& cards);

