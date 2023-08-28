#include "Cell.h"
#include <iostream>

#ifndef BOARD_H
#define BOARD_H

class Board {
  // m - rows, n - columns
  int m, n;
  Cell **cells;

  std::string getValue(int i, int j) {
    Cell *current = &cells[i][j];
    // used for debugging
    // std::cout << "i:" << i << " j:" << j << " state:" << current->getState()
    // << " action:" << current->getAction() << std::endl;
    switch (current->getAction()) {
    case Cell::Action::Flagged:
      return "F";
    case Cell::Action::Revealed:
    case Cell::Action::Uncovered:
      switch (current->getState()) {
      case Cell::State::Mine:
        return "*";
      case Cell::State::Number:
        return std::to_string(current->getNumber());
      }
    }
    return " ";
  }

public:
  Board(int _m, int _n) {
    m = _m;
    n = _n;
    cells = new Cell *[m];
    for (int i = 0; i < m; i++) {
      cells[i] = new Cell[n];
    }
  }
  ~Board() {
    for (int i = 0; i < m; i++) {
      delete[] cells[i];
    }
    delete[] cells;
  }

  void setState(int x, int y, Cell::State state) {
    if (x < 0 || x >= m || y < 0 || y >= n)
      return;
    cells[x][y].setState(state);
  }

  void setState(int x, int y, Cell::State state, int number) {
    if (x < 0 || x >= m || y < 0 || y >= n)
      return;
    if (state != Cell::State::Number)
      return;
    cells[x][y].setState(state);
    cells[x][y].setNumber(number);
  }

  Cell::State getState(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n)
      return (Cell::State)NULL;
    return cells[x][y].getState();
  }

  void setAction(int x, int y, Cell::Action action) {
    if (x < 0 || x >= m || y < 0 || y >= n)
      return;
    cells[x][y].setAction(action);
  }

  Cell::Action getAction(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n)
      return (Cell::Action)NULL;
    return cells[x][y].getAction();
  }

  std::string get() {
    // Returns a string of the board visualisation
    std::string *row_seperator = rowSeperator();
    std::string *column_header = columnHeader();

    std::string output = "";

    output.append(*column_header);
    output.append(*row_seperator);
    for (int i = 0; i < m; i++) {
      output.push_back('|');
      for (int j = 0; j < n; j++) {
        output.append(getValue(i, j));
        output.push_back('|');
      }
      // Prints the Row number
      output.push_back(' ');
      output.append(std::to_string(i + 1));
      output.push_back('\n');
      output.append(*row_seperator);
    }

    return output;
  }

private:
  std::string *rowSeperator() {
    // Returns a row string which can be used as seperator
    static std::string output = "";
    if (output.empty()) {
      for (int i = 0; i < n; i++) {
        output.append("--");
      }
      output.append("-\n");
    }
    return &output;
  }
  std::string *columnHeader() {
    // Returns a row string which is used as column header
    static std::string output = "";
    if (output.empty()) {
      for (int i = 0; i < n; i++) {
        output.append(" ");
        output.append(std::to_string(i + 1));
      }
      output.append(" \n");
    }
    return &output;
  }
};

#endif /*BOARD_H*/
