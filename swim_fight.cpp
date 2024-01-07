#include "field.h"
#include "ship.h"

void get_shot_coordinate(int& row, int& col)
{
	cout << "Введите координаты для выстрела, например A1: ";
	char col_char;
	cin >> col_char >> row;
	col = col_char - 'A';
	row--;
}

char perevod_bukva(int col)
{
	if (col == 0)
		return 'A';
	else if (col == 1)
		return 'B';
	else if (col == 2)
		return 'C';
	else if (col == 3)
		return 'D';
	else if (col == 4)
		return 'E';
	else if (col == 5)
		return 'F';
	else if (col == 6)
		return 'G';
	else if (col == 7)
		return 'H';
	else if (col == 8)
		return 'I';
	else
		return 'J';
}



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	field player_field;
	field computer_field;
	cout << "1. Расстановка кораблей рандомно" << endl << "2. Расстановка кораблей вручную" << endl;
	int choice;
	cin >> choice;


	if (choice == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			player_field.display();
			ship* sp = new ship(1);
			player_field.place_ship_player(sp);
			system("pause");
			system("cls");
		}

		for (int i = 0; i < 3; i++)
		{
			player_field.display();
			ship* sp_1 = new ship(2);
			player_field.place_ship_player(sp_1);
			system("pause");
			system("cls");
		}

		for (int i = 0; i < 2; i++)
		{
			player_field.display();
			ship* sp = new ship(3);
			player_field.place_ship_player(sp);
			player_field.display();
			system("pause");
			system("cls");
		}
		player_field.display();
		ship* sp = new ship(4);
		player_field.place_ship_player(sp);
		player_field.display();
		system("pause");
		system("cls");
	}

	else
	{
		for (int i = 0; i <= 4; i++)
		{
			ship* sp = new ship(1);
			player_field.placeShip(sp);
		}

		for (int i = 0; i < 3; i++)
		{
			ship* sp_1 = new ship(2);
			player_field.placeShip(sp_1);
		}

		for (int i = 0; i < 2; i++)
		{
			ship* sp = new ship(3);
			player_field.placeShip(sp);
		}
		ship* sp = new ship(4);
		player_field.placeShip(sp);
	}


	for (int i = 0; i < 4; i++)
	{
		ship* sp = new ship(1);
		computer_field.placeShip(sp);
	}

	for (int i = 0; i < 3; i++)
	{
		ship* sp = new ship(2);
		computer_field.placeShip(sp);
	}

	for (int i = 0; i < 2; i++)
	{
		ship* sp = new ship(3);
		computer_field.placeShip(sp);
	}

	ship* sp_2 = new ship(4);
	computer_field.placeShip(sp_2);


	int player_shots = 0;
	int computer_shots = 0;

		bool a = true;
		bool b_player = false;
		bool b_computer = false;
		bool c = true;
		bool d = true;

		while (a)
		{
			while (c || b_player)
			{
				cout << "Ваша доска:\n";
				player_field.display();
				cout << "Ваши выстрелы:\n";
				computer_field.display();

				int player_row, player_col;
				get_shot_coordinate(player_row, player_col);

				if (computer_field.isHit(player_row, player_col))
				{
					cout << "Попадание!\n";
					computer_field.markHit(player_row, player_col);
					b_player = true;
					c = false;
				}
				else
				{
					cout << "Промах\n";
					b_player = false;
					computer_field.markMiss(player_row, player_col);
					c = false;
				}

				player_shots++;


				bool player_won = computer_field.win();
				if (player_won)
				{
					cout << "Вы выиграли!\n" << "Количество выстрелов: " << player_shots;
					a = false;
				}
			}
			c = true;

			while (d || b_computer)
			{
				int computer_row, computer_col;
				bool b = true;
				while (b)
				{
					computer_row = rand() % 10;
					computer_col = rand() % 10;
					if (computer_row != '-' && computer_col != '-')
						b = false;
				}
				cout << "Компьютер выстрелил: " << perevod_bukva(computer_col) << computer_row << endl;

				if (player_field.isHit(computer_row, computer_col))
				{
					cout << "Компьютер попал!\n";
					b_computer = true;
					d = false;
					player_field.markHit(computer_row, computer_col);
				}

				else
				{
					cout << "Компьютер промахнулся!\n";
					b_computer = false;
					d = false;
					player_field.markMiss(computer_row, computer_col);
				}

				computer_shots++;
				bool computer_won = player_field.win();
				if (computer_won)
				{
					cout << "Вы проиграли!\n" << "Количество выстрелов компьютера: " << computer_shots;
					a = false;
				}
			}
			d = true;
			system("pause");
			system("cls");

		}
		
} //Доделать если попадание, то стреляет еще раз
//Сделать расстановку кораблей игроком
//Сделать, чтобы корабли нельзя было расставить ближе, чем через клетку