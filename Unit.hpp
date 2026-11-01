#ifndef UNIT
#define UNIT

#include "DataTypes.hpp"
#include "PlayingCard.hpp"
#include <string>
#include <vector>
#include <stdexcept>

class Unit {
private:
	UnitType unit_type_;

	//if contains a vehicle: must be at 0th slot!
	std::vector<PlayingCard> playing_cards_;

public:
	Unit(UnitType unit_type, std::vector<PlayingCard> playing_cards) {
		switch (unit_type_) {
		case SCOUT:
			//1 unit: cant be a vehicle
			if (playing_cards_.size() != 1 || playing_cards_[0].type() == CardType::FAHRZEUG) {//TODO: potential error in type()
				throw std::invalid_argument("Invalid Unit stats");
			}
			break;

		case EVAC:
			//1 unit: must be a vehicle
			if (playing_cards_.size() != 1 || playing_cards_[0].type() != CardType::FAHRZEUG) {
				throw std::invalid_argument("Invalid Unit stats");
			}
			break;

		case NACHSCHUB:
			//1 vehicle, 1-3 playing cards
			if (playing_cards_.size() < 1 || playing_cards_.size() > 4 ||
				playing_cards_[0].type() != CardType::FAHRZEUG) {//TODO: make sure other cards are not vehicles!
				throw std::invalid_argument("Invalid Unit stats");
			}
			break;

		case MISSION:
			//1-3 playing cards, at most one force user (jedi/sith)
			if (playing_cards_.size() < 1 || playing_cards_.size() > 3) {// TODO: fulfill force user condition
				throw std::invalid_argument("Invalid Unit stats");
			}
			break;

		case STRIKE_GROUP:
			//1-3 non-vehicle cards, 1-3 vehicles
			if (0) {	//TODO: condition check
				throw std::invalid_argument("Invalid Unit stats");
			}
			break;

		case BATALLION:
			//6-9 arbitrary cards
			if (playing_cards_.size() < 6 || playing_cards_.size() > 9) {
				throw std::invalid_argument("Invalid Unit stats");
			}
			break;

		default:
			throw std::invalid_argument("Invalid Unit stats");
			break;
		}
	}


};

#endif
