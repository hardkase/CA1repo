#pragma once
#include <string>

class Loot
{
public:
	Loot();
	Loot(std::string lootID, std::string name,  std::string roomLoc, std::string desc);
	~Loot(void);
	std::string getLootID() const {return lootID;}
	void setLootID(std::string lootID) {lootID = lootID;}
	std::string getName() const {return name;}
	void setName(std::string name) {name = name;}
	std::string getRoomLoc() const { return roomLoc; }
	void setRoomLoc(std::string roomLoc) { roomLoc = roomLoc; }
	std::string getDesc() const { return desc; }
	void setDesc(std::string desc) { desc = desc; }
	unsigned int getLootCount() const {return lootCount; }
	void sPrint();//basic var print out
	void print();//game examine Loot print out
	
private:
	std::string lootID;
	std::string name;
	std::string roomLoc;
	std::string desc;
	static unsigned int lootCount;
	//special vars here (weapons, food/water, etc.) NO - would use inheritance here to make a weapon more than loot :-)
};

