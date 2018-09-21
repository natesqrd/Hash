#include "Hash.h"
#include <random>
#include <ctime>

using namespace std;


int main()
{
	Hash h;
	srand(static_cast<int>(time(0)));
	for (int i = 0; i < 60; i++)
	{
		double n = rand() % 2000;
		h.hashf(n);
	}
	h.printTable();
    return 0;
}

