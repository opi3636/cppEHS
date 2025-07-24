#include <iostream>

#include "Poker.hpp"
#include "Card.hpp"
#include "Tables.hpp"
#include <print>
#include <thread>

int main() {
    checkUnicode();
    getHandAndFlop();
    getTurnAndRiver();
}
int askUser(const GameState &gameState, const QuestionType &questionType, const std::string_view &question) {
    std::println("{}", question);
    std::print("Please enter the {0} of the {1} card: ", questionTypeToString(questionType), gameStateToString(gameState));
    int max = 0;
    if (questionType == QuestionType::RANK) {
        max = 14;
    } else if (questionType == QuestionType::SUIT) {
        max = 4;
    }
    int answer = 0;
    std::cin >> answer;
    while (answer < 0 || answer > max ) {
       std::print("Invalid input! Please try again: ");
        std::cin >> answer;
    }
    return answer;
}
void exit() {
    std::println("Press any key to exit...");
    std::cin.ignore();
    std::cin.get();
}

void getHandAndFlop() {
    getCardFromUser(GameState::HAND1);
    getCardFromUser(GameState::HAND2);
    getCardFromUser(GameState::FLOP1);
    getCardFromUser(GameState::FLOP2);
    getCardFromUser(GameState::FLOP3);
    postFlopState = true;
}

void getTurnAndRiver() {
    getCardFromUser(GameState::TURN);
    getCardFromUser(GameState::RIVER);
}

void checkUnicode() {
    std::println("{}", UNICODE_CHECK);
    char answer;
    while (true) {
        std::print("Are you able to see these symbols correctly (colors do not matter)? [y/n]: ");
        std::cin >> answer;
        answer = static_cast<char>(std::toupper(answer));
        if (answer == 'Y') {
            isUnicodeSupported = true;
            break;
        }
        if (answer == 'N') {
            isUnicodeSupported = false;
            break;
        }
        std::println("Invalid input!");
    }
}

std::string_view getUnicodeSuitsTable() {
    if (isUnicodeSupported) {
        return u8_SUIT;
    }
    return SUIT;
}

std::string gameStateToString(const GameState &gameState) {
    switch (gameState) {
        case GameState::HAND1:
            return "first hand";
        case GameState::HAND2:
            return "second hand";
        case GameState::FLOP1:
            return "first flops";
        case GameState::FLOP2:
            return "second flop";
        case GameState::FLOP3:
            return "third flop";
        default:
            return "invalid game state";
    }
}

std::string questionTypeToString(const QuestionType &questionType) {
    if (questionType == QuestionType::RANK) {
        return "rank";
    }
    return "suit";
}

