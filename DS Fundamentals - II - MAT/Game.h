#include "Minesweeper.h"

#ifndef GAME_H
#define GAME_H

class Game {
  Minesweeper *minesweeper;
  void session() {
    std::cout << Constants::gameStartsString << std::endl;
    minesweeper->start();

    int x, y, flagged;
    bool flag;
    while (!minesweeper->completed()) {
      std::cout << "Enter 1 for flagging and 2 for revealing:";
      std::cin >> flagged;

      std::cout << "Which row[1-" << Constants::rows << "]?";
      std::cin >> x;
      std::cout << "Which column[1-" << Constants::columns << "]?";
      std::cin >> y;

      std::cout << minesweeper->reveal(x - 1, y - 1, flagged) << std::endl;
    }
    if (minesweeper->didPlayerWon()) {
      std::cout << Constants::gameWonString << std::endl;
    } else {
      std::cout << Constants::gameLostString << std::endl;
    }
  }

public:
  class Constants {
  public:
    static const int rows = 9, columns = 9;
    static const std::string welcomeHeader;
    static const std::string rulesString;
    static const std::string howToPlayString;
    static const std::string outroMessage;

    static const std::string gameStartsString;
    static const std::string gameWonString;
    static const std::string gameLostString;
  };

  Game() { minesweeper = new Minesweeper(Constants::rows, Constants::columns); }

  void start() {
    std::cout << Constants::welcomeHeader << std::endl;
    std::cout << Constants::rulesString << std::endl;
    std::cout << Constants::howToPlayString << std::endl;

    char choice = 'y';
    while (choice != 'N' && choice != 'n') {
      std::cout << "Enter Y/y to continue or N/n to close the game?";
      std::cin >> choice;
      if (choice == 'Y' || choice == 'y')
        session();
    }

    std::cout << Constants::outroMessage << std::endl;
  }

  ~Game() { delete minesweeper; }
};

const std::string Game::Constants::welcomeHeader = R"(
|---------------------------------------------------|
|                                                   |
|               WELCOME TO MINESWEEPER!             |
|                                                   |
|---------------------------------------------------|
)";

const std::string Game::Constants::rulesString = R"(
###################################################
                        Rules
###################################################
1. The game board consists of a 9x9 grid of cells.
2. Randomly placed mines are hidden within the cells.
3. Upon making the first move, the cells will be uncovered, revealing numbers.
4. The numbers indicate the count of mines adjacent to each cell.
5. Your goal is to uncover all non-mine cells.
6. If you successfully uncover all non-mine cells, it's considered a successful completion of the game.
)";

const std::string Game::Constants::howToPlayString = R"(
###################################################
                    How to Play
###################################################
1. Each turn, you will be prompted to enter two integers: x and y.
   - x represents the row number.
   - y represents the column number of the cell you want to uncover.
2. If the cell you choose contains a mine, you lose the game.
   Otherwise, continue to the next step.
3. Repeat step 1 for your subsequent moves until you uncover all non-mine cells or encounter a mine.
)";

const std::string Game::Constants::gameStartsString = R"(
-----------------------------------------------------
|                                                   |
|                 GAME STARTS!                      |
|                                                   |
-----------------------------------------------------
)";

const std::string Game::Constants::gameWonString = R"(
-----------------------------------------------------
|                                                   |
|             CONGRATULATIONS! YOU WON!             |
|                                                   |
-----------------------------------------------------
)";

const std::string Game::Constants::gameLostString = R"(
-----------------------------------------------------
|                                                   |
|            GAME OVER! YOU LOST!                   |
|                                                   |
-----------------------------------------------------
)";

const std::string Game::Constants::outroMessage = R"(
-----------------------------------------------------
|                                                   |
|       Thank you for playing! Hope you had a       |
|       fantastic time. We look forward to seeing   |
|       you again for more fun and excitement!      |
|                                                   |
-----------------------------------------------------
)";

#endif /*GAME_H*/