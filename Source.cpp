#include<iostream>
#include<windows.h>
#include<fstream>
#include"myconsole.h"
#include"mygraphics.h"
#include <winuser.h>
#include <conio.h>
const int r = 9;
const int c = 9;
int x = 0;
int y = 0;
using namespace std;

bool check(int grid[r][c]);
void crush_candy(int grid[r][c],int &score);
void SmashOneRowCandy(int grid[r][c], int i, int j,int &score);
void smashonecolcandy(int grid[r][c], int i, int j,int &score);
bool CheckStripped(int grid[r][c]);
void Striped_candy(int grid[r][c],int &score);
bool CheckWrapped(int grid[r][c]);
void Wrapped_candy(int grid[r][c],int &score);
bool CheckColorBomb(int grid[r][c]);
void Colour_Bomb(int grid[r][c],int &score);
bool checkps(int grid[r][c]);
void Ps_candy(int grid[r][c],int &score);
bool checkpw(int grid[r][c]);
void Pw_candy(int grid[r][c],int &score);
void smashhorizontal(int arr[r][c], int num,int &score);
void smashvertical(int arr[r][c], int num,int &score);
void smashwrap(int arr[r][c], int x, int y,int &score);
void replaceandsmash(int fill[r][c], int bef, int aft,int &score);
void swap(int arr[r][c], int x1, int y1, int x2, int y2);
void stripeandbomb(int arr[r][c], int cx1, int cy1, int x2, int y2,int &score);
void wrapandbomb(int arr[r][c], int cx1, int cy1, int x2, int y2,int &score);
void stripandwrap(int arr[r][c], int x1, int y1,int &score);
void wrapandwrap(int arr[r][c], int x, int y,int&score);
void plainandbomb(int arr[r][c], int cx1, int cy1, int x2, int y2,int &score);
void bombandbomb(int arr[r][c],int &score);

void plaincandies(int x1, int y1, int x2, int y2,int candy)
{
	if (candy == 1)
	{
		for (int i = x2 - 40; i <= x2 - 10; i++)
		{
			myLine(x1 + 25, y1 + 10, i, y2 - 25, RGB(255, 0, 0));
		}
		for (int i = x2 - 40; i <= x2 - 10; i++)
		{
			myLine(x1 + 25, y1 + 40, i, y2 - 25, RGB(255, 0, 0));
		}
	}
	else if (candy == 2)
	{
		for (int i = x2 - 40; i <= x2 - 10; i++)
		{
			myLine(x1 + 25, y1 + 15, i, y2 - 20, RGB(255, 255, 0));
		}
	}
	else if (candy == 3)
	{
		myRect((x1 + 10), (y1 + 10), (x2 - 10), (y2 - 10), RGB(0, 100, 0), RGB(0, 100, 0));
	}
	else if (candy == 4)
	{
		myEllipse(x1 + 10, y1 + 10, x2 - 10, y2 - 10, RGB(0, 0, 255), RGB(0, 0, 255));
	}
	else
	{
		myEllipse(x1 + 15, y1 + 15, x2 - 15, y2 - 10, RGB(255, 120, 0), RGB(255, 120, 0));
	}
}
void colorbomb(int x1, int y1, int x2, int y2)
{
	myEllipse(x1 + 8, y1 + 8, x2 - 8, y2 - 8, RGB(0, 0, 0), RGB(0, 0, 0));
	myEllipse(x1+20,y1+13,x2-35, y2-43, RGB(255, 0, 0), RGB(255, 0, 0));
	myEllipse(x1+28,y1+28,x2-28,y2-28, RGB(255, 255, 0), RGB(255, 255, 0));
	myEllipse(x1+33,y1+43,x2-23,y2-13, RGB(255, 0, 0), RGB(255, 0, 0));
	myEllipse(x1+37,y1+28,x2-6,y2-28, RGB(255, 120, 0), RGB(255, 120, 0));
	myEllipse(x1+33,y1+13,x2-23,y2-43, RGB(0, 100, 0), RGB(0, 100, 0));
	myEllipse(x1+13,y1+28,x2-43,y2-28, RGB(255, 0, 0), RGB(255, 0, 0));
	myEllipse(x1+17,y1+43,x2-38,y2-13, RGB(0, 0, 255), RGB(0, 0, 255));
}

