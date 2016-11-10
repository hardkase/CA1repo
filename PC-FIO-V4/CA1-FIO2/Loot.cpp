#include "Loot.h"
#include <string>
using namespace std;
Loot::Loot(string lootID, string name, string roomLoc, string desc): lootID(lootID), name(name), roomLoc(roomLoc), desc(desc)
{
	lootCount++;
}

Loot::~Loot(void)
{
	lootCount--;
}
/*	
std::string getLootID() const 
	{return lootID;}
	void setLootID(std::string lootID) {lootID = lootID;}
	std::string getName() const {return name;}
	void setName(std::string name) {name = name;}
	unsigned int getLootType() const {return lootType; }
	void setLootType(unsigned int lootType) { lootType = lootType; }
	std::string getLootVerb() const {return lootVerb; }
	void setLootVerb(std::string lootVerb) {lootVerb = lootVerb; }
	unsigned int getLootCount() const {return lootCount; }
	void sPrint();//basic var print out
	void print();//game examine Loot print out
	*/
