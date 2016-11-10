#include "PairObject.h"
#include <iostream>

PairObject::PairObject(unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string nameOfPairedObject, std::string nameOfCreatedObject, std::string room)
	: Object(id, name, description, pickUpable),  nameOfPairedObject(nameOfPairedObject),
	nameOfCreatedObject(nameOfCreatedObject), room(room)
{
}

PairObject::~PairObject()
{
}

std::string PairObject::useWith(Object o)
{
	if (nameOfPairedObject == "null")
	{
		return "Can't do that...";
	}

	else if (nameOfPairedObject == o.getName())  //the two items will be used to create other item
	{
		return nameOfCreatedObject;
	}

	else return "Can't do that...";
}

void PairObject::print()
{
	std::cout << name << std::endl;
}