#include "Room.h"
#include "Loot.h"
#include <string>
#include <vector>
using namespace std;


Room::Room(string roomID, string roomName, string west, string north, string east, string south, vector<Loot> lootList, string roomDesc): 
	roomID(roomID), roomName(roomName), west(west), north(north), east(east), south(south), lootList(lootList), roomDesc(roomDesc)
{
	roomCount++;
}
Room::Room(){ }

Room::~Room(void)
{
	roomCount--;
}
