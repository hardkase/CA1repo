#pragma once
#include <string>
class Loot
{
public:
	Loot();
	Loot(int id, std::string name, std::string description, bool isBox, bool isComb, bool isNew, int roomLoc);
	~Loot();
	int getID() const { return id; }
	void setID(int id) { id = id; }
	std::string getName() const { return name; }
	void setName(std::string name) { name = name; }
	std::string getDescription() const { return description; }
	void setDescription(std::string description) { description = description; }
	bool getIsBox() const { return isBox; }
	void setIsBox(bool isBox) { isBox = isBox; }
	bool getIsComb() const { return isComb; }
	void setIsComb(bool isComb) { isComb = isComb; }
	bool getIsNew() const { return isNew; }
	void setIsNew(bool isNew) { isNew = isNew; }
	int getRoomLoc() const { return roomLoc; }
	void setRoomLoc(int roomLoc) { roomLoc = roomLoc; }
private:
	int id, roomLoc;
	std::string name, description;
	bool isBox, isComb, isNew;//container, combinable, 
};

