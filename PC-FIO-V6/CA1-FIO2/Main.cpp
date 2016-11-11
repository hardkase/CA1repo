#include "Loot.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//method declation:
void initializeGame();
vector<Room> loadRooms();
//vector<Room> loadRooms(const vector<Loot> &masterLootList);
vector<Loot> loadLoot();
//vector<Loot> getRoomLoot(vector<Loot> masterLootList, string roomID);


int main()
{
	vector<Room> roomList;
	vector<Loot> masterLootList;
	Player p1;
	initializeGame();
	//global vars:

	//requisite bits:
	system("pause");
	return 0;
}
void initializeGame()
{
	vector<Loot> masterLootList;
	vector<Room> roomVector;
	vector<Loot> inventory;
	masterLootList = loadLoot();
	//roomVector = loadRooms(masterLootList);
	roomVector = loadRooms();
	/*for (Loot l : masterLootList)
	{
		l.print(l);
	}
	for (Room r : roomVector)
	{
		r.print(r);
	}*/
	Room test = roomVector[2];
	Loot testLoot = masterLootList[4];
	//print room
	string id = test.getRoomID();
	string rName = test.getRoomName();
	string rWest = test.getWest();
	cout << "ID: " << id << "\nName: " << rName << "\n West Exit: " << rWest << endl;
}
vector<Room> loadRooms(/*const vector<Loot> &masterLootList*/)
{
	//Room(std::string roomID, std::string roomName, std::string west, std::string north, 
	//std::string east, std::string south, std::vector<Loot> lootList, std::string roomDesc)
	//(hardcode - deprecated)Room r1("R001", "entry", "R002", "R003", "R004", "0", "You have entered the maze");
	//next 4 lines are to assist in user input to change drive location = scalability/usability
	string drive = "F:/";//which drive is the game data in? letter, colon, backslash like: "c:/"
	string dir = "temp/";//which folder/folders is the game file in, enter like: "users/joblogs/documents/gamedata/temp/", hit enter (with no spaces) if the file is in the root of the drive
	string fname = "room.txt";//enter the file name for ROOMS like "room.txt"
	string path = drive + dir + fname;
	cout << path << endl;//test path is correct
	vector<Room> outVector;
	ifstream roomData;
	roomData.open(path);
	if(roomData.is_open())
	{ }
		while (!roomData.eof())
		{
			Room chamber;
			//string holder="test";
			string holder = "";
			//string west, north, east, south; this was for array which is going to be really tricky to implement??
			getline(roomData, holder);
			chamber.setRoomID(holder);
			getline(roomData, holder);
			chamber.setRoomName(holder);
			getline(roomData, holder);
			chamber.setWest(holder);
			getline(roomData, holder);
			chamber.setNorth(holder);
			getline(roomData, holder);
			chamber.setEast(holder);
			getline(roomData, holder);
			chamber.setSouth(holder);
			//chamber.setLootList(getRoomLoot(masterLootList, roomID));
			getline(roomData, holder);
			chamber.setRoomDesc(holder);
			outVector.push_back(chamber);

		}
	roomData.close();
	return outVector;

}
vector<Loot> loadLoot()
{
	string drive = "F:/";//which drive is the game data in? letter, colon, backslash like: "c:/"
	string dir = "temp/";//which folder/folders is the game file in, enter like: "users/joblogs/documents/gamedata/temp/", hit enter (with no spaces) if the file is in the root of the drive
	string fname = "room.txt";//enter the file name for LOOT like "loot.txt"
	string path = drive + dir + fname;//concatenated path name
	vector<Loot> outVector;
	ifstream lootData;
	lootData.open("f:/temp/loot.txt");

	while (!lootData.eof())
	{
		//string lootID, string name, string roomLoc, string desc
		Loot lootItem;
		string holder="test";
		getline(lootData, holder);
		lootItem.setLootID(holder);
		getline(lootData, holder);
		lootItem.setName(holder);
		getline(lootData, holder);
		lootItem.setRoomLoc(holder);
		getline(lootData, holder);
		lootItem.setDesc(holder);
		outVector.push_back(lootItem);
	}
	lootData.close();

	return outVector;
}
/*vector<Loot> getRoomLoot(vector<Loot> masterLootList, string roomID)
{
	vector<Loot> roomLoot;
	//search master loot list and copy items to room loot, pass into room
	/*unsigned int searchObjects(vector<Object> vector, string roomID)
	{
	for (int i = 0; i < masterLootList.size(); i++)
	{
		Loot holder;
		if (masterLootList[i].getRoomLoc() == roomID)
			holder = masterLootList[i];
			roomLoot.push_back(holder);
	}
	return roomLoot;
}*/
/*
...semi-optional: create and intialize player
*  read room data from file &initialize rooms, & load into vector
...OPTIONAL...read objects and load
* start game for user, load current room (room 1) and describe including exits, get and handle user input
....OPTIONAL...place objects in rooms
*change current room state to users room/ if user selects unavailable exit - handle
...EXTRA OPTIONAL...enemies and combat
*/