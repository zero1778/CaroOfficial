#include "Caro.h"


void DrawC()
{
	int XO = 45, YO = 5;
	Color(12);
	int x, y;
	x = XO; y = YO;
	for (int i = 0; i < 2; i++) {
		x += 0; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c", 240, 240, 240, 240, 240, 240, 240);

	}

	x = XO - 17; y = YO - 3;
	for (int i = 5; i >2; i--) {
		y += 1; x = x - 2;
		gotoxy(x, y);
		for (int j = 0; j <= 41 - 4 * i; j++) {
			printf("%c", 240);


		}
	}

	x = XO - 23; y = YO;
	for (int i = 0; i < 15; i++) {
		x += 0; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c", 240, 240, 240, 240, 240, 240, 240);

	}
	x = XO - 25; y = YO + 14;
	for (int i = 5; i >2; i--) {
		y += 1; x = x + 2;
		gotoxy(x, y);
		for (int j = 0; j <= 9 + 4 * i; j++) {
			printf("%c", 240);


		}
	}
	x = XO; y = YO + 12;
	for (int i = 0; i < 3; i++) {
		x += 0; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c", 240, 240, 240, 240, 240, 240, 240);

	}
}
void DrawA() 
{
	int XO = 45, YO = 5;
	int x, y;
	Color(14);
	x = XO + 7; y = YO + 2;
	for (int i = 0; i <= 10; i++) {
		x -= 2; y += 1;
		gotoxy(x, y);
		printf("%c%c%c", 240, 240, 240);

	}
	y = YO + 2;
	for (int i = 0; i <= 9; i++) {
		y += 1;
		gotoxy(XO + 8, y);
		printf("%c%c%c%c", 240, 240, 240, 240);

	}
	x = XO - 3; y = YO + 7;
	for (int i = 0; i < 2; i++) {
		x -= 1; y += 1;
		gotoxy(x, y);
		for (int i = 0; i <= 12; i++) {
			printf("%c", 240);


		}
	}
}
void DrawR() 
{
	int XO = 45, YO = 5;
	int x, y;
	Color(10);
	y = YO;
	for (int i = 0; i <= 11; i++) 
	{
		y += 1;
		gotoxy(XO + 13, y);
		printf("%c%c%c%c%c", 240, 240, 240, 240, 240);
	}
	gotoxy(XO + 18, YO + 1);
	for (int i = 0; i <= 7; i++) printf("%c", 240);

	gotoxy(XO + 18, YO + 7);
	for (int i = 0; i <= 7; i++) printf("%c", 240);

	gotoxy(XO + 26, YO + 2);
	printf("%c%c", 240, 240);
	gotoxy(XO + 27, YO + 3);
	printf("%c%c", 240, 240);
	gotoxy(XO + 28, YO + 4);
	printf("%c%c", 240, 240);
	gotoxy(XO + 27, YO + 5);
	printf("%c%c", 240, 240);
	gotoxy(XO + 26, YO + 6);
	printf("%c%c", 240, 240);
	x = XO + 14; y = YO + 6;
	for (int i = 0; i <= 5; i++) 
	{
		x += 2; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c", 240, 240, 240, 240);
	}
}
void DrawO() 
{
	int XO = 45, YO = 5;
	Color(9);
	int x, y;
	x = XO + 31; y = YO - 3;

	for (int i = 5; i >2; i--) {
		y += 1; x = x - 2;
		gotoxy(x, y);
		for (int j = 0; j <= 42 - 4 * i; j++) {
			printf("%c", 240);


		}
	}
	x = XO + 25; y = YO;
	for (int i = 0; i < 15; i++) {
		x += 0; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c", 240, 240, 240, 240, 240, 240, 240);

	}
	x = XO + 23; y = YO + 14;
	for (int i = 5; i >2; i--) {
		y += 1; x = x + 2;
		gotoxy(x, y);
		for (int j = 0; j <= 10 + 4 * i; j++) {
			printf("%c", 240);


		}
	}
	x = XO + 49; y = YO;
	for (int i = 0; i < 15; i++) {
		x += 0; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c", 240, 240, 240, 240, 240, 240, 240);

	}
	Color(12);
	x = XO + 31; y = YO;
	for (int i = 0; i <= 13; i++) {
		x += 1; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c", 240, 240, 240, 240);

	}
	x = XO + 46; y = YO;
	for (int i = 0; i <= 13; i++) {
		x -= 1; y += 1;
		gotoxy(x, y);
		printf("%c%c%c%c", 240, 240, 240, 240);
	}
	Color(7);
	gotoxy(XO + 35, YO + 18);
	printf("*Created by Danniel Billiant*");
}

