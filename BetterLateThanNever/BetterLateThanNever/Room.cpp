#include "Room.h"
#include "Loot.h"
#include <string>
#include <vector>
using namespace std;

Room::Room()
{
}

Room::Room(int id, std::string name, std::string description, int west, int north, int east, int south, std::vector<Loot> roomLoot): id(id), name(name),
description(description), west(west), north(north), east(east), south(south), roomLoot(roomLoot)
{
}

Room::Room(int id, std::string name, std::string description, int west, int north, int east, int south):
	id(id), name(name), description(description), west(west), north(north), east(east), south(south)
{
	vector<Loot> roomLoot;
	setRoomLoot(roomLoot);//ok, how to do set up default constructor for a vector
}


Room::~Room()
{
}
