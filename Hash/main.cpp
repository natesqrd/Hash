#include "Hash.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
	Hash h;
	 h.hash("Wayn", "(555) 3450-986");
	 h.hash("Wyan", "(555) 866-1234");
	 h.hash("Behrouz", "(555) 864-8888");
	 h.hash("Dick", "(555) 864-8899");
	 h.hash("Julie", "(555) 916-1212");
	 h.hash("Phong", "(555) 245-8912");
	 h.hash("Delia", "(555) 7356-3869");
	 h.hash("Joe", "(555) 129-4739");
	 h.hash("Chris", "(555) 946-2859");
	 h.hash("Chung", "(555) 745-2284");
	 h.hash("Melissa", "(555) 645-3487");
	 h.hash("Jaya", "(555) 735-7246");
	 h.printTable();
	 cout << "\n\n";

	 h.printInfo("Jaya");
	
	

	
    return 0;
}

