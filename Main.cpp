#include <fstream>
#include <string>
#include "Game.h"
// This program loads in and processes the map of a cave system

int main()
{
Game game("map4.txt");

cout << endl;

string next;

do {
	game.printDescription();

	cout << endl;
	
	cout << "Next?";
	cin >> next;


	if (next == "n")
		game.move(NORTH);
	else if (next == "s")
		game.move(SOUTH);
	else if (next == "e")
		game.move(EAST);
	else if (next == "w")
		game.move(WEST);
} while (next != "q");


	return 0;
}
