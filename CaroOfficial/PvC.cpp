#include "Caro.h"

#define MAXN 2000

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13

#define Lmax 1000
#define pb push_back

typedef pair <int, int> ii;

struct ioi
{
	int X, Y, Value;
};

static char a[MAXN][MAXN];

static int p1 = 0, p2 = 0; // the point of two player;

static int ExtendX = 0, ExtendY = 0; // Toa độ mở rộng

static int XMain = Lmax, YMain = Lmax; // Toa do ô góc trái trên cùng

static int CurrX = 0, CurrY = 0;
static char *s1 = "YOU", *s2 = "COMPUTER";

int COL[9] = { 1 ,1 ,0, 1 , -1 , -1, 0, -1 , 0 };
int ROW[9] = { 0 ,1 ,1 ,-1, 0, -1, -1, 1 , 0 };

const int MaxDepth = 7;
const int XX = 1008, YY = 1008;
int Delta = 20;
const int INF = 1000000000 + 7;
static int XO = 47, YO = 21;
bool PlayAgain = false;
int mode; // che do choi

//mảng điểm tấn công
int Attack[5] = { 0, 9, 54, 162, 1458 };// { 0, 2, 18, 162, 1458 };//{ 0, 9, 54, 162, 1458, 13112, 118008 };
//mảng điểm phòng ngự
int Defense[5] = { 0, 3, 27, 99, 729 };// { 0, 1, 9, 81, 729 };//{ 0, 3, 27, 99, 729, 6561, 59049 };
// 1 Human
// 2 Computer

static void RefreshBoard()
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

static int KiemTra(int x, int y, int SizeX, int SizeY)
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

static void WinnerInform(int p, char *s1, char *s2,int GroundS, int WinS)
{
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
	//------------REFRESH INFORM BOX---------
	// Box 1
	Color(12);
	for (int i = 71; i <= 121; i++)
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
			CurrX = CurrY = 0;
			PlayAgain = true;
			PvC(GroundS, WinS);
		}
		if (x == 33)
		{
			p1 = p2 = 0;
			system("cls");
			Menu(GroundS, WinS);
		}
	}
}

void Save(string t, int p1, int p2)
{
	int t1, t2;
	ifstream inp;
	inp.open(t + ".txt");
	inp >> t1 >> t2;
	inp.close();

	ofstream out;
	out.open(t + ".txt");
	out << p1 + t1 << " " << p1 + p2 + t2;
	out.close();
}

void Player(int &x, int &y, int GroundS, int WinS,int mode)
{
	gotoxy(90, 13);
	printf("                            ");
	Color(12);
	gotoxy(90, 13);
	CurrX = (x - 2) / 4 + Lmax + ExtendX - XX;
	CurrY = (y - 1) / 2 + Lmax + ExtendY - YY;
	printf("Area : ( %d , %d )", CurrX, CurrY);
	gotoxy(x, y);
	bool wplace = false;
	while (1)
	{
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
				RefreshBoard();
			}
			CurrY--;
			break;
		case DOWN:
			if (y <= 31) y += 2;
			else
			{
				ExtendY++; YMain++;
				RefreshBoard();
			}
			CurrY++;
			break;
		case RIGHT:
			if (x <= 64) x += 4;
			else
			{
				ExtendX++; XMain++;
				RefreshBoard();
			}
			CurrX++;
			break;
		case LEFT:
			if (x >= 6) x -= 4;
			else
			{
				ExtendX--; XMain--;
				RefreshBoard();
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
						UpdateBD(s1, s2, p1, p2, x, y, XMain, YMain, 0, 1);
						SaveGame(BD);
					}
					string t;
					if (mode == 1) t = "easy";
					else
						if (mode == 2) t = "medium";
						else t = "hard";
					Save(t, p1 , p2);
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
						UpdateBD(s1, s2, p1, p2, x, y, XMain, YMain, 0, 1);
						SaveGame(BD);
					}
					string t;
					if (mode == 1) t = "easy";
					else
						if (mode == 2) t = "medium";
						else t = "hard";
						Save(t, p1, p2);
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

