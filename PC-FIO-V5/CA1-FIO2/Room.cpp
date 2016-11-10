#include "Room.h"
#include "Loot.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Room::Room(string roomID, string roomName, string west, string north, string east, string south, /*vector<Loot> lootList,*/ string roomDesc): 
	roomID(roomID), roomName(roomName), west(west), north(north), east(east), south(south), /*lootList(lootList),*/ roomDesc(roomDesc)
{
	//private int roomCount++;
}
Room::Room(){ }

Room::~Room(void)
{
	//roomCount--;
}

void Room::print()
{
	cout << "Room ID: " << getRoomID() << endl;
	cout << "roomName" << getRoomName() << endl;
	cout << "West Exit: " << getWest() << endl;
	cout << "North Exit: " << getNorth() << endl;
	cout << "East Exit: " << getEast() << endl;
	cout << "South Exit: " << getSouth() << endl;
	/*for (Loot l : getLootList())
	{
		l.print();
	}*/
	cout << "Room Desc. :" << getRoomDesc() << endl;
}
