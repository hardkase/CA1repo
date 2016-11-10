#pragma once
#include "Object.h"
class ContainerObject :
	public Object
{
public:
	ContainerObject(unsigned int id, std::string name, std::string description, bool pickUpable,
		std::string room, std::string nameOfObjectInside, std::string openText);
	~ContainerObject();

#pragma region Properties
	//Getters
	unsigned int getId() { return id; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	bool getPickUpable() { return pickUpable; }
	std::string getRoom() { return room; }
	std::string getNameOfObjectInside() { return nameOfObjectInside; }
	std::string getOpenText() { return openText; }

	//Setters
	void setId(unsigned int id) { ContainerObject::id = id; }
	void setName(std::string name) { ContainerObject::name = name; }
	void setDescription(std::string description) { ContainerObject::description = description; }
	void setPickUpable(bool pickUpable) { ContainerObject::pickUpable = pickUpable; }
	void setRoom(std::string room) { ContainerObject::room = room; }
	void setNameOfObjectInside(std::string nameOfObjectInside)
		{ ContainerObject::nameOfObjectInside = nameOfObjectInside; }
	void setOpenText(std::string openText) { ContainerObject::openText = openText; }
#pragma endregion

#pragma region Other Methods
	std::string open();
	std::string useWith(Object o) { return "Can't do that..."; }
	std::string addToInventory() { return "Can't do that..."; }
	void print();
#pragma endregion


private:
	unsigned int id;
	std::string name, description, room, nameOfObjectInside, openText;
	bool pickUpable;
};