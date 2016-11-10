#include "Loot.h"
#include "Room.h"
#include <string>
#include <vector>
#pragma once
class Player
{
public:
	Player();
	Player(std::string name, Room currentRoom, std::vector<Room> pastRooms, std::vector<Loot> inventory, int hitPoints, unsigned int armorPoints, int stats[8]);
	~Player();

private:
	std::string name;
	Room currentRoom;
	std::vector<Room> pastRooms;
	std::vector<Loot> inventory;
	int hitPoints;
	unsigned int armorPoints;
	int stats[8];
};

