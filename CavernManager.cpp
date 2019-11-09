#include "CavernManager.h"

CavernManager::CavernManager()
{
	howManyUsed = 0;
	assert(invariant());
}

bool CavernManager::isEmpty() const
{
	assert(invariant());
	return (howManyUsed == 0);
}

bool CavernManager::isFull() const
{
	assert(invariant());
	return (howManyUsed == MAX_NUM_CAVERNS);
}

unsigned int CavernManager::getCount() const
{
	assert(invariant());
	return howManyUsed;
}

const Cavern & CavernManager::get(unsigned int index) const
{
	assert(invariant());
	assert(index <= MAX_NUM_CAVERNS);
	return arrCavern[index];
}

const Cavern & CavernManager::getBack() const
{
	assert(invariant());
	assert(!isEmpty());
	return arrCavern[howManyUsed - 1];
}

Shape CavernManager::getBackShape() const
{
	assert(invariant());
	return shapeGetCavernShape(howManyUsed - 1);
}

void CavernManager::add(const Cavern & cavern1)
{
	assert(invariant());
	assert(!isFull());
	arrCavern[getCount()] = cavern1;
	howManyUsed++;
	assert(invariant());
}

bool CavernManager::invariant() const
{
	return (howManyUsed <= MAX_NUM_CAVERNS);
}
