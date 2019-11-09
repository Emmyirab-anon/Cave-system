/* Name: Emmanuel Efewongbe
   Student ID: 200417647
   Course: CS 115
   Classs section number: 002
   Lab section number: 083
*/

#pragma once

#include "MapSize.h"
#include "Shape.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Cavern.h"
using namespace std;


void rawMapLoad(char raw[][MAP_SIZE_EAST], const std::string& filename);
void rawMapPrint(const char raw[][MAP_SIZE_EAST]);
bool rawMapIsOpen(const char raw[][MAP_SIZE_EAST], int south, int east);
Shape rawMapCalculateShape(const char raw[][MAP_SIZE_EAST], int south, int east);

bool rawMapIsCavern(const char raw[][MAP_SIZE_EAST],int south, int east);
int rawMapGetCavernSouthSize(const char raw[][MAP_SIZE_EAST],int south, int east);
int rawMapGetCavernEastSize(const char raw[][MAP_SIZE_EAST],int south, int east);
int rawMapFindExitToSouth(const char raw[][MAP_SIZE_EAST],int south, int east,int max_distance);
int rawMapFindExitToEast(const char raw[][MAP_SIZE_EAST],int south, int east,int max_distance);
Cavern rawMapCalculateCavern(const char raw[][MAP_SIZE_EAST],int south, int east);
Position rawMapGetPlayerStart(const char raw[][MAP_SIZE_EAST]);