#include "Caro.h"

void Option(int &GroundS, int &WinS)
{
	int X = 50, Y = 14;
	Color(10);
	gotoxy(X, Y);
	printf("1. About author");
	Color(15);
	gotoxy(X, Y + 3);
	printf("2. Introduction");
	gotoxy(X, Y + 6);
	printf("3. Sound ");
	//gotoxy(X, Y + 9);
	//printf("4. Optimize rule of game");
	gotoxy(100, 35);
	printf("[ Back - Backspace ]");
	char c = 8;
	int x, y;
	x == X, y = Y;
	while (c != 13)
	{
		c = _getch();
		switch (c)
		{
		case 72: if (y > 14)
			y -= 3;
			break;
		case 80: if (y < 20)
			y += 3;
			break;
		case 8:
			system("cls");
			Menu(GroundS , WinS);
		}
		Color(15);
		gotoxy(X, Y);
		if (y == Y) Color(10);
		printf("1. About author");
		Color(15);
		gotoxy(X, Y + 3);
		if (y == Y + 3) Color(10);
		printf("2. Introduction");
		Color(15);
		gotoxy(X, Y + 6);
		if (y == Y + 6) Color(10);
		printf("3. Sound ");
		Color(15);
		gotoxy(X, Y + 9);
		//if (y == Y + 9) Color(10);
		//printf("4. Optimize rule of game");
	}
	system("cls");
	if (y == Y) About(GroundS, WinS);
	if (y == Y + 3) Introduction(GroundS, WinS);
	if (y == Y + 6) Sound();
	//if (y == Y + 9) Optimize();
}

void About(int GroundS, int WinS)
{
	int X = 50, Y = 14;
	Color(10);
	gotoxy(X, Y);
	printf("Name: ");
	Color(15);
	printf("PHAM BANG DANG");
	Color(10);
	gotoxy(X, Y + 2);
	printf("ID Student: ");
	Color(15);
	printf("18125125");
	Color(10);
	gotoxy(X, Y + 4);
	printf("Relationship: ");
	Color(15);
	printf("Single^^");
	Color(10);
	gotoxy(X, Y + 6);
	printf("Hobby: ");
	Color(15);
	printf("Learning CS161 ( just kidding )");
	gotoxy(100, 35);
	printf("[ Back - Backspace ]");
	char c = 8;
	while (1)
	{
		c = _getch();
		if (c == 8)
		{
			system("cls");
			Option(GroundS, WinS);
		}
	}
}

void Introduction(int GroundS, int WinS)
{
	int X = 40, Y = 8;
	Color(10);
	gotoxy(X, Y);
	printf("1. About normal rule: ");
	Color(15);
	gotoxy(X + 2, Y + 2);
	printf("** STILL SPACES");
	gotoxy(X + 2, Y + 4);
	printf("    Any player who gets 5 point in straight line, horizontal, cross");
	gotoxy(X + 2, Y + 6);
	printf("	without being blocked will win");
	gotoxy(X + 2, Y + 8);
	printf("** END OF TIME");
	gotoxy(X + 2, Y + 10);
	printf("	If player runs out of time will be lose");
	

	Color(10);
	gotoxy(X, Y + 13);
	printf("1. How to play: ");
	Color(15);
	gotoxy(X + 2, Y + 15);
	printf("** PLAYER 1:");
	gotoxy(X + 2, Y + 17);
	printf("   ^ : UP");
	gotoxy(X + 2, Y + 19);
	printf("   v : DOWN");
	gotoxy(X + 2, Y + 21);
	printf("   > : RIGHT");
	gotoxy(X + 2, Y + 23);
	printf("   < : LEFT");
	gotoxy(X + 2, Y + 25);
	printf("   ENTER : CHOOSE");
	gotoxy(X + 25, Y + 15);
	printf("** PLAYER 2:");
	gotoxy(X + 25, Y + 17);
	printf("   W : UP");
	gotoxy(X + 25, Y + 19);
	printf("   S : DOWN");
	gotoxy(X + 25, Y + 21);
	printf("   D : RIGHT");
	gotoxy(X + 25, Y + 23);
	printf("   A : LEFT");
	gotoxy(X + 25, Y + 25);
	printf("   SPACE : CHOOSE");
	

	gotoxy(100, 35);
	printf("[ Back - Backspace ]");
	char c = 8;
	while (1)
	{
		c = _getch();
		if (c == 8)
		{
			system("cls");
			Option(GroundS, WinS);
		}
	}
}

void Sound()
{
	ifstream inp;
	ofstream out;
	inp.open("sound.txt");
	int X = 50, Y = 14;
	gotoxy(X, Y);
	Color(10);
	printf("1. Sound in background ");
	gotoxy(X, Y + 2);
	printf("2. Sound in Winning    ");
	gotoxy(X, Y + 4);
	printf("   ( 1 is ON, 0 is OFF )");
	gotoxy(100, 35);
	printf("[ Back - Backspace ]");
	int u, v;
	inp >> u >> v;
	inp.close();
	out.open("sound.txt");
	Color(15);
	gotoxy(X + 25, Y);
	printf("%d", u);
	gotoxy(X + 25, Y + 2);
	printf("%d", v);
	int x, y;
	x = X + 25, y = Y;
	gotoxy(x, y);
	CursorTrue();
	char c = 8;
	while (c != 13)
	{
		c = _getch();
		switch (c)
		{
		case 72: if (y > 14)
			y -= 2;
			break;
		case 80: if (y < 16)
			y += 2;
			break;
		case 8:
			system("cls");
			out << u << "\n" << v;
			out.close();
			Option(u, v);
			break;
		case '1':
			gotoxy(x, y);
			if (y == 14) u = 1;
			else v = 1;
			printf("1");
			gotoxy(x, y);
			break;
		case '0':
			gotoxy(x, y);
			if (y == 14) u = 0;
			else v = 0;
			printf("0");
			gotoxy(x, y);
			break;
		default:
			gotoxy(x, y);
		}
		gotoxy(x, y);
	}
	system("cls");
	out << u << "\n" << v;
	out.close();
	Option(u, v);
}