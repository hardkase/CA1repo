#include "ContainerObject.h"

ContainerObject::ContainerObject(unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string room, std::string nameOfObjectInside)
	: Object(id, name, description, pickUpable, room),
	nameOfObjectInside(nameOfObjectInside)
{
}

ContainerObject::~ContainerObject()
{
}

std::string ContainerObject::useWith(std::string pairName)
{
	return "Can't do that...";
}

std::string ContainerObject::open()
{
	return nameOfObjectInside;
}