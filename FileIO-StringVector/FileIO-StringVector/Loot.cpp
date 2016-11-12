#include "Loot.h"
#include <string>
#include <iostream>
using namespace std;



Loot::Loot()
{
}

Loot::Loot(std::string id, std::string name, std::string desc) : id(id), name(name), desc(desc)
{
}


Loot::~Loot()
{
}

void Loot::print(Loot l)
{
	cout << "ID: " << l.getID() << endl;
	cout << "Name: " << l.getName() << endl;
	cout << "Description: " << l.getDesc() << endl;
}
