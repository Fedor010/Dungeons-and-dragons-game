/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#include "Weapon.h"

const Weapon Weapon::club_(5, 0, 5, 0);
const Weapon Weapon::spear_(5, 0, 5, 1);
const Weapon Weapon::rapier_(5, 1, 5, 2);
const Weapon Weapon::battle_axe_(5, 2, 5, 3);
const Weapon Weapon::longsword_(5, 3, 5, 4);

Weapon::Weapon(
	double weight, 
	double dmg, 
	double durability,
	size_t id
	) : 
	Item(weight), 
	dmg_(dmg), 
	durability_(durability),
	id_(id)
	{}

double Weapon::GetDmg() const {
	return dmg_;
}

size_t Weapon::GetId() const {
	return id_;
}

void Weapon::SetDurability(double new_durability) {
	durability_ = new_durability;
}
void Weapon::ChangeDurability(double change) {
	durability_ += change;
}
double Weapon::GetDurability() const {
	return durability_;
}

Weapon Weapon::CreateClub() {
	return club_;
}

Weapon Weapon::CreateSpear() {
	return spear_;
}
Weapon Weapon::CreateRapier() {
	return rapier_;
}
Weapon Weapon::CreateBattleAxe() {
	return battle_axe_;
}

Weapon Weapon::CreateLongSword() {
	return longsword_;
}