void Statistic(int GroundS, int WinS)
{
	int win, sum ;
	ifstream inp;
	inp.open("easy.txt");
	inp >> win >> sum ;
	inp.close();
	int X = 40, Y = 10;
	gotoxy(X, Y);
	Color(10);
	printf("*EASY");
	Color(15);
	gotoxy(X + 2, Y + 2);
	printf("- The total match : ");
	printf("%d", sum);
	gotoxy(X + 2, Y + 4);
	printf("- The number of match that you won : ");
	printf("%d ( %d o/o )", win, win / sum * 100);

	inp.open("medium.txt");
	inp >> win >> sum;
	inp.close();
	gotoxy(X, Y + 6);
	Color(10);
	printf("**MEDIUM");
	Color(15);
	gotoxy(X + 2, Y + 8);
	printf("- The total match : ");
	printf("%d", sum);
	gotoxy(X + 2, Y + 10);
	printf("- The number of match that you won : ");
	printf("%d ( %d o/o )", win, win / sum * 100);

	inp.open("hard.txt");
	inp >> win >> sum;
	inp.close();
	gotoxy(X, Y + 12);
	Color(10);
	printf("***HARD");
	Color(15);
	gotoxy(X + 2, Y + 14);
	printf("- The total match : ");
	printf("%d", sum);
	gotoxy(X + 2, Y + 16);
	printf("- The number of match that you won : ");
	printf("%d ( %d o/o )", win, win / sum * 100);
	gotoxy(100, 35);
	printf("[ Back - Backspace ]");

	char c = 9;
	while (c != 8) c = _getch();
	system("cls");
	Menu(GroundS, WinS);
}

//---------------------------

#pragma region ---EASY---

int DFS(int x, int y, int k, int ans)
{
	if (a[x][y] != 'X') return ans;
	else
	{
		int u = x + COL[k];
		int v = y + ROW[k];
		ans++;
		return DFS(u, v, k, ans);
	}
}

void Easy_Com(int &x, int &y)
{
	for (int i = BD.Col.size() - 1; i >= 0; i--)
	{
		int u = BD.Col[i];
		int v = BD.Row[i];
		for (int j = 0; j <= 7; j++)
		{
			int res = DFS(u, v, j, 0);
			int x1 = u - COL[j], y1 = v - ROW[j];
			int x2 = u + (res - 1)*COL[j], y2 = v + (res - 1)*ROW[j];
			if (res >= 3)
			{
				if (a[x1][y1] == ' ')
				{
					a[x1][y1] = 'O';
					x = 4 * (x1 - (ExtendX + Lmax)) + 2;
					y = 2 * (y1 - (ExtendY + Lmax)) + 1;
					gotoxy(x, y);
					Color(9);
					printf("O");
					gotoxy(x, y);
					BD.Col.pb(x1); BD.Row.pb(y1); BD.Value.pb(0);
					return;
				}
				if (a[x2][y2] == ' ')
				{
					a[x2][y2] = 'O';
					x = 4 * (x2 - (ExtendX + Lmax)) + 2;
					y = 2 * (y2 - (ExtendY + Lmax)) + 1;
					gotoxy(x, y);
					Color(9);
					printf("O");
					gotoxy(x, y);
					BD.Col.pb(x2); BD.Row.pb(y2); BD.Value.pb(0);
					return;
				}
			}
		}
	}
	//randomize();
	srand(time(NULL));
	int num = rand() % BD.Col.size();
	int col[8] = { -2, -2, -2 ,0 ,0 , 2 ,2, 2 };
	int row[8] = { -2, 0, 2 ,-2 ,2 , -2 ,0, 2 };
	for (int i = 0; i < 8; i++)
	{
		int u = BD.Col[num] + col[i];
		int v = BD.Row[num] + row[i];
		if (a[u][v] == ' ')
		{
			a[u][v] = 'O';
			x = 4 * (u - (ExtendX + Lmax)) + 2;
			y = 2 * (v - (ExtendY + Lmax)) + 1;
			gotoxy(x, y);
			Color(9);
			printf("O");
			gotoxy(x, y);
			BD.Col.pb(u); BD.Row.pb(v); BD.Value.pb(0);
			return;
		}
	}
}

