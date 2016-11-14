#pragma once
#include "Object.h"
class ContainerObject :
	public Object
{
public:
	ContainerObject(unsigned int id, std::string name, std::string description, bool pickUpable,
		std::string room, std::string nameOfObjectInside);
	~ContainerObject();

#pragma region Properties
	//Getters
	unsigned int getId() { return id; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	bool getPickUpable() { return pickUpable; }
	std::string getRoom() { return room; }
	std::string getNameOfObjectInside() { return nameOfObjectInside; }

	//Setters
	void setId(unsigned int id) { ContainerObject::id = id; }
	void setName(std::string name) { ContainerObject::name = name; }
	void setDescription(std::string description) { ContainerObject::description = description; }
	void setPickUpable(bool pickUpable) { ContainerObject::pickUpable = pickUpable; }
	void setRoom(std::string room) { ContainerObject::room = room; }
	void setNameOfObjectInside(std::string nameOfObjectInside)
	{
		ContainerObject::nameOfObjectInside = nameOfObjectInside;
	}
#pragma endregion

#pragma region Other Methods
	virtual std::string open();
	virtual std::string useWith(std::string pairName);
	std::string addToInventory() { return "Can't do that..."; }
	void print();
#pragma endregion


private:
	unsigned int id;
	std::string name, description, room, nameOfObjectInside, objectInside;
	bool pickUpable;
};