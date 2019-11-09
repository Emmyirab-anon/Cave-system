/* Name: Emmanuel Efewongbe
   Student ID: 200417647
   Course: CS 115
   Classs section number: 002
   Lab section number: 083
   Date: 21-09-2019
*/

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