#pragma once
#include <string_view>

constexpr std::string_view SUIT =
    "\t┌───────────────┐\n"
    "\t|  [1] spade    |\n"
    "\t|  [2] hearts   |\n"
    "\t|  [3] diamonds |\n"
    "\t|  [4] clubs    |\n"
    "\t└───────────────┘\n";
constexpr std::string_view u8_SUIT =
    "\t┌───────────────────┐\n"
    "\t|  [1] ♠ (spade)    |\n"
    "\t|  [2] ♥ (hearts)   |\n"
    "\t|  [3] ♦ (diamonds) |\n"
    "\t|  [4] ♣ (clubs)    |\n"
    "\t└───────────────────┘\n";

constexpr std::string_view RANK =
    "\t┌─────────────┐\n"
    "\t|  [1] One    |\n"
    "\t|  [2] Two    |\n"
    "\t|  [3] Three  |\n"
    "\t|  [4] Four   |\n"
    "\t|  [5] Five   |\n"
    "\t|  [6] Six    |\n"
    "\t|  [7] Seven  |\n"
    "\t|  [8] Eight  |\n"
    "\t|  [9] Nine   |\n"
    "\t|  [10] Ten   |\n"
    "\t|  [11] Jack  |\n"
    "\t|  [12] Queen |\n"
    "\t|  [13] King  |\n"
    "\t|  [14] Ace   |\n"
    "\t└─────────────┘\n";

constexpr std::string_view BOARD =
    "\t              board             \n"
    "\t┌──────────────────────────────┐\n"
    "\t|                              |\n"
    "\t|                              |\n"
    "\t|       {2}  {3}  {4}  {5}  {6}     |\n"
    "\t|                              |\n"
    "\t|              hand            |\n"
    "\t|         -------------        |\n"
    "\t|         |  {0}   {2}  |        |\n"
    "\t|         -------------        |\n"
    "\t|                              |\n"
    "\t└──────────────────────────────┘\n";

constexpr std::string_view HAND =
    "\t    hand    \n"
    "\t┌──────────┐\n"
    "\t| {0}  {1}|\n"
    "\t└──────────┘\n";

constexpr std::string_view UNICODE_CHECK =
    "\t┌─────────────────────────────────┐\n"
    "\t│ [1] ✓ check mark                │\n"
    "\t│ [2] ✗ cross mark                │\n"
    "\t│ [3] ★ star                      │\n"
    "\t│ [4] ♦ diamond                   │\n"
    "\t│ [5] ◆ filled diamond            │\n"
    "\t│ [6] ● filled circle             │\n"
    "\t│ [7] ▲ triangle                  │\n"
    "\t│ [8] ■ square                    │\n"
    "\t└─────────────────────────────────┘\n";

std::string_view getUnicodeSuitsTable();