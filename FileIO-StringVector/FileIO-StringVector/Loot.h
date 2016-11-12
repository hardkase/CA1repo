#pragma once
#include <string>
class Loot
{
public:
	Loot();
	Loot(std::string id, std::string name, std::string desc);
	~Loot();
	std::string getID() const { return id; }
	void setID(std::string id) { id = id; }
	std::string getName() const { return name; }
	void setName(std::string name) { name = name; }
	std::string getDesc() const { return desc; }
	void setDesc(std::string desc) { desc = desc; }
	void print(Loot l);
private:
	std::string id, name, desc;
};

