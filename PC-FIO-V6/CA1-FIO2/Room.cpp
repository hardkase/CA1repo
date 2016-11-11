#include "Room.h"
#include "Loot.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Room::Room(string roomID, string roomName, string west, string north, string east, string south, vector<Loot> lootList, string roomDesc): 
	roomID(roomID), roomName(roomName), west(west), north(north), east(east), south(south), lootList(lootList), roomDesc(roomDesc)
{
	//private int roomCount++;
}
Room::Room(){ }

Room::~Room(void)
{
	//roomCount--;
}

void Room::print(Room r)
{
	cout << "Room ID: " << r.getRoomID() << endl;
	cout << "roomName" << r.getRoomName() << endl;
	cout << "West Exit: " << r.getWest() << endl;
	cout << "North Exit: " << r.getNorth() << endl;
	cout << "East Exit: " << r.getEast() << endl;
	cout << "South Exit: " << r.getSouth() << endl;
	vector<Loot> localLootList = r.getLootList();
	for (Loot l : localLootList)
	{
		l.print(l);
	}
	cout << "Room Desc. :" << r.getRoomDesc() << endl;
}
