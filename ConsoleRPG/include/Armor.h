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
  int type_;
  std::string type_str_;
  int defense_;

public:
  Armor(int level, int rarity);
  Armor(int type, int defense, std::string name, int level, int buyValue, int sellValue, int rarity);
  ~Armor();

  // Pure virtual
  virtual std::shared_ptr<Item> clone() const override;

  // Functions
  std::string toString() const;
  std::string toStringSave() const;

  // Accessors
  int getDefense() const;
  int getType() const;

  // Static
  static std::vector<std::string> names;
  static void initNames();
};