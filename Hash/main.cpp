#include "Hash.h"
#include <random>
#include <ctime>

using namespace std;


int main()
{
	Hash h;
	//srand(static_cast<int>(time(0)));
	for (int i = 0; i < 60; i++)
	{
		double n = rand() % 20;
		h.hashf(n);
	}
	h.printTable();

	for (int i = 0; i < h.size(); i++)
	{
		cout << i << ": " << h.chainSize(i) << endl;
	}
	cout << "15 shows up " << h.search(15) << " times"<< endl;
    return 0;
}

