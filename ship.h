#pragma once
#include <iostream>
using namespace std;

class ship
{
private:
	int size;
	int hits;
public:
	ship(int s)
	{
		size = s;
		hits = 0;
	}

	int get_size()
	{
		return size;
	}
};