#include "MapSize.h"
#include "Shape.h"
#include "Map.h"
#include <iostream>
#include "RawMap.h"
using namespace std;

Map::Map()
{
	setRectangle(toPosition(0, 0), MAP_SIZE_SOUTH, MAP_SIZE_EAST, SHAPE_SOLID);
	startPos = toPosition(0, 0);
}

void Map::printMap()const
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			cout << shapeGetMapChar(map[i][j]);
		}
		cout << endl;
	}

}

bool Map::isOpen(const Position& pos)const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	{
		return (map[pos.south][pos.east] != SHAPE_SOLID);
	}
}

bool Map::isTunnel(const Position& pos)const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	{
		return shapeIsTunnel(map[pos.south][pos.east]);
	}
}

bool Map::isCavern(const Position& pos)const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	{
		return shapeIsCavern(map[pos.south][pos.east]);
	}
}

unsigned int Map::getCavernIndex(const Position& pos) const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	assert(shapeIsCavern(map[pos.south][pos.east]));
	{
		return shapeGetCavernIndex(map[pos.south][pos.east]);
	}
}

void Map::printDescription(const Position& pos)const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	assert(shapeIsCavern(map[pos.south][pos.east]) == false);
	{
		if (isTunnel(pos))
		{
			cout << "You are in a tunnel" << endl;
			if (isTunnelStraight(pos))
			{
				cout << "The tunnel is straight here." << endl;
			}
			if (isTunnelDirection(pos, NORTH))
			{
				cout << "You can go north." << endl;
			}
			if (isTunnelDirection(pos, SOUTH))
			{
				cout << "You can go south." << endl;
			}
			if (isTunnelDirection(pos, EAST))
			{
				cout << "You can go east." << endl;
			}
			if (isTunnelDirection(pos, WEST))
			{
				cout << "You can go west." << endl;
			}
		}
		else
		{
			cout << "You are in solid rock" << endl;
		}
	}

}

void Map::setAt(const Position& pos, Shape shape)
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	{
		map[pos.south][pos.east] = shape;
	}
}

void Map::setRectangle(const Position& pos_min, int south_size, int east_size, Shape shape)
{
	assert(south_size >= 0 && east_size >= 0);
	assert(isInMap(pos_min, south_size, east_size));
	{
		for (int s = 0; s < south_size; s++)
		{
			for (int e = 0; e < east_size; e++)
			{
				map[pos_min.south + s][pos_min.east + e] = shape;
			}
		}
	}
}

bool Map::isTunnelStraight(const Position& pos) const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	if (map[pos.south][pos.east] == SHAPE_SOLID)
	{
		return false;
	}
	else
		return shapeIsTunnelStraight(map[pos.south][pos.east]);
}

bool Map::isTunnelDirection(const Position& pos, Direction direction) const
{
	assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST);
	if (isTunnel(pos) == false)
	{
		return false;
	}
	else
		return shapeIsTunnelDirection(map[pos.south][pos.east], direction);
}

Position Map::getPlayerStart() const
{
	return startPos;
}
void Map::setPlayerStart(const Position& start1)
{
	assert(start1.south >= 0 && start1.south < MAP_SIZE_SOUTH && start1.east >= 0 && start1.east < MAP_SIZE_EAST);
	startPos = start1;
}
