#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Room.h"
#include "Loot.h"
#include "Player.h"
using namespace std;
//declarations
//implement all user input using this: http://www.cplusplus.com/forum/articles/6046/
void initialize();
vector<string> getData(string path);
vector<Loot> loadLoot(vector<string> gameData);
vector<Room> loadRooms(vector<string> gameData, vector<Loot> lootList);
vector<Loot> getRoomLoot(vector<Loot> lootList, int id);
Room searchRoomById(vector<Room> roomList, int id);
Loot searchLootByRoomLoc(vector<Loot> lootList, int search);
Loot searchLootById(vector<Loot> lootList, int search);
void readRoom(Room r);
vector<string> getUserInput();
void handleUserInput(vector<string> user, vector<Room> roomList, Player p1, Room currentRoom);
void runGame(Player p1, vector<Room>roomList, Room currentRoom);
void printError();
bool quit(bool gameOn);
int main()
{
	initialize();
	system("pause");
	return 0;
}
void initialize()
{
	//get player input (name)
	Room currentRoom;
	vector<Room> roomList;
	vector<Loot> lootList;
	vector<string> gameData;
	bool fileFound = false;
	Player p1("namelessOne");
	string pName;
	cout << "Welcome to Dungeon'Splorer! Please enter your character's name: " << endl;
	cin >> pName;
	p1.setName(pName);
	string path;
	while (!fileFound)
	{
		cout << "Please enter the drive letter where your game files are stored: " << endl;
		string driveLetter = "c";
		cin >> driveLetter;
		string drive = driveLetter + ":\\";
		cout << "Please enter the file path where the game files are located: " << endl;
		string fPath = "temp";
		cin >> fPath;
		string dir = fPath + "\\";
		cout << "Please enter the filename of the game data text file: " << endl;
		string fName1 = "gamedata";
		cin >> fName1;
		string fName = fName1 + ".txt";
		path = drive + dir + fName;
		cout << path << endl;
		ifstream gameFile(path);
		if (!gameFile)
		{
			cout << "file not found, please try again!" << endl;
		}
		else
		{
			fileFound = true;
			gameFile.close();
		}
	}
	gameData = getData(path);
	lootList = loadLoot(gameData);
	roomList = loadRooms(gameData, lootList);
	/*size_t lootv = lootList.size();
	size_t roomv = roomList.size();
	cout << lootv << "  " << roomv << endl;
	for (Room r : roomList)
	{
		cout << r.getID() << endl;
		cout << r.getName() << endl;
		cout << r.getDescription() << endl;
		cout << r.getWest() << endl;
		cout << r.getNorth() << endl;
		cout << r.getEast() << endl;
		cout << r.getSouth() <<"*******"<< endl;
		vector<Loot> tempLoot = r.getRoomLoot();
		size_t lootSize = tempLoot.size();
		cout << lootSize <<"********"<< endl;
	}
	for (Loot l : lootList)
	{
		cout << l.getID() << endl;
		cout << l.getName() << endl;
		cout << l.getDescription() << endl;
		cout << l.getIsBox() << endl;
		cout << l.getIsComb() << endl;
		cout << l.getIsNew() << endl;
		cout << l.getRoomLoc() <<"********"<< endl;
	}
	*/
	cout << " You decide to go on an adventure. \n You enter the local haunted house" << endl;
	Room c1;
	c1 = searchRoomById(roomList, 1);
	currentRoom =c1;
	runGame(p1,  roomList, currentRoom);
/*	readRoom(c1);
	int count = 0;
		}
		else
		{
			vector<string> user;
			user = getUserInput();
			handleUserInput(user, roomList, p1);
			count++;
		}
	}*/

	//get player input (gamedata location) - have defaults-DONE
	//load strings from text DONE
	//load objects & rooms from strings DONE
	//searches return loot or rooms by x- DONE
	//set roomLoot - DONE
	//set current room
	//start game loop
	//drop start text& first room - read current room
	//get user input
	//handle user input
	//drop end text
	//terminate game loop
}

vector<string> getData(string path)
{
	vector<string> outVector;
	ifstream gameFile;
	gameFile.open(path);
	while (!gameFile.eof())
	{
		string temp;
		getline(gameFile, temp);
		outVector.push_back(temp);
	}
	gameFile.close();
	return outVector;
}


