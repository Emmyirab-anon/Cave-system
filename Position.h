#pragma once
#include "Direction.h"

struct Position
{
  int south;
  int east;
};

Position toPosition (int south, int east);
bool isInMap (const Position& position);      // first variant 
bool isInMap (const Position& pos_min, int south_size, int east_size);   //second variant
Position moveDirection (const Position& position, Direction direction); 
