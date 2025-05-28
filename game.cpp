////22L-7997 MUHAMMAD FAKHAR BIN RASHID;
#include <iostream>
#include <sstream>
#include <vector>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;

bool errors = false;
int sub_grid[3][3] = { 0 };
int sub_grid2[3][3];
int arr[9][9] = { 0 };
int full[9][9] = { 0 };

int position[162];
int index_controller_position_arra = 0;

char menu_choice = ' ';

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool checker(int grid[9][9], int row, int col, int num)
{

	for (int i = 0; i < 9; i++)
	{
		if (grid[row][i] == num)
		{
			return false;
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (grid[j][col] == num)
		{
			return false;
		}
	}

	int air = row - row % 3, aic = col - col % 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i + air][j + aic] == num)
			{
				return false;
			}
		}
	}
	return true;
}
bool check(int num, int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == num)
				return true;
		}
	}return false;
}
void subGrid1(int grid[3][3]) {
	srand(time(0));

	int random = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = 0;
		}
	}
	int i = 0;
	int row = 0, col = 0;
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{

		re:
			random = (rand() % 9) + 1;
			if (check(random, grid))
			{
				goto re;
			}
			grid[row][col] = random;
		}
	}
}
void Fill(int grid[9][9], int sub_grid[3][3])
{
	subGrid1(sub_grid);
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			grid[j][k] = sub_grid[j][k];
		}
	}
}

void firstgridgenerator(int arr[][3])
{
	srand(time(0));
	int random;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
		position:
			random = (rand() % 10);
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (arr[k][l] == random)
					{
						goto position;
					}
				}
			}
			arr[i][j] = random;
		}
	}
}
void secondgridgenerator(int arr[3][3], int arr2[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (i == 1)
						arr2[2][j + l] = arr[i + k][j + l];
					if (i == 0)
						arr2[1][j + l] = arr[i + k][j + l];
					if (i == 2)
						arr2[0][j + l] = arr[i + k][j + l];
				}
			}
		}
	}

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 1; l++)
				{
					if (j == 0)
						arr[i + k][0] = arr2[i + k][2];
					if (j == 1)
						arr[i + k][1] = arr2[i + k][0];
					if (j == 2)
						arr[i + k][2] = arr2[i + k][1];
				}
			}
		}
	}


}

void topgrid(int big_grid[9][9])
{
	int arr2[3][3] = { 0 };
	int arr[3][3] = { 0 };

	firstgridgenerator(arr);

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 9; j += 3)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (j == 0)
					{
						big_grid[i + k][j + l] = arr[k][l];
					}
					if (j == 6 || j == 3)
						big_grid[i + k][j + l] = arr2[k][l];
				}

			}
			secondgridgenerator(arr, arr2);
			secondgridgenerator(arr2, arr);
		}
	}
}
void leftgrid(int big_grid[9][9])
{
	for (int i = 3; i < 9; i += 3)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (j == 0 && i == 3)
						big_grid[i + k][0] = big_grid[k][2];
					if (j == 1 && i == 3)
						big_grid[i + k][1] = big_grid[k][0];
					if (j == 2 && i == 3)
						big_grid[i + k][2] = big_grid[k][1];

					if (j == 0 && i == 6)
						big_grid[i + k][0] = big_grid[k][1];
					if (j == 1 && i == 6)
						big_grid[i + k][1] = big_grid[k][2];
					if (j == 2 && i == 6)
						big_grid[i + k][2] = big_grid[k][0];
				}
			}
		}
	}
}
void middlegrid(int big_grid[9][9])
{
	for (int i = 3; i < 9; i += 3)
	{
		for (int j = 3; j < 6; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 3; l < 6; l++)
				{
					if (j == 3 && i == 3)
						big_grid[i + k][3] = big_grid[k][5];
					if (j == 4 && i == 3)
						big_grid[i + k][4] = big_grid[k][3];
					if (j == 5 && i == 3)
						big_grid[i + k][5] = big_grid[k][4];

					if (j == 3 && i == 6)
						big_grid[i + k][3] = big_grid[k][4];
					if (j == 4 && i == 6)
						big_grid[i + k][4] = big_grid[k][5];
					if (j == 5 && i == 6)
						big_grid[i + k][5] = big_grid[k][3];
				}
			}
		}
	}
}
void rightgrid(int big_grid[9][9])
{
	for (int i = 3; i < 9; i += 3)
	{
		for (int j = 6; j < 9; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 6; l < 9; l++)
				{
					if (j == 6 && i == 3)
						big_grid[i + k][6] = big_grid[k][7];
					if (j == 7 && i == 3)
						big_grid[i + k][7] = big_grid[k][8];
					if (j == 8 && i == 3)
						big_grid[i + k][8] = big_grid[k][6];

					if (j == 6 && i == 6)
						big_grid[i + k][6] = big_grid[k][8];
					if (j == 7 && i == 6)
						big_grid[i + k][7] = big_grid[k][6];
					if (j == 8 && i == 6)
						big_grid[i + k][8] = big_grid[k][7];
				}
			}
		}
	}
}

