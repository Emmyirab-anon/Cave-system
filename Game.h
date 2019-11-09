#pragma once

#include <string>
#include "Map.h"
#include "CavernManager.h"
#include "RawMap.h"

class Game
{
public:

	Game(const std::string& filename); 
	void printDescription() const; 
	void move(Direction direction);
private:
	Map newP;
	CavernManager cavMan;
	Position playerPos;
	bool invariant() const;
	bool canMakeFirstMove(Direction direction) const;
	void makeFirstMove(Direction direction);
	void followTunnel(Direction direction);
};