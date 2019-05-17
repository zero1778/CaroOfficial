#include "Caro.h"

void Block(int x, int y)
{
	gotoxy(x, y);
	for (int i = 1; i <= 5; i++)
	{
		gotoxy(x, y + i);
		for (int i = 1; i <= 6; i++)
		{
			printf("%c", 219);
		}
	}
}

void Loading()
{
	Color(10);
	int X = 35;
	int Y = 15;
	gotoxy(X, Y);
	for (int i = 1; i <= 61; i++)
	{
		printf("%c", 219);
	}
	gotoxy(X, Y + 10);
	for (int i = 1; i <= 60; i++)
	{
		printf("%c", 219);
	}
	gotoxy(X, Y);
	for (int i = 1; i <= 10; i++)
	{
		gotoxy(X, Y + i);
		printf("%c%c", 219, 219);
	}
	gotoxy(X + 59, Y);
	for (int i = 1; i <= 10; i++)
	{
		gotoxy(X + 59, Y + i);
		printf("%c%c", 219, 219);
	}
	int dem = X + 3;
	for (int i = 1; i <= 8; i++)
	{
		Sleep(7);
		Block(dem, Y + 2);
		dem += 7;
	}
}