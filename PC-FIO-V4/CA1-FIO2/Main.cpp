#include "Loot.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//method declation:
void initializeGame();
vector<Room> loadRooms(const vector<Loot> &masterLootList);
vector<Loot> loadLoot();
vector<Loot> getRoomLoot(vector<Loot> masterLootList, string roomID);


int main()
{
	vector<Room> roomList;
	vector<Loot> masterLootList;
	Player p1;
	initializeGame();
	//global vars:

	//requisite bits:
	system("pause");
	return 0;
}
void initializeGame()
{
	vector<Loot> masterLootList;
	vector<Room> roomVector;
	vector<Loot> inventory;
	masterLootList = loadLoot();
	roomVector = loadRooms(masterLootList);
}
vector<Room> loadRooms(const vector<Loot> &masterLootList)
{
	//Room(std::string roomID, std::string roomName, std::string west, std::string north, 
	//std::string east, std::string south, std::vector<Loot> lootList, std::string roomDesc)
	//(hardcode - deprecated)Room r1("R001", "entry", "R002", "R003", "R004", "0", "You have entered the maze");
	vector<Room> outVector;
	ifstream roomData("f:/temp/room.txt");

	while (!roomData.eof())
	{
		Room chamber;
		string holder;
		string roomID;
		//string west, north, east, south; this was for array which is going to be really tricky to implement??
		getline(roomData, holder);
		roomID = holder;
		chamber.setRoomID(holder);
		getline(roomData, holder);
		chamber.setRoomName(holder);
		getline(roomData, holder);
		chamber.setWest(holder);
		getline(roomData, holder);
		chamber.setNorth(holder);
		getline(roomData, holder);
		chamber.setEast(holder);
		getline(roomData, holder);
		chamber.setSouth(holder);
		chamber.setLootList(getRoomLoot(masterLootList, roomID));
		getline(roomData, holder);
		chamber.setRoomDesc(holder);
		outVector.push_back(chamber);

	}
	return outVector;

}
vector<Loot> loadLoot()
{
	vector<Loot> outVector;
	ifstream lootData("f:/temp/loot.txt");

	while (!lootData.eof())
	{
		//string lootID, string name, string roomLoc, string desc
		Loot lootItem;
		string holder;
		getline(lootData, holder);
		lootItem.setLootID(holder);
		getline(lootData, holder);
		lootItem.setName(holder);
		getline(lootData, holder);
		lootItem.setRoomLoc(holder);
		getline(lootData, holder);
		lootItem.setDesc(holder);
		outVector.push_back(lootItem);
	}

	return outVector;
}
vector<Loot> getRoomLoot(vector<Loot> masterLootList, string RoomID)
{
	vector<Loot> roomLoot;
	//search master loot list and copy items to room loot, pass into room
	return roomLoot;
}
/*
...semi-optional: create and intialize player
*  read room data from file &initialize rooms, & load into vector
...OPTIONAL...read objects and load
* start game for user, load current room (room 1) and describe including exits, get and handle user input
....OPTIONAL...place objects in rooms
*change current room state to users room/ if user selects unavailable exit - handle
...EXTRA OPTIONAL...enemies and combat
*/