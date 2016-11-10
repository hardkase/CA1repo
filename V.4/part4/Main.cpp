#include <iostream>
#include <vector>
#include <sstream>
#include "Room.h"
#include "Object.h"
#include "PairObject.h"
#include "BuildableObject.h"

using namespace std;

unsigned int searchObjects(vector<Object> vector, std::string firstObject);
std::string examineObject(std::string objectName, vector<Object> vector);
void print(vector<Object> vector);

int main()
{
	vector<Object> roomVector;
	vector<Room> vRoom;
	Room currentRoom(0, 1, 0, 3, 0, "0", "Room 0");
	//					    N  S  E  W
	vRoom.push_back(Room(0, 1, 0, 3, 0, "0", "Room 0"));
	vRoom.push_back(Room(1, 0, 0, 2, 0, "1", "Room 1"));
	vRoom.push_back(Room(2, 7, 3, 5, 1, "2", "Room 2"));
	vRoom.push_back(Room(3, 2, 0, 4, 0, "3", "Room 3"));
	vRoom.push_back(Room(4, 5, 0, 0, 3, "4", "Room 4"));
	vRoom.push_back(Room(5, 0, 4, 0, 2, "5", "Room 5"));

	vector<Object> vObject;
	vObject.push_back(PairObject(0, "Stick", "A large woden stick about three feet in length.",
		true, "Stone", "Axe", "0"));
	vObject.push_back(PairObject(1, "Stone", "A flat stone pointed at one end.", true,
		"Stick", "Axe", "0"));
	vObject.push_back(BuildableObject(2, "Axe",
		"A large axe about 3 feet long.  Can be used for defence.", true, "null"));

	vector<Object> inventory;
	
	currentRoom.print();

	cout << endl << ">";
	string input;
	string word;
	int nextRoom;
	bool vase = false;

	do
	{
		getline(cin, input);
		vector<string> vWords;
		string word;
		istringstream iss(input);
		while (iss >> word) vWords.push_back(word);

		if (vWords[0] == "examine")
		{
			cout << examineObject(vWords[1], vObject);

			cout << endl << ">";
		}

		else if (vWords[0] == "go" && vWords[1] == "to")
		{
			//moveCharacter();

			cout << endl << ">";
		}

		else if (vWords[0] == "inventory")
		{
			cout << "Inventory:" << endl;
			if (inventory.size() == 0)
				cout << "Inventory Empty" << endl;
			print(inventory);
			cout << endl << ">";
		}

		else if (vWords[0] == "use")
		{
			std::string firstObjectName = vWords[1];
			std::string secondObjectName = vWords[3];

			unsigned int posOfFirstObject = searchObjects(vObject, firstObjectName);
			unsigned int posOfSecondObject = searchObjects(vObject, secondObjectName);

			std::string result = vObject[posOfFirstObject].useWith(vObject[posOfSecondObject]);

			unsigned int posOfNewObject;

			if (result == "Can't do that...")
				cout << result;
			else posOfNewObject = searchObjects(vObject, result);

			if (posOfNewObject < -1)
			{
				inventory.push_back(vObject[posOfNewObject]);
			}

			cout << endl << ">";
		}

		else cout << "can't do that..." << endl;

		/*
		if (input == "north")
		nextRoom = currentRoom.getNorth();
		else if (input == "south")
		nextRoom = currentRoom.getSouth();
		else if (input == "east")
		nextRoom = currentRoom.getEast();
		else if (input == "west")
		nextRoom = currentRoom.getWest();

		if (nextRoom == 0)
		{
		cout << "The way is blocked" << endl;
		}

		else
		{
		currentRoom.setNumber(vRoom[nextRoom].getNumber());
		currentRoom.setNorth(vRoom[nextRoom].getNorth());
		currentRoom.setSouth(vRoom[nextRoom].getSouth());
		currentRoom.setEast(vRoom[nextRoom].getEast());
		currentRoom.setWest(vRoom[nextRoom].getWest());
		currentRoom.setName(vRoom[nextRoom].getName());
		currentRoom.setDescription(vRoom[nextRoom].getDescription());
		currentRoom.print();
		}*/

		if (currentRoom.getNumber() == 5)
			vase = true;

	} while (vase == false);

	system("pause");
	return 0;
}

unsigned int searchObjects(vector<Object> vector, std::string firstObject)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i].getName() == firstObject)
			return i;
	}
}

std::string examineObject(std::string objectName, vector<Object> vector)
{
	unsigned int objectPosition = searchObjects(vector, objectName);
	return vector[objectPosition].getDescription();
}

void print(vector<Object> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << "vector[" << i << "] = "; vector[i].print();
	}
}