void DrawMenu()
{
	
	DrawC();
	DrawA();
	DrawO();
	DrawR();

	int XO = 47, YO = 21;
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
}


// Hàm này ve phan trên của bàn cờ 
void Vedongtren(int n)
{
	printf("%c", 201);
	for (int i = 0; i <= n; i++) {
		printf("%c%c%c%c", 196, 196, 196, 194);
	}
	printf("%c%c%c%c", 196, 196, 196, 187);
}
// Hàm này dùng để vẽ ô 
void Ve_O_Giao_Dien(int n)
{
	for (int i = 0; i <= n + 2; ++i) {
		printf("%c   ", 179);
	}
}
// Hàm này để vẽ dòng dưới của mỗi ô
void Ve_dong_Giao_dien(int n)
{
	printf("%c", 204);
	for (int i = 0; i <= n; i++) {
		printf("%c%c%c%c", 196, 196, 196, 197);
	}
	printf("%c%c%c%c", 196, 196, 196, 185);
}
// Hàm này dùng để vẽ đường dưới của bàn cờ
void Vedongduoi(int n)
{
	printf("%c", 200);
	for (int i = 0; i <= n; i++) {
		printf("%c%c%c%c", 196, 196, 196, 193);
	}
	printf("%c%c%c%c", 196, 196, 196, 188);
}

