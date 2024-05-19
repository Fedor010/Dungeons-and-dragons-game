/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#include "Player.h"

#include <random>
#include<unordered_set>

const size_t Player::UNIQUE_WEAPONS_BUFF = 4;

Player::Player(int hp, int coins, const Inventory& inventory) : hp_(hp), coins_(coins), inventory_(inventory) {}

int Player::GetHp() const {
	return hp_;
}

void Player::SetHp(int hp) {
	hp_ = hp;
}


void Player::ChangeHp(int change) {
	hp_ += change;
}

int Player::GetCoins() const {
	return coins_;
}

void Player::SetCoins(int coins) {
	coins_ = coins;
}

const Inventory& Player::GetInventory() const {
	return inventory_;
}

Inventory& Player::GetInventory() {
	return inventory_;
}

void Player::ChangeCoins(int change) {
	coins_ += change;
}

void Player::Cook(size_t cook_ware_index) {
	inventory_.GetFood().ChangeWeight(
	inventory_.GetExactCookWare(cook_ware_index).Cook(
	inventory_.GetIngredients()).GetWeight());
	inventory_.FixWeight();
}

void Player::Eat() {
	hp_ += inventory_.GetFood().Eat();
	inventory_.FixWeight();
}

double Player::BattleCoef(size_t enemy_rang) {
	std::random_device rd;
	size_t r1 = rd() % 6 + 1;
	size_t r2 = rd() % 6 + 1;
	auto weapons = inventory_.GetWeapon();
	double w = weapons.size();
	std::unordered_set<size_t> unique_ids;
	for (const auto& weapon : weapons) {
		w += weapon.GetDmg();
		unique_ids.insert(weapon.GetId());
	}
	w *= r1;
	if (unique_ids.size() == inventory_.GetCategoryCapacity()) {
		w += UNIQUE_WEAPONS_BUFF;
	}
	enemy_rang *= r2;
	double armor_amount = inventory_.GetArmor().size();
	enemy_rang /= armor_amount;
	return w - enemy_rang;
}