vector<Loot> loadLoot(vector<string> gameData)
{
	vector<Loot> outVector;
	
	/*int id, std::string name, std::string description, bool isBox, bool isComb, bool isNew, int roomLoc*/
	string strId, tempName, tempDesc, strBox, strComb, strNew, strRoom;
	int tId, tRoom;
	bool tBox, tComb, tNew;
	size_t size = gameData.size();
	size_t idSize;
	size_t roomSize;
	for (int i = 0; i < size; i++)
	{
		if (gameData[i] == "*L*")
		{
			strId = gameData[i + 1];
			tempName = gameData[i + 2];
			tempDesc = gameData[i + 3];
			strBox = gameData[i + 4];
			strComb = gameData[i + 5];
			strNew = gameData[i + 6];
			strRoom = gameData[i + 7];
			tId = stoi(strId, &idSize);
			tRoom = stoi(strRoom, &roomSize);
			tBox = stoi(strBox.c_str());
			tComb = stoi(strComb.c_str());
			tNew = stoi(strNew.c_str());
			Loot l1(tId, tempName, tempDesc, tBox, tComb, tNew, tRoom);
			outVector.push_back(l1);
		}
	}
	return outVector;
}

vector<Room> loadRooms(vector<string> gameData, vector<Loot> lootList)
{
	vector<Room> outVector;
	string strId, tName, tDesc, strW, strN, strE, strS;
	int tId, tWest, tNorth, tEast, tSouth;
	size_t size = gameData.size();
	size_t idSize, wSize, nSize, eSize, sSize;
	for (int i = 0; i < size; i++)
	{
		/*int id, std::string name, std::string description, int west,
		int north, int east, int south, std::vector<Loot> roomLoot*/
		if (gameData[i] == "*R*")
		{
			vector<Loot> roomLoot;
			strId = gameData[i + 1];
			tName = gameData[i + 2];
			tDesc = gameData[i + 3];
			strW = gameData[i + 4];
			strN = gameData[i + 5];
			strE = gameData[i + 6];
			strS = gameData[i + 7];
			tId = stoi(strId, &idSize);
			tWest = stoi(strW, &wSize);
			tNorth = stoi(strN, &nSize);
			tEast = stoi(strE, &eSize);
			tSouth = stoi(strS, &sSize);
			roomLoot = getRoomLoot(lootList, tId);
			Room r1(tId, tName, tDesc, tWest, tNorth, tEast, tSouth, roomLoot);
			outVector.push_back(r1);
		}
	}
	return outVector;
}
Loot searchLootById(vector<Loot> lootList, int search)
{
	Loot lootItem;
	size_t listSize = lootList.size();
	for (int i = 0; i < listSize; i++)
	{
		if (lootList[i].getID() == search)
			lootItem = lootList[i];
	}
	return lootItem;
}
void readRoom(Room r)
{
	vector<Loot> tempLoot = r.getRoomLoot();
	string room = r.getDescription();
	cout << room << endl;
	cout << "You see the following objects in the room: " << endl;
	for (Loot l : tempLoot)
	{
		string tName = l.getName();
		cout << tName << endl;
	}
	cout << "There are exits:" << endl;
	int west = r.getWest();
	if (west > 0)
		cout << "West" << endl;
	int north = r.getNorth();
	if (north > 0)
		cout << "North" << endl;
	int east = r.getEast();
	if (east > 0)
		cout << "East" << endl;
	int south = r.getSouth();
	if (south > 0)
		cout << "South" << endl;
}
vector<string> getUserInput()
{
	vector<string> outVector;
	string temp, input/*, temp1, temp2, temp3*/;
	string delimiter = " ";
	cout << "What do you do?" << endl;
	//while (cin != "\n") Doesn't work
	//cin >> temp >> temp1 >> temp2 >> temp3;
	//per http://stackoverflow.com/questions/15446951/how-to-cin-whole-sentence-with-whitespaces
	getline(cin, temp);
	//input = temp + delimiter + temp1 + delimiter + temp2 + delimiter + temp3 + delimiter;THIS WORKS, but has too many inputs...
	input = temp+delimiter;
	cout << input << endl;
	size_t oldPos = -1;
	size_t pos = input.find(delimiter, oldPos + 1);
	while (pos != string::npos)
	{
		string strElement;
		strElement = input.substr(oldPos + 1, pos - oldPos - 1);
		outVector.push_back(strElement);
		oldPos = pos;
		pos = input.find(delimiter, oldPos + 1);
		for (string s : outVector)
		{
			cout << s << endl;
		}
	}
	return outVector;
}
Loot searchLootByRoomLoc(vector<Loot> lootList, int search)
{
	Loot lootItem;
	size_t listSize = lootList.size();
	for (int i = 0; i < listSize; i++)
	{
		if (lootList[i].getRoomLoc() == search)
			lootItem = lootList[i];
	}
	return lootItem;
}
Room searchRoomById(vector<Room> roomList, int id)
{
	Room room;
	size_t listSize = roomList.size();
	for (int i = 0; i < listSize; i++)
	{
		if (roomList[i].getID() == id)
			room = roomList[i];
	}
	return room;
}
vector<Loot> getRoomLoot(vector<Loot> lootList, int id)
{
		vector<Loot> outVector;
		Loot lootItem;
		size_t listSize = lootList.size();
		for (int i = 0; i < listSize; i++)
		{
			if (lootList[i].getRoomLoc() == id)
			{
				lootItem = lootList[i];
				outVector.push_back(lootItem);
			}
		}
		return outVector;
}
void handleUserInput(vector<string> user, vector<Room> roomList, Player p1, Room currentRoom)
{
	if (user[0] == "go")//GO
	{
		Room c1 = currentRoom;
		if (user[1] != "")
		{
			string tmp = user[1];
			if (tmp == "west"||tmp == "West"||tmp=="WEST")
			{
				//Room c1 = currentRoom;
				int id = c1.getWest();
				if (id == 0)
				{
					printError();
					getUserInput();
				}
				else
				{
					Room next = searchRoomById(roomList, id);
					cout << "You head west..." << endl;
					currentRoom = next;
					runGame(p1, roomList, currentRoom);
				}
			}
			else if (tmp == "north")
			{
				//Room c1 = currentRoom;
				int id = c1.getNorth();
				if (id == 0)
				{
					printError();
					getUserInput();
				}
				else
				{
					Room next = searchRoomById(roomList, id);
					cout << "You head north..." << endl;
					currentRoom = next;
					runGame(p1, roomList, currentRoom);
				}
			}
			else if (tmp == "east")
			{
				//Room c1 = currentRoom;
				int id = c1.getEast();
				if (id == 0)
				{
					printError();
					getUserInput();
				}
				else
				{
					Room next = searchRoomById(roomList, id);
					cout << "You head east..." << endl;
					currentRoom = next;
					runGame(p1, roomList, currentRoom);
				}
			}
			else if (tmp == "south")
			{
				//Room c1 = currentRoom;
				int id = c1.getSouth();
				if (id == 0)
				{
					printError();
					getUserInput();
				}
				else
				{
					Room next = searchRoomById(roomList, id);
					cout << "You head south..." << endl;
					currentRoom = next;
					runGame(p1, roomList, currentRoom);
				}
			}
		}
		else
		{
			printError();
		}
	}
	else if (user[0] == "use" && user[1] != "")//USE
	{

	}
	else if (user[0] == "get" || user[0] == "take")//GET/TAKE
	{
		if (user[1] != "")
		{

		}
		else
		{

		}
	}
	else if (user[0] == "drop" && user[1] != "")//DROP
	{
	}
	else if (user[0] == "examine" && user[1] != "")//EXAMINE
	{

	}
	else if (user[0] == "open"&& user[1] != "")//OPEN
	{

	}
	else if (user[0] == "combine" && user[1] != "")//COMBINE
	{

	}
	/*else if (user[0] == "exit" || user[0] == "quit")
	{
		quit(gameOn);
	}*/
	else
	{
		cout << "Do they speak English in What? I don't get it..." << endl;
	}
}
void runGame(Player p1, vector<Room> roomList, Room currentRoom)
{
	//gameloop REMMOVED
	//bool gameOn = true;
	
	readRoom(currentRoom);//tried moving to handle input
	vector<string> user;
	user=getUserInput();
	/*for (string s : user)//testprint
		{
			cout <<"TEST - -"<< s << endl;
		}*/
	handleUserInput(user, roomList, p1, currentRoom);//in progress
}
void printError()
{
	cout << "Computer says No. Try that again..." << endl;
}
bool quit(bool gameOn)
{
	cout << "Thanks for playing!" << endl;
	gameOn = false;
	return gameOn;
}

//tests determinlootIteme that code so far is working. Need some search & return methods and user input
