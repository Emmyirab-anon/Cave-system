#include "Position.h"
#include "MapSize.h"


Position toPosition (int south, int east)
{
  Position place;
  place.south = south;
  place.east = east;
  return place;
}
bool isInMap (const Position& position)
{
	if (position.south <  0)
		return false;
	if (position.south >= MAP_SIZE_SOUTH)
		return false;
	if (position.east  <  0)
		return false;
	if (position.east >= MAP_SIZE_EAST)
		return false;
	return true;
}// first variant

bool isInMap (const Position& pos_min, int south_size, int east_size)
{
	if (pos_min.south < 0)
		return false;
	if (pos_min.south + south_size > MAP_SIZE_SOUTH)
		return false;
	if (pos_min.east  < 0)
		return false;
	if (pos_min.east + east_size  > MAP_SIZE_EAST)
		return false;
	return true;
}//second variant

Position moveDirection (const Position& position, Direction direction)
{
  Position loca = position;

  if (direction == NORTH)
    {
      loca.south =  loca.south - 1;
      return loca;
    }
  else if (direction == SOUTH)
    {
      loca.south = loca.south + 1;
      return loca;
    }
  else if (direction == EAST)
    {
      loca.east = loca.east + 1;
      return loca;
    }
  else if (direction == WEST)
    {
      loca.east = loca.east - 1;
      return loca;
    }
}
