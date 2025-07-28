#pragma once

//game class maybe idk think about it later

enum class GameState {
    HAND1 = 0,
    HAND2 = 1,
    FLOP1 = 2,
    FLOP2 = 3,
    FLOP3 = 4,
    TURN = 5,
    RIVER = 6
};

enum class QuestionType {
    RANK = 1,
    SUIT = 2
};

inline bool isUnicodeSupported = false;
inline bool postFlopState = false;

void waitForNextCard(const GameState &gameState);
void quitGame();
int askUser(const GameState &gameState, const QuestionType &questionType, const std::string_view &question);
void getHandAndFlop();
void getTurnAndRiver();
void checkUnicode();
std::string gameStateToString(const GameState &gameState);
std::string questionTypeToString(const QuestionType &questionType);
void createDummyHandAndFlop();
bool askYesNo(std::string question, bool defaultYes);