void stripedverticalcandy(int x1, int y1, int x2, int y2, int candy)
{
	if (candy == 1)
	{
		plaincandies(x1, y1, x2, y2,candy);
		myLine(x1 + 26, y1 + 12, x1 + 26, y1 + 38, RGB(255, 255, 255));
		myLine(x1 + 20, y1 + 15, x1+  20, y1 +35, RGB(255, 255, 255));
		myLine(x1 + 15, y1 + 18, x1+ 15, y1+30, RGB(255, 255, 255));
		myLine(x1 + 33, y1 + 15, x1 + 33, y1 + 35, RGB(255, 255, 255));
		myLine(x1 + 38, y1 + 18, x1 + 38, y1 + 30, RGB(255, 255, 255));
	}
	else if (candy == 2)
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1 + 20, y1 + 18, x1+ 20, y1+30, RGB(255, 255, 255));
		myLine(x1 +30, y1 + 18, x1 +30, y1 + 30, RGB(255, 255, 255));
		myLine(x1 + 25, y1 + 15, x1 + 25, y1 + 30, RGB(255, 255, 255));
		myLine(x1 + 15, y1 + 24, x1 + 15, y1 + 30, RGB(255, 255, 255));
		myLine(x1 + 35, y1 + 24, x1 + 35, y1 + 30, RGB(255, 255, 255));
	}
	else if (candy == 3)
	{
		plaincandies(x1, y1, x2, y2, candy);
		for (int i = 10; i <= 40; i = i + 10)
		{
			myLine(x1 + i, y1 + 10, x1 + i, y1 + 38, RGB(255, 255, 255));
		}
	}
	else if (candy == 4)
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1 + 15, y1 + 15, x1 + 15, y1 + 35, RGB(255, 255, 255));
		myLine(x1 + 20, y1 + 10, x1 + 20, y1 + 40, RGB(255, 255, 255));
		myLine(x1 + 25, y1 + 7, x1 + 25, y1 + 42, RGB(255, 255, 255));
		myLine(x1 + 30, y1 + 10, x1 + 30, y1 + 40, RGB(255, 255, 255));
		myLine(x1 + 35, y1 + 15, x1 + 35, y1 + 35, RGB(255, 255, 255));
	}
	else
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1 + 25, y1 + 13, x1 + 25, y1 + 40, RGB(255, 255, 255));
		myLine(x1 + 19, y1 + 18, x1 + 19, y1 + 35, RGB(255, 255, 255));
		myLine(x1 + 31, y1 + 18, x1 + 31, y1 + 35, RGB(255, 255, 255));
	}
}
void stripedhorizontalcandy(int x1, int y1, int x2, int y2, int candy)
{
	if (candy == 1)
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1 + 28, y1 + 12, x2 - 28, y2 - 38, RGB(255, 255, 255));
		myLine(x1+15,y1+18,x2-15, y2-32, RGB(255, 255, 255));
		myLine(x1+12,y1+24,x2-12,y2-26, RGB(255, 255, 255));
		myLine(x1+15,y1+30, x2-15,y2-20, RGB(255, 255, 255));
		myLine(x1+28, y1+38, x2-28,y2-12 , RGB(255, 255, 255));	
	}
	else if (candy == 2)
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1 + 20, y1 + 18, x2 - 20, y2 - 32, RGB(255, 255, 255));
		myLine(x1 + 13.5, y1 + 24, x2 - 13.5, y2 - 26, RGB(255, 255, 255));
		myLine(x1 + 12, y1 + 28, x2 - 12, y2 - 20, RGB(255, 255, 255));
	}
	else if (candy == 3)
	{
		plaincandies(x1, y1, x2, y2, candy);
		for (int i = 10; i <= 40; i = i + 10)
		{
			myLine(x1 + 10, y1 + i, x2-10, y1 + i, RGB(255, 255, 255));
		}
	}
	else if (candy == 4)
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1 + 15, y1 + 15, x2 - 15, y2 - 35, RGB(255,255,255));
		myLine(x1 + 10, y1 + 25, x2 - 10, y2 -25, RGB(255,255,255));
		myLine(x1 + 15, y1 + 35, x2 - 15, y2 -15 , RGB(255, 255, 255));
	}
	else
	{
		plaincandies(x1, y1, x2, y2, candy);
		myLine(x1+20,y1+15,x2-20,y1+15,RGB(255,255,255));
		myLine(x1 + 15, y1 + 20, x2 - 16, y1 + 20, RGB(255, 255, 255));
		myLine(x1 + 12, y1 + 25, x2 - 14, y1 + 25, RGB(255, 255, 255));
		myLine(x1 + 15, y1 + 30, x2 - 16, y1 + 30, RGB(255, 255, 255));
		myLine(x1 + 20, y1 + 37, x2 - 20, y1 + 37, RGB(255, 255, 255));
	}
}
void wrapcandies(int x1, int y1, int x2, int y2,int candy)
{
	if (candy == 1)
	{
		myRect(x1 + 8, y1 + 8, x2 - 8, y2 - 8, RGB(220, 20, 60), RGB(220, 20, 60));
		plaincandies(x1, y1, x2, y2, candy);
	}
	else if (candy == 2)
	{
		plaincandies(x1, y1, x2, y2, candy);
		myRect(x1 + 8, y1 + 8, x2 - 8, y2 - 8, RGB(255, 215, 0), RGB(255, 215, 0));
	}
	else if (candy == 3)
	{
		myRect(x1 + 6, y1 + 6, x2 - 6, y2 - 6, RGB(173, 255, 47), RGB(173, 255, 47));
		plaincandies(x1, y1, x2, y2, candy);
	}
	else if (candy == 4)
	{
		myRect(x1 + 8, y1 + 8, x2 - 8, y2 - 8, RGB(0, 255, 255), RGB(0, 255, 255));
		plaincandies(x1, y1, x2, y2, candy);
	}
	else
	{
		myRect(x1 + 8, y1 + 8, x2 - 8, y2 - 8, RGB(255, 165, 0), RGB(255, 165, 0));
		plaincandies(x1, y1, x2, y2, candy);
	}
	
}

void Candies(int fill[r][c],int i,int j, int x1, int y1, int x2, int y2)
{
	if(fill[i][j]>=1&&fill[i][j]<=5)
		plaincandies(x1, y1, x2, y2, fill[i][j]);
	if (fill[i][j] == 6)
		colorbomb(x1, y1, x2, y2);
	if (fill[i][j] >= 7 && fill[i][j] <= 11)
		stripedhorizontalcandy(x1, y1, x2, y2, fill[i][j] - 6);
	if (fill[i][j] >= 12 && fill[i][j] <= 16)
		wrapcandies(x1, y1, x2, y2, fill[i][j] - 11);
	if(fill[i][j]>=17&&fill[i][j]<=21)
		stripedverticalcandy(x1, y1, x2, y2, fill[i][j] - 16);
}
void FillGrid(int fill[r][c])
{
	srand(time(0));//filling the array
	int num = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			num = rand() % 5 + 1;
			fill[i][j] = num ;
		}
	}
}
void displaygrid(int fill[r][c])
{
	int k = 150;
	int l = 200;
	for (int i = 0; i < 9; i++)
	{
		int c = 150;
		int v = 200;
		for (int j = 0; j < 9; j++)
		{
			myRect(c, k, v, l, RGB(211, 211, 211), RGB(0, 0, 0));
			myRect(c + 4, k + 4, v - 4, l - 4, RGB(169, 169, 169), RGB(169, 169, 169));
			Candies(fill, i, j, c, k, v, l);
			c = c + 50;
			v = v + 50;
		}
		k = k + 50;
		l = l + 50;
	}
}
void Load(int arr[][c],int &score,int &moves)
{
	ifstream fin;
	fin.open("game");
	if (!fin)
	{
		cout << "ERROR.No previous data found.TRY AGAIN." << endl;
	}
	while (!fin.eof())
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				fin >> arr[i][j];
			}
		}
		fin >> score;
		fin >> moves;
	}
	fin.close();
}
void Save(int arr[][c], int score,int moves)
{
	ofstream write;
	write.open("game");
	if (!write)
	{
		cout << "ERROR." << endl;
	}
	while (!write.eof())
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				write << arr[i][j] << " ";
			}
			write << endl;
		}
		write << endl;
		write << score << " " << moves << endl;
	}
}
void repeatcrush(int grid[][c],int &score)
{
	 while (check(grid) == false && CheckStripped(grid) == false && CheckColorBomb(grid) == false && CheckWrapped(grid) == false && checkpw(grid) == false && checkps(grid) == false);
	 {
			 Colour_Bomb(grid,score);
			 Wrapped_candy(grid,score);
			 Striped_candy(grid,score);
			 crush_candy(grid,score);
			 Ps_candy(grid,score);
			 Pw_candy(grid,score);
	 }
}
void scorecalculate(int num, int& score)
{
	if (num == 1 || num == 2)
		score = score + 30;
	else if (num == 3)
		score = score + 50;
	else if (num == 4)
		score = score + 60;
	else
		score = score + 60;
}

