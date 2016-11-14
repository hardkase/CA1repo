/*DungeonSplorer Engine
Thomas Hanahoe & Patrick Collins
CA1 for C++
Version 1.12
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Room.h"
#include "Object.h"
#include "PairObject.h"
#include "BuildableObject.h"
#include "ContainerObject.h"
//#include <cstdlib>

using namespace std;

void initializeGame();
vector<string> readGameData();
vector<Object*> loadObjects(vector<string> gameStrings, vector<Object*> allObjectsInGame);
vector<Object*> loadPairObjects(vector<string> gameStrings, vector<Object*> allObjectsInGame);
vector<Object*> loadBuildables(vector<string> gameStrings, vector<Object*> allObjectsInGame);
vector<Object*> loadContainers(vector<string> gameStrings, vector<Object*> allObjectsInGame);
vector<Room> loadRooms(vector<string> gameStrings);
void printRooms(vector<Room> roomVector);//test
void printObjects(vector<Object*> allObjectsInGame);//test
//vector<string> getStartText(vector<string> gameStrings); GRAVEYARD
//vector<string> getEndText(vector<string> gameStrings); GRAVEYARD
//void printStartEnd(vector<string> startText, vector<string> endText); GRAVEYARD

vector<string> changeInputIntoVectorOfStrings(std::string input);

int searchObjects(vector<Object> vector, std::string firstObject);

int searchObjects(vector<Object*> vector, std::string firstObject);

int searchRooms(vector<Room> listOfRooms, std::string roomName);

void examineObject(vector<std::string> vWords, vector<Object*> vector);

void pickUpObject(std::string objectName, vector<Object*> allObjectsInGame, Room currentRoom,
	vector<Object*>& inventory);

void getNewRoom(vector<string> vWords, Room& currentRoom, vector<Room> listOfRooms);

void changeRoom(unsigned int posOfNewRoom, Room& currentRoom, vector<Room> listOfRooms);

void outputInventory(vector<Object*> inventory);

void openObject(vector<std::string> vWords, vector<Object*> allObjectsInGame,
	vector<Object*> inventory);

void joinTwoObjectsTogether(std::string firstObject, std::string secondObject,
	vector<Object*> allObjectsInGame, vector<Object*> inventory);

/*void joinObjectsTogether(std::string firstObject, std::string secondObject, vector<Object> allObjectsInGame,
vector<Object> inventory);*/

void print(vector<Object> vector);
void print(vector<Object*> vector);

void outputErrorMessage();

