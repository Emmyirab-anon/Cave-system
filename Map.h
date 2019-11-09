#pragma once
#include "MapSize.h"
#include "Shape.h"
#include "Position.h"
#include <cassert>

class Map
{
 public:
//
// function-name- Map
//
// Purpose: purpose- A default constructor; it sets all elements in the processed map to shape solid
// Parameter(s): N/A
// Precondition(s): N/A
// Returns: N/A
// Side effect: N/A
//
  Map();

//
// function-name- printMap
//
// Purpose: purpose- Prints all elements in the map;
// Parameter(s): N/A
// Precondition(s): N/A
// Returns: N/A
// Side effect: N/A
//
  void printMap()const;

//
// function-name- isOpen
//
// Purpose: purpose- Checks and returns if a specified position is open, i.e not shape solid
// Parameter(s):
//  <1> name-of-first-parameter: Position pos
// Precondition(s):
//  <1>: assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST) -The specified position must be within the map area
// Returns: Truth or False
// Side effect: N/A
//
  bool isOpen(const Position& pos)const;

//
// function-name- isTunnel
//
// Purpose: purpose- Checks and returns if the specified position is a tunnel (less than shape solid)
// Parameter(s):
//  <1> name-of-first-parameter: Position pos
// Precondition(s):
//  <1>: assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST) - The specified position must be within the map area
// Returns: Truth or False
// Side effect: N/A
//
  bool isTunnel(const Position& pos)const;

//
// function-name- isCavern
//
// Purpose: purpose- Checks and returns if the specified position is a cavern
// Parameter(s):
//  <1> name-of-first-parameter: Position pos
// Precondition(s):
//  <1>: assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST) - The specified position must be within the map area
// Returns: True or False
// Side effect: N/A
//
  bool isCavern(const Position& pos)const;

//
// function-name- getCavernIndex
//
// Purpose: purpose- Gets and returns the index of a cavern is a specified position
// Parameter(s):
//  <1> name-of-first-parameter: Position pos
// Precondition(s):
//  <1>: assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST) - The specified position must be within the map area
//  <2>: assert(shapeIsCavern(map[pos.south][pos.east]) == true) - The specified position must be a cavern
// Returns: Unsigned integer
// Side effect: N/A
//
  unsigned int getCavernIndex(const Position& pos) const;

//
// function-name- printDescription
//
// Purpose: purpose- Prints the description of a specified position (if it is a tunnel or a solid rock)
// Parameter(s):
//  <1> name-of-first-parameter: Position pos
// Precondition(s):
//  <1>: assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST) - The specified position must be within the map area
//  <2>: assert(shapeIsCavern(map[pos.south][pos.east]) == false) - The specified position must be a cavern
// Returns: N/A
// Side effect: N/A
//
  void printDescription(const Position& pos)const;

//
// function-name- setAt
//
// Purpose: purpose- sets a specified position to a specified shape
// Parameter(s):
//  <1> name-of-first-parameter: Position pos
//  <2> name-of-second-parameter: Shape shape
// Precondition(s):
//  <1>: assert(pos.south >= 0 && pos.south < MAP_SIZE_SOUTH && pos.east >= 0 && pos.east < MAP_SIZE_EAST) - The specified position must be within the map area
// Returns: N/A
// Side effect: N/A
//
  void setAt(const Position& pos, Shape shape);

//
// function-name- setRectangle
//
// Purpose: purpose- sets a specified position to a specified shape
// Parameter(s):
//  <1> name-of-first-parameter: Position Pos_min
//  <2> name-of-second-parameter: int south_size
//  <3> name - of - third - parameter: int east_size
//  <4> name - of - fourth - parameter: Shape shape
// Precondition(s):
//  <1>: assert(south_size >= 0 && east_size >= 0)- south and east sizes must be non-negative
//  <2>: assert(isInMap(pos, south_size, east_size)) - The entire rectangle must be inside the map area
// Returns: N/A
// Side effect: N/A
//
  void setRectangle(const Position& pos_min, int south_size, int east_size, Shape shape);

  bool isTunnelStraight(const Position& pos) const;
  bool isTunnelDirection(const Position& pos, Direction direction) const;
  Position getPlayerStart() const;
  void setPlayerStart(const Position& start1);

private:
	Shape map[MAP_SIZE_SOUTH][MAP_SIZE_EAST];
	Position startPos;
};

