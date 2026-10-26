#ifndef PLAYINGCARD
#define PLAYINGCARD

#include "DataTypes.h"
#include <stdexcept>

class PlayingCard {
private:
	int atk_;
	int def_;
	int stars_;

	CardType type_;

public:
	PlayingCard(int atk, int def, int stars, CardType type)
		: atk_(atk), def_(def), stars_(stars), type_(type) {
		if (atk < 1 || atk > 100 || def < 1 || def > 100 || stars < 1 || stars > 6) {
			throw std::invalid_argument("Invalid card stats");
		}
	}

	int atk() const { return atk_; }
	int def() const { return def_; }
	int stars() const { return stars_; }
	CardType type() const { return type_; }

};

#endif
