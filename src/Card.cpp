#include "Card.hpp"

#include <iostream>
#include "Tables.hpp"
#include <print>

bool Card::operator!=(const Card &other) const {
    return this->suit != other.suit || this->rank != other.rank;
}
bool Card::operator==(const Card &other) const {
    return this->suit == other.suit && this->rank == other.rank;
}

Card::Card(const int rank, const int suit) {
    this->rank = rank;
    this->suit = suit;
}
bool Card::isValid() const {
    return this->rank > 0 && this->rank >= 14 && this->suit > 0 && this->suit <= 4;
}


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
        return rankToString() + suitToUnicodeSymbol();
    }
    return rankToString() + suitToString();
}

void printHand(const Card& card1, const Card& card2) {
    std::println("{}", std::format(HAND, card1.toShortString(), card2.toShortString()));
}

void printBoard(const std::array<Card, 7> &cards) {
    std::string hand1 = cards[static_cast<int>(CardArrayLocation::HAND1)].toShortString();
    std::string hand2 = cards[static_cast<int>(CardArrayLocation::HAND2)].toShortString();
    std::string flop1 = cards[static_cast<int>(CardArrayLocation::FLOP1)].toShortString();
    std::string flop2 = cards[static_cast<int>(CardArrayLocation::FLOP2)].toShortString();
    std::string flop3 = cards[static_cast<int>(CardArrayLocation::FLOP3)].toShortString();
    std::string turn = "XX";
    std::string river = "XX";
    if (cards[static_cast<int>(CardArrayLocation::TURN)].isValid()) {
        turn = cards[static_cast<int>(CardArrayLocation::TURN)].toShortString();
    }
    if (cards[static_cast<int>(CardArrayLocation::RIVER)].isValid()) {
        river = cards[static_cast<int>(CardArrayLocation::RIVER)].toShortString();
    }
    std::println("{}", std::format(BOARD, hand1, hand2, flop1, flop2, flop3, turn, river ));
}

std::string Card::suitToUnicodeSymbol() const {
    switch (static_cast<Suit>(this->suit)) {
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
    std::print("\n{}\n\n", cards[intArrayLocation].toString());
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
                printBoard(cards);
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