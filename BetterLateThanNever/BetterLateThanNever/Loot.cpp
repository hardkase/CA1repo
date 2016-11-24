#include "Loot.h"
#include "Room.h"
#include <string>
#include <vector>
using namespace std;

Loot::Loot()
{
}
Loot::Loot(int id, string name, string description, bool isBox, bool isComb, bool isNew, int roomLoc) :
	id(id), name(name), description(description), isBox(isBox), isComb(isComb), isNew(isNew), roomLoc(roomLoc)
{

}

Loot::~Loot()
{
}
