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
vector<Loot> loadLoot(vector<string> gameData);
vector<Room> loadRooms(vector<string> gameData);
void printLoot(vector<Loot> lootList);
void printRoom(vector<Room> roomList);
vector<string> readGameData();
void printGameData(vector<string> gameData);
//main
int main()//step 1 main
{
	initializeGame();
	//stuff
	system("pause");
	return 0;
}

void initializeGame()//step 2, set everything up...this is where the party starts
{
	vector<Loot> lootList;
	vector<Room> roomList;
	vector<string> gameData;
	gameData = readGameData();//3
	lootList = loadLoot(gameData);//4
	roomList = loadRooms(gameData);//5
	printLoot(lootList);//6
	printRoom(roomList);//7
	printGameData(gameData);//8
}

vector<Loot> loadLoot(vector<string> gameData)//pass in string vector, pick out object identifier, get next 3 vars, instantiate, push to vector, return vector
{
	vector<Loot> outVector;
	string id;
	string name;
	string desc;
	size_t size = gameData.size();
	for (int i = 0; i < size; i++)
	{
		if (gameData[i] == "L")
		{
			id = gameData[i + 1];
			name = gameData[i + 2];
			desc = gameData[i + 3];
			Loot loot(id, name, desc);
			outVector.push_back(loot);
		}
	}
	return outVector;
}
vector<Room> loadRooms(vector<string> gameData)//pass in string vector, pick out object identifier, get next 3 vars, instantiate, push to vector, return vector
{
	vector<Room> outVector;
	string id;
	string name;
	string desc;
	size_t size = gameData.size();
	for (int i = 0; i < size; i++)
	{
		if (gameData[i] == "R")
		{
			id = gameData[i + 1];
			name = gameData[i + 2];
			desc = gameData[i + 3];
			Room room(id, name, desc);
			outVector.push_back(room);
		}
	}
	return outVector;
}

void printLoot(vector<Loot> lootList)//pass in Loot vector, ranged for loop to call object print method
{
	for (Loot l : lootList)
		l.print(l);
}
void printRoom(vector<Room> roomList)//pass in Room vector, ranged for loop to call object print method
{
	for (Room r : roomList)
		r.print(r);
}

vector<string> readGameData()//step 3: read in everything from text as strings, push into string vector and return
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

void printGameData(vector<string> gameData)//test method - print all elements of string vector and get count of elements
{
	size_t size = gameData.size();
	for (string s : gameData)
		cout << s << endl;
	cout << "GameData Length in Elements: " << size << endl;
		

}
