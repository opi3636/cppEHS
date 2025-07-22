#pragma once

#include <array>
#include <string>
#include "Poker.hpp"

#define SUIT_MAX 4
#define RANK_MAX 14

struct Card {
    int rank = 0;
    int suit = 0;

    [[nodiscard]] bool isValid() const {
        return rank > 0 && suit > 0 && rank <14 && suit < 5;
    }
};

inline std::array<Card, 7> cards {};

Card askCard(GameState gameState, int arrayLocation);
std::string cardToString(const Card& card);
std::string rankToString(const int& rank);
void getCardFromUser(GameState gameStage, CardArrayLocation arrayLocation);
std::string suitToString(const int& suit);
char suitToChar(const int& suit);

std::string_view suitToUnicodeSymbol(const int &suit);
char rankToChar(const int& rank);
std::string cardToShortString(const Card& card);

// func that accepts a varible amount(called ellipsis) of Card& and prints their string value. depends on cardToString fix
// func that takes the whole cards array and prints the board (hopefully as a nice table. std::format should be able to format predefined strings, its 4AM I don't want to test that rn)

void printHand(const Card& card1, const Card& card2);
void printBaord (const std::array<Card, 7>& cards);