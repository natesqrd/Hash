#pragma once
#include "DblyLL.h"
#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Hash
{
private:
	vector<DblyLinkedList<string>*> hashArray;
	DblyLinkedList<string> *dbly;
	int hashSize = 53;
	int key(double value)
	{
		return static_cast<int>(value) % hashSize;
	}

	void initHash(int ts)
	{
		hashSize = ts;
		for (int i = 0; i < hashSize; i++)
		{
			dbly = new DblyLinkedList<string>;
			hashArray.push_back(dbly);
		}
	}
public:
	int bernHash(string str)
	{
		int hash = 5381;
		for (char c : str)
			hash = (hash << 5) + c;
		return hash % hashSize;
	}
	Hash()
	{
		initHash(hashSize);
	}
	Hash(int ts)
	{
		initHash(ts);
	}
	/*void hashVal(double value)
	{
		dbly = hashArray[key(value)];
		//dbly->addFront(value);
	}*/
	void hash(string name, string phoneNum)
	{
		dbly = hashArray[bernHash(name)];
		dbly->addEnd(name, phoneNum);
	}
	int search(string value)
	{
		dbly = hashArray[bernHash(value)];
		return dbly->getDataCount(value);
	}
	string find(string name)
	{
		dbly = hashArray[bernHash(name)];
		return dbly->find(name);
	}
	int chainSize(double value)
	{
		dbly = hashArray[key(value)];
		return dbly->size();
	}
	void printTable()
	{
		for (int i = 0; i < hashSize; i++)
		{
			dbly = hashArray[i];
			cout << i << ": ";
			dbly->printList();
		}
	}
	int size()
	{
		return hashSize;
	}
	/*void hashString(string key, double value)
	{
		dbly = hashArray[bernHash(key)];
		dbly->addFront(value, key);
	}*/
};