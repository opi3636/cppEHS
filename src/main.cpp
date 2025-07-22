#include <iostream>

#include "Poker.hpp"
#include "Card.hpp"
#include "Tables.hpp"
#include <print>
#include <thread>

int main() {
    checkUnicode();
    getHandAndFlop();

}

int askUser(const std::string_view question, const std::string_view options, std::string_view selection, const int max) {
    std::print("{}", std::format("{}\n", question));
    std::print("{}", std::format("{}\n", options));
    std::print("Select your {} and press enter: ", selection);
    int answer = 0;
    std::cin >> answer;
    while (answer <  0 || answer > max) {
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
    getCardFromUser(GameState::START, CardArrayLocation::HAND1);
    getCardFromUser(GameState::START, CardArrayLocation::HAND2);
    getCardFromUser(GameState::FLOP, CardArrayLocation::FLOP1);
    getCardFromUser(GameState::FLOP, CardArrayLocation::FLOP2);
    getCardFromUser(GameState::FLOP, CardArrayLocation::FLOP3);
    postFlopState = true;
}

void getTurnAndRiver() {
    getCardFromUser(GameState::TURN, CardArrayLocation::TURN);
    getCardFromUser(GameState::RIVER, CardArrayLocation::RIVER);
}

void checkUnicode() {
    std::println("{}", UNICODE_CHECK);
    char answer;
    while (true) {
        std::print("Are you able to see these soymbols correctly (colors do not matter)? [y/n]: ");
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

std::string_view unicodeSuitsTable() {
    if (isUnicodeSupported) {
        return u8_SUIT;
    }
    return SUIT;
}