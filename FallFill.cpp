/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#include "FallFill.h"

EventResult FallFill::Procced(Player& player) {
	return EventResult::LOST;
}

size_t FallFill::ID() const {
	return 2;
}