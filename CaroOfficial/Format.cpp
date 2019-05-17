#include "Caro.h"


// Control the point to any coordinate
void gotoxy(int x, int y) {
	COORD cor;
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
// Change the color of text
void Color(int n) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

// Unhide the Cursor
void CursorFalse()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Hide the Cursor
void CursorTrue()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void UpdateBD(char *s1,char *s2,int p1,int p2,int x,int y,int XMain,int YMain, int time, int turn)
{
	BD.Name1 = s1, BD.Name2 = s2;
	BD.Point1 = p1, BD.Point2 = p2;
	BD.CoorX = x, BD.CoorY = y;
	BD.OriX = XMain, BD.OriY = YMain;
	BD.Time = time; BD.turn = turn;
	// Pham Bang Dang
}