// Hàm để vẽ khung
void Rectangle(int X, int Y, int length, int width, int c1, int c2, int c3, int c4)
{
	//--------1st side---------
	Color(c1);
	gotoxy(X, Y);
	printf("%c", 201);
	for (int i = 1; i <= length - 2; i++)
	{
		printf("%c", 205);
	}

	//--------2nd side---------
	Color(c2);
	gotoxy(X + length - 1, Y); 
	printf("%c", 187);
	int y = Y;
	for (int i = 1; i <= width - 2; i++)
	{
		y++;
		gotoxy(X + length - 1, y);
		printf("%c", 186);
	}

	//--------3rd side---------
	Color(c3);
	gotoxy(X + length - 1, Y + width - 1);
	printf("%c", 188);
	int x = X + length - 1;
	for (int i = 1; i <= length - 2; i++)
	{
		x--;
		gotoxy(x, Y + width - 1);
		printf("%c", 205);
	}

	//--------4nd side---------
	Color(c4);
	gotoxy(X, Y + width - 1);
	printf("%c", 200);
	y = Y + width - 1;
	for (int i = 1; i <= width - 2; i++)
	{
		y--;
		gotoxy(X, y);
		printf("%c", 186);
	}

}
void Rectangle_NULL(int X, int Y, int length, int width)
{
	for (int i = X; i <= X + length - 2 ;i++)
		for (int j = Y; j <= Y + width - 2; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
}

void DrawChessBoard()
{
	Color(11);
	gotoxy(0, 0);
	Vedongtren(15);
	int y = 0;
	for (int i = 0; i <= 15; i++)
	{
		y++;
		gotoxy(0, y);
		Ve_O_Giao_Dien(15);
		y++;
		gotoxy(0, y);
		Ve_dong_Giao_dien(15);
	}
	gotoxy(0, 33);
	Ve_O_Giao_Dien(15);
	gotoxy(0, 34);
	Vedongduoi(15);
}

void DrawControl1()
{
	gotoxy(72, 11);
	printf("^ : UP");
	gotoxy(72, 13);
	printf("v : DOWN");
	gotoxy(72, 15);
	printf("> : RIGHT");
	gotoxy(72, 17);
	printf("< : LEFT");
	gotoxy(72, 19);
	printf("ENTER : CHOOSE");
}

void DrawControl2()
{
	gotoxy(72, 24);
	printf("w : UP");
	gotoxy(72, 26);
	printf("s : DOWN");
	gotoxy(72, 28);
	printf("d : RIGHT");
	gotoxy(72, 30);
	printf("a : LEFT");
	gotoxy(72, 32);
	printf("SPACE : CHOOSE");
}

// This function draw the Point of players
void Point_Form(int p1, int p2)
{
	Rectangle(70, 0, 53, 9, 14, 14, 14, 14);
	gotoxy(94, 2);
	printf("SCORE");
	gotoxy(77, 4);
	Color(12);
	printf("PLAYER 1:  %d", p1);
	gotoxy(107, 4);
	Color(9);
	printf("PLAYER 2:  %d", p2);
}

// This function draw the information of players
void Inform_Form(int player, int color ,int X ,int Y ,char *s)
{
	Color(color);
	gotoxy(X, Y);
	printf("%c", 201);
	for (int i = 0; i <= 50; i++)
	{
		printf("%c", 205);
	}
	gotoxy(X + 52, Y);
	printf("%c", 187);
	int y = Y;
	for (int i = 0; i <= 11; i++)
	{
		y++;
		gotoxy(X + 52, y);
		printf("%c", 186);
	}
	gotoxy(X + 52, Y + 12);
	printf("%c", 188);
	int x = X + 52;
	for (int i = 0; i <= 50; i++)
	{
		x--;
		gotoxy(x, Y + 12);
		printf("%c", 205);
	}
	gotoxy(X, Y + 12);
	printf("%c", 200);
	y = Y + 12;
	for (int i = 0; i <= 10; i++)
	{
		y--;
		gotoxy(X, y);
		printf("%c", 186);
	}

	gotoxy(X + 17, Y);
	printf("%c", 203);
	y = Y + 1;
	for (int i = 0 ; i <= 10; i++)
	{
		gotoxy(X + 17, y + i);
		printf("%c", 186);
	}
	gotoxy(X + 17, Y + 12);
	printf("%c", 202);

	gotoxy(X + 20, Y + 2);
	printf("Player%d : %s", player, s);

	Color(color);
	gotoxy(X + 20, Y + 6);
	if (s != "COMPUTER") printf("***UNDO : Z");
} 

void Winner(int X, int Y, int color)
{
	Color(color);
	gotoxy(X, Y);
	printf("***     *****     *** *** ******   ***");
	gotoxy(X, Y + 1);
	printf(" ***   *** ***   ***  *** *** ***  ***");
	gotoxy(X, Y + 2);
	printf("  *** ***   *** ***   *** ***  *** ***");
	gotoxy(X, Y + 3);
	printf("   *****     *****    *** ***   ******");
}
void Loser(int X, int Y, int color)
{
	Color(color);
	gotoxy(X, Y);
	printf("***      ********* ********* *********");
	gotoxy(X, Y + 1);
	printf("***      ***   *** ***       **");
	gotoxy(X, Y + 2);
	printf("***      ***   *** ********* *********");
	gotoxy(X, Y + 3);
	printf("******** ***   ***       *** **");
	gotoxy(X, Y + 4);
	printf("******** ********* ********* *********");
}

void Back_Exit()
{
	int X = 70, Y = 35;
	Rectangle(X, Y, 53, 5, 15, 15, 15, 15);
	gotoxy(X + 7, Y + 2);
	printf("Back - Backspace");
	gotoxy(X + 35, Y + 2);
	printf("Exit - Esc");
}






