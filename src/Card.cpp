#include "Card.hpp"

#include <iostream>
#include "Tables.hpp"
#include <print>

Card askCard(const GameState gameState, const int arrayLocation) {
    /*
    switch (gameState) {
        case GameState::START: {
            if (arrayLocation == static_cast<int>(CardArrayLocation::HAND1)) {
                const int suit = askUser("Enter the suit of your first card: ", unicodeSuitsTable() , "suit", SUIT_MAX);
                const int rank = askUser("Enter the rank of your first card: ", RANK, "rank", RANK_MAX);
                return Card(rank, suit);
            }
            const int suit = askUser("Enter the suit of your second card: ", unicodeSuitsTable(), "suit", SUIT_MAX);
            const int rank = askUser("Enter the rank of your second card: ", RANK, "rank", RANK_MAX);
            return Card(rank, suit);
        }
        case GameState::FLOP: {
            if (arrayLocation == static_cast<int>(CardArrayLocation::FLOP1)) {
                const int suit = askUser("Enter the suit of the first flop card: ", unicodeSuitsTable(), "suit", SUIT_MAX);
                const int rank = askUser("Enter the rank of the first flop card: ", RANK, "rank", RANK_MAX);
                return Card(rank, suit);
            }
            if (arrayLocation == static_cast<int>(CardArrayLocation::FLOP2)) {
                const int suit = askUser("Enter the suit of the second flop card: ", unicodeSuitsTable(), "suit", SUIT_MAX);
                const int rank = askUser("Enter the rank of the second flop card: ", RANK, "rank", RANK_MAX);
                return Card(rank, suit);
            }
            const int suit = askUser("Enter the suit of the third flop card: ", unicodeSuitsTable(), "suit", SUIT_MAX);
            const int rank = askUser("Enter the rank of the third flop card: ", RANK, "rank", RANK_MAX);
            return Card(rank, suit);
        }
        case GameState::TURN: {
            const int suit = askUser("Enter the suit of turn card: ", unicodeSuitsTable(), "suit", SUIT_MAX);
            const int rank = askUser("Enter the rank of turn card: ", RANK, "rank", RANK_MAX);
            return Card(rank, suit);
        }
        case GameState::RIVER: {
            const int suit = askUser("Enter the suit of the river card: ", unicodeSuitsTable(), "suit", SUIT_MAX);
            const int rank = askUser("Enter the rank of the river card: ", RANK, "rank", RANK_MAX);
            return Card(rank, suit);
        }
        default:
            return Card(0,0);
    }
    */
    // 🤢 shits ass. fix this
}

std::string cardToString(const Card& card) {
    std::string transtaltion = "Your card is "; //make this a perameter so I can do a matzhiki
    transtaltion += rankToString(card.rank);
    return transtaltion += suitToString(card.suit);
}

std::string suitToString(const int& suit) {
    switch (static_cast<Suit>(suit)) {
        case Suit::SPADES: return "Spades";
        case Suit::HEARTS: return "Hearts";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::CLUBS: return "Clubs";
        default: return "";
    }
}

char suitToChar(const int& suit) {
    switch (static_cast<Suit>(suit)) {
        case Suit::SPADES: return 's';
        case Suit::HEARTS: return 'h';
        case Suit::DIAMONDS: return 'd';
        case Suit::CLUBS: return 'c';
        default: return '\0' ;
    }
}

std::string rankToString(const int& rank) {
    switch (static_cast<Rank>(rank)) {
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

char rankToChar(const int& rank) {
    switch (static_cast<Rank>(rank)) {
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

std::string cardToShortString(const Card& card) {
    //if windows no Unicode matzhik and if no windows ken (forrest) Unicode matzhik
    if (isUnicodeSupported) {
        return rankToString(card.rank) + suitToUnicodeSymbol(card.suit);
    }
    return rankToString(card.rank) + suitToString(card.suit);
}

void printHand(const Card& card1, const Card& card2) {
    std::println("{}", std::format(HAND, cardToShortString(card1), cardToShortString(card2)));
}

void printBaord(const std::array<Card, 7> &cards) {
    std::string hand1 = cardToShortString(cards[static_cast<int>(CardArrayLocation::HAND1)]);
    std::string hand2 = cardToShortString(cards[static_cast<int>(CardArrayLocation::HAND2)]);
    std::string flop1 = cardToShortString(cards[static_cast<int>(CardArrayLocation::FLOP1)]);
    std::string flop2 = cardToShortString(cards[static_cast<int>(CardArrayLocation::FLOP2)]);
    std::string flop3 = cardToShortString(cards[static_cast<int>(CardArrayLocation::FLOP3)]);
    std::string turn = "XX";
    std::string river = "XX";
    if (cards[static_cast<int>(CardArrayLocation::TURN)].isValid()) {
        turn = cardToShortString(cards[static_cast<int>(CardArrayLocation::TURN)]);
    }
    if (cards[static_cast<int>(CardArrayLocation::RIVER)].isValid()) {
        river = cardToShortString(cards[static_cast<int>(CardArrayLocation::RIVER)]);
    }
    std::println("{}", std::format(BOARD, hand1, hand2, flop1, flop2, flop3, turn, river ));
}

std::string_view suitToUnicodeSymbol(const int &suit) {
    switch (static_cast<Suit>(suit)) {
        case Suit::SPADES: return "♠";
        case Suit::HEARTS: return "♥";
        case Suit::DIAMONDS: return "♣";
        case Suit::CLUBS: return "♦";
        default: return "";
    }
}

void getCardFromUser(const GameState gameStage, const CardArrayLocation arrayLocation) {
    const int intArrayLocation = static_cast<int>(arrayLocation);
    cards[intArrayLocation] = askCard(gameStage, intArrayLocation);
    std::print("\n{}\n\n", cardToString(cards[intArrayLocation]));
    waitForNextCard(postFlopState);
}

void waitForNextCard(const bool postFlop) {
    if (postFlop) {
        std::println("Press B to see the current board\n"
                     "Press H to see your hand\n"
                     "Press C to input the next card");
        char answer;
        while (true) {
            std::print("What do you want to do? ");
            std::cin >> answer;
            answer = static_cast<char>(toupper(answer));
            std::println("{}", static_cast<int>(answer));
            if (answer == 'B') {
                printBaord(cards);
                return;
            }
            if (answer == 'H') {
                printHand(cards[static_cast<int>(CardArrayLocation::HAND1)], cards[static_cast<int>(CardArrayLocation::HAND2)]);
                return;
            }
            if (answer == 'C') {
                return;
            }
            std::println("Invalid input!");
        }
    }
    std::println("Press any key to input the next card...");
    std::cin.ignore();
    std::cin.get();
}