void Easy(int x, int y, int GroundS, int WinS)
{
	int point;
	while (1)
	{
		Player(x, y, GroundS, WinS, 1);
		point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN);
		if (point >= 5) p1++, WinnerInform(1, s1, s2, GroundS, WinS);
		Easy_Com(x, y);
		point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN);
		if (point >= 5) p2++, WinnerInform(2, s1, s2, GroundS, WinS);
	}
}

#pragma endregion

//---------------------------

#pragma region ---MEDIUM---

// hàm đánh giá TAN CONG
int Assess_a(int x, int y, int k)
{
	int Comp = 0;
	int User = 0;
	for (int i = 1; i < 6; i++)
	{
		int u = x + i*COL[k];
		int v = y + i*ROW[k];
		if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || a[u][v] == ' ') break;
		if (a[u][v] == 'O') Comp++;
		else
		{
			User++;
			break;
		}
	}
	for (int i = 1; i < 6; i++)
	{
		int u = x + i*COL[k + 4];
		int v = y + i*ROW[k + 4];
		if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || a[u][v] == ' ') break;
		if (a[u][v] == 'O') Comp++;
		else
		{
			User++;
			break;
		}
	}
	if (User == 2) return 0;
	return Attack[Comp] - Defense[User + 1] * 2;
}
// hàm đánh giá PHONG THU
int Assess_d(int x, int y, int k)
{
	int Comp = 0;
	int User = 0;
	for (int i = 1; i < 6; i++)
	{
		int u = x + i*COL[k];
		int v = y + i*ROW[k];
		if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || a[u][v] == ' ') break;
		if (a[u][v] == 'O')
		{
			Comp++;
			break;
		}
		else User++;
	}
	for (int i = 1; i < 6; i++)
	{
		int u = x + i*COL[k + 4];
		int v = y + i*ROW[k + 4];
		if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || a[u][v] == ' ') break;
		if (a[u][v] == 'O')
		{
			Comp++;
			break;
		}
		else User++;
	}
	if (Comp == 2) return 0;
	return Defense[User];
}

void Med_Com(int &x, int &y)
{
	int res = -1000000000;
	int x1, y1;
	for (int i = BD.Col.size() - 1; i >= 0; i--)
	{
		int X = BD.Col[i];
		int Y = BD.Row[i];
		for (int j = 0; j <= 7; j++)
		{
			int u = X + COL[j];
			int v = Y + ROW[j];
			if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || a[u][v] != ' ') continue;
			int attack_point = 0, defense_point = 0;
			for (int k = 0; k <= 3; k++)
			{
				attack_point += Assess_a(u, v, k);
				defense_point += Assess_d(u, v, k);
			}
			int sum = attack_point > defense_point ? attack_point : defense_point;
			if (sum > res)
			{
				res = sum;
				x1 = u, y1 = v;
			}
		}
	}
	x = 4 * (x1 - (ExtendX + Lmax)) + 2;
	y = 2 * (y1 - (ExtendY + Lmax)) + 1;
	gotoxy(x, y);
	Color(9);
	printf("O");
	gotoxy(x, y);
	BD.Col.pb(x1); BD.Row.pb(y1); BD.Value.pb(0);
	a[x1][y1] = 'O';
}

void Medium(int x, int y, int GroundS, int WinS)
{
	int point;
	while (1)
	{
		Player(x, y, GroundS, WinS ,2);
		point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN);
		if (point >= 5) p1++, WinnerInform(1, s1, s2, GroundS, WinS);
		Med_Com(x, y);
		point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN);
		if (point >= 5) p2++, WinnerInform(2, s1, s2, GroundS, WinS);
	}
}

#pragma endregion

//---------------------------

#pragma region ---HARD---

int Value[MAXN][MAXN];
int ix, iy; // Luu vi tri COMPUTER danh ma WIN

