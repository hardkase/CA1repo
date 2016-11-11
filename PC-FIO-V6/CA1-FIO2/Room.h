#pragma once
#include "Loot.h"
#include <string>
#include <vector>
class Room
{
public:
	Room();
	Room(std::string roomID, std::string roomName, std::string west, std::string north, std::string east, 
		std::string south, std::vector<Loot> lootList, std::string roomDesc);
	~Room();
	std::string getRoomID() const {return roomID; }
	void setRoomID(std::string roomID) {roomID = roomID; }
	std::string getRoomName() const {return roomName; }
	void setRoomName(std::string roomName) {roomName = roomName; }
	std::string getWest() const {return west; }
	void setWest(std::string west) {west = west; }
	std::string getNorth() const {return north; }
	void setNorth(std::string north) {north = north; }
	std::string getEast() const {return east; }
	void setEast(std::string east) {east = east; }
	std::string getSouth() const {return south; }
	void setSouth(std::string south) {south = south; }
	std::vector<Loot> getLootList() const {return lootList; }
	void setLootList(std::vector<Loot> lootList) {lootList = lootList; }
	std::string getRoomDesc() const {return roomDesc; }
	void setRoomDesc (std::string roomDesc) {roomDesc = roomDesc; }
	unsigned int getRoomCount() const {return roomCount; }
	//void sPrint();//simple print of room props
	void print(Room r);//detailed room print out for game...
	
private:
	std::string roomID;
	std::string roomName;
	std::string west;
	std::string north;
	std::string east;
	std::string south;
	std::vector<Loot> lootList;
	std::string roomDesc;
	static unsigned int roomCount;

};

