#pragma once
#include <string>

class Object
{
public:
#pragma region Constructors/ Destructor
	Object(unsigned int id, std::string name, std::string description, bool pickUpable,
		std::string room);
	~Object();
#pragma endregion

#pragma region Properties
	//Getters
	unsigned int getId() { return id; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	bool getPickUpable() { return pickUpable; }
	std::string getRoom() { return room; }

	//Setters
	void setId(unsigned int id) { Object::id = id; }
	void setName(std::string name) { Object::name = name; }
	void setDescription(std::string description) { Object::description = description; }
	void setPickUpable(bool pickUpable) { Object::pickUpable = pickUpable; }
	void setRoom(std::string room) { Object::room = room; }
#pragma endregion

#pragma region Other Methods
	virtual std::string open();
	virtual std::string useWith(std::string pairName);
	void print();
	//void virtual print() = 0;
#pragma endregion


private:
	unsigned int id;
	std::string name, description, room;
	bool pickUpable;
};