#include "Caro.h"

#define MAXN 2000

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13

#define Lmax 1000
#define pb push_back

struct info BD;

/*
int p1 = 0, p2 = 0; // the point of two player;

int ExtendX = 0, ExtendY = 0; // Toa độ mở rộng

int XMain = Lmax, YMain = Lmax; // Toa do ô góc trái trên cùng

int CurrX = 0, CurrY = 0;
*/
void ChooseName(char *s1, char *s2,int GroundS, int WinS)
{
	CursorTrue();
	gotoxy(50, 14);
	Color(12);
	printf("ENTER NICKNAME OF PLAYER");
	Color(7);
	gotoxy(30, 18);
	printf("PLAYER 1: ");
	fgets(s1, 30, stdin);
	gotoxy(70, 18);
	Color(7);
	printf("PLAYER 2: ");
	fgets(s2, 30, stdin);
	ChooseTurn(s1, s2, GroundS, WinS);
}

void ChooseTurn(char *s1, char *s2 ,int GroundS, int WinS)
{
	int turn;
	gotoxy(45, 21);
	Color(12);
	printf("ENTER PLAYER WHO GO FIRST ? (1 / 2) ");
	Color(15);
	scanf_s("%d", &turn);
	system("cls");
	ChooseTime(s1, s2, turn, GroundS, WinS);
}

void ChooseTime(char *s1, char *s2,int turn, int GroundS, int WinS)
{
	int time;
	gotoxy(50, 14);
	Color(12);
	printf("ENTER TIME FOR EACH TURN");
	Color(7);
	gotoxy(52, 18);
	printf("CHOOSE TIME: ");
	scanf_s("%d", &time);
	system("cls");
	struct info X ;
	PvP(s1, s2, time, 0, 0, turn, GroundS, WinS, X, true);
}
// Hàm kiểm tra xem có chiến thắng hay không
int KiemTra(int x, int y, int SizeX, int SizeY, char **a)
{
	int Dem = 1;
	int Max = 0;
	int i = x;
	int j = y;
	char o1 = NULL, o2 = NULL;

	if (j == SizeY) o1 = ' ';

	while (j <= SizeY)
	{
		if (a[i][j] != a[x][y])
		{
			o1 = a[i][j];
			break;
		}
		j++;
		Max++;
	}
	j = y;
	Max--;
	if (j == 0) o2 = ' ';

	while (j >= 0)
	{
		if (a[i][j] != a[x][y])
		{
			o2 = a[i][j];
			break;
		}
		j--;
		Max++;
	}
	if (o1 != a[x][y] && o1 == o2 && o1 != ' ')
		Max = 0;
	Dem = max(Max, Dem);
	/*--------------------------------------------------------------*/
	Max = 0;
	j = y;
	if (i == SizeX) o1 = ' ';

	while (i <= SizeX)
	{
		if (a[i][j] != a[x][y])
		{
			o1 = a[i][j];
			break;
		}
		i++;
		Max++;
	}
	Max--;
	i = x;
	if (i == 0) o2 = ' ';
	while (i >= 0)
	{
		if (a[i][j] != a[x][y])
		{
			o2 = a[i][j];
			break;
		}
		i--;  
		Max++;
	}
	if (o1 != a[x][y] && o1 == o2 && o1 != ' ')
		Max = 0;
	Dem = max(Max, Dem);
	/*--------------------------------------------------------------*/
	Max = 0;
	i = x;
	j = y;
	if ((i == SizeX) || (j == SizeY))
		o1 = ' ';
	while ((i <= SizeX) && (j <= SizeY))
	{
		if (a[i][j] != a[x][y])
		{
			o1 = a[i][j];
			break;
		}
		i++;
		j++;
		Max++;
	}
	i = x;
	j = y;
	Max--;	
	if ((i == 0) || (j == 0))
		o2 = ' ';
	while ((i >= 0) && (j >= 0))
	{
		if (a[i][j] != a[x][y])
		{
			o2 = a[i][j];
			break;
		}
		i--;
		j--;
		Max++;
	}
	if (o1 != a[x][y] && o1 == o2 && o1 != ' ')
		Max = 0;
	Dem = max(Max, Dem);
	/*--------------------------------------------------------------*/
	Max = 0;
	i = x;
	j = y;
	if ((i == SizeX) || (j == 0))
		o1 = ' ';
	while ((i <= SizeX) && (j >= 0))
	{
		if (a[i][j] != a[x][y])
		{
			o1 = a[i][j];
			break;
		}
		i++;
		j--;
		Max++;
	}
	Max--;
	i = x;
	j = y;
	if ((i == 0) || (j == SizeY))
		o2 = ' ';
	while ((i >= 0) && (j <= SizeY))
	{
		if (a[i][j] != a[x][y])
		{
			o2 = a[i][j];
			break;
		}
		i--;
		j++;
		Max++;
	}
	if (o1 != a[x][y] && o1 == o2 && o1 != ' ')
		Max = 0;
	Dem = max(Max, Dem);

	return Dem;
}

