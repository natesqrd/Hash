#include "DblyLL.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
using std::string;
using std::vector;
using std::ifstream;

class Hash
{
protected:
	vector<DblyLinkedList<double>*> hashTable;
	
	DblyLinkedList<double> *db;
	int tableSize = 53;

	void init(int tableSize)
	{
		this->tableSize = tableSize;
		for (int i = 0; i < this->tableSize; i++)
			this->hashTable.push_back(new DblyLinkedList<double>);
	}
	int key(double key) { return static_cast<int>(key) % this->size(); }
	int key(string key)
	{
		int hashVal = 5381;
		for (char c : key)
			hashVal = abs((hashVal << 5) + c);
		return this->key(hashVal);
	}

public:
	//Hash functions
	Hash() { this->init(this->tableSize); }
	Hash(int hs) { this->init(hs); }
	void hash(double value)
	{ 
		this->db = this->hashTable[this->key(value)];
		this->db->addEnd(value);
	}
	void hash(string key, double value)
	{
		this->db = this->hashTable[this->key(key)];
		this->db->addEnd(value);
	}
	int search(double value)
	{
		this->db = this->hashTable[this->key(value)];
		return this->db->getDataCount(value);
	}
	int search(string key)
	{
		this->db = this->hashTable[this->key(key)];
		return this->db->size();
	}
	double get(string key)
	{
		this->db = this->hashTable[this->key(key)];
		return this->db->getHeadData();
	}
	void printTable()
	{
		for (int i = 0; i < this->size(); i++)
		{
			this->db = this->hashTable[i];
			cout << i << ": "; db->printList();
		}
	}
	int size() { return this->tableSize; }





	//File functions

	

};