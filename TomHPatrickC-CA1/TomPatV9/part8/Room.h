#pragma once#pragma once
#include <string>
#include <vector>
#include "Object.h"

class Room
{
public:
	//Constructors/ Destructors
	Room(unsigned int number, std::string east, std::string south, std::string west,
		std::string north, std::string name, std::string description);
	~Room();

	//Getters/ Setters
	//Getters
	int getNumber() { return number; }
	std::string getEast() { return east; }
	std::string getSouth() { return south; }
	std::string getWest() { return west; }
	std::string getNorth() { return north; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }

	//Setters
	void setNumber(unsigned int number) { Room::number = number; }
	void setWest(std::string west) { Room::west = west; }
	void setSouth(std::string south) { Room::south = south; }
	void setEast(std::string east) { Room::east = east; }
	void setNorth(std::string north) { Room::north = north; }
	void setName(std::string name) { Room::name = name; }
	void setDescription(std::string description) { Room::description = description; }

	//Other Metods
	void print();

private:
	unsigned int number;
	std::string north, south, east, west, name, description;
};