#include "Card.hpp"

#include <algorithm>
#include <iostream>
#include "Tables.hpp"
#include <print>

bool Card::operator != (const Card &other) const {
    return this->suit != other.suit || this->rank != other.rank;
}
bool Card::operator == (const Card &other) const {
    return this->suit == other.suit && this->rank == other.rank;
}
bool Card::operator == (const Card *other) const {
    return this->suit == other->suit && this->rank == other->rank;
}

Card::Card(const int rank, const int suit) {
    this->rank = rank;
    this->suit = suit;
}
bool Card::isValid() const {
    return this->rank > 0 && this->rank >= 14 && this->suit > 0 && this->suit <= 4;
}



std::string Card::toString() const {
    std::string string = "Your card is "; //make this a perameter so I can do a matzhiki
    string += rankToString();
    return string += suitToString();
}

std::string Card::suitToString() const {
    switch (static_cast<Suit>(this->suit)) {
        case Suit::SPADES: return "Spades";
        case Suit::HEARTS: return "Hearts";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::CLUBS: return "Clubs";
        default: return "";
    }
}

char Card::suitToChar() const {
    switch (static_cast<Suit>(this->suit)) {
        case Suit::SPADES: return 's';
        case Suit::HEARTS: return 'h';
        case Suit::DIAMONDS: return 'd';
        case Suit::CLUBS: return 'c';
        default: return '\0' ;
    }
}

std::string Card::rankToString() const {
    switch (static_cast<Rank>(this->rank)) {
        case Rank::ONE: return "the One of ";
        case Rank::TWO: return "the Two of ";
        case Rank::THREE: return "the Three of ";
        case Rank::FOUR: return "the Four of ";
        case Rank::FIVE: return "the Five of ";
        case Rank::SIX: return "the Six of ";
        case Rank::SEVEN: return "the Seven of ";
        case Rank::EIGHT: return "the Eight of ";
        case Rank::NINE: return "the Nine of ";
        case Rank::TEN: return "the Ten of ";
        case Rank::JACK: return "the Jack of ";
        case Rank::QUEEN: return "the Queen of ";
        case Rank::KING: return "the King of ";
        case Rank::ACE: return "an Ace of ";
        default: return "";
    }
}

char Card::rankToChar() const {
    switch (static_cast<Rank>(this->rank)) {
        case Rank::ONE: return '1';
        case Rank::TWO: return '2';
        case Rank::THREE: return '3';
        case Rank::FOUR: return '4';
        case Rank::FIVE: return '5';
        case Rank::SIX: return '6';
        case Rank::SEVEN: return '7';
        case Rank::EIGHT: return '8';
        case Rank::NINE: return '9';
        case Rank::TEN: return 'T';
        case Rank::JACK: return 'J';
        case Rank::QUEEN: return 'Q';
        case Rank::KING: return 'K';
        case Rank::ACE: return 'A';
        default: return '\0';
    }
}

std::string Card::toShortString() const {
    //if windows no Unicode matzhik and if no windows ken (forrest) Unicode matzhik
    if (isUnicodeSupported) {
        return rankToChar() + suitToUnicodeSymbol();
    }
    return std::to_string(rankToChar()) + suitToChar();
}
std::string Card::suitToUnicodeSymbol() const {
    switch (static_cast<Suit>(this->suit)) {
        case Suit::SPADES: return "♠";
        case Suit::HEARTS: return "♥";
        case Suit::CLUBS: return "♣";
        case Suit::DIAMONDS: return "♦";
        default: return "";
    }
}

bool Card::alradyPulled() const {
    return std::ranges::any_of(cards, [this](const Card &card) {
        return card == *this;
    });
}

Card askCard(const GameState gameState) {
    const int suit = askUser(gameState, QuestionType::SUIT, getUnicodeSuitsTable());
    const int rank = askUser(gameState, QuestionType::RANK, RANK);
    return {rank, suit};
}

void printHand() {
    std::println("{}", std::format(HAND, cards[static_cast<int>(GameState::HAND1)].toShortString(), cards[static_cast<int>(GameState::HAND2)].toShortString()));
}

void printBoard(const std::array<Card, 7> &cards) {
    std::string hand1 = cards[static_cast<int>(GameState::HAND1)].toShortString();
    std::string hand2 = cards[static_cast<int>(GameState::HAND2)].toShortString();
    std::string flop1 = cards[static_cast<int>(GameState::FLOP1)].toShortString();
    std::string flop2 = cards[static_cast<int>(GameState::FLOP2)].toShortString();
    std::string flop3 = cards[static_cast<int>(GameState::FLOP3)].toShortString();
    std::string turn = "XX";
    std::string river = "XX";
    if (cards[static_cast<int>(GameState::TURN)].isValid()) {
        turn = cards[static_cast<int>(GameState::TURN)].toShortString();
    }
    if (cards[static_cast<int>(GameState::RIVER)].isValid()) {
        river = cards[static_cast<int>(GameState::RIVER)].toShortString();
    }
    std::println("{}", std::format(BOARD, hand1, hand2, flop1, flop2, flop3, turn, river ));
}



void getCardFromUser(const GameState gameState) {
    Card card = askCard(gameState);
    while (card.alradyPulled()) {
        std::println("Card has alrady been pulled! Please try again");
        card = askCard(gameState);
    }
    cards[static_cast<int>(gameState)] = card;
    std::println("\n{}\n", card.toString());
    waitForNextCard(gameState);
}

void waitForNextCard(const GameState &gameState) {
    if (gameState == GameState::FLOP3 || gameState == GameState::TURN) {
        char answer;
        while (true) {
            std::println("Press B to see the current board\n"
             "Press H to see your hand\n"
             "Press C to input the next card\n"
             "Press F to fold");
            std::print("What do you want to do? ");
            std::cin >> answer;
            answer = static_cast<char>(toupper(answer));
            if (answer == 'B') {
                printBoard(cards);
            }
            if (answer == 'H') {
                printHand();
            }
            if (answer == 'C') {
                std::println("Please enter the next card");
                return;
            }
            if (answer == 'F') {
                quitGame();
                return;
            }
        }
    }
    if (gameState == GameState::RIVER) {

    }
    std::println("Press any key to input the next card...");
    std::cin.ignore();
    std::cin.get();
}

