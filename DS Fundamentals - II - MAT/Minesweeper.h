#include "Board.h"

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

class Minesweeper {
  Board *board;
  int _total_mines, _total_moves, _total_discovered;
  int rows, columns;
  bool steppedOnAMine;
  bool flag;

  int digAround(int i, int j) {
    int mines = 0;
    for (int a = -1; a < 2; a++) {
      for (int b = -1; b < 2; b++) {
        if (board->getState(i + a, j + b) == Cell::State::Mine) {
          flag = false;
          mines++;
          continue;
        }
        if (!flag)
          continue;
        if (board->getAction(i + a, j + b) == Cell::Action::Blank) {
          board->setAction(i + a, j + b, Cell::Action::Uncovered);
          board->setState(i + a, j + b, Cell::State::Number,
                          digAround(i + a, j + b));
          _total_discovered++;
        }
      }
    }
    return mines;
  }

  void placeMinesInRandomLocations() {
    int total_cells = rows * columns;
    _total_mines = getRandomInt(total_cells / 2,
                                total_cells / 8 > 1 ? total_cells / 8 : 1);
    // Placing mines in random locations
    for (int i = 0; i < _total_mines; i++) {
      int x = getRandomInt(rows - 1, 0);
      int y = getRandomInt(columns - 1, 0);
      if (board->getAction(x, y) != Cell::Action::Blank) {
        i--;
        continue;
      }
      board->setState(x, y, Cell::State::Mine);
    }
    // used for debugging
    // std::cout << board->get() << std::endl;
  }

  int getRandomInt(int upperBound, int lowerBound) {
    return rand() % (upperBound - lowerBound + 1);
  }

public:
  Minesweeper(int _m, int _n) {
    srand(time(0));
    board = NULL;
    rows = _m;
    columns = _n;
  }

  void start() {
    if (board != NULL)
      delete board;

    steppedOnAMine = false;

    _total_discovered = 0;
    _total_moves = 0;
    _total_mines = 0;

    board = new Board(rows, columns);
  }

  std::string reveal(int x, int y, int action) {
    if (board->getAction(x, y) != Cell::Action::Blank &&
        board->getAction(x, y) != Cell::Action::Flagged)
      return board->get();

    flag = true;

    switch (action) {
    case 1:
      board->setAction(x, y, Cell::Action::Flagged);
      return board->get();
    case 2:
      board->setAction(x, y, Cell::Action::Revealed);
      break;
    default:
      return board->get();
    }

    Cell::State state = board->getState(x, y);
    if (state == Cell::State::Mine) {
      steppedOnAMine = true;
      return board->get();
    }

    if (_total_moves < 1)
      placeMinesInRandomLocations();
    _total_moves++;

    board->setState(x, y, Cell::State::Number, digAround(x, y));
    _total_discovered++;

    return board->get();
  }

  bool completed() { return didPlayerWon() || didPlayerLost(); }

  bool didPlayerWon() {
    return (rows * columns) - _total_mines == _total_discovered &&
           !steppedOnAMine;
  }
  bool didPlayerLost() { return steppedOnAMine; }

  ~Minesweeper() {
    if (board != NULL)
      delete board;
  }
};

#endif /*MINESWEEPER_H*/