int main()
{
	int fill[9][9] ;
	displaygrid(fill);
	int ts = 12000;
	int score = 0;
	int choice;
	int input = -1;
	int moves =2;
	int indice1x = 0, indice1y = 0;
	int indice2x = 0, indice2y = 0;
	FullScreen();
	SetConsoleTitleA("Candy Crush Saga");
	PlaceCursor(0, 10);
	cout << "HELLO!Welcome to Candy Crush Saga." << endl;
	cout << "Want to start the game or you want to continue where you left before??." << endl;
	cout <<"Enter 0 to start and 1 to continue from where you left.If playing for the first time choose 0." << endl;
	cin >> choice;
	if (choice == 0)
	{
		FillGrid(fill);
	}
	else
		Load(fill,score,moves);
	cout << " Crush the candies to gain 12000 points before moves run out.BEST OF LUCK!" << endl;
	cout << "  INSTRUCTIONS: Match three candies.Match 5 candies to make color bomb and 4 to make striped candy. " << endl;   
	cout<<"TIME TO RELAX!!!.Lets Begin the Saga." << endl;
	Sleep(3000);
	ClearScreen();
	PlaceCursor(0, 0);
	cout << "Target score = 12000" << endl;
	cout << "Score = " <<" "<< endl;
	cout << "moves remaining: " << " " ;
	displaygrid(fill);
	//game
	if (moves == 0)
	{
		ClearScreen();
		if (score < ts)
			cout << "SORRY! You have lost the game.TRY AGAIN!." << endl;
		else if (score >= ts)
			cout << "CONGRATULATIONS.You have won the game.See you next time." << endl;
	}
	while (moves != 0 && input!=0)
	{
		PlaceCursor(11, 1);
		cout << score << endl;
		PlaceCursor(17, 2);
		cout << moves;
		repeatcrush(fill, score);
		Sleep(3000);
		displaygrid(fill);
		int c = 0;
		PlaceCursor(80, 1);
		cout << "Enter the  first candy coordinates you want to swap" << endl;
		PlaceCursor(80, 2);
		cin >> indice1x;
		PlaceCursor(82, 2);
		cin	>> indice1y;
		PlaceCursor(80, 3);
		cout << "Enter the  second candy coordinates you want to swap" << endl;
		PlaceCursor(80, 4);
		cin >> indice2x;
		PlaceCursor(82, 4);
		cin>> indice2y;
		swap(fill, indice1x, indice1y, indice2x, indice2y);
		Sleep(1000);
		displaygrid(fill);
		repeatcrush(fill, score);
		Sleep(1000);
		displaygrid(fill);
		stripeandbomb(fill, indice1x, indice1y, indice2x, indice2y,score);
		//colorbomb with wrapped candy
		wrapandbomb(fill, indice1x, indice1y, indice2x, indice2y,score);
		if (((fill[indice1x][indice1y] <= 11 && fill[indice1x][indice1y] >= 7) || (fill[indice1x][indice1y] <= 17 && fill[indice1x][indice1y] >= 21)) && (fill[indice2x][indice2y] <= 16 && fill[indice2x][indice2y] >= 12))
			stripandwrap(fill, indice1x, indice1y,score);
		if (((fill[indice2x][indice2y] <= 11 && fill[indice2x][indice2y] >= 7) || (fill[indice2x][indice2y] <= 17 && fill[indice2x][indice2y] >= 21)) && (fill[indice2x][indice2y] <= 16 && fill[indice2x][indice2y] >= 12))
			stripandwrap(fill, indice1x, indice1y,score);
		else if (fill[indice1x][indice1y] == 6 && (fill[indice2x][indice2y] == 1 || fill[indice2x][indice2y] == 2 || fill[indice2x][indice2y] == 3 || fill[indice2x][indice2y] == 4 || fill[indice2x][indice2y] == 5))
			plainandbomb(fill, indice1x, indice1y, indice2x, indice2y,score);
		else if (fill[indice1x][indice1y] == 6 && fill[indice2x][indice2y] == 6)
			bombandbomb(fill,score);
		else if ((fill[indice1x][indice1y] <= 16 && fill[indice1x][indice1y] >= 12) && (fill[indice2x][indice2y] <= 16 && fill[indice1x][indice1y] >= 12))
			wrapandwrap(fill, indice1x, indice1y,score);
		Sleep(1000);
		repeatcrush(fill, score);
		Sleep(1000);
		displaygrid(fill);
		PlaceCursor(35, 1);
		cout << "ENTER 0 TO EXIT .PRESS 1 TO CONTINUE. " << endl;
		PlaceCursor(35, 2);
		cin >> input;
		moves--;
	}
	if (input == 0)
	{
		Save(fill,score,moves);
		ClearScreen();
		system("pause");
	}
	
}
void swap(int arr[r][c], int x1, int y1, int x2, int y2)
{
	if ((x1 == x2 && (y1 == y2 - 1 || y2 == y1 - 1)) || (y1 == y2 && (x1 == x2 - 1 || x2 == x1 - 1)))
	{
		int temp = arr[x1][y1];
		arr[x1][y1] = arr[x2][y2];
		arr[x2][y2] = temp;
	}
	else
	{
		while (!(((x1 == x2 && (y1 == y2 - 1 || y2 == y1 - 1)) || (y1 == y2 && (x1 == x2 - 1 || x2 == x1 - 1)))))
		{
			cout << "swap not possible.Input coordinates again." << endl;
			PlaceCursor(80, 2);
			cin >> x1;
			PlaceCursor(82, 2);
			cin >> y1;
			PlaceCursor(80, 4);
			cin >> x2;
			PlaceCursor(82, 4);
			cin >> y2;
		}
	}
		
}
void wrapandwrap(int arr[r][c], int x, int y, int& score)
{
	if (x < r - 2)
	{
		if (y > 1)
		{
			for (int i = x + 2, c = 5 && i >= 0; c >= 1; c--, i--)
				scorecalculate(arr[i][y - 2], score);
			for (int i = x + 2, k = 5; i >= 0; i--)//moving top to bottom for (left) candies
			{
				if (i >= k)
					arr[i][y - 2] = arr[i - k][y - 2];
				else
					arr[i][y - 2] = rand() % 6;
			}
		}
		if (y != 0)
		{
			for (int i = x + 2, c = 5 && i >= 0; c >= 1; c--, i--)
				scorecalculate(arr[i][y - 1], score);
			for (int i = x + 2, k = 5; i >= 0; i--)//moving top to bottom for (left) candies
			{
				if (i >= k)
					arr[i][y - 1] = arr[i - k][y - 1];
				else
					arr[i][y - 1] = rand() % 6;
			}
		}
		if (y < c - 2)
		{
			for (int i = x + 2, c = 5; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 2], score);
			for (int i = x + 2, k = 5; i >= 0; i--)//moving top to bottom for (right) candies
			{

				if (i >= k)
					arr[i][y + 2] = arr[i - k][y + 2];
				else
					arr[i][y + 2] = rand() % 6;
			}
		}
		if (y < c - 1)
		{
			for (int i = x + 2, c = 5; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 1], score);
			for (int i = x + 2, k = 5; i >= 0; i--)//moving top to bottom for (right) candies
			{

				if (i >= k)
					arr[i][y + 1] = arr[i - k][y + 1];
				else
					arr[i][y + 1] = rand() % 6;
			}
		}
		for (int i = x + 2, c = 5; c >= 1 && i >= 0; c--, i--)
			scorecalculate(arr[i][y], score);
		for (int i = x + 2, k = 5; i >= 0; i--)//moving top to bottom 
		{

			if (i >= k)
				arr[i][y] = arr[i - k][y];
			else
				arr[i][y] = rand() % 6;
		}
	}
	else if (x < r - 1)
	{
		if (y > 1)
		{
			for (int i = x + 1, c = 4; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y - 2], score);
			for (int i = x + 1, k = 4; i >= 0; i--)//moving top to bottom for (left) candies
			{
				if (i >= k)
					arr[i][y - 2] = arr[i - k][y - 2];
				else
					arr[i][y - 2] = rand() % 6;
			}
		}
		if (y != 0)
		{
			for (int i = x + 1, c = 4; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y - 1], score);
			for (int i = x + 1, k = 4; i >= 0; i--)//moving top to bottom for (left) candies
			{
				if (i >= k)
					arr[i][y - 1] = arr[i - k][y - 1];
				else
					arr[i][y - 1] = rand() % 6;
			}
		}
		if (y < c - 2)
		{
			for (int i = x + 1, c = 4; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 2], score);
			for (int i = x + 1, k = 4; i >= 0; i--)//moving top to bottom for (right) candies
			{

				if (i >= k)
					arr[i][y + 2] = arr[i - k][y + 2];
				else
					arr[i][y + 2] = rand() % 6;
			}
		}
		if (y < c - 1)
		{
			for (int i = x + 1, c = 4; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 1], score);
			for (int i = x + 1, k = 4; i >= 0; i--)//moving top to bottom for (right) candies
			{

				if (i >= k)
					arr[i][y + 1] = arr[i - k][y + 1];
				else
					arr[i][y + 1] = rand() % 6;
			}
		}
		for (int i = x + 1, c = 4; c >= 1 && i >= 0; c--, i--)
			scorecalculate(arr[i][y], score);
		for (int i = x + 1, k = 4; i >= 0; i--)//moving top to bottom 
		{

			if (i >= k)
				arr[i][y] = arr[i - k][y];
			else
				arr[i][y] = rand() % 6;
		}
	}
	else
	{
		if (y > 1)
		{
			for (int i = x, c = 3; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y - 2], score);
			for (int i = x, k = 3; i >= 0; i--)//moving top to bottom for (left) candies
			{
				if (i >= k)
					arr[i][y - 2] = arr[i - k][y - 2];
				else
					arr[i][y - 2] = rand() % 6;
			}
		}
		if (y != 0)
		{
			for (int i = x, c = 3; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y - 1], score);
			for (int i = x, k = 3; i >= 0; i--)//moving top to bottom for (left) candies
			{
				if (i >= k)
					arr[i][y - 1] = arr[i - k][y - 1];
				else
					arr[i][y - 1] = rand() % 6;
			}
		}
		if (y < c - 2)
		{
			for (int i = x, c = 3; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 2], score);
			for (int i = x, k = 3; i >= 0; i--)//moving top to bottom for (right) candies
			{

				if (i >= k)
					arr[i][y + 2] = arr[i - k][y + 2];
				else
					arr[i][y + 2] = rand() % 6;
			}
		}

		if (y < c - 1)
		{
			for (int i = x, c = 3; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 1], score);
			for (int i = x, k = 3; i >= 0; i--)//moving top to bottom for (right) candies
			{

				if (i >= k)
					arr[i][y + 1] = arr[i - k][y + 1];
				else
					arr[i][y + 1] = rand() % 6;
			}
		}
		for (int i = x, c = 3; c >= 1 && i >= 0; c--, i--)
			scorecalculate(arr[i][y], score);
		for (int i = x, k = 3; i >= 0; i--)//moving top to bottom 
		{

			if (i >= k)
				arr[i][y] = arr[i - k][y];
			else
				arr[i][y] = rand() % 6;
		}
	}
}
void stripandwrap(int arr[r][c], int x1, int y1, int& score)
{
	for (int i = 0; i < c; i++)
		scorecalculate(arr[x1][i], score);
	for (int i = 0; i < c; i++)
		scorecalculate(arr[x1 + 1][i], score);
	for (int i = 0; i < c; i++)
		scorecalculate(arr[x1 - 1][i], score);
	//deleting three rows and shifting
	for (int i = x1 + 1, k = 3; i >= 0; i--)
	{
		for (int j = 0; j < c; j++)
		{
			if (i >= k)
				arr[i][j] = arr[i - k][j];
			else
				arr[i][j] = rand() % 6;
		}
	}

	smashvertical(arr, y1 - 1, score);
	smashvertical(arr, y1, score);
	smashvertical(arr, y1 + 1, score);
}
void replaceandsmash(int fill[r][c], int bef, int aft,int &score)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (fill[i][j] == bef)
			{
				fill[i][j] = aft;
				if (aft >= 7 && aft <= 11)//for horizontal striped candy
				{
					smashhorizontal(fill, i,score);
				}
				else if (aft >= 17 && aft <= 21)//for verticalstriped candy
				{
					smashvertical(fill, j,score);
				}
				else
				{
					smashwrap(fill, i, j,score);
				}
			}
		}
	}
}
void smashwrap(int arr[r][c], int x, int y, int& score)
{
	if (x < r - 1)
	{
		if (y != 0)
		{
			for (int i = x + 1, c = 3; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y - 1], score);
			for (int i = x + 1, k = 3; i >= 0; i--)//moving top to bottom for three deleted(left) candies
			{
				if (i >= k)
					arr[i][y - 1] = arr[i - k][y - 1];
				else
					arr[i][y - 1] = rand() % 6 + 1;
			}
		}
		if (y < c - 1)
		{
			for (int i = x + 1, c = 3; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 1], score);
			for (int i = x + 1, k = 3; i >= 0; i--)//moving top to bottom for three deleted(right) candies
			{

				if (i >= k)
					arr[i][y + 1] = arr[i - k][y + 1];
				else
					arr[i][y + 1] = rand() % 6 + 1;
			}
		}
		for (int i = x + 1, c = 3; c >= 1 && i >= 0; c--, i--)
			scorecalculate(arr[i][y], score);
		for (int i = x + 1, k = 3; i >= 0; i--)//moving top to bottom for three deleted candies
		{
			if (i >= k)
				arr[i][y] = arr[i - k][y];
			else
				arr[i][y] = rand() % 6 + 1;
		}
	}
	else
	{
		if (y != 0)
		{
			for (int i = x, c = 2; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y - 1], score);
			for (int i = x; i >= 0; i--)//moving top to bottom for three deleted(left) candies
			{
				if (i >= 2)
					arr[i][y - 1] = arr[i - 2][y - 1];
				else
					arr[i][y - 1] = rand() % 6 + 1;
			}
		}
		if (y < c - 1)
		{
			for (int i = x, c = 2; c >= 1 && i >= 0; c--, i--)
				scorecalculate(arr[i][y + 1], score);
			for (int i = x; i >= 0; i--)//moving top to bottom for three deleted(right) candies
			{

				if (i >= 2)
					arr[i][y + 1] = arr[i - 2][y + 1];
				else
					arr[i][y + 1] = rand() % 6;
			}
		}
		for (int i = x, c = 2; c >= 1 && i >= 0; c--, i--)
			scorecalculate(arr[i][y], score);
		for (int i = x; i >= 0; i--)//moving top to bottom for three deleted candies
		{
			if (i >= 2)
				arr[i][y] = arr[i - 2][y];
			else
				arr[i][y] = rand() % 6;
		}
	}
}
void stripeandbomb(int arr[r][c], int x1, int y1, int x2, int y2,int&score)
{

	if (arr[x1][y1] == 6 && arr[x2][y2] >= 7 && arr[x2][y2] <= 11)
		replaceandsmash(arr, arr[x2][y2] - 6, arr[x2][y2],score);
	else if (arr[x2][y2] == 6 && arr[x1][y1] >= 7 && arr[x1][y1] <= 11)
		replaceandsmash(arr, arr[x1][y1] - 6, arr[x1][y1], score);
	else if (arr[x1][y1] == 6 && arr[x2][y2] >= 17 && arr[x2][y2] <= 21)
		replaceandsmash(arr, arr[x2][y2] - 16, arr[x2][y2], score);
	else if (arr[x2][y2] == 6 && arr[x1][y1] >= 17 && arr[x1][y1] <= 21)
		replaceandsmash(arr, arr[x1][y1] - 16, arr[x1][y1], score);
}
void wrapandbomb(int arr[r][c], int x1, int y1, int x2, int y2,int &score)
{
	if (arr[x1][y1] == 6 && arr[x2][y2] >= 12 && arr[x2][y2] <= 16)
		replaceandsmash(arr, arr[x2][y2] - 11, arr[x2][y2], score);
	else  if (arr[x2][y2] == 6 && arr[x1][y1] >= 12 && arr[x1][y1] <= 16)
		replaceandsmash(arr, arr[x1][y1] - 11, arr[x1][y1], score);
}
void bombandbomb(int arr[r][c],int &score)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scorecalculate(arr[i][j], score);
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = 1 + rand() % 6;
		}
	}
}
void plainandbomb(int arr[r][c], int cx1, int cy1, int x2, int y2,int &score)
{
	if (arr[x2][y2] == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] == 1 || arr[i][j] == 7 || arr[i][j] == 12 || arr[i][j] == 17)
				{
					scorecalculate(arr[i][j], score);
					if (i > 0)
					{
						arr[i][j] = arr[i - 1][j];
					}
					else
					{
						arr[i][j] = 1 + rand() % 6;
					}
				}
			}
		}
	}

	if (arr[x2][y2] == 2)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] == 2 || arr[i][j] == 8 || arr[i][j] == 13 || arr[i][j] == 18)
				{
					scorecalculate(arr[i][j], score);
					if (i > 0)
					{
						arr[i][j] = arr[i - 1][j];
					}
					else
					{
						arr[i][j] = 1 + rand() % 6;
					}
				}

			}
		}
	}

	if (arr[x2][y2] == 3)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] == 3 || arr[i][j] == 9 || arr[i][j] == 14 || arr[i][j] == 19)
				{
					scorecalculate(arr[i][j], score);
					if (i > 0)
					{
						arr[i][j] = arr[i - 1][j];
					}
					else
					{
						arr[i][j] = 1 + rand() % 6;
					}
				}
			}
		}
	}

	if (arr[x2][y2] == 4)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] == 4 || arr[i][j] == 10 || arr[i][j] == 15 || arr[i][j] == 20)
				{
					scorecalculate(arr[i][j], score);
					if (i > 0)
					{
						arr[i][j] = arr[i - 1][j];
					}
					else
					{
						arr[i][j] = 1 + rand() % 6;
					}
				}

			}
		}
	}

	if (arr[x2][y2] == 5)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] == 5 || arr[i][j] == 11 || arr[i][j] == 16 || arr[i][j] == 21)
				{
					scorecalculate(arr[i][j], score);
					if (i > 0)
					{
						arr[i][j] = arr[i - 1][j];
					}
					else
					{
						arr[i][j] = 1 + rand() % 6;
					}
				}
			}
		}
	}
}
bool check(int grid[r][c])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])
				return false;
		}
	}
	for (int j = 0; j < c; j++) {

		for (int i = 0; i < r; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j])
				return false;
		}
	}
	return true;
}
void crush_candy(int grid[r][c],int &score)
{
	for (y = 0; y < c; y++)//rows crushed
	{
		for (x = 0; x < r; x++)
		{
			if (grid[x][y] == grid[x + 1][y] && grid[x + 1][y] == grid[x + 2][y] && grid[x][y] == grid[x + 2][y])
			{
				SmashOneRowCandy(grid, x, y,score);
				SmashOneRowCandy(grid, x + 1, y,score);
				SmashOneRowCandy(grid, x + 2, y,score);
			}
		}
	}
	for (x = 0; x <= r; x++)// colums crushed
	{
		for (y = 0; y <= c; y++)
		{
			if (grid[x][y] == grid[x][y + 1] && grid[x][y + 1] == grid[x][y + 2] && grid[x][y] == grid[x][y + 2])
			{
				smashonecolcandy(grid, x, y,score);
				smashonecolcandy(grid, x, y + 1,score);
				smashonecolcandy(grid, x, y + 2,score);
			}

		}
	}
}

