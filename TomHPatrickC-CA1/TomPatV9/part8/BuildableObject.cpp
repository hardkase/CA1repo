#include "BuildableObject.h"

BuildableObject::BuildableObject(unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string room, std::string descriptionOfCreation) : Object(id, name,
		description, pickUpable, room), descriptionOfCreation(descriptionOfCreation)
{
}

BuildableObject::~BuildableObject()
{
}

std::string BuildableObject::useWith(std::string pairName)
{
	return "Can't do that...";
}

std::string BuildableObject::open()
{
	return "Can't do that...";
}