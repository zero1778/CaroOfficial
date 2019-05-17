#include "Caro.h"

void Menu(int GroundS, int WinS)
{
	if (GroundS == 1) PlaySound(TEXT("Game-Menu_Looping.wav"), NULL, SND_FILENAME | SND_ASYNC);
	CursorFalse();
	DrawMenu();	
	PickMenu(GroundS, WinS);
}

void PickKind(int GroundS, int WinS)
{
	int XO = 47, YO = 21;
	gotoxy(XO + 3, YO + 5);
	Color(14);
	printf("    1. Player vs Player");
	gotoxy(XO + 3, YO + 8);
	Color(3);
	printf("    2. Player vs Computer");
	int y = 26;
	char chon = 8;
	while (chon != 13)
	{
		chon = _getch();
		switch (chon)
		{
		case 72: if (y > 26)
			y -= 3;
			break;
		case 80: if (y < 29)
			y += 3;
			break;
		case 8: 
			Rectangle_NULL(XO, YO + 5, 55, 30);
			gotoxy(XO + 7, YO + 5);
			Color(14);
			printf("    NEW GAME");
			gotoxy(XO + 7, YO + 8);
			Color(3);
			printf("    LOAD GAME ");
			Color(9);
			gotoxy(XO + 7, YO + 11);
			Color(3);
			printf("   GAME OPTION");
			gotoxy(XO + 7, YO + 14);
			Color(3);
			printf("    EXIT GAME");
			Color(12);
			gotoxy(XO + 6, YO + 5);
			printf(">");
			gotoxy(XO + 23, YO + 5);
			printf("<");
			PickMenu(GroundS, WinS);
			break;
		
		}
		gotoxy(XO + 3, YO + 5);
		Color(3);
		if (y == YO + 5) Color(14);
		printf("    1. Player vs Player");
		gotoxy(XO + 3, YO + 8);
		Color(3);
		if (y == YO + 8) Color(14);
		printf("    2. Player vs Computer");

	}
	if (y == YO + 5)
	{
		char s1[50], s2[50];
		system("cls");
		ChooseName(s1, s2, GroundS, WinS);
	}
	else PvC(GroundS, WinS);
}

void PickMenu(int GroundS, int WinS)
{
	int XO = 47, YO = 21;
	char chon;
	chon = _getch();
	int y = 26;
	while (chon != 13)
	{
		chon = _getch();
		switch (chon)
		{
		case 72: if (y > 26)
			y -= 3;
			break;
		case 80: if (y < 35)
			y += 3;
			break;
		}
		gotoxy(XO + 7, YO + 5);
		Color(3);
		if (y == YO + 5) Color(14);
		printf("    NEW GAME");
		gotoxy(XO + 7, YO + 8);
		Color(3);
		printf("    LOAD GAME ");
		gotoxy(XO + 7, YO + 11);
		Color(3);
		printf("   GAME OPTION");
		gotoxy(XO + 7, YO + 14);
		Color(3);
		printf("    EXIT GAME");
		gotoxy(XO + 6, YO + 5);
		printf(" ");
		gotoxy(XO + 6, YO + 8);
		printf(" ");
		gotoxy(XO + 6, YO + 11);
		printf(" ");
		gotoxy(XO + 6, YO + 14);
		printf(" ");
		gotoxy(XO + 23, YO + 5);
		printf(" ");
		gotoxy(XO + 24, YO + 8);
		printf(" ");
		gotoxy(XO + 23, YO + 11);
		printf(" ");
		gotoxy(XO + 23, YO + 14);
		printf(" ");
		if (y == YO + 5)
		{
			Color(12);
			gotoxy(XO + 6, YO + 5);
			printf(">");
			gotoxy(XO + 23, YO + 5);
			printf("<");

			//---
			gotoxy(XO + 7, YO + 5);
			Color(14);
			printf("    NEW GAME");
			gotoxy(1, 1);
		}
		if (y == YO + 8)
		{
			Color(12);
			gotoxy(XO + 6, YO + 8);
			printf(">");
			gotoxy(XO + 24, YO + 8);
			printf("<");

			//---
			gotoxy(XO + 7, YO + 8);
			Color(14);
			printf("    LOAD GAME ");
			gotoxy(1, 1);
		}
		if (y == YO + 11)
		{
			Color(12);
			gotoxy(XO + 6, YO + 11);
			printf(">");
			gotoxy(XO + 23, YO + 11);
			printf("<");

			//---
			gotoxy(XO + 7, YO + 11);
			Color(14);
			printf("   GAME OPTION");
			gotoxy(1, 1);
		}
		if (y == YO + 14)
		{
			Color(12);
			gotoxy(XO + 6, YO + 14);
			printf(">");
			gotoxy(XO + 23, YO + 14);
			printf("<");

			//---
			gotoxy(XO + 7, YO + 14);
			Color(14);
			printf("    EXIT GAME");
			gotoxy(1, 1);
		}
	}
	if (chon == 13)
	{
		if (y == YO + 5)
		{
			Rectangle_NULL(XO, YO + 5, 55, 30);
			PickKind(GroundS, WinS);
		}
		else if (y == YO + 8)
		{
			system("cls");
			LoadGame();
		}
		else if (y == YO + 11)
		{
			system("cls");
			Option(GroundS, WinS);
		}
		else exit(0);
	}
}