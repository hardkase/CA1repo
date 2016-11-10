#pragma once
#include <string>

class Object
{
public:
#pragma region Constructors/ Destructor
	Object(unsigned int id, std::string name, std::string description, bool pickUpable);
	~Object();
#pragma endregion

#pragma region Properties
	//Getters
	unsigned int getId() { return id; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	bool getPickUpable() { return pickUpable; }

	//Setters
	void setId(unsigned int id) { Object::id = id; }
	void setName(std::string name) { Object::name = name; }
	void setDescription(std::string description) { Object::description = description; }
	void setPickUpable(bool pickUpable) { Object::pickUpable = pickUpable; }
#pragma endregion

#pragma region Other Methods
	std::string open() { return "Can't do that..."; }
	std::string useWith(Object o) { return "Can't do that..."; }
	void print();
	std::string addToInventory();
#pragma endregion


private:
	unsigned int id;
	std::string name, description, room;
	bool pickUpable;
};