void RefreshBoard(char **a,int XMain, int YMain)
{
	CursorFalse();
	int u = 2, v = 1;
	for (int i = XMain; i <= XMain + 16; i++)
	{
		for (int j = YMain; j <= YMain + 16; j++)
		{
			gotoxy(u, v);
			if (a[i][j] == 'X') Color(12);
			else Color(9);
			printf("%c", a[i][j]);
			v += 2;
		}
		u += 4; v = 1;
	}
	CursorTrue();
}

void Player1(int &x, int &y, char *s1, char *s2, int time, char **a, int p1, int p2, int &CurrX, int &CurrY, int &ExtendX, int &ExtendY, int &XMain, int &YMain,int GroundS, int WinS)
{
	gotoxy(90, 26);
	printf("                            ");
	Color(12);
	gotoxy(90, 13);
	printf("Area : ( %d , %d )", CurrX, CurrY);
	gotoxy(110, 28);
	printf("           ");
	bool wplace = false;
	gotoxy(x, y);
	int dem = 0;
	while (1)
	{
		while (!_kbhit())//Nếu không nhấn 1 phím nào trên bàn phím thì vòng lặp này vẫn tiếp tục chạy
		{
			Sleep(10);
			dem++;
			if ((dem / 80 <= time) && (dem % 80 == 0))
			{
				gotoxy(110, 15);
				printf("TIME : ");
				if (time - dem / 80 < 10)
					printf("0");
				printf("%d", time - dem / 80);
				gotoxy(x, y);
			}
			if (dem / 80 > time)
			{
				gotoxy(107, 15);
				printf("             ");
				gotoxy(107, 15);
				printf("END OF TIME!!!");
				for (int i = 0; i < 3; i++)
				{
					Beep(700,300);
					Sleep(500);
				}
				p2++;
				WinnerInform(2, s1, s2, time, p1, p2, GroundS, WinS);
				continue;
			}
		}
		char c = _getch();
		//------ENTER--------
		if (c == ENTER)
		{
			if (a[(x - 2) / 4 + Lmax + ExtendX][(y - 1) / 2 + Lmax + ExtendY] != ' ')
			{
				gotoxy(90, 17);
				Color(12);
				printf("THIS PLACE HAS BEEN MARKED!!!");
				gotoxy(x, y);
				Beep(700, 300);
				wplace = true;
				continue;
			}
			if (wplace)
			{
				wplace = false;
				gotoxy(90, 17);
				printf("                             ");
				gotoxy(x, y);
			}
			a[(x - 2) / 4 + Lmax + ExtendX][(y - 1) / 2 + Lmax + ExtendY] = 'X';
			Color(12);
			printf("X");
			BD.Col.pb((x - 2) / 4 + Lmax + ExtendX), BD.Row.pb((y - 1) / 2 + Lmax + ExtendY), BD.Value.pb(1);
			gotoxy(x, y);
			break;
		}

		//------MOVE---------
		switch (c)
		{
		case UP:
			if (y >= 3) y -= 2;
			else
			{
				ExtendY--; YMain--;
				RefreshBoard(a, XMain, YMain);
			}
			CurrY--;
			break;
		case DOWN:
			if (y <= 31) y += 2;
			else
			{
				ExtendY++; YMain++;
				RefreshBoard(a, XMain, YMain);
			}
			CurrY++;
			break;
		case RIGHT:
			if (x <= 64) x += 4;
			else
			{
				ExtendX++; XMain++;
				RefreshBoard(a, XMain, YMain);
			}
			CurrX++;
			break;
		case LEFT:
			if (x >= 6) x -= 4;
			else
			{
				ExtendX--; XMain--;
				RefreshBoard(a, XMain, YMain);
			}
			CurrX--;
			break;
		}

		//-------BACK & EXIT----------
		if (c == 27 || c == 8)// Exit
		{
			//CheckBE(71, 36, 51, 3, c);
			for (int i = 71; i <= 121; i++)
				for (int j = 36; j <= 38; j++)
				{
					gotoxy(i, j);
					printf(" ");
				}
			if (c == 27)
			{
				gotoxy(71 + 5, 36 + 1);
				printf("Do you want to exit this game ? (1 / 0)");
				char c1 = _getch();
				switch (c1) {
				case '1':
				{
					gotoxy(71 + 5, 36 + 1);
					printf("Do you want to save this match ? (1 / 0)");
					c1 = _getch();
					if (c1 == '1')
					{
						UpdateBD(s1, s2, p1, p2, x, y, XMain, YMain, time, 1);
						SaveGame(BD);
					}
					exit(0);
				}
				break;
				case '0':
				{
					Rectangle_NULL(71, 36, 51, 3);
					Back_Exit();
					gotoxy(x, y);
				}
				}
			}
			if (c == 8)
			{
				gotoxy(71 + 5, 36 + 1);
				printf("Do you want to back to Menu ? (1 / 0)");
				char c1 = _getch();
				switch (c1) {
				case '1':
				{
					gotoxy(71 + 5, 36 + 1);
					printf("Do you want to save this match ? (1 / 0)");
					c1 = _getch();
					if (c1 == '1')
					{
						UpdateBD(s1, s2, p1, p2, x, y, XMain, YMain, time , 1);
						SaveGame(BD);
					}
					system("cls");
					Menu(GroundS, WinS);
				}
				break;
				case '0':
				{
					Rectangle_NULL(71, 36, 51, 3);
					Back_Exit();
					gotoxy(x, y);
				}
				}
			}
		}

		//-----------UNDO-------------
		if (c == 'z' || c == 'Z')
		{
			char c1 = 8;
			while ((c1 != '1') && (c1 != '0'))
			{
				gotoxy(90, 30);
				printf("Do you agree ? (1 / 0)");
				c1 = _getch();
				switch (c1)
				{
				case '1':
					for (int i = 0; i < 2; i++)
					{
						int u = BD.Col.back();
						int v = BD.Row.back();
						a[u][v] = ' ';
						int u1 = 4 * (u - (ExtendX + Lmax)) + 2;
						int v1 = 2 * (v - (ExtendY + Lmax)) + 1;
						gotoxy(u1, v1);
						printf(" ");
						gotoxy(u1, v1);
						BD.Col.pop_back(); BD.Row.pop_back(); BD.Value.pop_back();
					}
					break;
				case '0': break;
				}
			}
			gotoxy(90, 30);
			printf("                           ");
			gotoxy(x, y);
		}
		
		CursorFalse();
		gotoxy(90, 13);
		printf("                            ");
		Color(12);
		gotoxy(90, 13);
		printf("Area : ( %d , %d )", CurrX, CurrY);
		gotoxy(x, y);
		CursorTrue();
	}
}

