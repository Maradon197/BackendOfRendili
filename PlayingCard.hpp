#ifndef PLAYINGCARD
#define PLAYINGCARD

#include "DataTypes.hpp"
#include <stdexcept>

//TODO: senate logic
class PlayingCard {
private:
	int atk_;
	int def_;
	int stars_;

	bool is_open_;

	CardType type_;
	Faction faction_;
	Rarity rarity_;

public://TODO
	PlayingCard(int atk, int def, int stars, CardType type)
		: atk_(atk), def_(def), stars_(stars), type_(type) {
		if (atk < 1 || atk > 101 || def < 1 || def > 101 || stars < 1 || stars > 5) {
			throw std::invalid_argument("Invalid card stats");
		}
	}

	int atk() const { if(is_open_) return atk_; }
	int def() const { if (is_open_) return def_; }
	int stars() const { if (is_open_) return stars_; }
	CardType type() const { return type_; }
	Faction faction() const { return faction_; }
	Rarity rarity() const { if (is_open_) return rarity_; }

};

#endif