void EvalBoard(int player)
{
	int ePC, eHuman;

	//Danh gia theo hang
	/*for (int i = 0; i < BD.Col.size(); i++)
	{
	int X = BD.Col[i];
	int Y = BD.Row[i];
	for (int j = 0; j <= 8; ++j)
	{
	int u = X + COL[j];
	int v = Y + ROW[j];*/
	for (int u = XX - Delta; u <= XX + Delta; u++)
		for (int v = YY - Delta; v <= YY + Delta; v++) Value[u][v] = 0;

	for (int u = XX - Delta; u <= XX + Delta; u++)
		for (int v = YY - Delta; v <= YY + Delta; v++)
		{
			ePC = 0; eHuman = 0;
			for (int k = 0; k < 5; k++)
			{
				if (v + k >= MAXN) break;
				if (a[u][v + k] == 'X') eHuman++;
				if (a[u][v + k] == 'O') ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int k = 0; k < 5; k++)
				{
					if (v + k >= MAXN) break;
					if (a[u][v + k] == ' ') // Neu o chua duoc danh
					{
						if (eHuman == 0)
							if (player == 1) Value[u][v + k] += Defense[ePC];
							else Value[u][v + k] += Attack[ePC];
						if (ePC == 0)
							if (player == 2) Value[u][v + k] += Defense[eHuman];
							else Value[u][v + k] += Attack[eHuman];
						if (eHuman == 4 || ePC == 4) Value[u][v + k] *= 2;
						//if (eHuman == 3 || ePC == 3) Value[u][v + k] *= 2;
					}
				}

			}
		}


	//Danh gia theo cot
	for (int u = XX - Delta; u <= XX + Delta; u++)
		for (int v = YY - Delta; v <= YY + Delta; v++)
		{
			ePC = 0; eHuman = 0;
			for (int k = 0; k < 5; k++)
			{
				if (u + k >= MAXN) break;
				if (a[u + k][v] == 'X') eHuman++;
				if (a[u + k][v] == 'O') ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int k = 0; k < 5; k++)
				{
					if (u + k >= MAXN) break;
					if (a[u + k][v] == ' ') // Neu o chua duoc danh
					{
						if (eHuman == 0)
							if (player == 1)
								Value[u + k][v] += Defense[ePC];
							else Value[u + k][v] += Attack[ePC];
							if (ePC == 0)
								if (player == 2)
									Value[u + k][v] += Defense[eHuman];
								else Value[u + k][v] += Attack[eHuman];
								if (eHuman == 4 || ePC == 4)
									Value[u + k][v] *= 2;
								//if (eHuman == 3 || ePC == 3) Value[u + k][v] *= 2;
					}

				}

			}
		}


	//Danh gia duong cheo xuong
	for (int u = XX - Delta; u <= XX + Delta; u++)
		for (int v = YY - Delta; v <= YY + Delta; v++)
		{
			ePC = 0; eHuman = 0;
			for (int k = 0; k < 5; k++)
			{
				if (u + k >= MAXN || v + k >= MAXN) break;
				if (a[u + k][v + k] == 'X') eHuman++;
				if (a[u + k][v + k] == 'O') ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int k = 0; k < 5; k++)
				{
					if (u + k >= MAXN || v + k >= MAXN) break;
					if (a[u + k][v + k] == ' ') // Neu o chua duoc danh
					{
						if (eHuman == 0)
							if (player == 1)
								Value[u + k][v + k] += Defense[ePC];
							else Value[u + k][v + k] += Attack[ePC];
							if (ePC == 0)
								if (player == 2)
									Value[u + k][v + k] += Defense[eHuman];
								else Value[u + k][v + k] += Attack[eHuman];
								if (eHuman == 4 || ePC == 4)
									Value[u + k][v + k] *= 2;
								//if (eHuman == 3 || ePC == 3) Value[u + k][v + k] *= 2;
					}

				}

			}
		}


	//Danh gia duong cheo len
	for (int u = XX - Delta; u <= XX + Delta; u++)
		for (int v = YY - Delta; v <= YY + Delta; v++)
		{
			ePC = 0; eHuman = 0;
			for (int k = 0; k < 5; k++)
			{
				if (u - k < 0 || v + k >= MAXN) break;
				if (a[u - k][v + k] == 'X') eHuman++;
				if (a[u - k][v + k] == 'O') ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int k = 0; k < 5; k++)
				{
					if (u - k < 0 || v + k >= MAXN) break;
					if (a[u - k][v + k] == ' ') // Neu o chua duoc danh
					{
						if (eHuman == 0)
							if (player == 1)
								Value[u - k][v + k] += Defense[ePC];
							else Value[u - k][v + k] += Attack[ePC];
							if (ePC == 0)
								if (player == 2)
									Value[u - k][v + k] += Defense[eHuman];
								else Value[u - k][v + k] += Attack[eHuman];
								if (eHuman == 4 || ePC == 4)
									Value[u - k][v + k] *= 2;
								//if (eHuman == 3 || ePC == 3) Value[u - k][v + k] *= 2;
					}

				}

			}
		}


}

