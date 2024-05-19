/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once
#include "Inventory.h"

class Player {
private:
	int hp_;
	int coins_;
	Inventory inventory_;

	static const size_t UNIQUE_WEAPONS_BUFF;
public:
	Player(int hp, int coins, const Inventory& inventory);
	int GetHp() const;
	void SetHp(int hp);
	void ChangeHp(int change);
	int GetCoins() const;
	void SetCoins(int coins);
	void ChangeCoins(int change);
	Inventory& GetInventory();
	const Inventory& GetInventory() const;
	void Cook(size_t cook_ware_index);
	void Eat();
	double BattleCoef(size_t enemy_rang);
};