#pragma once
#include <string_view>

constexpr std::string_view SUIT =
    "-----------------\n"
    "|  [1] spade    |\n"
    "|  [2] hearts   |\n"
    "|  [3] diamonds |\n"
    "|  [4] clubs    |\n"
    "-----------------";
constexpr std::string_view u8_SUIT =
    "---------------------\n"
    "|  [1] ♠ (spade)    |\n"
    "|  [2] ♥ (hearts)   |\n"
    "|  [3] ♦ (diamonds) |\n"
    "|  [4] ♣ (clubs)    |\n"
    "---------------------";

constexpr std::string_view RANK =
    "---------------\n"
    "|  [1] One    |\n"
    "|  [2] Two    |\n"
    "|  [3] Three  |\n"
    "|  [4] Four   |\n"
    "|  [5] Five   |\n"
    "|  [6] Six    |\n"
    "|  [7] Seven  |\n"
    "|  [8] Eight  |\n"
    "|  [9] Nine   |\n"
    "|  [10] Ten   |\n"
    "|  [11] Jack  |\n"
    "|  [12] Queen |\n"
    "|  [13] King  |\n"
    "|  [14] Ace   |\n"
    "---------------";

constexpr std::string_view BOARD =
    "              board             \n"
    "--------------------------------\n"
    "|                              |\n"
    "|                              |\n"
    "|       {2}  {3}  {4}  {5}  {6}     |\n"
    "|                              |\n"
    "|              hand            |\n"
    "|         -------------        |\n"
    "|         |  {0}   {2}  |        |\n"
    "|         -------------        |\n"
    "|                              |\n"
    "--------------------------------\n";

constexpr std::string_view HAND =
    "    hand    \n"
    "------------\n"
    "| {0}  {1}|\n"
    "--------------\n";

constexpr std::string_view UNICODE_CHECK =
    "-------------------------------\n"
    "|  [1] ✓ (check mark)         |\n"
    "|  [2] ✗ (cross mark)         |\n"
    "|  [3] ☀ (sun)               |\n"
    "|  [4] ☂ (umbrella)          |\n"
    "|  [5] ⚡ (high voltage)      |\n"
    "|  [6] ☕ (hot beverage)     |\n"
    "|  [7] 🚀 (rocket)          |\n"
    "|  [8] 🧠 (brain)              |\n"
    "-------------------------------";

std::string_view getUnicodeSuitsTable();