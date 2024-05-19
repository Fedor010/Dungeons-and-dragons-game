/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once
#include <vector>

#include "Ingredient.h"
#include "Weapon.h"
#include "Food.h"
#include "Cookware.h"
#include "Armor.h"


class Inventory {
private:
	double weight_;
	double max_weight_;
	size_t category_capacity_;
	
	Ingredient ingredients_;
	Food food_;

	std::vector<CookWare> cook_ware_;
	std::vector<Weapon> weapons_;
	std::vector<Armor> armor_;

public:
	enum class InteractionResult {
		NO_DENY,
		TO_HEAVY,
		TO_MANY,
	};
public:
	Inventory(double max_weight = 100, int category_capacity = 4);
	
	InteractionResult AddIngredients(const Ingredient& ingredients);
	InteractionResult AddFood(const Food& food);

	InteractionResult AddCookWare(const CookWare& cook_ware);
	InteractionResult AddWeapon(const Weapon& weapon);
	InteractionResult AddArmor(const Armor& armor);

	size_t GetCategoryCapacity() const;

	Ingredient GetIngredients() const;
	Food GetFood() const;

	std::vector<CookWare> GetCookWare() const;
	std::vector<Weapon> GetWeapon() const;
	std::vector<Armor> GetArmor() const;

	std::vector<CookWare>& GetCookWare();
	std::vector<Weapon>& GetWeapon();
	std::vector<Armor>& GetArmor();

	Ingredient& GetIngredients();
	void FixWeight();
	Food& GetFood();

	CookWare& GetExactCookWare(size_t index);
};