#pragma once
#include "Object.h"
class BuildableObject :public Object
{
public:
	#pragma region Constructor/ Destructor

		BuildableObject(unsigned int id, std::string name, std::string description,
			bool pickUpable, std::string descriptionOfCreation);
		~BuildableObject();

	#pragma endregion

	#pragma region Properties
		//Getters
		unsigned int getId() { return id; }
		std::string getName() { return name; }
		std::string getDescription() { return description; }
		bool getPickUpable() { return pickUpable; }
		std::string getDescriptionOfCreation() { return descriptionOfCreation; }

		//Setters
		void setId(unsigned int id) { BuildableObject::id = id; }
		void setName(std::string name) { BuildableObject::name = name; }
		void setDescription(std::string description)
			{ BuildableObject::description = description; }
		void setPickUpable(bool pickUpable) { BuildableObject::pickUpable = pickUpable; }
		void setDescriptionOfCreation(std::string descriptionOfCreation)
			{ BuildableObject::descriptionOfCreation = descriptionOfCreation;}
	#pragma endregion

	#pragma region Other Methods
		std::string open() { return "Can't do that..."; }
		std::string virtual useWith(Object o) { return "Can't do that..."; }
		std::string addToInventory();
		void print();
	#pragma endregion


	private:
		unsigned int id;
		std::string name, description, room, descriptionOfCreation;
		bool pickUpable;
};