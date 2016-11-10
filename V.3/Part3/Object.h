#pragma once
#include <string>

class Object
{
public:
#pragma region Constructors/ Destructor
	Object(unsigned int id, std::string name, std::string description, std::string nameOfPairedObject,
		std::string nameOfCreatedObject);
	~Object();
#pragma endregion

#pragma region Properties
	//Getters
	unsigned int getId() { return id; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	std::string getNameOfPairedObject() { return nameOfPairedObject; }
	std::string getNameOfCreatedObject() { return nameOfCreatedObject; }

	//Setters
	void setId(unsigned int id) { Object::id = id; }
	void setName(std::string name) { Object::name = name; }
	void setDescription(std::string description) { Object::description = description; }
	void setNameOfPairedObject(std::string nameOfPairedObject) { Object::nameOfPairedObject = nameOfPairedObject; }
	void setNameOfCreatedObject(std::string nameOfCreatedObject) { Object::nameOfCreatedObject = nameOfCreatedObject; }
#pragma endregion

#pragma region Other Methods
	std::string open();
	std::string useWith(Object o);
	void print();
#pragma endregion


private:
	unsigned int id;
	std::string name, description, nameOfPairedObject, nameOfCreatedObject;
};