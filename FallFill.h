/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#pragma once

#include "RoomFill.h"

class FallFill : public RoomFill {
public:
	EventResult Procced(Player& player) override;
	size_t ID() const override;
};