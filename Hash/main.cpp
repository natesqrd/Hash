#include "Contacts.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{
	Contacts h;
	char answer;
	string name;
	h.getFile();
	cout << "Would you like to look up a number or view all numbers?" << endl;
	cout << "(y) for look up, (n) for all numbers" << endl;
	cin >> answer;
	if (answer == 'y')
	{
		while (tolower(answer) != 'n')
		{
			cout << "Enter in a name" << endl;
			cin >> name;
			h.printPhoneNum(name);
			cout << "Would you like to look up a number?(y/n)" << endl;
			cin >> answer;
		}
	}
	else if (answer == 'n')
		h.printAll();

	cout << "Goodbye" << endl;

	
    return 0;
}