int main()
{
	/*
	Name: Main

	Purpose: Runs the prgrame

	Input: None

	Output: None

	Exception: None

	Author: Thomas Hanahoe
	*/
	vector<Object*> allObjectsInGame;
	vector<string> gameStrings = readGameData();
	vector<Room> listOfRooms = loadRooms(gameStrings);
	loadObjects(gameStrings, allObjectsInGame);
	loadPairObjects(gameStrings,  allObjectsInGame);
	loadContainers(gameStrings,  allObjectsInGame);
	loadBuildables(gameStrings, allObjectsInGame);
	vector<Object*> inventory;
	//vector<string> startText = getStartText(gameStrings);
	//vector<string> endText = getEndText(gameStrings);

	//printRooms(roomVector);//test
	printObjects(allObjectsInGame);//test
	//printStartEnd(startText, endText);//test - not working right
	/*
	vector<Room> listOfRooms;
	vector<Object*> inventory;


	Room currentRoom(0, "1", "0", "3", "0", "0", "Room 0");
	//Add rooms to the vector
	//					    N  S  E  W
	listOfRooms.push_back(Room(0, "a dark room", "0", "3", "0", "0", "Room 0"));
	listOfRooms.push_back(Room(1, "0", "a dark room", "2", "0", "1", "Room 3"));
	listOfRooms.push_back(Room(2, "7", "3", "5", "1", "a dark room", "Room 2"));
	listOfRooms.push_back(Room(3, "2", "0", "4", "0", "7", "Room 7"));
	listOfRooms.push_back(Room(4, "5", "0", "0", "3", "4", "Room 4"));
	listOfRooms.push_back(Room(5, "0", "4", "0", "2", "5", "Room 5"));

	//Add objects to allObjectsInGame
	PairObject p1(0, "Stick", "A large woden stick about three feet in length.", true, "Stone",
	"Axe", "0");
	PairObject p2(1, "Stone", "A flat stone pointed at one end.", true, "Stick", "Axe", "1");
	BuildableObject b1(2, "Axe", "A large axe about 3 feet long.  Can be used for defence.", true,
	"null", "null");
	ContainerObject c1(3, "Woden Grate",
	"An old woden grate.  It has an engraving of a seal on it", false, "1", "Stick");
	Object o1(4, "Book", "A dusty old book.  It has a strange crest on it", true, "1");

	vector<Object*> allObjectsInGame;

	allObjectsInGame.push_back(&p1);
	allObjectsInGame.push_back(&p2);
	allObjectsInGame.push_back(&b1);
	allObjectsInGame.push_back(&c1);
	allObjectsInGame.push_back(&o1);
	*/
	Room currentRoom = listOfRooms[0];
	currentRoom.print();

	cout << endl << ">";
	string input;
	string word;
	//int nextRoom;
	int posOfVase;

	do
	{
		vector<string> vWords = changeInputIntoVectorOfStrings(input);

		if (vWords[0] == "examine")
		{
			examineObject(vWords, allObjectsInGame);
			cout << endl << ">";
		}

		else if (vWords[0] == "pick" && vWords[1] == "up")
		{
			pickUpObject(vWords[2], allObjectsInGame, currentRoom, inventory);
			/*
			int pos = searchObjects(allObjectsInGame, vWords[2]);
			if (pos == -1)
			outputErrorMessage();
			else
			{
			bool pickUpable = allObjectsInGame[pos].getPickUpable();
			if (pickUpable = true)
			inventory.push_back(allObjectsInGame[pos]);
			else
			outputErrorMessage();
			}
			*/
			cout << endl << ">";
		}

		else if (vWords[0] == "go" && vWords[1] == "to")
		{
			getNewRoom(vWords, currentRoom, listOfRooms);
			cout << endl << ">";
		}

		else if (vWords[0] == "inventory")
		{
			outputInventory(inventory);
			cout << endl << ">";
		}

		else if (vWords[0] == "use" && vWords[2] == "with")
		{
			joinTwoObjectsTogether(vWords[1], vWords[3], allObjectsInGame, inventory);
			/*
			std::string firstObject = vWords[1];
			std::string secondObject = vWords[3];

			int posOfFirstObject = searchObjects(allObjectsInGame, firstObject);
			int posOfSecondObject = searchObjects(allObjectsInGame, secondObject);

			//Right so far


			std::string nameOfBuildableObject
			= allObjectsInGame[posOfFirstObject]->useWith(secondObject);

			cout << "nameOfBuildableObject: " << nameOfBuildableObject << endl;

			int posOfBuildableObject = searchObjects(allObjectsInGame, nameOfBuildableObject);

			cout << "posOfBuildableObject: " << posOfBuildableObject << endl;

			inventory.push_back(allObjectsInGame[posOfBuildableObject]);

			*/

			//joinObjectsTogether(vWords[1], vWords[3], allObjectsInGame, inventory);
			/*
			std::string firstObjectName = vWords[1];
			std::string secondObjectName = vWords[3];

			int posOfFirstObject = searchObjects(allObjectsInGame, firstObjectName);
			int posOfSecondObject = searchObjects(allObjectsInGame, secondObjectName);

			if (posOfFirstObject == -1 || posOfSecondObject == -1)
			outputErrorMessage();
			else
			{
			std::string createdObject
			= allObjectsInGame[posOfFirstObject].useWith(allObjectsInGame[posOfSecondObject]);

			int posOfNewObject = 0;

			if (createdObject == "Can't do that...")
			outputErrorMessage();
			else
			posOfNewObject = searchObjects(allObjectsInGame, createdObject);

			if (posOfNewObject < -1)
			{
			inventory.push_back(allObjectsInGame[posOfNewObject]);
			}
			}
			*/
			cout << endl << ">";
		}

		else if (vWords[0] == "open")
		{
			openObject(vWords, allObjectsInGame, inventory);
			cout << endl << ">";
		}

		else
		{
			outputErrorMessage();
			cout << endl << ">";
		}

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

		posOfVase = searchObjects(inventory, "Ming vase");
	} while (posOfVase == -1);

	system("pause");
	return 0;
}

