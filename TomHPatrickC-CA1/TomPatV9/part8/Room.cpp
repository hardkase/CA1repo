#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room(unsigned int number, std::string east, std::string south, std::string west,
	std::string north, std::string name, std::string description) : number(number), east(east),
	south(south), west(west), north(north), name(name), description(description)
{
}

Room::~Room()
{
}

void Room::print()
{
	cout << "---------------------------------------------------------------------\n"
		<< name
		<< "\n---------------------------------------------------------------------\n"
		<< description << "\n"
		<< "You see" /*Put room objects here*/ << "\n"
		<< "From here you can go to: " << "\n"
		<< "\n---------------------------------------------------------------------";
}