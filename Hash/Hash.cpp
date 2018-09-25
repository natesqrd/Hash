/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: 9/24
Assignment: HashTable
Description: Use a Hash table to store and retrieve names adn phone#s form a file
*/
#include "Hash.h"

using namespace std;
/*
	Constructor
	Author:Nathaniel Tucker
	initiates Hash Table with default table size
	*/
Hash::Hash() { this->init(this->tableSize); }

/*
Working Constructor
Author:Nathaniel Tucker
initiates Hash Table with specified table size
*/
Hash::Hash(int hs) { this->init(hs); }

/*
Function: hash(double)
Author: NT
takes double, calls key(double) then adds to DLL
*/
void Hash::hash(double value)
{
	this->db = this->hashTable[this->key(value)];
	this->db->addEnd(value);
}

/*
Function: hash(string, double)
Author: NT
takes string in and calls key(string), places double in location of key(string)
*/
void Hash::hash(string key, double value)
{
	this->db = this->hashTable[this->key(key)];
	this->db->addEnd(value);
}

/*
Function: search(double)
Author: NT
returns the number of times value shows up in the DLL
Since there is no linear probing, it is expected that value will always
mod to the same location.
*/
int Hash::search(double value)
{
	this->db = this->hashTable[this->key(value)];
	return this->db->getDataCount(value);
}

/*
Function: search(string)
Author: NT
returns the size of the DLL at location of key(string)
Since string will not be stored into the DLL and other strings can
mod to the same location, there is no easy way to pull the data that was inserted
at key(string) location. So, the number of items at that location is returned
*/
int Hash::search(string key)
{
	this->db = this->hashTable[this->key(key)];
	return this->db->size();
}

/*
Function: get
Author: NT
returns first item in DLL
*/
double Hash::get(string key)
{
	this->db = this->hashTable[this->key(key)];
	return this->db->getHeadData();
}

/*
Function: printTable
Author: NT
Prints out all data in hash with locations they are modded to seen
by the iterator i.
*/
void Hash::printTable()
{
	for (int i = 0; i < this->size(); i++)
	{
		this->db = this->hashTable[i];
		cout << i << ": "; db->printList();
	}
}

/*
Function: size()
Author: NT
returns tableSize
*/
int Hash::size() { return this->tableSize; }
/*
	Function: init
	Author: Nathaniel Tucker
	initiates hash table with DLL for collision
	*/
void Hash::init(int tableSize)
{
	this->tableSize = tableSize;
	for (int i = 0; i < this->tableSize; i++)
		this->hashTable.push_back(new DblyLinkedList<double>);
}

/*
Function: key(double)
Author: Nathaniel Tucker
returns the double modded by the table size for iterating to position in Hash
*/
int Hash::key(double key) { return static_cast<int>(key) % this->size(); }

/*
Funciton: key(string)
Author: Nathaniel Tucker, from Lecture
takes each char in the string and adds to leftshift of hashVal
returns the mod of the hashVal through key(double)
*/
int Hash::key(string key)
{
	int hashVal = 5381;
	for (char c : key)
		hashVal = abs((hashVal << 5) + c);
	return this->key(hashVal);
}