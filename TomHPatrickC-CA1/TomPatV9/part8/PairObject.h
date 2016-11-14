#pragma once
#include "Object.h"
class PairObject : public Object
{
public:
#pragma region Constructors/ Destructor
	//PairObject();
	PairObject(unsigned int id, std::string name, std::string description, bool pickUpable,
		std::string nameOfPairedObject, std::string nameOfCreatedObject, std::string room);
	~PairObject();
#pragma endregion

#pragma region Properties
	//Getters
	unsigned int getId() { return id; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	bool getPickUpable() { return pickUpable; }
	std::string getNameOfPairedObject() { return nameOfPairedObject; }
	std::string getNameOfCreatedObject() { return nameOfCreatedObject; }
	std::string getRoom() { return room; }

	//Setters
	void setId(unsigned int id) { PairObject::id = id; }
	void setName(std::string name) { PairObject::name = name; }
	void setDescription(std::string description) { PairObject::description = description; }
	void setPickUpable(bool pickUpable) { PairObject::pickUpable = pickUpable; }
	void setNameOfPairedObject(std::string nameOfPairedObject)
	{
		PairObject::nameOfPairedObject = nameOfPairedObject;
	}
	void setNameOfCreatedObject(std::string nameOfCreatedObject)
	{
		PairObject::nameOfCreatedObject = nameOfCreatedObject;
	}
	void setRoom(std::string room) { PairObject::room = room; }
#pragma endregion

#pragma region Other Methods
	virtual std::string open();
	virtual std::string useWith(std::string nameOfPair);
	std::string addToInventory();
	void print();
	bool operator==(PairObject& other);
	bool operator==(Object& other);
#pragma endregion


private:
	unsigned int id;
	std::string name, description, room, nameOfPairedObject, nameOfCreatedObject;
	bool pickUpable;
};