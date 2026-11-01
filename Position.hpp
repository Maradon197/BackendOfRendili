#ifndef POSITION
#define POSITION

#include "DataTypes.hpp"
#include "PlayingCard.hpp"
#include <string>
#include <vector>
#include <stdexcept>

class Position {
private:
	PositionType type_;

	bool walkable_;
	float movement_penalty_;
	std::vector<bool> is_under_fog_[2];

	int rewarded_orbital_points_;
	int rewarded_cards_;

public:
	RadarStation(){}
	Werft(){}
	Versorgunsstation(){}
	Geschütz(){}
	Hangar(){}
};

#endif
