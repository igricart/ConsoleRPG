#pragma once

#include "STLINCLUDE.h"

#include "Character.h"
#include "Enemy.h"
#include "Puzzle.h"
#include "Boss.h"
#include <thread>
#include <chrono>
#include <optional>

class Event
{
private:
  void printShop(Inventory& inventory);
  void printShopMenu() const;
  void validateShopInput(size_t& choice, size_t max_value);
  std::optional<size_t> enterOrInput(size_t max_value);

public:
  Event();
  virtual ~Event();
  void generateEvent(Character& character, std::vector<Enemy>& enemies);

  // Events
  // TODO: Sort items based on type (weapon/armor) and then based on type/rarity
  void shopEncouter(Character& character);
  void enemyEncouter(Character& character, std::vector<Enemy>& enemies);
  void puzzleEncouter(Character& character);
  // TODO: Create boss
  //  void bossEncouter(Character& character, Boss& boss);

  // statics
  static int nrOfEvents;
};
