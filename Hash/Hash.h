#pragma once
#include "DblyLL.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Hash
{
private:
	vector<DblyLinkedList<double>*> hashArray;
	DblyLinkedList<double> *dbly;
	int hashSize = 12;
	int key(int value)
	{
		return value % hashSize;
	}
	void initHash(int ts)
	{
		hashSize = ts;
		for (int i = 0; i < hashSize; i++)
		{
			dbly = new DblyLinkedList<double>;
			hashArray.push_back(dbly);
		}
	}
public:
	Hash()
	{
		initHash(hashSize);
	}
	Hash(int ts)
	{
		initHash(ts);
	}
	void hashf(double value)
	{
		dbly = hashArray[key(value)];
		dbly->addEnd(value);
	}
	int search(double value)
	{
		dbly = hashArray[key(value)];
		for (int i = 0; dbly->size(); i++)
		{

		}
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

};