int _Min(int depth, int Alpha, int Beta);
int _Max(int depth, int Alpha, int Beta)
{
	EvalBoard(2);
	ioi Q[3];
	for (int k = 0; k < 3; k++)
	{
		int maxi = -INF;
		for (int i = XX - Delta; i <= XX + Delta; i++)
			for (int j = YY - Delta; j <= YY + Delta; j++)
				if (maxi < Value[i][j])
				{
					maxi = Value[i][j];
					Q[k].X = i;
					Q[k].Y = j;
					Q[k].Value = maxi;
				}
		Value[Q[k].X][Q[k].Y] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		ioi p = Q[i];
		a[p.X][p.Y] = 'O';
		if (i == 0 && depth == 0)
		{
			ix = p.X;
			iy = p.Y;
		}
		if (KiemTra(p.X, p.Y, MAXN, MAXN) == 5)
		{
			a[p.X][p.Y] = ' ';
			if (depth == 0)
			{
				ix = p.X;
				iy = p.Y;
			}
			return INF;
		}
		int tam = _Min(depth + 1, Alpha, Beta);
		a[p.X][p.Y] = ' ';
		if (tam > Beta) return INF;
		if (Alpha < tam)
		{
			if (depth == 0)
			{
				ix = p.X;
				iy = p.Y;
			}
			Alpha = tam;
		}
	}
	return Alpha;
}
int _Min(int depth, int Alpha, int Beta)
{
	if (depth == MaxDepth)
	{
		EvalBoard(1);
		int maxi = -INF;
		for (int i = XX - Delta; i <= XX + Delta; i++)
			for (int j = YY - Delta; j <= YY + Delta; j++) maxi = max(maxi, Value[i][j]);
		return maxi;
	}
	else
	{
		EvalBoard(1);
		ioi Q[3];
		for (int k = 0; k < 3; k++)
		{
			int maxi = -INF;
			for (int i = XX - Delta; i <= XX + Delta; i++)
				for (int j = YY - Delta; j <= YY + Delta; j++)
					if (maxi < Value[i][j])
					{
						maxi = Value[i][j];
						Q[k].X = i;
						Q[k].Y = j;
						Q[k].Value = maxi;
					}
			Value[Q[k].X][Q[k].Y] = 0;
		}
		for (int i = 0; i < 3; i++)
		{
			ioi p = Q[i];
			a[p.X][p.Y] = 'X';
			if (KiemTra(p.X, p.Y, MAXN, MAXN) == 5)
			{
				a[p.X][p.Y] = ' ';
				return -INF;
			}
			int tam = _Max(depth + 1, Alpha, Beta);
			a[p.X][p.Y] = ' ';
			if (tam < Alpha) return -INF;
			Beta = min(Beta, tam);
		}
	}
	return Beta;
}

void Hard_Com(int &x, int &y)
{
	int t = _Max(0, -INF, +INF);
	x = 4 * (ix - (ExtendX + Lmax)) + 2;
	y = 2 * (iy - (ExtendY + Lmax)) + 1;
	gotoxy(x, y);
	Color(9);
	printf("O");
	gotoxy(x, y);
	BD.Col.pb(ix); BD.Row.pb(iy); BD.Value.pb(0);
	a[ix][iy] = 'O';
}

