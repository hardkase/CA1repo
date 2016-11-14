#include "PairObject.h"
#include <iostream>

/*PairObject::PairObject() : Object(0, "def", "defDes", false, "null", "null"),
nameOfPairedObject("def"), nameOfCreatedObject("def")
{
}*/

PairObject::PairObject(unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string nameOfPairedObject, std::string nameOfCreatedObject,
	std::string room) : Object(id, name, description, pickUpable, room),
	nameOfPairedObject(nameOfPairedObject), nameOfCreatedObject(nameOfCreatedObject)
{
}

PairObject::~PairObject()
{
}

std::string PairObject::useWith(std::string nameOfPair)
{
	if (nameOfPairedObject == "null")
	{
		return "Can't do that...";
	}

	else if (nameOfPairedObject == nameOfPair)  //the two items will be used to create other item
	{
		return nameOfCreatedObject;
	}

	else return "Can't do that...";
}

void PairObject::print()
{
	std::cout << name << std::endl;
}

bool PairObject::operator==(PairObject& other)
{
	return (id == other.getId())
		&& (name == other.getName())
		&& (description == other.getDescription())
		&& (pickUpable == other.getPickUpable())
		&& (nameOfPairedObject == other.getNameOfPairedObject())
		&& (nameOfCreatedObject == other.getNameOfCreatedObject())
		&& (room == other.getRoom());
}

bool PairObject::operator==(Object& other)
{
	return (id == other.getId())
		&& (name == other.getName())
		&& (description == other.getDescription())
		&& (pickUpable == other.getPickUpable())
		&& (nameOfPairedObject == "Null")
		&& (nameOfCreatedObject == "Null")
		&& (room == other.getRoom());
}

std::string PairObject::open()
{
	return "Can't do that...";
}