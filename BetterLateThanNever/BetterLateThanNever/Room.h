#pragma once
#include <string>
#include <vector>
#include "Loot.h"
class Room
{
public:
	Room();
	Room(int id, std::string name, std::string description, int west, int north, int east, int south, std::vector<Loot> roomLoot);
	Room(int id, std::string name, std::string description, int west, int north, int east, int south);
	~Room();
	int getID() const { return id; }
	void setID(int id) { id = id; }
	std::string getName() const { return name; }
	void setName(std::string name) { name = name; }
	std::string getDescription() const { return description; }
	void setDescription(std::string description) { description = description; }
	int getWest() const { return west; }
	void setWest(int west) { west = west; }
	int getNorth() const { return north; }
	void setNorth(int north) { north = north; }
	int getEast() const { return east; }
	void setEast(int east) { east = east; }
	int getSouth() const { return south; }
	void setSouth(int south) { south = south; }
	std::vector<Loot> getRoomLoot() const { return roomLoot; }
	void setRoomLoot(std::vector<Loot> roomLoot) { roomLoot = roomLoot; }
private:
	int id, west, north, east, south;
	std::string name, description;
	std::vector<Loot> roomLoot;
};

