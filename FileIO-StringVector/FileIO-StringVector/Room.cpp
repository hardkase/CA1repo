#include "Room.h"
#include <string>
#include <iostream>
using namespace std;



Room::Room()
{
}

Room::Room(std::string id, std::string name, std::string desc) : id(id), name(name), desc(desc)
{
}


Room::~Room()
{
}

void Room::print(Room r)
{
	cout << "ID: " << r.getID() << endl;
	cout << "Name: " << r.getName() << endl;
	cout << "Description: " << r.getDesc() << endl;
}
