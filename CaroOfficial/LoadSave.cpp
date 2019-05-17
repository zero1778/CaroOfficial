#include "Caro.h"

int UpSave()
{
	int res;
	int x, first;
	ifstream inp;
	ofstream out;
	inp.open("SaveGame.txt");
	inp >> x >> first;
	x++;
	inp.close();
	out.open("SaveGame.txt");
	res = (x % 10) + ((x % 10 == 0) ? 10 : 0);
	if (x <= 10) first = x;
	else
	{
		first = res + 1;
		if (first == 11) first = 1;
	}
	out << x << " " << first;
	out.close();
	return res;

}

void SaveGame(info x)
{
	int stt = UpSave();
	string s = to_string(stt);
	const char *num = s.c_str();
	const char *Caro = "Caro";

	char *Save = new char[100]; // So luong chu cai de save

	Save[0] = 0;
	strcat(Save, Caro); strcat(Save, num);
	char* p = strcat(Save, ".txt");
	ofstream out;
	out.open(p);

	time_t now = time(0);
	tm *ltm = localtime(&now);

	out << (int)ltm->tm_mday << " "; // Ngay
	out << 1 + ltm->tm_mon << " ";// Thang
	out << 1900 + ltm->tm_year << "\n";// Nam
	out << ltm->tm_hour << " ";// Gio 
	out << ltm->tm_min << " " ;// Phut
	out << ltm->tm_sec << "\n";// Giay
	

	out << x.Point1 << " " << x.Point2 << "\n";
	out << x.Name1 << "\n";
	out << x.Name2 << "\n";
	out << x.OriX << " " << x.OriY << "\n";
	out << x.CoorX << " " << x.CoorY << "\n";
	out << x.Time << " " << x.turn << "\n";
	out << x.Col.size() << "\n";
	for (int i = 0; i < (int)x.Col.size(); i++)
		out << x.Col[i] << " " << x.Row[i] << " " << x.Value[i] << "\n";
	out.close();
}

void LoadGame()
{
	int x, first;
	ifstream inp;
	ofstream out;
	inp.open("SaveGame.txt");
	inp >> x >> first;
	inp.close();

	int GroundS, WinS;
	inp.open("sound.txt");
	inp >> GroundS >> WinS;
	inp.close();

	gotoxy(39, 10);
	printf("Which match do you want to play continue ? ");
	gotoxy(41, 11);
	printf("*** We just save 10 lastest matches ***  ");
	Color(7);
	gotoxy(89, 10);
	printf("( Input 0 if you want to back to Menu )");
	if (x <= 10)
	{
		int X = 39, Y = 14;
		for (int i = 0; i < x; i++)
		{
			string s = to_string(i + 1);
			const char *num = s.c_str();
			const char *Caro = "Caro";

			char *Save = new char[100]; // So luong chu cai de save

			Save[0] = 0;
			strcat(Save, Caro); strcat(Save, num);
			char* p = strcat(Save, ".txt");
			inp.open(p);
			//---------------------
			int date, month, year; 
			int hr,min,sec;
			int p1, p2;
			string N1, N2;
			//---------------------
			inp >> date >> month >> year;
			inp>> hr >> min >> sec;

			inp>> p1 >> p2;
			inp>> N1;
			inp>> N2;
			inp.close();
			//---------------------
			gotoxy(X, Y + i*2);
			Color(15);
			printf("%d. %d/%d/%d ", i + 1, date, month, year);
			printf("%d:%d:%d ", hr, min, sec);
			cout << N1 << " - " << N2 << " ( " << p1 << " - " << p2 << " ) \n";
		}
		//Sleep(10000);
	}
	CursorTrue();
	gotoxy(83, 10);
	int turn;
	scanf_s("%d", &turn);
	if (turn == 0)
	{
		system("cls");
		Menu(GroundS, WinS);
	}
	while (turn > 10 || turn <= 0)
	{
		gotoxy(83, 10);
		printf("                                  ");
		gotoxy(83, 10);
		scanf_s("%d", &turn);
		if (turn == 0)
		{
			system("cls");
			Menu(GroundS, WinS);
		}
	}
	string s = to_string(turn);
	const char *num = s.c_str();
	const char *Caro = "Caro";

	char *Save = new char[100]; // So luong chu cai de save

	Save[0] = 0;
	strcat(Save, Caro); strcat(Save, num);
	char* p = strcat(Save, ".txt");
	inp.open(p);
	//---------------------
	int date, month, year;
	int hr, min, sec;
	struct info X;
	int n;
	char N1[50], N2[50];
	//---------------------
	inp >> date >> month >> year;
	inp >> hr >> min >> sec;

	inp >> X.Point1 >> X.Point2;
	inp >> N1;
	inp >> N2;
	X.Name1 = N1, X.Name2 = N2;
	inp >> X.OriX >> X.OriY; 
	inp >> X.CoorX >> X.CoorY;
	inp >> X.Time >> X.turn >>n;
	
	for (int i = 0; i < n; i++)
	{
		int u, v , uv;
		inp >> u >> v >> uv;
		X.Col.push_back(u); X.Row.push_back(v);
		X.Value.push_back(uv);
	}

	inp.close();
	system("cls");
	PvP(X.Name1, X.Name2, X.Time, X.Point1, X.Point2, 1, GroundS, WinS, X, false);
	CursorFalse();


}

