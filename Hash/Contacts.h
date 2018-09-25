/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: 9/24
Assignment: HashTable
Description: Use a Hash table to store and retrieve names adn phone#s form a file
*/
#pragma once
#include "DblyLL.h"
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;

class Contacts : public Hash
{
	vector<string> Keys; //stores names for exact phone# search
	int contactSize = 53;

	int collision(string key);
	string reformat(double doub);
	string FormatStrNum(string str);
	string twiceFormat(string str);
	string FormatString(string str);
	void getFile();

public:
	Contacts();
	Contacts(int ts);
	
	void printPhoneNum(string key);
	void printAll();
	void addName(string key, double value);
};