void initializeGame()
{
}

vector<string> readGameData()
{
	vector<string> outVector;
	ifstream gameData;
	string drive = "C:\\";
	//setup for user selectable gamedata location - fix if time permits - default to c:/temp/gamedata.txt
	//size_t driveSize = drive.size();
	//cout << "Please enter the drive letter the game file is stored on i.e. C or E, etc. " << endl;
	//cin >> drive;
	string dir = "temp\\";
	string fName = "gameData.txt";
	string path = drive + dir + fName;
	gameData.open(path);
	if (!gameData)
	{
		cout << "Error-can't find file or file is empty!" << endl;
	}
	while (!gameData.eof())
	{
		string temp;
		getline(gameData, temp);
		outVector.push_back(temp);
	}
	gameData.close();
	return outVector;
}
vector<Room> loadRooms(vector<string> gameStrings)
{
	/*ROOM VARS: unsigned int number, std::string east, std::string south, std::string west,
	std::string north, std::string name, std::string description*/
	//could use a load of vectors, get all objects from text, put vectors into an array, and return array...?
	vector<Room> outVector;
	string id;
	size_t idSize;
	int number;
	string east;
	string south;
	string west;
	string north;
	string name;
	string descr;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*R*")
		{
			//string to int conversion reference: http://www.cplusplus.com/reference/string/stoi/
			id = gameStrings[i + 1];
			number = stoi(id, &idSize);
			east = gameStrings[i + 2];
			south = gameStrings[i + 3];
			west = gameStrings[i + 4];
			north = gameStrings[i + 5];
			name = gameStrings[i + 6];
			descr = gameStrings[i + 7];
			Room room(number, east, south, west, north, name, descr);
			outVector.push_back(room);
		}
	}
	return outVector;
}
//following three print methods are for testing file-IO and object instantiation
void printRooms(vector<Room> roomVector)//test print method to check room and vector propagation
{
	for (Room r : roomVector)
	{
		cout << r.getNumber() << endl;
		cout << r.getEast() << endl;
		cout << r.getSouth() << endl;
		cout << r.getWest() << endl;
		cout << r.getNorth() << endl;
		cout << r.getName() << endl;
		cout << r.getDescription() << endl;
	}
}
void printObjects(vector<Object*> allObjectsInGame)
{
	for (Object* o : allObjectsInGame)
	{
		cout << o->getId() << endl;
		cout << o->getName() << endl;
		cout << o->getDescription() << endl;
		cout << o->getPickUpable() << endl;
		cout << o->getRoom() << endl;
	}

}
void printStartEnd(vector<string> startText, vector<string> endText)
{
	cout << "Start: " << endl;
	for (string s : startText)
		cout << s << endl;
	cout << "\n\n End: " << endl;
	for (string s : endText)
		cout << s << endl;
}
vector<Object*> loadObjects(vector<string> gameStrings, vector<Object*> allObjectsInGame)//*O*
{
	/*OBJ VARS: unsigned int id, std::string name, std::string description, bool pickUpable,
	std::string room, std::string objectInside*/
	//vector<Object> outVector;
	string id;
	size_t idSize;
	int number;
	string name;
	string description;
	string toBool;
	bool pUable;
	string room;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*O*")
		{
			//string to int conversion reference: http://www.cplusplus.com/reference/string/stoi/
			//string to bool conversion reference: 
			//http://stackoverflow.com/questions/2165921/converting-from-a-stdstring-to-bool
			//used STD::STOI approach
			id = gameStrings[i + 1];
			number = stoi(id, &idSize);
			name = gameStrings[i + 2];
			description = gameStrings[i + 3];
			toBool = gameStrings[i + 4];
			pUable = stoi(toBool.c_str());
			room = gameStrings[i + 5];
			Object item(number, name, description, pUable, room);
			allObjectsInGame.push_back(&item);
		}
	}
	return allObjectsInGame;
}
vector<Object*> loadPairObjects(vector<string> gameStrings, vector<Object*> allObjectsInGame)//*PO*
{
	/*PAIR OBJ VARS: unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string room, std::string objectInside, std::string
	nameOfPairedObject, std::string nameOfCreatedObject*/
	//vector<PairObject> outVector;
	string id;
	size_t idSize;
	int number;
	string name;
	string description;
	string toBool;
	bool pUable;
	string room;
	string nOpO;
	string nOcO;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*PO*")
		{
			//string to int conversion reference: http://www.cplusplus.com/reference/string/stoi/
			//string to bool conversion reference: 
			//http://stackoverflow.com/questions/2165921/converting-from-a-stdstring-to-bool
			//used STD::STOI approach
			id = gameStrings[i + 1];
			number = stoi(id, &idSize);
			name = gameStrings[i + 2];
			description = gameStrings[i + 3];
			toBool = gameStrings[i + 4];
			pUable = stoi(toBool.c_str());
			room = gameStrings[i + 5];
			nOpO = gameStrings[i + 6];
			nOcO = gameStrings[i + 7];
			PairObject pItem(number, name, description, pUable, room, nOpO, nOcO);
			allObjectsInGame.push_back(&pItem);
		}
	}
	return allObjectsInGame;
}
vector<Object*> loadBuildables(vector<string> gameStrings, vector<Object*> allObjectsInGame)//*BO*
{
	/*BObj VARS unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string room, std::string objectInside, std::string descriptionOfCreation
	*/
	//vector<BuildableObject> outVector;
	string id;
	size_t idSize;
	int number;
	string name;
	string description;
	string toBool;
	bool pUable;
	string room;
	string descCreat;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*BO*")
		{
			//string to int conversion reference: http://www.cplusplus.com/reference/string/stoi/
			//string to bool conversion reference: 
			//http://stackoverflow.com/questions/2165921/converting-from-a-stdstring-to-bool
			//used STD::STOI approach
			id = gameStrings[i + 1];
			number = stoi(id, &idSize);
			name = gameStrings[i + 2];
			description = gameStrings[i + 3];
			toBool = gameStrings[i + 4];
			pUable = stoi(toBool.c_str());
			room = gameStrings[i + 5];
			descCreat = gameStrings[i + 6];
			BuildableObject bItem(number, name, description, pUable, room, descCreat);
			allObjectsInGame.push_back(&bItem);
		}
	}
	return allObjectsInGame;
}
vector<Object*> loadContainers(vector<string> gameStrings, vector<Object*> allObjectsInGame)//*CO*
{
	/* CONTAINER VARS unsigned int id, std::string name, std::string description,
	bool pickUpable, std::string room, std::string objectInside, std::string openText
	*/
	//vector<ContainerObject> outVector;
	string id;
	size_t idSize;
	int number;
	string name;
	string description;
	string toBool;
	bool pUable;
	string room;
	string objI;
	string openText;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*CO*")
		{
			//string to int conversion reference: http://www.cplusplus.com/reference/string/stoi/
			//string to bool conversion reference: 
			//http://stackoverflow.com/questions/2165921/converting-from-a-stdstring-to-bool
			//used STD::STOI approach
			id = gameStrings[i + 1];
			number = stoi(id, &idSize);
			name = gameStrings[i + 2];
			description = gameStrings[i + 3];
			toBool = gameStrings[i + 4];
			pUable = stoi(toBool.c_str());
			room = gameStrings[i + 5];
			objI = gameStrings[i + 6];
			ContainerObject cItem(number, name, description, pUable, room, objI);
			allObjectsInGame.push_back(&cItem);
		}
	}
	return allObjectsInGame;
}
vector<string> getStartText(vector<string> gameStrings)
{
	vector<string> outVector;
	string line;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*START*")
		{
			for (int j = i + 1; j < 10; j++)
				line = gameStrings[j];
			outVector.push_back(line);
		}
	}
	return outVector;
}
vector<string> getEndText(vector<string> gameStrings)
{
	vector<string> outVector;
	string line;
	size_t size = gameStrings.size();
	for (int i = 0; i < size; i++)
	{
		if (gameStrings[i] == "*END*")
		{
			for (int j = i + 1; j < 10; j++)
				line = gameStrings[j];
			outVector.push_back(line);
		}
	}
	return outVector;
}
void examineObject(vector<std::string> vWords, vector<Object*> allObjectsInGame)
{
	/*
	Name: examineObject

	Purpose: Allows the user to get the details of a particular object

	Input: List of words inputted by the user and the list of all the objects in the game

	Output: Description of Object

	Exception: None

	Author: Thomas Hanahoe
	*/
	string objectName = "";
	if (vWords.size() > 2)
	{
		for (int i = 1; i < vWords.size(); i++)
		{
			if (i == (vWords.size() - 1))
				objectName += vWords[i];
			else
				objectName += vWords[i] + " ";
		}
	}
	else objectName = vWords[1];

	int posOfObject = searchObjects(allObjectsInGame, objectName);
	if (posOfObject == -1)
		outputErrorMessage();
	else
		cout << allObjectsInGame[posOfObject]->getDescription() << endl;
}