void Player2(int &x, int &y, char *s1, char *s2, int time, char **a, int p1 ,int p2, int &CurrX, int &CurrY, int &ExtendX, int &ExtendY, int &XMain, int &YMain,int GroundS, int WinS)
{
	gotoxy(90, 13);
	printf("                            ");
	Color(9);
	gotoxy(90, 26);
	printf("Area : ( %d , %d )", CurrX, CurrY);
	bool wplace = false;
	gotoxy(110, 15);
	printf("           ");
	gotoxy(x, y);
	int dem = 0;
	while (1)
	{
		while (!_kbhit())//Nếu không nhấn 1 phím nào trên bàn phím thì vòng lặp này vẫn tiếp tục chạy
		{
			Sleep(10);
			dem++;
			if ((dem / 80 <= time) && (dem % 80 == 0))
			{
				gotoxy(110, 28);
				printf("TIME : ");
				if (time - dem / 80 < 10)
					printf("0");
				printf("%d", time - dem / 80);
				gotoxy(x, y);
			}
			if (dem / 80 > time)
			{
				gotoxy(108, 28);
				printf("             ");
				gotoxy(108, 28);
				printf("END OF TIME!!!");
				for (int i = 0; i < 3; i++)
				{
					Beep(700, 300);
					Sleep(500);
				}
				p1++;
				WinnerInform(1, s1, s2, time, p1, p2, GroundS, WinS);
				continue;
			}
		}
		char c = _getch();
		//-------ENTER-------
		if (c == ' ')
		{
			if (a[(x - 2) / 4 + Lmax + ExtendX][(y - 1) / 2 + Lmax + ExtendY] != ' ')
			{
				gotoxy(90, 30);
				Color(9);
				printf("THIS PLACE HAS BEEN MARKED!!!");
				gotoxy(x, y);
				wplace = true;
				Beep(700, 300);
				continue;
			}

			if (wplace)
			{
				wplace = false;
				gotoxy(90, 30);
				printf("                             ");
				gotoxy(x, y);
			}
			a[(x - 2) / 4 + Lmax + ExtendX][(y - 1) / 2 + Lmax + ExtendY] = 'O';
			Color(9);
			printf("O");
			BD.Col.pb((x - 2) / 4 + Lmax + ExtendX), BD.Row.pb((y - 1) / 2 + Lmax + ExtendY), BD.Value.pb(0);
			gotoxy(x, y);
			break;
		}

		//-------MOVE--------
		switch (c)
		{
		case 'w': case 'W':
			if (y >= 3) y -= 2;
			else
			{
				ExtendY--; YMain--;
				RefreshBoard(a, XMain, YMain);
			}
			CurrY--;
			break;
		case 's': case 'S':
			if (y <= 31) y += 2;
			else
			{
				ExtendY++; YMain++;
				RefreshBoard(a, XMain, YMain);
			}
			CurrY++;
			break;
		case 'd': case 'D':
			if (x <= 64) x += 4;
			else
			{
				ExtendX++; XMain++;
				RefreshBoard(a, XMain, YMain);
			}
			CurrX++;
			break;
		case 'a': case 'A':
			if (x >= 6) x -= 4;
			else
			{
				ExtendX--; XMain--;
				RefreshBoard(a, XMain, YMain);
			}
			CurrX--;
			break;
		}

		//-------BACK & EXIT----------
		if (c == 27 || c == 8)// Exit
			{
				//CheckBE(71, 36, 51, 3, c);
				for (int i = 71; i <= 121; i++)
					for (int j = 36; j <= 38; j++)
					{
						gotoxy(i, j);
						printf(" ");
					}
				if (c == 27)
				{
					gotoxy(71 + 5, 36 + 1);
					printf("Do you want to exit this game ? (1 / 0)");
					char c1 = _getch();
					switch (c1) {
					case '1':
					{
						gotoxy(71 + 5, 36 + 1);
						printf("Do you want to save this match ? (1 / 0)");
						c1 = _getch();
						if (c1 == '1')
						{
							UpdateBD(s1, s2, p1, p2, x, y, XMain, YMain, time, 2);
							SaveGame(BD);
						}
						exit(0);
					}
					break;
					case '0':
					{
						Rectangle_NULL(71, 36, 51, 3);
						Back_Exit();
						gotoxy(x, y);
					}
					}
				}
				if (c == 8)
				{
					gotoxy(71 + 5, 36 + 1);
					printf("Do you want to back to Menu ? (1 / 0)");
					char c1 = _getch();
					switch (c1) {
					case '1':
					{
						gotoxy(71 + 5, 36 + 1);
						printf("Do you want to save this match ? (1 / 0)");
						c1 = _getch();
						if (c1 == '1')
						{
							UpdateBD(s1, s2, p1, p2, x, y, XMain, YMain, time, 2);
							SaveGame(BD);
						}
						system("cls");
						Menu(GroundS, WinS);
					}
					break;
					case '0':
					{
						Rectangle_NULL(71, 36, 51, 3);
						Back_Exit();
						gotoxy(x, y);
					}
					}
				}
			}

		//-----------UNDO-------------
		if (c == 'z' || c == 'Z')
		{
			char c1 = 8;
			while (c1 != '1' && c1 != '0')
			{
				gotoxy(90, 17);
				printf("Do you agree ? (1 / 0)");
				c1 = _getch();
				switch (c1)
				{
				case '1':
					for (int i = 0; i < 2; i++)
					{
						int u = BD.Col.back();
						int v = BD.Row.back();
						a[u][v] = ' ';
						int u1 = 4 * (u - (ExtendX + Lmax)) + 2;
						int v1 = 2 * (v - (ExtendY + Lmax)) + 1;
						gotoxy(u1, v1);
						printf(" ");
						gotoxy(u1, v1);
						BD.Col.pop_back(); BD.Row.pop_back(); BD.Value.pop_back();
					}
					break;
				case '0': break;
				}
			}
			gotoxy(90, 17);
			printf("                               ");
			gotoxy(x, y);
		}

		CursorFalse();
		gotoxy(90, 26);
		printf("                            ");
		Color(9);
		gotoxy(90, 26);
		printf("Area : ( %d , %d )", CurrX, CurrY);
		gotoxy(x, y);
		CursorTrue();
	}
}

