#include "Object.h"
#include <iostream>

Object::Object(unsigned int id, std::string name, std::string description, bool pickUpable,
	std::string room) : id(id), name(name), description(description), pickUpable(pickUpable),
	room(room)
{
}

Object::~Object() {}

void Object::print()
{
	std::cout << name << std::endl;
}

std::string Object::useWith(std::string pairName)
{
	return "Can't do that...";
}

std::string Object::open()
{
	return "Can't do that...";
}