void pickUpObject(std::string objectName, vector<Object*> allObjectsInGame, Room currentRoom,
	vector<Object*>& inventory)
{
	/*
	Name: pickUpObject

	Purpose: Allows the user to "pick up" an object and put it in their inventory

	Input: the object's name, the list of all objects in the game, the current room and the inentory

	Output: <Object> has been added to the inventory

	Exception: None

	Author: Thomas Hanahoe
	*/
	/*
	Get the third word inputed
	Find it in the object list
	if it is not in the list output the error
	if it is get it's pickupable value
	if it's pickupable value is false output the error
	if it's pickupable value is true then get it's room value
	if it's room value is equal to the current room's room value then add it to the inventory.
	*/
	int pos = searchObjects(inventory, objectName);
	if (pos == -1)//Object is not already in the inventory...
	{
		pos = searchObjects(allObjectsInGame, objectName);
		if (pos != -1)
		{
			if (allObjectsInGame[pos]->getPickUpable() == false)
				outputErrorMessage();
			else
			{
				if (allObjectsInGame[pos]->getRoom() == currentRoom.getName())
				{
					inventory.push_back(allObjectsInGame[pos]);
					cout << objectName << " has been added to the inventory" << endl;
				}
				else
					outputErrorMessage();
			}
		}
		else
			outputErrorMessage();
	}
	else
	{
		outputErrorMessage();
	}
}

