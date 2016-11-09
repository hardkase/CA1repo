#include "Object.h"
#include <iostream>

using namespace std;

Object::Object(unsigned int id, std::string name, std::string description,
	std::string nameOfPairedObject, std::string nameOfCreatedObject)
	: id(id), name(name), description(description), nameOfPairedObject(nameOfPairedObject),
	nameOfCreatedObject(nameOfCreatedObject) {}

Object::~Object() {}

std::string Object::open()
{
	return "Can't do that...";
}

std::string Object::useWith(Object o)
{
	if (nameOfPairedObject == "null")
	{
		return "Can't do that...";
	}

	else if (nameOfPairedObject == o.getName())  //the two items will be used to create other item
	{
		return nameOfCreatedObject;
		//search vector by name
		//return position in vector
		//output object creation description
		//Copy object at position whatever to inventory
		//remove o and this object from inventory
		//return createdObjectDescription;

		//vObject.search();
	}

	else return "Can't do that...";
}

void Object::print()
{
	std::cout << name << endl;
}