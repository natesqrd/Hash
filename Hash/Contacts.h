#pragma once
#include "DblyLL.h"
#include "Hash.h"
#include <iostream>
#include <fstream>

using std::string;
using std::vector;

class Contacts : public Hash
{
	vector<string> Keys;
public:
	Contacts()
	{
		this->init(tableSize);
	}
	Contacts(int ts)
	{
		this->init(ts);
	}
	void getFile()
	{
		ifstream infile("HashData.txt");
		string str, str1;
		if (!infile)
			cout << "Error reading file" << endl;
		while (!infile.eof())
		{
			getline(infile, str, ';');
			Keys.push_back(FormatString(str));

			getline(infile, str1, ';');
			this->hash(FormatString(str), stod(Format(str1)));
		}
	}
	void printPhoneNum(string key)
	{
		this->db = hashTable[this->key(key)];
		if (this->search(key) == 1)
			cout << key << '(' << this->key(key) << ") " << reformat(this->get(key)) << endl;
		else if (this->search(key) > 1)
		{
			int n = collision(key);
			cout << key << '(' << this->key(key) << '-' << n << ") " << reformat(db->find(n)) << endl;
		}
		else if (this->search(key) < 1)
			cout << "Contact not found" << endl;
	}
	void printAll()
	{
		for (int i = 0; i < Keys.size(); i++)
			printPhoneNum(Keys.at(i));
	}
	int collision(string key)
	{
		vector<string> subKeys;
		for (unsigned int i = 0; i < Keys.size(); i++)
		{
			if (this->key(key) == this->key(Keys.at(i)))
				subKeys.push_back(Keys.at(i));
		}
		int i = 0;
		while (key != subKeys.at(i))
			i++;

		return i;
	}
	string reformat(double doub)
	{
		std::stringstream ss;
		string str;
		ss << std::setprecision(10) << doub;
		ss >> str;
		string tmp;
		for (int i = 0; i < 3; i++)
			tmp += str[i];
		tmp = "(" + tmp + ") ";
		for (int i = 3; i < 6; i++)
			tmp += str[i];
		tmp += "-";
		for (unsigned int i = 6; i < str.length(); i++)
			tmp += str[i];
		return tmp;
	}
	string FormatStrNum(string str)
	{
		//because algorithm below doesnt remove first char
		for (char c : str)
			if (!isdigit(c))
				str.erase(std::remove(str.begin(), str.end(), c), str.end());
		return str;
	}
	string Format(string str)
	{
		return FormatStrNum(FormatStrNum(str));
	}
	string FormatString(string str)
	{
		for (char c : str)
			if (c == '\r') //Method I am using to get data from file adds \r to beginning of string
				str.erase(std::remove(str.begin(), str.end(), c), str.end());
		return str;
	}
};