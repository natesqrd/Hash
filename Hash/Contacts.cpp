/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: 9/24
Assignment: HashTable
Description: Use a Hash table to store and retrieve names adn phone#s form a file
*/
#include "Contacts.h"

using namespace std;

/*
	Working Constructor
	NT
	Initializes Hash with default table size and loads file into Hash
	*/
Contacts::Contacts()
{
	this->init(this->contactSize);
	this->getFile();
}

/*
Working Constructor
NT
Initializes Hash with given table size and loads file into Hash
*/
Contacts::Contacts(int ts)
{
	this->init(ts);
	this->getFile();
}
/*
added last minute
*/
void Contacts::addName(string key, double value)
{
	Keys.push_back(key);
	this->hash(key, value);
}
/*
Function: printPhoneNum
Author: NT
If name is in hash then the info is printed out
else Contact not found is printed
*/
void Contacts::printPhoneNum(string key)
{
	this->db = hashTable[this->key(key)];
	if (this->search(key) == 1)
		cout << key << '(' << this->key(key) << ") " << reformat(this->get(key)) << endl;
	else if (this->search(key) > 1)
	{
		int n = collision(key);
		cout << key << '(' << this->key(key) << '-' << n << ") " << reformat(db->at(n)) << endl;
	}
	else if (this->search(key) < 1)
		cout << "Contact not found" << endl;
}

/*
Funciton: printAll()
Author: NT
prints all names, positions and phone#s
*/
void Contacts::printAll()
{
	for (unsigned int i = 0; i < Keys.size(); i++)
		printPhoneNum(Keys.at(i));
}
/*
Function: collision
Author: NT
The idea here is to create a sub vector or names.
In the vector Keys the names of the people is stored in the order that they were added.
so if say Wyan and Wayn were stored in the same DLL then the order that they were added
is the same order that they appear in the vector.

ie.
[name, name, Wyan, name, name, name, Wayn] <-- Wyan is first in Keys

HashTable
{
	0. name
	1. name
	2. Wyan, Wayn <---- Wyan is first in DLL and in Keys
	3. name, name
	4. name
}

If the number of phone# in a DLL is greater than 1, collision is called
[name, name, Wyan, name, name, name, Wayn] <-- Keys
				2						6			2 < 6
If Wyan and Wayn are modded to the same				|
location then they are moved into the				|
subKey vector										|
[Wyan, Wayn] <-- subKeys							v
	0	1		         0 < 1	--------->	Wyan's pos < Wayn's pos
Wyan and Wayn's position is the same in the DLL;
therefore their phone#'s will be in the same position

Going further with this method, If I create an addPhone# feature this will always hold true
The position in which they are added is the same as their position in the DLL
*/
int Contacts::collision(string key)
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
/*
Function: reformat
Author: NT
Since the phone numbers were stored as double, they need to be returned
in their original string state. This function adds in the ( ) - into the string
in their appropriate positions for ease of reading
*/
string Contacts::reformat(double doub)
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
/*
Funciton: FormatStrNum
Author: NT
This funciton removes the ( ) - so that the phone numbers can be added
into the Hash as a double
*/
string Contacts::FormatStrNum(string str)
{
	for (char c : str)
		if (!isdigit(c))
			str.erase(std::remove(str.begin(), str.end(), c), str.end());
	return str;
}
/*
	Function: twiceFormat
	Author: NT
	Not all non numbers are removed the first time. This tries to ensure that only
	numbers are left in the string to be converted into doubles
	*/
string Contacts::twiceFormat(string str)
{
	return FormatStrNum(FormatStrNum(str));
}

/*
Function: FormatString
Author: NT
Given the method I am using to pull the data from the file
a \r ends up being added to the front of the string in each line
this removes the \r
*/
string Contacts::FormatString(string str)
{
	for (char c : str)
		if (c == '\r') //Method I am using to get data from file adds \r to beginning of string
			str.erase(std::remove(str.begin(), str.end(), c), str.end());
	return str;
}

/*
Function: getFile
Author: NT
This is an odd way to pull data but given that the data comes in
pairs of name and phone#, this method gets those pairs and seperates them
into their appropriate functions to be modified then added into the Hash
*/
void Contacts::getFile()
{
	ifstream infile("HashData.txt");//preloaded file
	string str, str1;
	if (!infile)
		cout << "Error reading file" << endl;
	while (getline(infile, str, ';'))
	{
		getline(infile, str1, ';');
		this->addName(FormatString(str), stod(twiceFormat(str1)));
	}
	infile.close();
}