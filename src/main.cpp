#include <iostream>
#include <print>
#include <random>
#include "Poker.hpp"
#include "Card.hpp"
#include "Tables.hpp"


int main() {
    checkUnicode();
    getHandAndFlop();
    getTurnAndRiver();
    if (const bool playAgain = askYesNo("Do you wish to play again?", true); !playAgain) {
        quitGame();
    }
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
void quitGame() {
    std::println("Press any key to exit...");
    std::cin.ignore();
    std::cin.get();
    exit(0);
}

void getHandAndFlop() {
    getCardFromUser(GameState::HAND1);
    getCardFromUser(GameState::HAND2);
    getCardFromUser(GameState::FLOP1);
    getCardFromUser(GameState::FLOP2);
    postFlopState = true;
    getCardFromUser(GameState::FLOP3);
}

void getTurnAndRiver() {
    getCardFromUser(GameState::TURN);
    getCardFromUser(GameState::RIVER);
}

void checkUnicode() {
    std::println("{}", UNICODE_CHECK);
    isUnicodeSupported = askYesNo("Are you able to see these symbols correctly?", false);
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
        case GameState::RIVER:
            return "river";
        case GameState::TURN:
            return "turn";
        default:
            return "invalid game state";
    }
}

std::string questionTypeToString(const QuestionType& questionType) {
    if (questionType == QuestionType::RANK) {
        return "rank";
    }
    return "suit";
}

void createDummyHandAndFlop() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution rank(0, 14);
    std::uniform_int_distribution suit(0, 4);
    cards[static_cast<int>(GameState::HAND1)] = Card(rank(gen), suit(gen));
    cards[static_cast<int>(GameState::HAND2)] = Card(rank(gen), suit(gen));
    cards[static_cast<int>(GameState::FLOP1)] = Card(rank(gen), suit(gen));
    cards[static_cast<int>(GameState::FLOP2)] = Card(rank(gen), suit(gen));
    cards[static_cast<int>(GameState::FLOP3)] = Card(rank(gen), suit(gen));
    postFlopState = true;
}

bool askYesNo(const std::string& question, const bool defaultYes) {
    std::string suffix = " [y/N]: ";
    if (defaultYes) {
        suffix = " [Y/n]: ";
    }
    while (true) {
        std::print("{}", question + suffix);
        std::string answer;
        std::getline(std::cin, answer);
        std::transform(answer.begin(), answer.end(), answer.begin(), toupper);
        if (answer.empty() && defaultYes) {
            return true;
        }
        if (answer.empty()) {
            return false;
        }
        if (answer == "N") {
            return false;
        }
        if (answer == "N") {
            return false;
        }
        std::println("Invalid input!");
    }
}