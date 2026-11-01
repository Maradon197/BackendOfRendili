#ifndef DATATYPES
#define DATATYPES

#include <vector>

//Was steht hinten auf der Karte?
enum CardType{JEDI_RITTER, SITH, KLONKRIEGER, SENAT, MANDALORIAN, 
	KOPFGELDJAEGER, VERBRECHERLORD, DROIDE, PIRAT, FAHRZEUG};
enum Faction{REPUBLIK, SEPARATISTEN, SOELDNER};

enum Rarity { NORMAL, STAR_KARTE, FORCE_MEISTER };

enum UnitType {SCOUT, EVAC, NACHSCHUB, MISSION, STRIKE_GROUP, BATALLION};

enum PositionType {};

using Puzzle_ID = int;
typedef struct PuzzleCard {
	Puzzle_ID id;
	int position;
};

typedef struct Puzzle {
	std::vector<PuzzleCard> cards;
};

#endif
