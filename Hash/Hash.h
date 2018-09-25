/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: 9/24
Assignment: HashTable
Description: Use a Hash table to store and retrieve names adn phone#s form a file
*/
#include "DblyLL.h"
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;


class Hash
{
protected:
	vector<DblyLinkedList<double>*> hashTable;
	DblyLinkedList<double> *db;
	int tableSize = 50;

	void init(int tableSize);
	int key(double key);
	int key(string key);

public:
	Hash();
	Hash(int hs);

	void hash(double value);
	void hash(string key, double value);

	int search(double value);
	int search(string key);

	double get(string key);

	void printTable();
	int size();
};