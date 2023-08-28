#ifndef CELL_H
#define CELL_H

class Cell {
public:
  enum State { StateNULL, Unknown, Empty, Number, Mine };
  enum Action { ActionNULL, Blank, Revealed, Uncovered, Flagged };

private:
  State state;
  Action action;
  int number;

public:
  Cell() {
    state = State ::Unknown;
    action = Action::Blank;
    number = -1;
  }

  void setState(State state) { this->state = state; }
  State getState() { return this->state; }

  void setAction(Action action) { this->action = action; }
  Action getAction() { return this->action; }

  void setNumber(int number) { this->number = number; }
  int getNumber() {
    if (state != State::Number)
      return -1;
    return this->number;
  }
};

#endif /*CELL_H*/
