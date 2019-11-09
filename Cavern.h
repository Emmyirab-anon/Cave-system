#pragma once
#include "Direction.h"
#include "Position.h"
#include "Shape.h"
#include <cassert>

const unsigned int CAVERN_SIZE_MIN = 2;


class Cavern
{
private:
	int southN;
	int eastW;
	bool isAnExit[DIRECTION_COUNT];
	Position posExit[DIRECTION_COUNT];
//
// function-name- invariant
//
// Purpose: purpose- Checks and returns if the conditions for the class invariant are all true or false
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: first-condition- N/A
// Returns: N/A
// Side effect: N/A
//
	bool invariant()const;
public:
//
// function-name- Cavern
//
// Purpose: purpose- Initializes the cavern have a size of CAVERN_SIZE_MIN in both directions
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: first-condition- N/A
// Returns: N/A
// Side effect: N/A
//
	Cavern();

//
// function-name- Cavern
//
// Purpose: purpose- Sets the size of the cavern and sets the cavern exits to false
// Parameter(s):
//  <1> name-of-first-parameter: south_size
//  <2> name-of-second-parameter: east_size
// Precondition(s):
//  <1>: first-condition- south and east sizes need to be at least CAVERN_SIZE_MIN which is 2
// Returns: N/A
// Side effect: N/A
//
	Cavern(int south_size1, int east_size1);

//
// function-name- getSouthSize
//
// Purpose: Returns the size of the south
// Parameter(s):
//  <1> name-of-first-parameter: N/A
// Precondition(s):
//				N/A
// Returns: integer
// Side effect: N/A
//
	int getSouthSize()const; 

//
// function-name- getEastSize
//
// Purpose: Returns the size of the east
// Parameter(s):
//  <1> name-of-first-parameter: N/A
// Precondition(s):
//				N/A
// Returns: integer
// Side effect: N/A
//
	int getEastSize()const; 

//
// function-name- isExit
//
// Purpose: checks if there is an exit the specified direction and returns true or false
// Parameter(s):
//  <1> name-of-second-parameter: Direction direction
// Precondition(s):
//  <1>: first-condition- direction should always be less than DIRECTION_COUNT, 4.
// Returns: true or false
// Side effect: N/A
//
	bool isExit(Direction direction)const; 

//
// function-name- getExitPosition
//
// Purpose: purpose- gets the position of the exit in the specified direction
// Parameter(s):
//  <1> name-of-second-parameter: direction
// Precondition(s):
//  <1>: first-condition- direction should always be less than DIRECTION_COUNT
//  <2>: second-condition- they must be an exit in that direction
// Returns: Position (position of the exit)
// Side effect: N/A
//
	Position getExitPosition(Direction direction)const; 

//
// function-name- addExit
//
// Purpose: changes the cavern to have an exit in the specified direction that is at the specified position
// Parameter(s):
//  <1> name-of-second-parameter: direction
//  <2> name-of-second-parameter: position
// Precondition(s):
//  <1>: first-condition- direction should always be less than direction count
//  <2>: second-condition- there must not already be an exit in the directioin
// Returns: N/A
// Side effect: N/A
//
	void addExit(Direction direction, const Position& position); 

//
// function-name- print
//
// Purpose: prints the dimensions of the cavern, then prints on which sides they are exits
// Parameter(s):
//  <1> name-of-first-parameter: N/A
// Precondition(s):
//		N/A
// Returns: N/A
// Side effect: N/A
//
	void print()const; 
};

