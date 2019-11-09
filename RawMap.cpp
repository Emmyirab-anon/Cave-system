/* Name: Emmanuel Efewongbe
   Student ID: 200417647
   Course: CS 115
   Classs section number: 002
   Lab section number: 083
   Date: 21-09-2019
*/

#include "MapSize.h"
#include "Shape.h"
#include "RawMap.h"

void rawMapLoad(char raw[][MAP_SIZE_EAST], const std::string& filename)
{
	ifstream inData;
	inData.open(filename);
	if (!inData)
	{
		cout << "The file can not be opened!" << endl;
	}

	else
	{
		for (int i = 0; i < MAP_SIZE_SOUTH; i++)
		{
			for (int j = 0; j < MAP_SIZE_EAST; j++)
			{
				inData >> raw[i][j];
			}
			inData.ignore(1000, '\n');
		}
	}
	inData.close();
}

void rawMapPrint(const char raw[][MAP_SIZE_EAST])
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			cout << raw[i][j];
		}
		cout << endl;
	}

}

bool rawMapIsOpen(const char raw[][MAP_SIZE_EAST], int south, int east)
{

	if (south >= MAP_SIZE_SOUTH || south < 0 || east >= MAP_SIZE_EAST || east < 0)
	{
		return false;
	}
	if (raw[south][east] == '#')
	{
		return false;
	}

	else 
	{
		return true;
	}
}

Shape rawMapCalculateShape(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	bool b1 = rawMapIsOpen(raw, (south - 1), east);
	bool b2 = rawMapIsOpen(raw, (south + 1), east);
	bool b3 = rawMapIsOpen(raw, south, (east + 1));
	bool b4 = rawMapIsOpen(raw, south, (east - 1));

	if (rawMapIsOpen(raw, south, east) == false)
	{
		return SHAPE_SOLID;
	}

	return shapeCalculate(b1, b2, b3, b4);

}

bool rawMapIsCavern(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	return (rawMapIsOpen(raw, south, east) && rawMapIsOpen(raw, south, east + 1) && rawMapIsOpen(raw, south + 1, east) && rawMapIsOpen(raw, south + 1, east + 1));
	
}

int rawMapGetCavernSouthSize(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	for (int s = 0; s < MAP_SIZE_SOUTH + 1; s++)
	{
		if (!rawMapIsOpen(raw, south + s, east) || !rawMapIsOpen(raw, south + s, east + 1))
		{
			return s;
		}
	}
	return 0; 
}

int rawMapGetCavernEastSize(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	for (int e = 0; e < MAP_SIZE_EAST + 1; e++) 
	{
		if (!rawMapIsOpen(raw, south, east + e) || !rawMapIsOpen(raw, south + 1, east + e))
		{
			return e;
		}
	}
	return 0;
}

int rawMapFindExitToSouth(const char raw[][MAP_SIZE_EAST], int south, int east, int max_distance)
{
	
	for (int i = 0; i < max_distance; i++)
	{
		if (rawMapIsOpen(raw, south, east + i))
			return i;
	}
	return -1;
}


int rawMapFindExitToEast(const char raw[][MAP_SIZE_EAST], int south, int east, int max_distance)
{

	for (int i = 0; i < max_distance; i++)
	{
		if (rawMapIsOpen(raw, south + i, east))
			return i;
	}
	return -1;
}

Cavern rawMapCalculateCavern(const char raw[][MAP_SIZE_EAST], int south, int east)
{
	int south_size = rawMapGetCavernSouthSize(raw, south, east);
	int east_size = rawMapGetCavernEastSize(raw, south, east);

	Cavern c(south_size, east_size);

	int exit_north = rawMapFindExitToSouth(raw, south - 1, east, east_size);
	int exit_south = rawMapFindExitToSouth(raw, south + south_size, east, east_size);
	int exit_east = rawMapFindExitToEast(raw, south, east + east_size, south_size);
	int exit_west = rawMapFindExitToEast(raw, south, east - 1, south_size);

	if (exit_north != -1)
		c.addExit(NORTH, toPosition(south - 1, east + exit_north));
	if (exit_south != -1)
		c.addExit(SOUTH, toPosition(south + south_size, east + exit_south));
	if (exit_east != -1)
		c.addExit(EAST, toPosition(south + exit_east, east + east_size));
	if (exit_west != -1)
		c.addExit(WEST, toPosition(south + exit_west, east - 1));

	return c;
}

Position rawMapGetPlayerStart(const char raw[][MAP_SIZE_EAST])
{
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			if (raw[i][j] == '@')
			{
				return toPosition(i, j);
			}
		}
	}

	return toPosition(0, 0);
}
