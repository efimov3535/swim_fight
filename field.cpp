#include "field.h"

void field::display()
{
	cout << "  A B C D E F G H I J" << "\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void field::display_computer()
{
	cout << "  A B C D E F G H I J" << "\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			if(board[i][j] == '-' || board[i][j] == 'X')
			{
				cout << board[i][j] << " ";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}



void field::placeShip(ship* sp)
{
	int size = sp->get_size();
	while (true)
	{
		int row = rand() % 10;
		int col = rand() % 10;

		bool horizontal = rand() % 2 == 0;

		if (can_place_ship(row, col, size, horizontal))
		{
			place_ship_art(row, col, size, horizontal);
			break;
		}
	}
}

void field::place_ship_player(ship* sp)
{
	int size = sp->get_size();
	while (true)
	{
		cout << "Введите координаты для корабля размером " << size << " (Например, A3): ";
		string input;
		cin >> input;
		char column = input[0];
		int row = input[1] - '0';
		row--;
		int col = column - 'A';
		cout << "Введите ориентацию корабля (0 - горизонтально, 1 - вертикально): ";
		bool horizontal;
		cin >> horizontal;

		if (can_place_ship(row, col, size, horizontal))
		{
			place_ship_art(row, col, size, horizontal);
			break;
		}
		else
		{
			cout << "Невозможно установить корабль в заданных координатах. Попробуйте снова.\n";
		}
	}
}

bool field::can_place_ship(int row, int col, int size, bool horizontal) {
	// Проверка, чтобы корабль не выходил за пределы поля
	if (horizontal && col + size > 10) {
		return false;
	}
	else if (!horizontal && row + size > 10) {
		return false;
	}

	// Проверка наличия кораблей вокруг и по всем диагоналям от заданных координат
	for (int i = std::max(0, row - 1); i < std::min(10, row + size + 1); ++i) {
		for (int j = std::max(0, col - 1); j < std::min(10, (horizontal ? col + size : col + 1)); ++j) {
			if (board[i][j] == 'O') {
				return false; // Обнаружен корабль вблизи
			}
		}
	}

	// Дополнительная проверка для первого корабля
	if (size == 1) {
		return true; // Разрешаем размещение первого корабля на одну клетку
	}

	// Проверка по вертикали и горизонтали
	for (int i = row; i < row + size; ++i) {
		for (int j = col; j < col + size; ++j) {
			if (board[i][j] == 'O') {
				return false; // Обнаружен корабль внутри предполагаемой области размещения
			}
		}
	}

	return true;
}






void field::place_ship_art(int row, int col, int size, bool horizontal)
{
	if (horizontal)
	{
		for (int j = col; j < col + size; j++)
		{
			board[row][j] = 'O';
		}
	}

	else
	{
		for (int i = row; i < row + size; i++)
		{
			board[i][col] = 'O';
		}
	}
}

bool field::isHit(int row, int col)
{
	return board[row][col] == 'O';
}

void field::markHit(int row, int col)
{
	board[row][col] = 'X';
}

void field::markMiss(int row, int col)
{
	board[row][col] = '-';
}
