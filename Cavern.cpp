#include "Cavern.h"
#include "Direction.h"
#include <iostream>
using namespace std;

bool Cavern::invariant()const
{
	return(southN >= CAVERN_SIZE_MIN && eastW >= CAVERN_SIZE_MIN);
}

Cavern::Cavern()
{
	southN = CAVERN_SIZE_MIN;
	eastW = CAVERN_SIZE_MIN;
	for (unsigned int d = 0; d < DIRECTION_COUNT; d++)
	{
		isAnExit[d] = false;
	}
}

Cavern::Cavern(int south_size1, int east_size1)
{
	southN = south_size1;
	eastW = east_size1;
	for (unsigned int d = 0; d < DIRECTION_COUNT; d++)
	{
		isAnExit[d] = false;
		posExit[d].south = 0;
		posExit[d].east = 0;
	}
}

int Cavern::getSouthSize()const
{
	assert(invariant());
	{
		return southN;
	}
}

int Cavern::getEastSize()const
{
	assert(invariant());
	{
		return eastW;
	}
}

bool Cavern::isExit(Direction direction)const
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT);
	{
		return isAnExit[direction];

	}

}

Position Cavern::getExitPosition(Direction direction)const
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT && isExit(direction) == true);
	{
		return posExit[direction]; 
	}
	
}

void Cavern::addExit(Direction direction, const Position & position)
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT && isExit(direction) == false);
	{
		isAnExit[direction] = true;
		Position loc = position;
		posExit[direction] = loc;
	}
	assert(invariant());
}

void Cavern::print()const
{
	assert(invariant());
	cout << "You are in a cavern " << southN << 0 << "ft by " << eastW << 0 << "ft in size." << endl;
	if (isExit(NORTH) == true)
		cout << "There is a tunnel leading north." << endl;
	if (isExit(SOUTH) == true)
		cout << "There is a tunnel leading south." << endl;
	if (isExit(EAST) == true)
		cout << "There is a tunnel leading east." << endl;
	if (isExit(WEST) == true)
		cout << "There is a tunnel leading west." << endl;
}