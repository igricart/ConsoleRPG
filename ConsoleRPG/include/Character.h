#pragma once

#include <math.h>

#include "Inventory.h"
#include "STLINCLUDE.h"

class Character
{
private:
  int distanceTravelled;

  Inventory inventory;
  Weapon weapon;
  Armor armor_head;
  Armor armor_chest;
  Armor armor_arms;
  Armor armor_legs;
  int gold;

  std::string name;
  int level;
  int exp;
  int expNext;

  int strength;
  int vitality;
  int dexterity;
  int intelligence;

  int hp;
  int hpMax;
  int stamina;
  int staminaMax;
  int damageMin;
  int damageMax;
  int defense;
  int accuracy;
  // TODO: Add luck to the system
  int luck;

  int statPoints;

public:
  Character();
  Character(std::string name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality,
            int dexterity, int intelligence, int hp, int stamina, int statPoints);
  ~Character();

  // Functions
  void initialize(const std::string name);
  void printStats() const;
  std::string getAsString() const;
  std::string getInvAsString(bool shop = false);
  std::string getInvAsStringSave();
  void levelUp();
  void updateStats();
  void addToStat(int stat, int value);
  void equipItem(unsigned index);
  void resetHP();
  void addItem(const Item& item);
  void removeItem(const int index);
  const Item& getItem(const int index);

  // Accessors
  const int& getDistTravel() const;
  const std::string& getName() const;
  const int& getLevel() const;
  const int& getExp() const;
  const int& getExpNext() const;
  const int& getStatPoints() const;
  const int& getHP() const;
  const int& getHPMax() const;
  const bool isAlive();
  const int& getStamina() const;
  const int& getDamageMin() const;
  const int& getDamageMax() const;
  const int getDamage() const;
  const int& getDefense() const;
  const int getAddedDefense() const;
  const int& getAccuracy() const;
  const int getGold() const;
  const int getInventorySize() const;

  // Modifier
  void setDistTravelled(const int& distance);
  void travel();
  void gainExp(const int exp);
  void gainGold(const int gold);
  void payGold(const int gold);
  void takeDamage(const int damage);
  void setWeapon(Weapon weapon);
  void setArmorHead(Armor armor_head);
  void setArmorChest(Armor armor_chest);
  void setArmorArms(Armor armor_arms);
  void setArmorLegs(Armor armor_legs);
};