void remover(int big_grid[9][9], int full[9][9])

{
	srand(time(0));
	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (i == 0 && j == 0)
					{
						if (big_grid[i + k][j + l] == 6 || big_grid[i + k][j + l] == 9 || big_grid[i + k][j + l] == 7)
							full[i + k][j + l] = big_grid[i + k][j + l];
						else
							full[i + k][j + l] = 0;
					}
					else
					{
						if (big_grid[i + k][j + l] == (rand() % 9) + 1 || big_grid[i + k][j + l] == (rand() % 9) + 1 || big_grid[i + k][j + l] == (rand() % 9) + 1 || big_grid[i + k][j + l] == (rand() % 9) + 1 || big_grid[i + k][j + l] == (rand() % 9) + 1)
							full[i + k][j + l] = big_grid[i + k][j + l];
						else
							full[i + k][j + l] = 0;
					}
				}
			}

		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setCord(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void color(int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void constantPositions(int display_wali_grid[9][9], int position[162])
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (display_wali_grid[i][j] != 0)
			{
				position[index_controller_position_arra] = i + (5 + i);
				index_controller_position_arra++;
				position[index_controller_position_arra] = (j + 68) + (j * 3);
				index_controller_position_arra++;
			}
		}
	}
}
bool PositionChecker(int row, int col, int position[162])
{
	int a = index_controller_position_arra;
	int find[2] = { 0 };
	find[0] = row;
	find[1] = col;

	int count = 0;

	for (int i = 0; i <= a - 2; i += 2)
	{
		for (int j = 0; j < 2; j++)
		{
			if (position[i + j] == find[j])
			{
				count++;
			}
		}
		if (count == 2)
		{
			return true;
		}
		count = 0;
	}
	return false;
}
void DisplayingConstants(int arr[9][9])
{
	int i = 0, j = 0;

	color(241);
	for (int y = 5; y <= 21; y += 2)
	{
		for (int x = 68; x <= 100; x += 4)
		{
			setCord(x, y);
			if (arr[i][j] != 0)
			{
				cout << arr[i][j];
			}
			else
				cout << " ";
			j++;
		}
		i++;
		j = 0;
	}
	color(240);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void boadring(int length = 35, int width = 67, int x = 50, int y = 3)
{
	char horizontal = 196;
	char vertical = 179;

	char  down_rigth_corner = 217,
		upper_left_corner = 218,
		down_left_corner = 192,
		upper_right_corner = 191;



	//starting cordinates of box


	setCord(x, y);
	cout << upper_left_corner;
	for (int i = 0; i < width; i++)
	{
		cout << horizontal;
	}
	cout << upper_right_corner;
	for (int j = 0; j < length; j++)
	{
		y++;
		setCord(x, y);
		cout << vertical;
	}

	setCord(x, y);
	cout << down_left_corner;
	for (int i = 0; i < width; i++)
	{
		cout << horizontal;
	}
	cout << down_rigth_corner;

	x = x + width + 1;
	for (int j = 0; j < length - 1; j++)//-1 is lia kia ku ke ak vertical line bahar nikal rahi the upper se
	{
		y--;
		setCord(x, y);
		cout << vertical;
	}

}
void background_colour(int width = 38, int length = 118, int C = 240, int x = 50, int y = 4)
{
	int a = y, b = x;
	for (y = a; y < width; y++)
	{
		for (x = b; x < length; x++)
		{
			setCord(x, y);
			color(C);
			cout << " ";
		}
	}
}
void pauseplaybuttons()
{
	char horizontal = 196, vertical = 179;
	char  down_rigth_corner = 217, upper_left_corner = 218, down_left_corner = 192, upper_right_corner = 191;
	char pause = 179;
	setCord(114, 4);
	cout << upper_left_corner << horizontal << upper_right_corner << endl;
	setCord(114, 5);
	cout << vertical << "*" << vertical << endl;
	setCord(114, 6);
	cout << down_left_corner << horizontal << down_rigth_corner << endl;
}
void board()
{

	//to print one big box
	char horizontal = 205;
	char vertical = 186;

	char  down_rigth_corner = 188,
		upper_left_corner = 201,
		down_left_corner = 200,
		upper_right_corner = 187;

	int length = 18, width = 35;

	//starting cordinates of box
	int x = 66, y = 4;

	setCord(x, y);
	cout << upper_left_corner;
	for (int i = 0; i < width; i++)
	{
		cout << horizontal;
	}
	cout << upper_right_corner;
	for (int j = 0; j < length; j++)
	{
		y++;
		setCord(x, y);
		cout << vertical;
	}

	setCord(x, y);
	cout << down_left_corner;
	for (int i = 0; i < width; i++)
	{
		cout << horizontal;
	}
	cout << down_rigth_corner;

	x = x + width + 1;
	for (int j = 0; j < length - 1; j++)//-1 is lia kia ku ke ak vertical line bahar nikal rahi the upper se
	{
		y--;
		setCord(x, y);
		cout << vertical;
	}

	//to print big cells
	char PLUS = 206, DOWN_T = 203, UP_T = 202;

	for (int x = 78; x < 91; x += 12)
	{
		for (int y = 4; y <= 22; y++)
		{
			setCord(x, y);
			if (y == 4)
				cout << DOWN_T;
			else if (y == 22)
				cout << UP_T;
			else
				cout << vertical;
		}
	}
	for (int y = 10; y < 22; y += 6)
	{
		for (int x = 67; x < 102; x += 1)
		{
			setCord(x, y);
			if (x == 78 || x == 90)
			{
				cout << PLUS;
			}
			else
				cout << horizontal;
		}
	}

	//to print small cells
	char H = 196, P = 197;
	char v = 179;

	for (int l = 5; l < 23; l += 6)
	{
		for (x = 67; x < 103; x += 12)
		{
			y = l;
			for (int i = 0; i < 1; i++)
			{
				if (i == 0)
					setCord(x, y);
				y++;//agar y++ nai kare ge to cord dubara pecha he screen par chala jaye ga.
				cout << "   " << v << "   " << v << "   " << endl;
				for (int i = 0; i < 2; i++)
				{
					setCord(x, y);
					y++;
					{
						cout << H << H << H << P << H << H << H << P << H << H << H << endl;
					}
					setCord(x, y);
					cout << "   " << v << "   " << v << "   " << endl;
					y++;
				}
			}
		}
	}

	//finishing (JOINING OF BIG BOX WITH SMALL CELLS)
	char Q = 209, W = 216, E = 207;
	for (int x = 70; x < 100; x += 4)
	{
		if (x == 78 || x == 90)
			continue;
		setCord(x, 4);
		cout << Q;
	}
	y = 10;
	while (y <= 16)
	{
		for (int x = 70; x < 100; x += 4)
		{
			if (x == 78 || x == 90)
				continue;
			setCord(x, y);
			cout << W;
		}
		y += 6;
	}
	for (int x = 70; x < 100; x += 4)
	{
		if (x == 78 || x == 90)
			continue;
		setCord(x, 22);
		cout << E;
	}

}
void SUDOKU_display() {
	const int ROWS = 6;
	const int COLS = 54;
	color(240);
	string numbersString = R"(
        219 219 219 219 219 219 219 187 219 219 187 32 32 32 219 219 187 219 219 219 219 219 219 187 32 32 219 219 219 219 219 219 187 32 219 219 187 32 32 32 219 219 187 219 219 187 32 32 32 32 219 219 187 10 
		219 219 201 205 205 205 205 188 219 219 186 32 32 32 219 219 186 219 201 205 205 205 219 219 187 219 219 201 205 205 205 219 219 187 219 219 186 32 32 219 219 201 188 219 219 186 32 32 32 32 219 219 186 10
		219 219 219 219 219 219 219 187 219 219 186 32 32 32 219 219 186 219 186 32 32 32 219 219 186 219 219 186 32 32 32 219 219 186 219 219 219 219 219 219 201 188 32 219 219 186 32 32 32 32 219 219 186 10
		200 205 205 205 205 219 219 186 219 219 186 32 32 32 219 219 186 219 186 32 32 32 219 219 186 219 219 186 32 32 32 219 219 186 219 219 201 205 205 219 219 187 32 219 219 186 32 32 32 32 219 219 186 10
		219 219 219 219 219 219 219 186 200 219 219 219 219 219 219 201 188 219 219 219 219 219 219 201 188 32 219 219 219 219 219 219 201 188 219 219 186 32 32 32 219 219 187 32 219 219 219 219 219 219 219 201 188 10
		200 205 205 205 205 205 205 188 32 200 205 205 205 205 205 188 32 32 200 205 205 205 205 188 32 32 32 200 205 205 205 205 188 32 200 205 188 32 32 32 200 205 188 32 32 200 205 205 205 205 205 188 10 32
    )";

	stringstream ss(numbersString);
	int ch;
	vector<vector<int>> array2D;

	for (int i = 0; i < ROWS; ++i) {
		vector<int> row;
		for (int j = 0; j < COLS; ++j) {
			if (ss >> ch) {
				row.push_back(ch);
			}
		}
		array2D.push_back(row);
	}

	color(240);
	int x = 58, y = 6;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			setCord(x + j, y + i);
			char ch;
			ch = array2D[i][j];
			cout << ch;
		}
	}
}
void menubox(char& choice)
{

	char horizontal = 205;
	char vertical = 186;
	char  down_rigth_corner = 188, upper_left_corner = 201, down_left_corner = 200, upper_right_corner = 187;
	int length = 13, width = 20;

	int x = 73, y = 13;
	int x2 = x, y2 = y;

	setCord(x, y);
	cout << upper_left_corner;
	for (int i = 0; i < width; i++)
	{
		cout << horizontal;
	}
	cout << upper_right_corner;
	for (int j = 0; j < length; j++)
	{
		y++;
		setCord(x, y);
		cout << vertical;
	}
	setCord(x, y);
	cout << down_left_corner;
	for (int i = 0; i < width; i++)
	{
		cout << horizontal;
	}
	cout << down_rigth_corner;

	x = x + width + 1;
	for (int j = 0; j < length - 1; j++)
	{
		y--;
		setCord(x, y);
		cout << vertical;
	}

	setCord(x2 + 3, y2 + 4);
	color(244);
	cout << "  > LOAD GAME." << endl;
	setCord(x2 + 3, y2 + 6);
	cout << "  > NEW GAME." << endl;
	setCord(x2 + 3, y2 + 8);
	cout << "  > QUIT GAME." << endl;

	x = 77, y = 17;
	setCord(x, y);
	while (true)
	{
		char ch = _getch();
		if (ch == 72)//up
		{
			y -= 2;
			if (y < 19)
				y = 17;
		}
		else if (ch == 80)//down
		{
			y += 2;
			if (y > 21)
				y = 17;
		}
		setCord(x, y);
		if (ch == 13 && y == 17)
		{
			color(240);
			choice = 'l';
			break;
		}
		if (ch == 13 && y == 19)
		{
			color(240);
			choice = 'n';
			break;
		}
		if (ch == 13 && y == 21)
		{
			color(240);
			choice = 'q';
			break;
		}
	}
}
char InGameMenu()
{
	int x = 72, y = 29;
	//length,width,colour,x,y
	background_colour(36, 102, 176, 66, 27);
	char ch = ' ';
	//length,width,x,y
	boadring(8, 35, 66, 27);
	setCord(x, y);
	cout << " |> SAVE GAME";
	setCord(x, y + 2);
	cout << " |> MAIN MENU";
	setCord(x, y + 4);
	cout << " |> RESUME";
	setCord(x, y);
	while (true)
	{
		ch = _getch();
		if (ch == 72)//up
		{
			y -= 2;
			if (y < 29)
				y = 33;
		}
		else if (ch == 80)//down
		{
			y += 2;
			if (y > 33)
				y = 29;
		}
		setCord(x, y);
		if (ch == 13 && y == 29)
		{
			color(240);
			return 's';
		}
		if (ch == 13 && y == 31)
		{
			color(240);
			return 'm';
		}
		if (ch == 13 && y == 33)
		{
			color(240);
			return 'o';
		}
	}
	return ch;
}
void loading()
{
	char c = -37;
	boadring(2, 32, 65, 19);
	for (int x = 66; x < 98; x++)
	{
		setCord(x, 20);
		Sleep(80);
		cout << c;
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char Slots()
{
	int x = 72, y = 29;
	//length,width,colour,x,y
	background_colour(36, 102, 176, 66, 27);
	char ch = ' ';
	//length,width,x,y
	boadring(8, 35, 66, 27);
	setCord(x, y);
	cout << " |> SLOT 1";
	setCord(x, y + 2);
	cout << " |> SLOT 2";
	setCord(x, y + 4);
	cout << " |> SLOT 3";
	setCord(x, y);
	while (true)
	{
		ch = _getch();
		if (ch == 72)//up
		{
			y -= 2;
			if (y < 29)
				y = 33;
		}
		else if (ch == 80)//down
		{
			y += 2;
			if (y > 33)
				y = 29;
		}
		setCord(x, y);
		if (ch == 13 && y == 29)
		{
			color(240);
			return '1';
		}
		if (ch == 13 && y == 31)
		{
			color(240);
			return '2';
		}
		if (ch == 13 && y == 33)
		{
			color(240);
			return '3';
		}
		if (ch == '*')
			return '*';
	}
	return ch;
}
void SaveGame()
{
	char slot;
	slot = Slots();
	if (slot == '1')
	{
		ofstream save1("slot1.txt");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (full[i][j] != 0)
					save1 << full[i][j] << " ";
				else
					save1 << "#" << " ";
			}
			save1 << endl;
		}
		save1 << index_controller_position_arra << endl;
		for (int i = 0; i < index_controller_position_arra; i++)
		{
			save1 << position[i] << " ";
		}save1.close();
	}
	else if (slot == '2')
	{
		ofstream save2("slot2.txt");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (full[i][j] != 0)
					save2 << full[i][j] << " ";
				else
					save2 << "#" << " ";
			}
			save2 << endl;
		}
		save2 << index_controller_position_arra << endl;
		for (int i = 0; i < index_controller_position_arra; i++)
		{
			save2 << position[i] << " ";
		}save2.close();
	}
	else if (slot == '3')
	{
		ofstream save3("slot3.txt");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (full[i][j] != 0)
					save3 << full[i][j] << " ";
				else
					save3 << "#" << " ";
			}
			save3 << endl;
		}
		save3 << index_controller_position_arra << endl;
		for (int i = 0; i < index_controller_position_arra; i++)
		{
			save3 << position[i] << " ";
		}save3.close();
	}
	if (slot != '*')
	{
		setCord(108, 37);
		cout << "saved! (" << slot << ")" << endl;
	}
	else
	{
		color(240);
	}

}
void loadGame(int arr1[9][9], int position[162])
{

	char slot;
	slot = Slots();

	if (slot == '1')
	{
		ifstream load1("slot1.txt");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char ch;
				load1 >> ch;
				if (ch == '#')
					arr1[i][j] = 0;
				else
					arr1[i][j] = ch - 48;
			}
		}
		load1 >> index_controller_position_arra;
		for (int i = 0; i < index_controller_position_arra; i++)
		{
			load1 >> position[i];
		}
		load1.close();
	}
	else if (slot == '2')
	{
		ifstream load2("slot2.txt");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char ch;
				load2 >> ch;
				if (ch == '#')
					arr1[i][j] = 0;
				else
					arr1[i][j] = ch - 48;
			}
		}
		load2 >> index_controller_position_arra;
		for (int i = 0; i < index_controller_position_arra; i++)
		{
			load2 >> position[i];
		}load2.close();
	}
	else if (slot == '3')
	{
		ifstream load3("slot3.txt");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char ch;
				load3 >> ch;
				if (ch == '#')
					arr1[i][j] = 0;
				else
					arr1[i][j] = ch - 48;
			}
		}
		load3 >> index_controller_position_arra;
		for (int i = 0; i < index_controller_position_arra; i++)
		{
			load3 >> position[i];
		}load3.close();
	}
}
void solution()
{
	setCord(0, 0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void input(int arr[9][9], int num, int row, int col)
{
	full[row][col] = num;
}
int  spaces(int arr[9][9])
{
	int spaces = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
				spaces++;
		}
	}
	return spaces;
}
bool similar(int arr[9][9])
{
	int count = 0;
	for (int num = 1; num <= 9; num++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (arr[i][j] == num)
					count++;
				if (count > 9)
					return true;
			}
		}
		count = 0;
	}
	return false;
}
void cursorMover()
{
	int space = 0;
	int row = 0, col = 0;
	int x = 68, y = 5;


	while (true)
	{
		space = spaces(full);
		setCord(66, 23);
		cout << "                       ";
		setCord(66, 23);
		cout << "EMPTY BOXES :" << space;

		while (PositionChecker(y, x, position))
		{
			x += 4;
			col++;
		}
		setCord(x, y);
		char ch = _getch();

		if (ch == 72)//up
		{
			y -= 2;
			while (PositionChecker(y, x, position))
			{
				y -= 2;
				row--;
			}
			if (y < 5)
			{
				y = 5;
				row = 0;
				while (PositionChecker(y, x, position))
				{
					y += 2;
					row++;
				}
			}
			else
			{
				row--;
			}

			setCord(x, y);
		}
		else if (ch == 80)//down
		{
			y += 2;
			while (PositionChecker(y, x, position))
			{
				y += 2;
				row++;
			}
			if (y > 21)
			{
				y = 21;
				row = 8;
				while (PositionChecker(y, x, position))
				{
					y -= 2;
					row--;
				}
			}
			else
			{
				row++;
			}

			setCord(x, y);

		}
		else if (ch == 75)//left
		{
			x -= 4;
			while (PositionChecker(y, x, position))
			{
				x -= 4;
				col--;
			}
			if (x < 67)
			{
				if (y < 6)
				{
					x = 100;
					y = 21;
					row = 9;
				}
				else
				{
					y -= 2;
					x = 100;
				}
				col = 8;
				row--;
				while (PositionChecker(y, x, position))
				{
					x -= 4;
					col--;
				}
			}
			else
			{
				col--;
			}

			setCord(x, y);
		}
		else if (ch == 77)//right
		{
			x += 4;
			while (PositionChecker(y, x, position))
			{
				x += 4;
				col++;
			}
			if (x > 100)
			{
				if (y > 20)
				{
					x = 68;
					y = 5;
					row = -1;
				}
				else
				{
					y += 2;
					x = 68;
				}
				row++;
				col = 0;
				while (PositionChecker(y, x, position))
				{
					x += 4;
					col++;
				}
			}
			else
			{
				col++;
			}

			setCord(x, y);
		}
		else if (ch == ' ' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		{
			int num = 0;

			if (ch == ' ')
				ch = '0';

			num = int(ch) - 48;

			setCord(x, y);

			//ye condition check ho ge or colour set ho jaye ga
			if (checker(full, row, col, num) == false)
			{
				color(252);
			}
			else
			{
				color(240);
			}
			if (num != 0)
			{
				cout << num;
			}
			else
				cout << " ";

			color(240);

			input(full, num, row, col);
			//setCord(x, y);
		}
		if (ch == '*')
		{
			char option;
			option = InGameMenu();
			if (option == 's')
			{
				SaveGame();
				for (int row = 24; row < 38; row++)
				{
					for (int col = 65; col < 104; col++)
					{
						setCord(col, row);
						cout << " ";
					}
				}
			}
			else if (option == 'm')
			{
				break;
			}
			else if (option == 'o')
			{
				background_colour(36, 103, 240, 66, 27);
			}
		}
		errors = similar(full);
		if (space == 0 && errors == false)
		{
			boadring(8, 35, 66, 27);
			setCord(71, 31);
			cout << "CONGRATULATIONS! YOU WIN!" << endl;
		}
	}
}
int main()
{
	system("pause>0");
	background_colour();
	boadring();
	loading();
	while (true)
	{
		background_colour();
		boadring();
		SUDOKU_display();
		menubox(menu_choice);

		system("color 0f");
		if (menu_choice == 'n')
		{
			firstgridgenerator(sub_grid);
			secondgridgenerator(sub_grid, sub_grid2);
			topgrid(arr);
			leftgrid(arr);
			middlegrid(arr);
			rightgrid(arr);
			remover(arr, full);

			system("color 0f");
			system("cls");


			background_colour();

			pauseplaybuttons();
			boadring();
			board();


			DisplayingConstants(full);
			constantPositions(full, position);
			cursorMover();
		}
		else if (menu_choice == 'l')
		{
			background_colour();
			SUDOKU_display();
			boadring();

			position[161] = { 0 };
			loadGame(full, position);
			setCord(0, 0);

			background_colour();
			pauseplaybuttons();
			boadring();
			board();

			DisplayingConstants(full);

			cursorMover();
		}
		else if (menu_choice == 'q')
		{
			system("cls");
			background_colour();
			boadring();
			setCord(69, 20);
			cout << "THANK YOU FOR PALYING THE GAME !";
			system("pause>0");
			break;
		}
		index_controller_position_arra = 0;
		position[161] = { 0 };
	}
}