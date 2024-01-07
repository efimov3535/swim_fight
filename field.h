#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "ship.h"
class field
{
private:
	char board[10][10];

public:
	field()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				board[i][j] = ' ';
			}
		}
	}

	void display();

	void display_computer();
	

	void placeShip(ship* sp);
	void place_ship_player(ship* sp);

	bool can_place_ship(int row, int col, int size, bool horizontal);

	void place_ship_art(int row, int col, int size, bool horizontal);

	bool isHit(int row, int col);

	void markHit(int row, int col);

	void markMiss(int row, int col);

	bool win()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] == 'O')
				{
					return false;
					break;
				}
				
			}
		}
		return true;
	}
};