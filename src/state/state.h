#pragma once 

enum StateNo {
  A,
  B
};

class State {
public:
  virtual StateNo exec() = 0;
};