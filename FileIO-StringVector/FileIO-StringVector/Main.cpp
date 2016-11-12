#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Room.h"
#include "Loot.h"
using namespace std;

//declarations
void initializeGame();
//vector<Loot> loadLoot();
//vector<Room> loadRooms();
//void printLoot(vector<Loot> lootList);
//void printRoom(vector<Room> roomList);
vector<string> readGameData();
void printGameData(vector<string> gameData);
//main
int main()
{
	initializeGame();
	//stuff
	system("pause");
	return 0;
}

void initializeGame()
{
	vector<Loot> lootList;
	vector<Room> roomList;
	vector<string> gameData;
	gameData = readGameData();
	//lootList = loadLoot();
	//roomList = loadRooms();
	//printLoot(lootList);
	//printRoom(roomList);
	//roomList = loadRooms();
	printGameData(gameData);
}

/*vector<Loot> loadLoot()
{
	vector<Loot> outVector;
	ifstream lootData;
	lootData.open("F:/temp/loot2.txt");
	if (!lootData)
	{
		cout << "Error-can't find file or file is empty!" << endl;
	}
	Loot item;
	while (!lootData.eof())
	{
		string id;
		string name;
		string desc;
		getline(lootData, id);
		getline(lootData, name);
		getline(lootData, desc);
		Loot item(id, name, desc);
		outVector.push_back(item);
	}
	lootData.close();
	return outVector;
}
vector<Room> loadRooms()
{
	vector<Room> outVector;
	ifstream roomData;
	roomData.open("F:/temp/room2.txt");
	if (!roomData)
	{
		cout << "Error-can't find file or file is empty!" << endl;
	}
	//string holder = "";
	while (!roomData.eof())
	{
		//string datadump;
		//getline(roomData, datadump);
		//while(!datadump.eof())
		//{
		string id;
		string name;
		string desc;
		getline(roomData, id);
		getline(roomData, name);
		getline(roomData, desc);
		Room chamber(id, name, desc);
		outVector.push_back(chamber);
		//}
		/*getline(roomData, holder);
		chamber.setID(holder);
		getline(roomData, holder);
		chamber.setName(holder);
		getline(roomData, holder);
		chamber.setDesc(holder);
		outVector.push_back(chamber);
	}
	roomData.close();
	return outVector;
}

void printLoot(vector<Loot> lootList)
{
	for (Loot l : lootList)
		l.print(l);
}
void printRoom(vector<Room> roomList)
{
	for (Room r : roomList)
		r.print(r);
}*/

vector<string> readGameData()
{
	vector<string> outVector;
	ifstream gameData;
	gameData.open("f:\\temp\\gamedata.txt");
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

void printGameData(vector<string> gameData)
{
	size_t size = gameData.size();
	for (string s : gameData)
		cout << s << endl;
	cout << "GameData Length in Elements: " << size << endl;
		

}
