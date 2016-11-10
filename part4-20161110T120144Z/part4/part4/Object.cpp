#include "Object.h"
#include <iostream>

Object::Object(unsigned int id, std::string name, std::string description, bool pickUpable)
	: id(id), name(name), description(description), pickUpable(pickUpable)
{
}

Object::~Object() {}

std::string addToInventory()
{
	if (pickUpable == true)
	{

	}
	return "hellow";
}

void Object::print()
{
	std::cout << name << std::endl;
}