void SmashOneRowCandy(int grid[r][c], int i, int j,int &score)
{
	for (int k = i; k >= 0; k--)
	{
		if (k > 0)
		{
			grid[k][j] = grid[k - 1][j];
		}
		else
			grid[k][j] = 1 + rand() % 6;
	}
	scorecalculate(grid[i][j], score);
}
void smashonecolcandy(int grid[r][c], int i, int j,int &score)
{
	scorecalculate(grid[i][j], score);
	for (int k = j; k >= 0; k--)
	{
		if (k > 0)
		{
			grid[i][k] = grid[i][k - 1];
		}
		else
			grid[i][k] = 1 + rand() % 6;
	}
}
bool CheckStripped(int grid[r][c])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 2; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3])
				return false;
		}
	}
	for (int j = 0; j < c; j++)//column check 
	{
		for (int i = 0; i < r - 2; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j])
				return false;
		}
	}
	return true;
}
void Striped_candy(int grid[r][c],int &score)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 3; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3])
			{	
				SmashOneRowCandy(grid, i, j, score);
				SmashOneRowCandy(grid, i, j + 1, score);
				SmashOneRowCandy(grid, i, j + 2, score);
				scorecalculate(grid[i][j + 3], score);
				if (grid[i][j] == 1)
					grid[i][j + 3] = 7;
				else if (grid[i][j] == 2)
					grid[i][j + 3] = 8;
				else if (grid[i][j] == 3)
					grid[i][j + 3] = 9;
				else if (grid[i][j] == 4)
					grid[i][j + 3] = 10;
				else if (grid[i][j] == 5)
					grid[i][j + 3] = 11;
			}
		}
	}
	for (int j = 0; j < c; j++) 
	{
		for (int i = 0; i < r - 3; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j])
			{
				for (int c = 0; c < 4; c++)
				{
					scorecalculate(grid[i+c][j], score);
				}
				if (grid[i + 3][j] == 1)
				{
					grid[i + 3][j] = 17;
				}
				else if (grid[i + 3][j] == 2)
				{
					grid[i + 3][j] = 18;
				}
				else if (grid[i + 3][j] == 3)
				{
					grid[i + 3][j] = 19;
				}
				else if (grid[i + 3][j] == 4)
				{
					grid[i + 3][j] = 20;
				}
				else if (grid[i + 3][j] == 5)
				{
					grid[i + 3][j] = 21;
				}
				for (int k = i + 2, c = 3; k >= 0; k--)
				{
					if (k > c)
						grid[i][j] = grid[i - c][j];
					else
						grid[i][j] = 1 + rand() % 6;
				}
			}
		}
	}
}
bool CheckWrapped(int grid[r][c])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 3; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 1] == grid[i + 1][j + 1] && grid[i + 1][j + 1] == grid[i + 2][j + 1])

				return false;
		}
	}
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < r- 3; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 1][j] == grid[i + 1][j + 1] && grid[i + 1][j + 1] == grid[i + 1][j + 2])

				return false;
		}
	}
	return true;
}
void Wrapped_candy(int grid[r][c],int &score)
{
	//T wrapped candy
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 3; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 1] == grid[i + 1][j + 1] && grid[i + 1][j + 1] == grid[i + 2][j + 1])
			{
				SmashOneRowCandy(grid, i, j, score);
				SmashOneRowCandy(grid, i, j + 2, score);
				SmashOneRowCandy(grid, i + 1, j + 1, score);
				SmashOneRowCandy(grid, i + 2, j + 1, score);
				scorecalculate(grid[i][j + 1], score);
				if (grid[i][j] == 1)
					grid[i][j + 1] = 12;
				else if (grid[i][j] == 2)
					grid[i][j + 1] = 13;
				else if (grid[i][j] == 3)
					grid[i][j + 1] = 14;
				else if (grid[i][j] == 4)
					grid[i][j + 1] = 15;
				else if (grid[i][j] == 5)
					grid[i][j + 1] = 16;
			}
		}
	}
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < r - 3; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 1][j] == grid[i + 1][j + 1] && grid[i + 1][j + 1] == grid[i + 1][j + 2])
			{
				smashonecolcandy(grid, i, j, score);
				smashonecolcandy(grid, i + 2, j, score);
				smashonecolcandy(grid, i + 1, j + 1, score);
				smashonecolcandy(grid, i + 1, j + 2, score);
				scorecalculate(grid[i + 1][j], score);
				if (grid[i][j] == 1)
					grid[i + 1][j] = 12;
				else if (grid[i][j] == 2)
					grid[i + 1][j] = 13;
				else if (grid[i][j] == 3)
					grid[i + 1][j] = 14;
				else if (grid[i][j] == 4)
					grid[i + 1][j] = 15;
				else if (grid[i][j] == 5)
					grid[i + 1][j] = 16;
			}
		}
	}
	//L wrapped candy
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 3; j++)
		{
			for (int a = 1, k = 12; a <= 5, k <= 16; a++, k++)
			{
				if (grid[i][j] == grid[i + 1][j] && grid[i + 2][j] == grid[i + 1][j] && grid[i + 2][j] == grid[i + 2][j + 1] && grid[i + 2][j + 1] == grid[i + 2][j + 2])
				{
					if (grid[i][j] == a)
					{
						SmashOneRowCandy(grid, i, j,score);
						SmashOneRowCandy(grid, i + 1, j, score);
						SmashOneRowCandy(grid, i + 2, j + 1, score);
						SmashOneRowCandy(grid, i + 2, j + 2, score);
						scorecalculate(grid[i + 2][j], score);
						grid[i + 2][j] = k;
					}
				}
				else if (grid[i][j] == grid[i + 1][j] && grid[i + 2][j] == grid[i + 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])
				{

					if (grid[i][j] == a)
					{
						SmashOneRowCandy(grid, i + 1, j, score);
						SmashOneRowCandy(grid, i + 2, j, score);
						SmashOneRowCandy(grid, i, j + 1, score);
						SmashOneRowCandy(grid, i, j + 2, score);
						scorecalculate(grid[i][j], score);
						grid[i][j] = k;
					}
				}
				else if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i + 1][j + 2] && grid[i + 1][j + 2] == grid[i + 2][j + 2])
				{
					if (grid[i][j] == a)
					{
						SmashOneRowCandy(grid, i, j, score);
						SmashOneRowCandy(grid, i, j + 1, score);
						SmashOneRowCandy(grid, i + 1, j + 2, score);
						SmashOneRowCandy(grid, i + 2, j + 2, score);
						scorecalculate(grid[i][j+2], score);
						grid[i][j + 2] = k;
					}
				}
				else if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i - 1][j + 2] && grid[i - 1][j + 2] == grid[i - 2][j + 2])
				{
					if (grid[i][j] == a)
					{
						SmashOneRowCandy(grid, i, j,score);
						SmashOneRowCandy(grid, i, j + 1,score);
						SmashOneRowCandy(grid, i - 1, j + 2,score);
						SmashOneRowCandy(grid, i - 2, j + 2,score);
						scorecalculate(grid[i][j+2], score);
						grid[i][j + 2] = k;
					}
				}
			}

		}
	}
}
bool CheckColorBomb(int grid[r][c])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 2; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3] && grid[i][j] == grid[i][j + 4])
				return false;
		}
	}
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < r - 2; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j] && grid[i][j] == grid[i][j + 4])
				return false;
		}
	}
	return true;
}
void smashhorizontal(int arr[r][c], int num, int& score)
{
	for (int i = 0; i < c; i++)
		scorecalculate(arr[num][i], score);
	for (int c2 = num; c2 > 0; c2--)//shifting from top to bottom
	{
		for (int c3 = 0; c3 < c; c3++)
		{
			arr[c2][c3] = arr[c2 - 1][c3];
		}
	}
	for (int c1 = 0; c1 < c; c1++)//filling the upper most row
	{
		arr[0][c1] = rand() % 6;
	}
}
void smashvertical(int arr[r][c], int num, int& score)
{
	for (int i = 0; i < r; i++)
	{
		scorecalculate(arr[i][num], score);
		arr[i][num] = rand() % 6;
	}

}
void Colour_Bomb(int grid[r][c],int &score)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 2; j++)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j+2] == grid[i][j + 3] && grid[i][j + 3] == grid[i][j + 4])
			{
				SmashOneRowCandy(grid, i, j, score);
				SmashOneRowCandy(grid, i, j + 1, score);
				SmashOneRowCandy(grid, i, j + 3, score);
				SmashOneRowCandy(grid, i, j + 4, score);
				scorecalculate(grid[i][j + 2], score);
					grid[i][j + 2] = 6;
			}
		}
	}
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < r - 2; i++)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j] && grid[i][j]==grid[i+4][j])
			{
				for (int c = 0; c < 5; c++)
				{
					scorecalculate(grid[i + c][j], score);
				}
				grid[i + 2][j] = 6;
				for (int k = i + 2, c = 3; k >= 0; k--)
				{
					if (k > c)
						grid[i][j] = grid[i - c][j];
					else
						grid[i][j] = 1 + rand() % 6;
				}
			}
		}
	}
}
bool checkps(int grid[r][c])
{

	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 7, k = 1; (i <= 11 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x][y + 1] == k && grid[x][y + 2] == i)
					return false;
				else if (grid[x][y] == k && grid[x][y + 1] == i && grid[x][y + 2] == k)
					return false;
				else if (grid[x][y] == i && grid[x][y + 1] == k && grid[x][y + 2] == k)
					return false;
			}

		}
	}

	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 17, k = 1; (i <= 21 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x][y + 1] == k && grid[x][y + 2] == i)
					return false;
				else if (grid[x][y] == k && grid[x][y + 1] == i && grid[x][y + 2] == k)
					return false;
				else if (grid[x][y] == i && grid[x][y + 1] == k && grid[x][y + 2] == k)
					return false;
			}

		}
	}
	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 7, k = 1; (i <= 11 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x + 1][y] == k && grid[x + 2][y] == i)
					return false;
				else if (grid[x][y] == k && grid[x + 1][y] == i && grid[x + 2][y] == k)
					return false;
				else if (grid[x][y] == i && grid[x + 1][y] == k && grid[x + 2][y] == k)
					return false;
			}

		}
	}
	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 17, k = 1; (i <= 21 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x + 1][y] == k && grid[x + 2][y] == i)
					return false;
				else if (grid[x][y] == k && grid[x + 1][y] == i && grid[x + 2][y] == k)
					return false;
				else if (grid[x][y] == i && grid[x + 1][y] == k && grid[x + 2][y] == k)
					return false;
			}

		}
	}
	return true;
}
void Ps_candy(int grid[r][c],int &score)
{
	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 7, k = 1; (i <= 11 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x][y + 1] == k && grid[x][y + 2] == i)
				{
					smashhorizontal(grid, x, score);
					smashonecolcandy(grid, x, y, score);
					smashonecolcandy(grid, x, y + 1, score);

				}
				else if (grid[x][y] == k && grid[x][y + 1] == i && grid[x][y + 2] == k)
				{
					smashhorizontal(grid, x, score);
					smashonecolcandy(grid, x, y, score);
					smashonecolcandy(grid, x, y + 2, score);
				}
				else if (grid[x][y] == i && grid[x][y + 1] == k && grid[x][y + 2] == k)
				{
					smashhorizontal(grid, x, score);
					smashonecolcandy(grid, x, y + 1, score);
					smashonecolcandy(grid, x, y + 2, score);
				}
			}

		}
	}

	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 17, k = 1; (i <= 21 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x][y + 1] == k && grid[x][y + 2] == i)
				{
					smashvertical(grid, y + 2, score);


				}
				else if (grid[x][y] == k && grid[x][y + 1] == i && grid[x][y + 2] == k)
				{
					smashvertical(grid, y + 1, score);
				}
				else if (grid[x][y] == i && grid[x][y + 1] == k && grid[x][y + 2] == k)
				{
					smashvertical(grid, y, score);
				}
			}

		}
	}

	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 7, k = 1; (i <= 11 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x + 1][y] == k && grid[x + 2][y] == i)
				{
					smashhorizontal(grid, x + 2, score);
					SmashOneRowCandy(grid, x, y, score);
					SmashOneRowCandy(grid, x + 1, y, score);

				}
				else if (grid[x][y] == k && grid[x + 1][y] == i && grid[x + 2][y] == k)
				{
					smashhorizontal(grid, x + 1, score);
					SmashOneRowCandy(grid, x, y, score);
					SmashOneRowCandy(grid, x + 2, y, score);
				}
				else if (grid[x][y] == i && grid[x + 1][y] == k && grid[x + 2][y] == k)
				{
					smashhorizontal(grid, x, score);
					SmashOneRowCandy(grid, x + 2, y, score);
					SmashOneRowCandy(grid, x + 1, y, score);
				}
			}

		}
	}


	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 17, k = 1; (i <= 21 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x + 1][y] == k && grid[x + 2][y] == i)
				{
					smashvertical(grid, y, score);

				}
				else if (grid[x][y] == k && grid[x + 1][y] == i && grid[x + 2][y] == k)
				{
					smashvertical(grid, y, score);
				}
				else if (grid[x][y] == i && grid[x + 1][y] == k && grid[x + 2][y] == k)
				{
					smashvertical(grid, y,score);
				}
			}

		}
	}
}
bool checkpw(int grid[r][c])
{
	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)

		{
			for (int i = 12, k = 1; (i <= 16 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x][y + 1] == k && grid[x][y + 2] == i) //for red  
				{
					return false;
				}
				else if (grid[x][y] == k && grid[x][y + 1] == i && grid[x][y + 2] == k)
				{
					return false;
				}
				else if (grid[x][y] == i && grid[x][y + 1] == k && grid[x][y + 2] == k)
				{
					return false;
				}
			}
		}
	}
	for (y = 0; y < c; y++)
	{
		for (x = 0; x < r; x++)
		{
			for (int i = 12, k = 1; (i <= 16 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x + 1][y] == k && grid[x + 2][y] == i) //for red  
				{
					return false;
				}
				else if (grid[x][y] == k && grid[x + 1][y] == i && grid[x + 2][y] == k)
				{
					return false;
				}
				else if (grid[x][y] == i && grid[x + 1][y] == k && grid[x + 2][y] == k)
					return false;
			}
		}
	}
	return true;
}
void Pw_candy(int grid[r][c],int &score)
{
	crush_candy(grid,score);
	for (x = 0; x < r; x++)
	{
		for (y = 0; y < c; y++)
		{
			for (int i = 12, k = 1; (i <= 16 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x][y + 1] == k && grid[x][y + 2] == i) //for red  
				{
					smashwrap(grid, x, y + 2,score);
				}
				else if (grid[x][y] == k && grid[x][y + 1] == i && grid[x][y + 2] == k)
				{
					smashwrap(grid, x, y + 1, score);
				}
				else if (grid[x][y] == i && grid[x][y + 1] == k && grid[x][y + 2] == k)
				{
					smashwrap(grid, x, y, score);
				}
			}
		}
	}
	for (y = 0; y < c; y++)
	{
		for (x = 0; x < r; x++)
		{
			for (int i = 12, k = 1; (i <= 16 && k <= 5); k++, i++)
			{
				if (grid[x][y] == k && grid[x + 1][y] == k && grid[x + 2][y] == i) //for red  
				{
					smashwrap(grid, x + 2, y, score);
				}
				else if (grid[x][y] == k && grid[x + 1][y] == i && grid[x + 2][y] == k)
				{
					smashwrap(grid, x + 1, y, score);
				}
				else if (grid[x][y] == i && grid[x + 1][y] == k && grid[x + 2][y] == k)
				{
					smashwrap(grid, x, y, score);
				}
			}
		}
	}
}