void WinnerInform(int p ,char *s1, char *s2, int time, int p1, int p2, int GroundS, int WinS)
{
	if (WinS == 1) PlaySound(TEXT("Winner.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Color(14);
	int x, y;
	char c;
	gotoxy(0, 35);
	printf("%c", 201);
	for (int i = 0; i <= 50; i++)
	{
		printf("%c", 205);
	}
	gotoxy(51, 35);
	printf("%c", 187);
	y = 35;
	for (int i = 0; i <= 4; i++)
	{
		y++;
		gotoxy(51, y);
		printf("%c", 186);
	}
	gotoxy(51, 40);
	printf("%c", 188);
	x = 51;
	for (int i = 0; i <= 50; i++)
	{
		x--;
		gotoxy(x, 40);
		printf("%c", 205);
	}
	gotoxy(0, 40);
	printf("%c", 200);
	y = 40;
	for (int i = 0; i <= 3; i++)
	{
		y--;
		gotoxy(0, y);
		printf("%c", 186);
	}
	gotoxy(13, 36);
	printf("DO YOU WANT TO PLAY AGAIN?");
	gotoxy(16, 38);
	printf("YES");
	gotoxy(33, 38);
	printf("NO");
	Sleep(100);
	//------------REFRESH INFORM BOX---------
	// Box 1
	Color(12);
	for (int i = 71 ; i<= 121 ;i++)
		for (int j = 10; j <= 20; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	gotoxy(87, 9);
	printf("%c", 205);
	gotoxy(87, 21);
	printf("%c", 205);

	// Box 2
	Color(9);
	for (int i = 71; i <= 121; i++)
		for (int j = 23; j <= 33; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	gotoxy(87, 22);
	printf("%c", 205);
	gotoxy(87, 34);
	printf("%c", 205);
	//--------------------------------------
	if (p == 1)
	{
		Winner(77, 13, 12);
		Loser(77, 26, 9);
	}
	else
	{
		Loser(77, 13, 12);
		Winner(77, 26, 9);
	}
	//--------------------------------------
	gotoxy(16, 38);
	x = 16; y = 38;
	c = _getch();
	while (c != 13)
	{
		c = _getch();
		switch (c)
		{
		case LEFT: if (x > 16)
			x -= 17;
			break;
		case RIGHT: if (x < 46)
			x += 17;
			break;
		}
		gotoxy(x, 38);
	}
	if (c == 13)
	{
		if (x == 16)
		{
			system("cls");
			struct info XX;
			PvP(s1, s2, time, p1, p2, p, GroundS, WinS ,XX , true);
		}
		if (x == 33)
		{
			p1 = p2 = 0;
			system("cls");
			Menu(GroundS, WinS);
		}
	}
}

void PvP(char *s1, char *s2, int time, int p1, int p2, int turn, int GroundS, int WinS, info XXX, bool pAgain)
{
	//-------------------
	//int p1 = 0, p2 = 0; // the point of two player;

	int ExtendX = 0, ExtendY = 0; // Toa độ mở rộng

	int XMain = Lmax, YMain = Lmax; // Toa do ô góc trái trên cùng

	int CurrX = 0, CurrY = 0;

	int x = 34, y = 17;

	char **a = NULL;
	a = new char*[MAXN];
	for (int i = 0; i <= MAXN; ++i)
	{
		a[i] = new char[MAXN];
		for (int j = 0; j <= MAXN; ++j)
			a[i][j] = ' ';
	}
	//--------------------
	PlaySound(NULL, NULL, 0);

	if (!pAgain)
	{
		XMain = XXX.OriX, YMain = XXX.OriY;
		x = XXX.CoorX, y = XXX.CoorY;
		CurrX = (x - 2) / 4 + XMain - 1008;
		CurrY = (y - 1) / 2 + YMain - 1008;
		for (int i = 0; i < XXX.Col.size(); i++)
		{
			int u = XXX.Col[i];
			int v = XXX.Row[i];
			int uv = XXX.Value[i];
			a[u][v] = (uv == 1) ? 'X' : 'O';
			BD.Col.pb(u); BD.Row.pb(v); BD.Value.pb(uv);
		}
		turn = XXX.turn;
	}

	DrawChessBoard();
	Point_Form(p1, p2);

	Inform_Form(1, 12, 70, 9, s1); DrawControl1();
	Inform_Form(2, 9, 70, 22, s2); DrawControl2();

	Back_Exit();

	RefreshBoard(a, XMain, YMain);

	CursorTrue();
	int max1 = 0, max2 = 0;
	Color(12);
	gotoxy(90, 13);
	printf("Area : ( %d , %d )", CurrX, CurrY);
	gotoxy(x, y);
	int point;
	while (1)
	{
		if (turn == 1)
		{
			Player1(x, y, s1, s2, time, a, p1, p2, CurrX, CurrY, ExtendX, ExtendY, XMain, YMain, GroundS, WinS);
			point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN, a);
			if (point >= 5) p1++, WinnerInform(1, s1, s2, time, p1, p2, GroundS, WinS);
			Player2(x, y, s1, s2, time, a, p1, p2, CurrX, CurrY, ExtendX, ExtendY, XMain, YMain, GroundS, WinS);
			point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN, a);
			if (point >= 5) p2++, WinnerInform(2, s1, s2, time, p1, p2, GroundS, WinS);
		}
		if (turn == 2)
		{
			Player2(x, y, s1, s2, time, a, p1, p2, CurrX, CurrY, ExtendX, ExtendY, XMain, YMain, GroundS, WinS);
			point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN, a);
			if (point >= 5) p2++, WinnerInform(2, s1, s2, time, p1, p2, GroundS, WinS);
			Player1(x, y, s1, s2, time, a, p1, p2, CurrX, CurrY, ExtendX, ExtendY, XMain, YMain, GroundS, WinS);
			point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN, a);
			if (point >= 5) p1++, WinnerInform(1, s1, s2, time, p1, p2, GroundS, WinS);
		}
	}
	
}
