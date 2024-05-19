/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once
#include "Item.h"

class Weapon : public Item {
private:
	double dmg_;
	double durability_;
	size_t id_;

	static const Weapon club_;
	static const Weapon spear_;
	static const Weapon rapier_;
	static const Weapon battle_axe_;
	static const Weapon longsword_;
public:
	Weapon(double weight, double dmg, double durability, size_t id);
	double GetDmg() const;
	void SetDurability(double new_durability);
	void ChangeDurability(double change);
	double GetDurability() const;
	size_t GetId() const;

	static Weapon CreateClub();
	static Weapon CreateSpear();
	static Weapon CreateRapier();
	static Weapon CreateBattleAxe();
	static Weapon CreateLongSword();
};