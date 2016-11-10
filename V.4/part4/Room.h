#pragma once
#include <string>
#include <vector>
#include "Object.h"

class Room
{
public:
	//Constructors/ Destructors
	Room(unsigned int number, unsigned int north, unsigned int south, unsigned int east, unsigned int west,
		std::string name, std::string description);
	~Room();

	//Getters/ Setters
	//Getters
	int getNumber() { return number; }
	int getNorth() { return north; }
	int getSouth() { return south; }
	int getEast() { return east; }
	int getWest() { return west; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }

	//Setters
	void setNumber(unsigned int number) { Room::number = number; }
	void setNorth(unsigned int north) { Room::north = north; }
	void setSouth(unsigned int south) { Room::south = south; }
	void setEast(unsigned int east) { Room::east = east; }
	void setWest(unsigned int west) { Room::west = west; }
	void setName(std::string name) { Room::name = name; }
	void setDescription(std::string description) { Room::description = description; }

	//Other Metods
	void print();

private:
	unsigned int number, north, south, east, west;
	std::string name, description;
};