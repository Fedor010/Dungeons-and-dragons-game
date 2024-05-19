/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once

#include"RoomFill.h"

class CoinsFill : public RoomFill {
private:
	unsigned int coins_;
public:
	CoinsFill(unsigned int coins);
	EventResult Procced(Player& player) override;
	size_t ID() const override;
	unsigned int GetCoins()const;
};