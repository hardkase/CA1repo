#include "Room.h"
#include <iostream>

using namespace std;

Room::Room()
{
}

Room::Room(unsigned int number, unsigned int north, unsigned int south, unsigned int east, unsigned int west,
	std::string name, std::string description) : number(number), north(north), south(south), east(east), west(west),
	name(name), description(description)
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