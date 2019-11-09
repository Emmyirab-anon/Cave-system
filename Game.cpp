#include "Game.h"

Game::Game(const std::string & filename)
{
	char oldMap[MAP_SIZE_SOUTH][MAP_SIZE_EAST];
	rawMapLoad(oldMap, filename);
	rawMapPrint(oldMap);

	cout << endl;

	newP.setPlayerStart(rawMapGetPlayerStart(oldMap));
	playerPos = newP.getPlayerStart();
	for (int i = 0; i < MAP_SIZE_SOUTH; i++)
	{
		for (int j = 0; j < MAP_SIZE_EAST; j++)
		{
			if (newP.isCavern(toPosition(i, j)) == false)
			{
				if (rawMapIsCavern(oldMap, i, j) == false)
				{
					newP.setAt(toPosition(i, j), rawMapCalculateShape(oldMap, i, j));
				}
				else
				{
					cavMan.add(rawMapCalculateCavern(oldMap, i, j));
					Shape cS = cavMan.getBackShape();
					int s = rawMapGetCavernSouthSize(oldMap, i, j);
					int e = rawMapGetCavernEastSize(oldMap, i, j);
					newP.setRectangle(toPosition(i, j), s, e, cS);
				}

			}
		}
	}

	newP.printMap();
}

void Game::printDescription() const
{
	if (isInMap(playerPos))
	{
		if (newP.isCavern(playerPos))
		{
			cavMan.get(newP.getCavernIndex(playerPos)).print();
		}
		else
		{
			newP.printDescription(playerPos);
		}
	}
}

void Game::move(Direction direction)
{

	assert(direction < DIRECTION_COUNT);
	if (canMakeFirstMove(direction))
	{
		makeFirstMove(direction);
		followTunnel(direction);
	}
	else
	{
		cout << "There is no way to go in that direction." << endl;
	}
	assert(invariant());
}

bool Game::invariant() const
{
	return (isInMap(playerPos) && newP.isOpen(playerPos));
}

bool Game::canMakeFirstMove(Direction direction) const
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT);
	if (newP.isCavern(playerPos))
	{
		unsigned int index = newP.getCavernIndex(playerPos);
		Cavern cavManExit = cavMan.get(index);
		return cavManExit.isExit(direction);
	}
	else
	{
		bool tunDir = newP.isTunnelDirection(playerPos, direction);
		return tunDir;
	}
}

void Game::makeFirstMove(Direction direction)
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT);
	assert(canMakeFirstMove(direction));
	if (newP.isCavern(playerPos))
	{
		unsigned int index = newP.getCavernIndex(playerPos);
		Cavern cavManExit = cavMan.get(index);
		playerPos = cavManExit.getExitPosition(direction);
		cout << "You leave the cavern and start walking..." << endl;
	}
	else
	{
		playerPos = moveDirection(playerPos, direction);
		cout << "You start walking..." << endl;
	}
}

void Game::followTunnel(Direction direction)
{
	assert(invariant());
	assert(direction < DIRECTION_COUNT);
	cout << "10 ft..." << endl;
	int count = 0;
	while (newP.isTunnelStraight(playerPos))
	{
		int DDD = 2 + count;
		playerPos = moveDirection(playerPos, direction);
		cout << DDD << "0 ft..."  << endl;
		count++;
	}
}