#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <mmsystem.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <queue>

using namespace std;

struct info {
	int Point1, Point2;// Point od two players
	char *Name1, *Name2;// Name of two players
	vector <int> Col, Row, Value; // Toa do va gia tri cua cac o duoc danh
	int OriX, OriY;// Toa do góc trái trên
	int CoorX, CoorY; // The area of cursor 
	int Time, turn;
} ;

extern struct info BD;
extern vector <info> X;
// Format
void gotoxy(int x, int y);
void Color(int n);
void CursorTrue();
void CursorFalse();

void Loading();

void Menu(int GroundS, int WinS);

void PickKind(int GroundS, int WinS);
void PickMenu(int GroundS, int WinS);
void DrawMenu();
void DrawControl1();
void DrawControl2();
void DrawChessBoard();
void Rectangle_NULL(int X, int Y, int length, int width);
void Rectangle(int X, int Y, int length, int width, int c1, int c2, int c3, int c4);

void Point_Form(int p1, int p2);
void Inform_Form(int player, int color, int X, int Y, char *s);

void Winner(int X ,int Y,int color);
void Loser (int X ,int Y,int color);

void ChooseName(char *s1, char *s2,int GroundS, int WinS);
void ChooseTurn(char *s1, char *s2, int GroundS, int WinS);
void ChooseTime(char *s1, char *s2, int turn, int GroundS, int WinS);
void WinnerInform(int p, char *s1, char *s2, int time, int p1, int p2,int GroundS,int WinS);

void PvC(int GroundS, int WinS);
void PvP(char *s1, char *s2, int time, int p1, int p2, int turn, int GroundS, int WinS, info XXX, bool pAgain);


void Back_Exit();
void UpdateBD(char *s1, char *s2, int p1, int p2, int x, int y, int XMain, int YMain, int time, int turn);
void SaveGame(info x);
void LoadGame();

void Option(int &WinS, int &GroundS);
void About(int GroundS, int WinS);
void Introduction( int GroundS, int WinS);
void Sound();

