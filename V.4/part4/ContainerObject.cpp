#include "ContainerObject.h"



ContainerObject::ContainerObject(unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string room, std::string nameOfObjectInside, std::string openText)
	: Object(id, name, description, pickUpable), room(room), nameOfObjectInside(nameOfObjectInside),
	openText(openText)
{
}


ContainerObject::~ContainerObject()
{
}

std::string open()
{

}