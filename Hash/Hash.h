#pragma once
#include "DblyLL.h"

template<class T>
class Hash : public DblyLinkedList<T>
{
private:
	int hashArray[hashSize];
	static int hashSize = 50;
	void initHash(int ts)
	{
		hashSize = ts;
		for (int i = 0; i < hashSize; i++)
		{
			hashArray[i] = new Node<T>;
		}
	}
	int hash(T);
public:
	Hash()
	{
		initHash(hashSize);
	}
	Hash(int ts)
	{
		initHash(ts);
	}

};