void getNewRoom(vector<string> vWords, Room& currentRoom, vector<Room> listOfRooms)
{
	/*
	Name: getNewRoom

	Purpose: Allows the user to move to a different room

	Input: the user's input, the current room and the list of rooms

	Output: None

	Exception: None

	Author: Thomas Hanahoe
	*/

	//Get name of room
	string roomName = "";
	if (vWords.size() > 3)
	{
		for (int i = 2; i < vWords.size(); i++)
		{
			if (i == (vWords.size() - 1))
				roomName += vWords[i];
			else
				roomName += vWords[i] + " ";
		}
	}
	else roomName = vWords[2];

	//Search Object vector for a room with that name
	int posOfNewRoom = searchRooms(listOfRooms, roomName);
	if (posOfNewRoom == -1)
		outputErrorMessage();
	else if (posOfNewRoom > -1)
		changeRoom(posOfNewRoom, currentRoom, listOfRooms);
}

void changeRoom(unsigned int posOfNewRoom, Room& currentRoom, vector<Room> listOfRooms)
{
	/*
	Name: changeRoom

	Purpose: sets the values of current room to the desired rooms values

	Input: position of the new Rooms values in list of rooms, the current room and the list of rooms

	Output: prints the room

	Exception: None

	Author: Thomas Hanahoe
	*/
	currentRoom.setNumber(listOfRooms[posOfNewRoom].getNumber());
	currentRoom.setWest(listOfRooms[posOfNewRoom].getWest());
	currentRoom.setSouth(listOfRooms[posOfNewRoom].getSouth());
	currentRoom.setEast(listOfRooms[posOfNewRoom].getEast());
	currentRoom.setNorth(listOfRooms[posOfNewRoom].getNorth());
	currentRoom.setName(listOfRooms[posOfNewRoom].getName());
	currentRoom.setDescription(listOfRooms[posOfNewRoom].getDescription());
	currentRoom.print();
}

void outputInventory(vector<Object*> inventory)
{
	/*
	Name: changeRoom

	Purpose: sets the values of current room to the desired rooms values

	Input: position of the new Rooms values in list of rooms, the current room and the list of rooms

	Output: prints the room

	Exception: None

	Author: Thomas Hanahoe
	*/
	cout << "Inventory:" << endl;
	if (inventory.size() == 0)
		cout << "Inventory Empty" << endl;
	else
		print(inventory);
}

