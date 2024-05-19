/*
Fedor Vlasov
CSCI1300
Project#3
Dungeon Escape
*/

#include "File.h"
#include <fstream>
#include "BossFill.h"
#include "EmptyFill.h"
#include "ExitFill.h"
#include "FallFill.h"
#include "SwordFill.h"
#include "CoinsFill.h"

Map FileWorker::ReadFile(const char* adress) const {
	Map map;
	std::ifstream fin(adress);
	if (!fin) {
		return map;
	}
	int condition;
	fin >> condition;
	switch (condition) {
	case 0: {
		map.condition_ = GameCondition::NOT_STARTED;
		break;
	}
	case 1: {
		map.condition_ = GameCondition::IN_PROGRESS;
		break;
	}
	case 2: {
		map.condition_ = GameCondition::LOST;
		break;
	}
	case 3: {
		map.condition_ = GameCondition::WON;
		break;
	}
	}
	int size;
	fin >> size;
	for (int i = 0; i < size; ++i) {
		int room_type;
		fin >> room_type;
		switch (room_type) {
		case 0: {
			int dragon;
			fin >> dragon;
			map.buffer_.push_back(new BossFill(dragon, 5));
			map.rooms_.push_back(map.buffer_.back());
			break;
		}
		case 1: {
			map.buffer_.push_back(new ExitFill);
			map.rooms_.push_back(map.buffer_.back());
			break;
		}
		case 2: {
			map.buffer_.push_back(new FallFill);
			map.rooms_.push_back(map.buffer_.back());
			break;
		}
		case 3: {
			map.buffer_.push_back(new EmptyFill);
			map.rooms_.push_back(map.buffer_.back());
			break;
		}
		case 4: {
			int sword;
			fin >> sword;
			map.buffer_.push_back(new SwordFill(sword));
			map.rooms_.push_back(map.buffer_.back());
			break;
		}
		case 5: {
			int coins;
			fin >> coins;
			map.buffer_.push_back(new CoinsFill(coins));
			map.rooms_.push_back(map.buffer_.back());
			break;
		}
		}
		size_t amount_or_neighbours;
		fin >> amount_or_neighbours;
		for (size_t i = 0; i < amount_or_neighbours; ++i) {
			size_t neighbour;
			fin >> neighbour;
			map.rooms_.back().AddNearRoom(neighbour);
		}
	}
	fin >> map.start_room_;
	int hp;
	fin >> hp;
	map.player_.SetHp(hp);
	int sword;
	fin >> sword;
	unsigned int coins;
	fin >> coins;
	map.player_.SetCoins(coins);
	fin >> map.player_room_;
	return map;
}

bool FileWorker::WriteFile(const char* adress, const Map& map) const {
	std::ofstream fout(adress);
	if (!fout) {
		return false;
	}
	
	switch (map.condition_) {
	case GameCondition::NOT_STARTED: {
		fout << 0 << '\n';
		break;
	}
	case GameCondition::IN_PROGRESS: {
		fout << 1 << '\n';
		break;
	}
	case GameCondition::LOST: {
		fout << 2 << '\n';
		break;
	}
	case GameCondition::WON: {
		fout << 3 << '\n';
		break;
	}
	}
	fout << map.rooms_.size() << '\n';
	for (int i = 0; i < map.rooms_.size(); ++i) {
		int ID = map.rooms_[i].GetFill()->ID();
		fout << ID << '\n';
		if (ID == 0) {
			fout << reinterpret_cast<const BossFill*>(map.rooms_[i].GetFill())->IsBossAlive() << '\n';
		}
		if (ID == 4) {
			fout << reinterpret_cast<const SwordFill*>(map.rooms_[i].GetFill())->GetSword() << '\n';
		}
		if (ID == 5) {
			fout << reinterpret_cast<const CoinsFill*>(map.rooms_[i].GetFill())->GetCoins() << '\n';
		}
		auto neighbours = map.rooms_[i].GetNearRooms();
		fout << neighbours.size() << '\n';
		for (const auto& elem : neighbours) {
			fout << elem << " ";
		}
	}
	fout << '\n';
	fout << map.start_room_ << '\n';
	fout << map.player_.GetHp() << '\n';
	fout << map.player_room_ << '\n';
	return true;
}

void FileWorker::UploadCoins(const char* adress, const Map& map) const {
	std::ofstream fout(adress);
	if (!fout) {
		return;
	}
	fout << map.GetPlayer().GetCoins();
}

size_t FileWorker::DownloadCoins(const char* adress) const {
	std::ifstream fin(adress);
	if (!fin) {
		return 0;
	}
	size_t coins_amount;
	fin >> coins_amount;
	return coins_amount;
}