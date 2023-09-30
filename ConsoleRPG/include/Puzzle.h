#pragma once

#include "STLINCLUDE.h"

class Puzzle
{
private:
  std::string question_;
  std::vector<std::string> answers_;
  int correct_answer_;

public:
  Puzzle(std::string fileName);
  virtual ~Puzzle();
  std::string getAsString();

  inline const int& getCorrectAns() const
  {
    return correct_answer_;
  }
};
