#pragma once

#include "STLINCLUDE.h"
#include "Item.h"

enum armorType
{
  HEAD = 0,
  CHEST,
  ARMS,
  LEGS
};

class Armor : public Item
{
private:
  int type;
  std::string typeStr;
  int defense;

public:
  Armor();
  Armor(int level, int rarity);
  Armor(int type, int defense, std::string name, int level, int buyValue, int sellValue, int rarity);
  virtual ~Armor();

  // Pure virtual
  virtual Armor* clone() const;

  // Functions
  std::string toString() const;
  std::string toStringSave() const;

  // Accessors
  inline int getDefense() const
  {
    return this->defense;
  }
  inline int getType() const
  {
    return this->type;
  }

  // Static
  static dArr<std::string> names;
  static void initNames();
};