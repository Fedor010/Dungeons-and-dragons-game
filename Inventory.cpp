/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#include"Inventory.h"

Inventory::Inventory(double max_weight, int category_capacity): 
	weight_(0), 
	max_weight_(max_weight), 
	category_capacity_(category_capacity) {}

Inventory::InteractionResult Inventory::AddIngredients(const Ingredient& ingredients) {
	if (weight_ + ingredients.GetWeight() > max_weight_) {
		return InteractionResult::TO_HEAVY;
	}
	ingredients_.ChangeWeight(ingredients.GetWeight());
	return InteractionResult::NO_DENY;
}

Inventory::InteractionResult Inventory::AddFood(const Food& food) {
	if (weight_ + food.GetWeight() > max_weight_) {
		return InteractionResult::TO_HEAVY;
	}
	ingredients_.ChangeWeight(food_.GetWeight());
	FixWeight();
	return InteractionResult::NO_DENY;
}

Inventory::InteractionResult Inventory::AddCookWare(const CookWare& cook_ware) {
	if (weight_ + cook_ware.GetWeight() > max_weight_) {
		return InteractionResult::TO_HEAVY;
	}
	if (cook_ware_.size() == category_capacity_) {
		return InteractionResult::TO_MANY;
	}
	cook_ware_.push_back(cook_ware);
	FixWeight();
	return InteractionResult::NO_DENY;
}

#include<iostream>
Inventory::InteractionResult Inventory::AddWeapon(const Weapon& weapon) {
	if (weight_ + weapon.GetWeight() > max_weight_) {
		return InteractionResult::TO_HEAVY;
	}
	if (cook_ware_.size() == category_capacity_) {
		return InteractionResult::TO_MANY;
	}
	weapons_.push_back(weapon);
	FixWeight();
	return InteractionResult::NO_DENY;
}

Inventory::InteractionResult Inventory::AddArmor(const Armor& armor) {
	if (weight_ + armor.GetWeight() > max_weight_) {
		return InteractionResult::TO_HEAVY;
	}
	if (cook_ware_.size() == category_capacity_) {
		return InteractionResult::TO_MANY;
	}
	armor_.push_back(armor);
	FixWeight();
	return InteractionResult::NO_DENY;
}

Ingredient Inventory::GetIngredients() const {
	return ingredients_;
}
Food Inventory::GetFood() const {
	return food_;
}

std::vector<CookWare> Inventory::GetCookWare() const {
	return cook_ware_;
}

std::vector<Weapon> Inventory::GetWeapon() const {
	return weapons_;
}

std::vector<Armor> Inventory::GetArmor() const {
	return armor_;
}

Ingredient& Inventory::GetIngredients() {
	return ingredients_;
}
Food& Inventory::GetFood() {
	return food_;
}

CookWare& Inventory::GetExactCookWare(size_t index) {
	return cook_ware_[index];
}

void Inventory::FixWeight() {
	weight_ = 0;
	weight_ += ingredients_.GetWeight();
	weight_ += food_.GetWeight();
	for (const auto& cook_ware : cook_ware_) {
		weight_ += cook_ware.GetWeight();
	}
	for (const auto& weapon : weapons_) {
		weight_ += weapon.GetWeight();
	}
	for (const auto& armor : armor_) {
		weight_ += armor.GetWeight();
	}
}

std::vector<CookWare>& Inventory::GetCookWare() {
	return cook_ware_;
}

std::vector<Weapon>& Inventory::GetWeapon() {
	return weapons_;
}

std::vector<Armor>& Inventory::GetArmor() {
	return armor_;
}

size_t Inventory::GetCategoryCapacity() const {
	return category_capacity_;
}