void joinTwoObjectsTogether(std::string firstObject, std::string secondObject,
	vector<Object*> allObjectsInGame, vector<Object*> inventory)
{
	int posOfFirstObject = searchObjects(allObjectsInGame, firstObject);
	int posOfSecondObject = searchObjects(allObjectsInGame, secondObject);

	std::string nameOfBuildableObject = allObjectsInGame[posOfFirstObject]->useWith(secondObject);

	int posOfBuildableObject = searchObjects(allObjectsInGame, nameOfBuildableObject);

	inventory.push_back(allObjectsInGame[posOfBuildableObject]);
	cout << nameOfBuildableObject << " has been added to the inventory" << endl;
}

/*void joinObjectsTogether(std::string firstObject, std::string secondObject, vector<Object> allObjectsInGame,
vector<Object> inventory)
{
int posOfFirstObject = searchObjects(allObjectsInGame, firstObject);
int posOfSecondObject = searchObjects(allObjectsInGame, secondObject);

std::string createdObject = "";
if (posOfFirstObject == -1 || posOfSecondObject == -1)
outputErrorMessage();
else
createdObject = allObjectsInGame[posOfFirstObject].useWith(allObjectsInGame[posOfSecondObject]);

int posOfNewObject = 0;
if (createdObject == "Can't do that...")
{
outputErrorMessage();
return;
}
else
posOfNewObject = searchObjects(allObjectsInGame, createdObject);

if (posOfNewObject < -1)
{
inventory.push_back(allObjectsInGame[posOfNewObject]);
}
else
outputErrorMessage();
}*/

void openObject(vector<std::string> vWords, vector<Object*> allObjectsInGame,
	vector<Object*> inventory)
{
	string objectName = "";
	if (vWords.size() > 2)
	{
		for (int i = 1; i < vWords.size(); i++)
		{
			if (i == (vWords.size() - 1))
				objectName += vWords[i];
			else
				objectName += vWords[i] + " ";
		}
	}
	else objectName = vWords[1];

	int posOfObject = searchObjects(allObjectsInGame, objectName);
	if (posOfObject == -1)
		outputErrorMessage();
	else
	{
		std::string nameOfObjectInsideContainer = allObjectsInGame[posOfObject]->open();
		if (nameOfObjectInsideContainer == "Can't do that...")
			outputErrorMessage();
		else
		{
			cout << "You opened the " << objectName << ".  Inside it was a "
				<< nameOfObjectInsideContainer << "." << endl;
		}
		/*PairObject p1 = PairObject();
		p1 == allObjectsInGame[posOfObject];
		cout << "Object Inside: " << p1.getObjectInside();
		std::string result = allObjectsInGame[posOfObject].getObjectInside();
		if (result == "null")
		outputErrorMessage();
		else
		{
		//cout << "You open the " << objectName << " and find a " << result << endl;
		inventory.push_back(allObjectsInGame[posOfObject]);
		}*/
	}
}

vector<string> changeInputIntoVectorOfStrings(std::string input)
{
	vector<string> returnVector;
	string word;

	getline(cin, input);
	istringstream iss(input);
	while (iss >> word) returnVector.push_back(word);
	return returnVector;
}

int searchObjects(vector<Object> vector, std::string firstObject)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i].getName() == firstObject)
			return i;
	}

	return -1;
}

int searchObjects(vector<Object*> vector, std::string firstObject)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i]->getName() == firstObject)
			return i;
	}

	return -1;
}

int searchRooms(vector<Room> listOfRooms, std::string roomName)
{
	for (unsigned int i = 0; i < listOfRooms.size(); i++)
	{
		if (listOfRooms[i].getName() == roomName)
			return i;
	}

	return -1;
}

void print(vector<Object> vector)
{
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		//cout << "vector[" << i << "] = ";
		vector[i].print();
	}
}

void print(vector<Object*> vector)
{
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		//cout << "vector[" << i << "] = ";
		vector[i]->print();
	}
}

void outputErrorMessage()
{
	cout << "Can't do that..." << endl;
}

/*int searchObjects(vector<Object*> vector, std::string firstObject)
{
for (unsigned int i = 0; i < vector.size(); i++)
{
if (vector[i]->getName() == firstObject)
return i;
}

return -1;
}*/