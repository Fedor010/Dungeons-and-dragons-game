/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#include"Cookware.h"
#include<random>

const CookWare CookWare::pot_(10, 25, 0);
const CookWare CookWare::frying_pan_(10, 10, 1);
const CookWare CookWare::cauldron_(10, 2, 2);

CookWare::CookWare(double weight, int break_chance, int ID) : Item(weight), break_chance_(break_chance), broken_(false), ID_(ID) {}

Food CookWare::Cook(Ingredient& ingredient) {
	if (broken_) {
		ingredient.SetWeight(0);
		return Food(0);
	}
	std::random_device rd;
	int chance = rd() % 100;
	if (chance < break_chance_) {
		broken_ = true;
		ingredient.SetWeight(0);
		return Food(0);
	}
	Food food(ingredient.GetWeight());
	ingredient.SetWeight(0);
	return food;
}

bool CookWare::IsBroken() const {
	return broken_;
}

CookWare CookWare::CreatePot() {
	return pot_;
}

CookWare CookWare::CreateFryingPan() {
	return frying_pan_;
}

CookWare CookWare::CreateCauldron() {
	return cauldron_;
}

int CookWare::GetId() const {
	return ID_;
}