#include "Player.h"
#include <string>
#include <vector>
#include <stack>
#include "Room.h"
#include "Loot.h"
using namespace std;

Player::Player()
{
}

Player::Player(std::string name):name(name)
{
	Room r1;
	//setCurrentRoom(r1);
	vector<Loot> v1;
	setInventory(v1);
	stack<Room> s1;
	setPastRooms(s1);
	bool time2go = false;
}


Player::~Player()
{
}
