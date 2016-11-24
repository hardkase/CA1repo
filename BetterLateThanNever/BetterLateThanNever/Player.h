#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Loot.h"
#include "Room.h"
class Player
{
public:
	Player();
	Player(std::string name);
	~Player();
	std::string getName() const { return name; }
	void setName(std::string name) { name = name; }
	//Room getCurrentRoom() const { return currentRoom; }
	//void setCurrentRoom(Room currentRoom) { currentRoom = currentRoom; }
	std::vector<Loot> getInventory() const { return inventory; }
	void setInventory(std::vector<Loot> inventory) { inventory = inventory; }
	std::stack<Room> getPastRooms() const { return pastRooms; }
	void setPastRooms(std::stack<Room> pastRooms) { pastRooms = pastRooms; }
	bool getTime2Go() const { return time2go; }
	void setTime2Go(bool time2go) { time2go = time2go; }
private:
	std::string name;
	//Room currentRoom;
	std::vector<Loot> inventory;
	std::stack<Room> pastRooms;
	bool time2go;
};

