/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once
#include "Item.h"
#include "Ingredient.h"
#include "Food.h"

class CookWare : public Item {
private:
	int break_chance_;
	bool broken_;
	int ID_;

	static const CookWare pot_;
	static const CookWare frying_pan_;
	static const CookWare cauldron_;


public:
	CookWare(double weight, int break_chance, int ID);
	Food Cook(Ingredient& ingredient);
	bool IsBroken() const;
	int GetId() const;

	static CookWare CreatePot();
	static CookWare CreateFryingPan();
	static CookWare CreateCauldron();
};
