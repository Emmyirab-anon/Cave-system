#pragma once
#include "Cavern.h"

const unsigned int MAX_NUM_CAVERNS = 25;
class CavernManager
{
private:
	Cavern arrCavern[MAX_NUM_CAVERNS];
	int howManyUsed;


//
// function-name- invariant
//
// Purpose: purpose- Checks if the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
// Parameter(s):
//  N/A
// Precondition(s):
//  N/A
// Returns: N/A
// Side effect: Can exceed the maxinmum number of allowed arrays and cause a function to give out random numbers
//
	bool invariant() const;
public:
//
// function-name- CavernManager
//
// Purpose: purpose- sets the current number of caverns
// Parameter(s):
//  N/A
// Precondition(s):
//  N/A
// Returns: N/A
// Side effect: N/A
//
	CavernManager();

//
// function-name- isEmpty
//
// Purpose: purpose- Checks and returns if they are caverns in the array of caverns
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: assert(invariant() == true)- Checks if the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
// Returns: bool
// Side effect: N/A
//
	bool isEmpty() const;

//
// function-name- isFull
//
// Purpose: purpose- Checks and returns if the Cavern manager contains the maximun of number of caverns
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: assert(invariant() == true)- Checks if the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
// Returns: bool
// Side effect: N/A
//
	bool isFull() const;

//
// function-name- getCount
//
// Purpose: purpose- Returns how many caverns are currently in the cavern manager
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: assert(invariant() == true)- Checks if the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
// Returns: unsigned int
// Side effect: N/A
//
	unsigned int getCount() const;

//
// function-name- get
//
// Purpose: purpose- gets and returns a cavern exactly as it is in the cavern manager
// Parameter(s):
//  <1>: unsigned int index 
// Precondition(s):
//  <1>: assert(invariant() == true)- Makes sure the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
//	<2>: assert(index <= MAX_NUM_CAVERNS) - Makes sure the specified index is less than or equal to the array size(MAX_NUM_CAVERNS)
// Returns: const Cavern&
// Side effect: N/A
//
	const Cavern& get(unsigned int index) const;

//
// function-name- getBack
//
// Purpose: purpose- gets and returns a cavern exactly as it is in the cavern manager
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: assert(invariant() == true)- Makes sure the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
//	<2>: assert(isEmpty() == false) - Makes sure the cavern manager is not empty
// Returns: const Cavern&
// Side effect: N/A
//
	const Cavern& getBack() const;

//
// function-name- getBackShape
//
// Purpose: purpose- returns the tunnel shape for the most recently added cavern
// Parameter(s):
//  N/A
// Precondition(s):
//  <1>: assert(invariant() == true)- Makes sure the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
// Returns: Shape
// Side effect: N/A
//
	Shape getBackShape() const;

//
// function-name- getBack
//
// Purpose: purpose- Adds the new specified cavern to the aray of caverns and increaes the cavern count
// Parameter(s):
//  <1>: const Cavern cavern1
// Precondition(s):
//  <1>: assert(invariant() == true)- Makes sure the number of caverns is less than or equal to the array size(MAX_NUM_CAVERNS)
//	<2>: assert(isFull() == false) - Makes sure the cavern manager is not full
// Returns: N/A
// Side effect: N/A
//
	void add(const Cavern& cavern1);
};