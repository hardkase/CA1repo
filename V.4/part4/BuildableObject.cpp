#include "BuildableObject.h"

BuildableObject::BuildableObject(unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string descriptionOfCreation) : Object(id, name, description, pickUpable),
	descriptionOfCreation(descriptionOfCreation)
{
}


BuildableObject::~BuildableObject()
{
}
