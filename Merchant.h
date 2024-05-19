/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once
#include "Armor.h"
#include "Ingredient.h"
#include "Weapon.h"
#include "Cookware.h"
#include <stddef.h>

#include "Inventory.h"
#include "Player.h"

#include <vector>

class Merchant {
public:
	enum class GoodsCategoty {
		COOK_WARE,
		WEAPON,
		ARMOR,
	};
	enum class DealResult {
		NO_DENY,
		NOT_AVAILABLE,
		TO_EXPENSIVE,
		TO_SMALL_AMOUNT
	};
	using PriceList = std::vector<std::vector< int > >;
private:
	Inventory inventory_;
	PriceList price_list_;
	size_t ingredients_lower_border_;

	static const size_t INGREDIENTS_INDEX_;
	static const size_t COOKWARE_INDEX_;
	static const size_t WEAPON_INDEX_;
	static const size_t ARMOR_INDEX_;

	static const size_t INF_;
public:
	Merchant(
		const Inventory& inventory, 
		const PriceList& price_list, 
		size_t ingredients_lower_border
	);
	std::pair<size_t, size_t> ShowIngredientsPrices() const;
	std::vector<std::pair<CookWare, size_t > > ShowCookWarePrices() const;
	std::vector<std::pair<Weapon, size_t > > ShowWeaponPrices() const;
	std::vector<std::pair<Armor, size_t > > ShowArmorPrices() const;
	DealResult BuyIngredients(int amount, Player& player);
	DealResult Buy(GoodsCategoty gc, size_t index, Player& player);
	size_t GetIngredientsLowerBordrer() const;

	static Merchant CreateDefaultMerchant();
};