void Hard(int &x, int &y, int GroundS, int WinS)
{
	int point;
	while (1)
	{
		Player(x, y, GroundS, WinS, 3);
		point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN);
		if (point >= 5) p1++, WinnerInform(1, s1, s2, GroundS, WinS);
		Hard_Com(x, y);
		point = KiemTra((x - 2) / 4 + Lmax + ExtendX, (y - 1) / 2 + Lmax + ExtendY, MAXN, MAXN);
		if (point >= 5) p2++, WinnerInform(2, s1, s2, GroundS, WinS);
	}
}

#pragma endregion

//---------------------------

int PickMode(int GroundS, int WinS)
{
	gotoxy(XO + 13, YO + 10);
	Color(15);
	printf("I.   Easy");
	gotoxy(XO + 13, YO + 12);
	Color(10);
	printf("II.  Medium");
	gotoxy(XO + 13, YO + 14);
	Color(12);
	printf("III. Hard");
	gotoxy(XO + 13, YO + 16);
	Color(11);
	printf("STATISTIC");
	gotoxy(XO + 11, YO + 10);
	Color(14);
	printf("=>");
	int y = YO + 10;
	char chon = 8;
	while (chon != 13)
	{
		chon = _getch();
		switch (chon)
		{
		case 72: if (y > YO + 10)
			y -= 2;
			break;
		case 80: if (y < YO + 16)
			y += 2;
			break;
		case 8:
			Rectangle_NULL(XO + 9, YO + 9, 55, 30);
			PickKind(GroundS, WinS);
			break;

		}
		gotoxy(XO + 13, YO + 10);
		Color(15);
		printf("I.   Easy");
		gotoxy(XO + 13, YO + 12);
		Color(10);
		printf("II.  Medium");
		gotoxy(XO + 13, YO + 14);
		Color(12);
		printf("III. Hard");
		gotoxy(XO + 13, YO + 16);
		Color(11);
		printf("STATISTIC");
		gotoxy(XO + 11, YO + 10);
		printf("  ");
		gotoxy(XO + 11, YO + 12);
		printf("  ");
		gotoxy(XO + 11, YO + 14);
		printf("  ");
		gotoxy(XO + 11, YO + 16);
		printf("  ");
		if (y == YO + 10)
		{
			gotoxy(XO + 11, YO + 10);
			Color(14);
			printf("=>");
		}
		if (y == YO + 12)
		{
			gotoxy(XO + 11, YO + 12);
			Color(14);
			printf("=>");
		}
		if (y == YO + 14)
		{
			gotoxy(XO + 11, YO + 14);
			Color(14);
			printf("=>");
		}
		if (y == YO + 16)
		{
			gotoxy(XO + 11, YO + 16);
			Color(14);
			printf("=>");
		}
	}
	if (y == YO + 10) return 1;
	else
		if (y == YO + 12) return 2;
		else 
			if (y == YO + 14) return 3;
			else
			{
				system("cls");
				Statistic(GroundS, WinS);
			}
}

void PvC(int GroundS, int WinS)
{
	if (!PlayAgain)
	{
		mode = PickMode(GroundS, WinS);
		system("cls");
	}
	PlaySound(NULL, NULL, 0);
	DrawChessBoard();
	Point_Form(p1, p2);

	Inform_Form(1, 12, 70, 9, "YOU"); DrawControl1();
	Inform_Form(2, 9, 70, 22, "COMPUTER"); DrawControl2();

	Back_Exit();

	CursorTrue();
	int x = 34, y = 17;
	int max1 = 0, max2 = 0;
	Color(12);
	gotoxy(90, 13);
	printf("Area : ( %d , %d )", CurrX, CurrY);
	gotoxy(x, y);
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++) a[i][j] = ' ';
	if (mode == 1) Easy(x, y, GroundS, WinS);
	else 
		if (mode == 2) Medium(x, y, GroundS, WinS);
		else Hard(x, y, GroundS, WinS);
}