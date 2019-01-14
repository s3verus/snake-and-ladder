#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdio>
#include <time.h>
#include <fstream>

using namespace std;
int k1 = 2;
int k2 = 2;
int a = 4;//column for player1
int b = 38;//row for player1
int c = 3;
int w = 4;//column for player2
int v = 38;//row for player2
int x;
int n;//dice number
int sc1 = 1;
int sc2 = 1;
int turn = 1;
int k = 1;
int l = 1;
int l2 = 1;
int ai[7];
int aj[7];
int bi[7];
int bj[7];
int notp1[100][100];
int sl = 0;
int ti = 0;
int tj = 0;
int i = 4;//the columns
int j = 1;//the rows
int loca;
int locb;
int locw;
int locv;
int bn;//bomb number
int kb = 5;
int hb = 3;
int bnumber1 = 3;
int bnumber2 = 3;
int timer1 = 1;
int timer2 = 1;
int counter1 = 3;
int counter2 = 3;
int bombnumber;
int sp1[7];
int sp[7];
void ldd(void);
void one();
void two();
void three();
void four();
void five();
void six();
void snake(void);
void start1();
void start2();
void dice();
void notp(void);//notp = number of the places
void gotoxy(int, int);
void p(void);
void p1(void);
void p2(void);
void menu(void);
void chart(void);
void about(void);
void back(void);
void changeColor(int);
void ladder(void);
void pm1();
void pm2();
void movesnake(void);
void movesnake2(void);

void moveladder(void);
void moveladder2(void);

void bomb1(void);
void bomb2(void);

void bomb_destroy1(void);
void bomb_destroy2(void);

void fPositions1();
void fPositions2();
void finish();
void option(void);
//void mouse(void);
void load(void);
void save(void);
ofstream out;
ifstream in;

int main() {
	system("title snake and ladder");
	//codes for changing the default size of terminal
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1800, 800, TRUE); // 1800 width, 800 height

	srand(time(NULL));

	menu();

	return 0;
}

void chart(void) {//10*10 game chart
	system("color 71");
	for (int s = 1; s <= 10; ++s) {
		for (int i = 0; i <= 40; ++i) {
			cout << "* ";
		}
		cout << "\n";
		for (int k = 1; k <= 3; ++k) {
			for (int j = 1; j <= 5; ++j) {
				cout << "*       *       ";
			}cout << "*\n";
		}
	}
	for (int i = 0; i <= 40; ++i) {
		cout << "* ";
	}
	notp();
	p1();
	p2();
	snake();
	sl = 0;
	ldd();

}

void back(void)
{

	cout << "\n0.back\n";
	int x;
	cin >> x;
	if (x == 0) {
		system("cls");
		menu();
	}
}
void about(void) {
	gotoxy(65, 24); cout << "   we dicided to design a game in cpp type";
	gotoxy(65, 25); cout << "and this is a game about a snake-and-ladder chart";
	gotoxy(65, 26); cout << "with some fun options included in the game";
	gotoxy(65, 27); cout << "and the game is gonig to be design by";
	gotoxy(65, 28); cout << "three-of-use (.Benyamin .Ali .Alireza)";
	gotoxy(65, 29); cout << "from iran for the university's project.";
	gotoxy(65, 30); cout << "           -HOPE YOU ENJOY IT-          ";
	gotoxy(65, 32);
	cout << "0.back";
	system("cls");
	menu();
}

void menu(void) {//first menu
	system("color  b3");
	gotoxy(82, 20); cout << "1.start";
	gotoxy(82, 22); cout << "2.option";
	gotoxy(82, 24); cout << "3.load";
	gotoxy(82, 26); cout << "4.help";
	gotoxy(82, 28); cout << "5.about";
	gotoxy(82, 30);cout << "6.exit";
	gotoxy(85, 32);
//start music ;)
	Beep(500, 1000); Sleep(250);
	Beep(400, 1000); Sleep(250);
	Beep(300, 1000); Sleep(250);
	Beep(200, 1000); Sleep(250);
//end of music
	cin >> x;

	switch (x) {
	case 1:
		system("cls");
		chart();
		k++;
		p();
		break;
	case 2:
		system("cls");
		option();
		break;
	case 3:
		system("color 71");
		for (int s = 1; s <= 10; ++s) {
			for (int i = 0; i <= 40; ++i) {
				cout << "* ";
			}
			cout << "\n";
			for (int k = 1; k <= 3; ++k) {
				for (int j = 1; j <= 5; ++j) {
					cout << "*       *       ";
				}cout << "*\n";
			}
		}
		for (int i = 0; i <= 40; ++i) {
			cout << "* ";
		}
		notp();
		p1();
		p2();
		load();
		p();
		break;
	case 4:
		system("cls");
		gotoxy(65, 24); cout << "  this is a game of snakes and ladders";
		gotoxy(65, 25); cout << "with some exciting options";
		gotoxy(65, 26); cout << "such as bitting by other players";
		gotoxy(65, 27); cout << "and placing some bombs in the map\n";
		gotoxy(65, 28); cout << "we have a cheating code in the game";
		gotoxy(65, 29); cout << "by which you can enter INT_MAX value";
		gotoxy(65, 30); cout << "and you will see the automatic movement";
		gotoxy(65, 31); cout << " of the players";
		break;
	case 5:
		system("cls");
		about();
		break;
	case 6:
		exit(0);
		break;
	default:
		gotoxy(0, 6); cout << "invalid key!! you can choose between 1 to 6";
		menu();
		break;
	}

	back();

}
void p(void) {
	gotoxy(100, 30); cout << "1.roll the dice";
	gotoxy(100, 31); cout << "2.place bomb";
	gotoxy(100, 32); cout << "3.save";
	gotoxy(100, 33); cout << "4.back to the menu";
	gotoxy(100, 34); cout << "0.exit from the game";
	gotoxy(0, 41);
	cin >> x;
	switch (x) {
	case 1:
		if (timer1 == 0) {
			counter1--;
		}
		if (timer2 == 0) {
			counter2--;
		}
		while (x == 1) {

			while (turn == 1) {
				dice();
				fPositions1();
				pm1();
				finish();
				if (sc2 == 0) {
					locw = w;
					locv = v;
					gotoxy(locw, locv);
					cout << "$";
				}
				loca = a;
				locb = b;
				movesnake();
				moveladder();
				if ((w == a) && (v == b)) {
					w = 4;
					v = 38;
					k2 = 2;
				}
				bomb_destroy2();
				if (n == 6) {
					gotoxy(111, 8); cout << "    ";
					gotoxy(111, 6); cout << "turn";
					start1();
					p();
					pm1();
					finish();
					if (sc2 == 0) {
						locw = w;
						locv = v;
						gotoxy(locw, locv);
						cout << "$";
					}
					loca = a;
					locb = b;
					movesnake();
					moveladder();
					if ((w == a) && (v == b)) {
						w = 4;
						v = 38;
						k2 = 2;
					}
					bomb_destroy2();
					continue;
				}
				turn--;
				gotoxy(111, 6); cout << "    ";
				gotoxy(111, 8); cout << "turn";
				p();
			}
			while (turn == 0) {
				dice();
				fPositions2();
				gotoxy(3, 38); cout << " ";
				pm2();
				finish();
				if (sc1 == 0) {
					loca = a;
					locb = b;
					gotoxy(loca, locb);
					cout << "@";
				}
				locw = w;
				locv = v;
				movesnake2();
				moveladder2();
				if ((w == a) && (v == b)) {
					a = 4;
					b = 38;
					k1 = 2;
				}
				bomb_destroy1();
				if (n == 6) {
					gotoxy(111, 6); cout << "    ";
					gotoxy(111, 8); cout << "turn";
					start2();
					p();
					pm2();
					finish();
					if (sc1 == 0) {
						loca = a;
						locb = b;
						gotoxy(loca, locb);
						cout << "@";
					}
					locw = w;
					locv = v;
					movesnake2();
					moveladder2();
					if ((w == a) && (v == b)) {
						a = 4;
						b = 38;
						k1 = 2;
					}
					bomb_destroy1();
					continue;
				}
				turn++;
				gotoxy(111, 8); cout << "    ";
				gotoxy(111, 6); cout << "turn";
				p();
			}
			continue;
		}
		break;
	case 2:
		if (turn == 1) {
			if (timer1 == 0) {
				gotoxy(100, 13);
				cout << "you've already put a bomb ,you can not place twice in a row!!";
				Sleep(3000);
				gotoxy(100, 13);
				cout << "                                                             ";
				p();
			}
			else {
				if (bnumber1 != 0) {
					bomb1();
					bnumber1--;
					turn = 0;
					gotoxy(120, 6);
					cout << bnumber1;
					p();
				}
				else {
					gotoxy(120, 6);
					cout << "you do not have enough bomb!!";
					Sleep(2000);
					gotoxy(120, 6);
					cout << "                              ";
					turn = 0;
					p();
				}
			}
		}
		if (turn == 0) {
			if (timer2 == 0) {
				gotoxy(100, 14);
				cout << "you've already put a bomb ,you can not place twice in a row!!";
				Sleep(3000);
				gotoxy(100, 14);
				cout << "                                                              ";
				p();
			}
			else {
				if (bnumber2 != 0) {
					bomb2();
					bnumber2--;
					turn = 1;
					gotoxy(120, 8);
					cout << bnumber2;
					p();
				}
				else {
					gotoxy(120, 8);
					cout << "you do not have enough bomb!! ";
					Sleep(2000);
					gotoxy(120, 8);
					cout << "                              ";
					turn = 1;
					p();
				}
			}
		}
		break;
	case 3:
		save();
		break;
	case 4:
		system("cls");
		menu();
		break;
	case 0:
		exit(0);
		break;
	default:

		gotoxy(100, 35); cout << "invalid key!!!";
		p();

		break;
	}

}

void p1(void) {
	if (k == 1) {
		gotoxy(111, 6); cout << "turn";
		k--;
	}
	gotoxy(100, 6); cout << "player 1 :";

}
void p2(void) {
	gotoxy(100, 8); cout << "player 2 :";

}

void dice() {
	srand(time(NULL));
	n = rand();
	n = 1 + n % 6;

	switch (n)
	{
	case 1:
		one();
		break;
	case 2:
		two();
		break;
	case 3:
		three();
		break;
	case 4:
		four();
		break;
	case 5:
		five();
		break;
	case 6:
		six();
		break;
	default:
		cout << "invalid number";

	}
}
void notp(void) {//number of the places
	int num = 100;
	int n1 = 1;
	for (int j = 3; j <= 40; j += 4) {
		if (n1 == 1) {
			for (int i = 5; i <= 80; i += 8) {
				gotoxy(i, j);
				cout << num;
				notp1[i][j] = num;
				num--;
			}
			n1--;
		}
		else {
			for (int i = 77; i >= 5; i -= 8) {
				gotoxy(i, j);
				cout << num;
				notp1[i][j] = num;
				num--;
			}
			n1++;
		}
	}
}

void snake(void) {
	sl = 0;
	ti = 0;
	tj = 0;
	i = 4;
	j = 1;
	while (sl < 7) {
		ti = i;
		tj = j;
		i = 8 * (1 + rand() % 10) - 4;
		j = 4 * (1 + rand() % 10) - 3;
		if ((i == 4 && j == 1) || (i == 4 && j == 37)) {
			continue;
		}
		if ((i == ti) && (j == tj)) {
			continue;
		}
		gotoxy(i, j);
		cout << "s<<";
		ai[sl] = i;
		aj[sl] = j;
		sl++;
	}
}
void ldd(void) {
	int sl1 = 0;
	ti = 0;
	tj = 0;
	i = 4;
	j = 1;
	while (sl < 7) {
		ti = i;
		tj = j;
		i = 8 * (1 + rand() % 10) - 4;
		j = 4 * (1 + rand() % 10) - 3;
		sl1 = 0;
		while (sl1 < 7) {
			if (ai[sl1] == i && aj[sl1] == j) {
				break;
			}
			sl1++;
		}
		if (sl1 < 7) {
			continue;
		}

		if ((i == 4 && j == 1) || (i == 4 && j == 37)) {
			continue;
		}
		if (i == ti && j == tj) {
			continue;
		}
		else {
			gotoxy(i, j);
			cout << "l>>";
			bi[sl] = i;
			bj[sl] = j;
			sl++;
		}
	}
}
void one()
{
	gotoxy(100, 20); cout << " -----" << endl;
	gotoxy(100, 21); cout << "|     |" << endl;
	gotoxy(100, 22); cout << "|  O  |" << endl;
	gotoxy(100, 23); cout << "|     |" << endl;
	gotoxy(100, 24); cout << " -----" << endl;
}
void two()
{
	gotoxy(100, 20); cout << " -----" << endl;
	gotoxy(100, 21); cout << "|    O|" << endl;
	gotoxy(100, 22); cout << "|     |" << endl;
	gotoxy(100, 23); cout << "|O    |" << endl;
	gotoxy(100, 24); cout << " -----" << endl;
}
void three()
{
	gotoxy(100, 20); cout << " -----" << endl;
	gotoxy(100, 21); cout << "|    O|" << endl;
	gotoxy(100, 22); cout << "|  O  |" << endl;
	gotoxy(100, 23); cout << "|O    |" << endl;
	gotoxy(100, 24); cout << " -----" << endl;
}
void four()
{
	gotoxy(100, 20); cout << " -----" << endl;
	gotoxy(100, 21); cout << "|O   O|" << endl;
	gotoxy(100, 22); cout << "|     |" << endl;
	gotoxy(100, 23); cout << "|O   O|" << endl;
	gotoxy(100, 24); cout << " -----" << endl;
}
void five()
{
	gotoxy(100, 20); cout << " -----" << endl;
	gotoxy(100, 21); cout << "|O   O|" << endl;
	gotoxy(100, 22); cout << "|  O  |" << endl;
	gotoxy(100, 23); cout << "|O   O|" << endl;
	gotoxy(100, 24); cout << " -----" << endl;
}
void six()
{
	//cout << "\a";
	gotoxy(100, 20); cout << " -----" << endl;
	gotoxy(100, 21); cout << "|O   O|" << endl;
	gotoxy(100, 22); cout << "|O   O|" << endl;
	gotoxy(100, 23); cout << "|O   O|" << endl;
	gotoxy(100, 24); cout << " -----" << endl;
}

void start1(void) {
	if (sc1 == 1) {
		gotoxy(a, b); cout << "@";
		sc1--;
	}
}
void start2(void) {
	if (sc2 == 1) {
		gotoxy(w - 1, v); cout << "$";
		sc2--;
	}
}

void gotoxy(int x, int y) {//coordinating the locations

	COORD coord{ 0,0 };
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


void pm1(void) {
	int h = 0;
	if (turn == 1) {
		if (sc1 == 0) {
			while (h < n) {
				if (a < 76 && (k1 % 2 == 0)) {
					gotoxy(a, b); cout << "@";
					a += 8;
					gotoxy(a - 8, b); cout << " ";
					gotoxy(a, b); cout << "@";
					h++;
					Sleep(500);
				}
				else {
					if (((a == 76) || (a == 4)) && (l == 1)) {
						k1--;
						h++;
						gotoxy(a, b); cout << " ";
						b -= 4;
						gotoxy(a, b); cout << "@";
						l--;
						Sleep(500);
					}
					while (h < n) {
						if (a > 4) {
							gotoxy(a, b); cout << "@";
							a -= 8;
							gotoxy(a + 8, b); cout << " ";
							gotoxy(a, b); cout << "@";
							h++;
							Sleep(500);
						}
						else {
							if (((a == 76) || (a == 4)) && (l == 0)) {
								k1++;
								h++;
								gotoxy(a, b); cout << " ";
								b -= 4;
								gotoxy(a, b); cout << "@";
								l++;
								Sleep(500);
							}
							break;
						}
					}
				}
			}
		}
	}
}
void pm2(void) {
	int h = 0;
	if (turn == 0) {
		if (sc2 == 0) {
			while (h < n) {
				if (w < 76 && (k2 % 2 == 0)) {
					gotoxy(w, v); cout << "$";
					w += 8;
					gotoxy(w - 8, v); cout << " ";
					gotoxy(w, v); cout << "$";
					h++;
					Sleep(500);
				}
				else {
					if (((w == 76) || (w == 4)) && (l2 == 1)) {
						k2--;
						h++;
						gotoxy(w, v); cout << " ";
						v -= 4;
						gotoxy(w, v); cout << "$";
						l2--;
						Sleep(500);
					}
					while (h < n) {
						if (w > 4) {
							gotoxy(w, v); cout << "$";
							w -= 8;
							gotoxy(w + 8, v); cout << " ";
							gotoxy(w, v); cout << "$";
							h++;
							Sleep(500);
						}
						else {
							if (((w == 76) || (w == 4)) && (l2 == 0)) {
								k2++;
								h++;
								gotoxy(w, v); cout << " ";
								v -= 4;
								gotoxy(w, v); cout << "$";
								l2++;
								Sleep(500);
							}
							break;
						}
					}
				}
			}
		}
	}
}
void changeColor(int h) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, h);
}
void ladder(void) {
	int ldd = 0;
	//int snake = 0;

}
void movesnake(void) {
	int sp1[7];
	int sp[7];
	int j1 = 3;
	int i1 = 5;
	int snake = 0;
	for (snake = 0; snake < 7; snake++) {
		sp[snake] = notp1[ai[snake]][aj[snake]];
		sp1[snake] = (2 + rand() % (sp[snake] - 2));
		for (j1 = 3; j1 <= 40; j1 += 4) {
			for (i1 = 5; i1 <= 80; i1 += 8) {
				if (sp1[snake] == notp1[i1][j1]) {
					break;
				}
			}
			if (sp1[snake] == notp1[i1][j1]) {
				break;
			}
		}
		if ((loca == ai[snake]) && (locb - 1 == aj[snake])) {
			gotoxy(loca, locb); cout << " ";
			gotoxy(i1 - 1, j1 - 1); cout << "@";
			a = i1 - 1;
			b = j1 - 1;
			if (((b == 6) || (b == 14) || (b == 22) || (b == 30) || (b == 38))) {
				k1 = 2;
				l = 1;
			}
			else {
				k1 = 1;
				l = 0;
			}
		}
	}
}
void movesnake2(void) {
	int sp1[7];
	int sp[7];
	int i2 = 5;
	int j2 = 3;
	int snake = 0;
	for (snake = 0; snake < 7; snake++) {
		sp[snake] = notp1[ai[snake]][aj[snake]];
		sp1[snake] = (2 + rand() % (sp[snake] - 2));
		for (j2 = 3; j2 <= 40; j2 += 4) {
			for (i2 = 5; i2 <= 80; i2 += 8) {
				if (sp1[snake] == notp1[i2][j2]) {
					break;
				}
			}
			if (sp1[snake] == notp1[i2][j2]) {
				break;
			}
		}
		if ((locw == ai[snake]) && (locv - 1 == aj[snake])) {
			gotoxy(locw, locv);
			cout << " ";
			gotoxy(i2 - 1, j2 - 1);
			cout << "$";
			w = i2 - 1;
			v = j2 - 1;
			if (((v == 6) || (v == 14) || (v == 22) || (v == 30) || (v == 38))) {
				k2 = 2;
				l2 = 1;
			}
			else {
				k2 = 1;
				l2 = 0;
			}
		}
	}
}
void moveladder(void) {

	int sp1[7];
	int sp[7];
	int j1 = 3;
	int i1 = 5;
	int mbyl = 0;
	for (mbyl = 0; mbyl < 7; mbyl++) {
		sp[mbyl] = notp1[bi[mbyl]][bj[mbyl]];
		sp1[mbyl] = ((sp[mbyl] + 1) + rand() % (99 - sp[mbyl]));
		for (j1 = 3; j1 <= 40; j1 += 4) {
			for (i1 = 5; i1 <= 80; i1 += 8) {
				if (sp1[mbyl] == notp1[i1][j1]) {
					break;
				}
			}
			if (sp1[mbyl] == notp1[i1][j1]) {
				break;
			}
		}
		if ((loca == bi[mbyl]) && (locb - 1 == bj[mbyl])) {
			gotoxy(loca, locb);
			cout << " ";
			gotoxy(i1 - 1, j1 - 1);
			cout << "@";
			a = i1 - 1;
			b = j1 - 1;
			if (((b == 6) || (b == 14) || (b == 22) || (b == 30) || (b == 38))) {
				k1 = 2;
				l = 1;
			}
			else {
				k1 = 1;
				l = 0;
			}
		}
	}


}
void moveladder2(void) {
	int sp1[7];
	int sp[7];
	int j2 = 3;
	int i2 = 5;
	int mbyl = 0;
	for (mbyl = 0; mbyl < 7; mbyl++) {
		sp[mbyl] = notp1[bi[mbyl]][bj[mbyl]];
		sp1[mbyl] = ((sp[mbyl] + 1) + rand() % (99 - sp[mbyl]));
		for (j2 = 3; j2 <= 40; j2 += 4) {
			for (i2 = 5; i2 <= 80; i2 += 8) {
				if (sp1[mbyl] == notp1[i2][j2]) {
					break;
				}
			}
			if (sp1[mbyl] == notp1[i2][j2]) {
				break;
			}
		}
		if ((locw == bi[mbyl]) && (locv - 1 == bj[mbyl])) {
			gotoxy(locw, locv);
			cout << " ";
			gotoxy(i2 - 1, j2 - 1);
			cout << "$";
			w = i2 - 1;
			v = j2 - 1;
			if (((v == 6) || (v == 14) || (v == 22) || (v == 30) || (v == 38))) {
				k2 = 2;
				l2 = 1;
			}
			else {
				k2 = 1;
				l2 = 0;
			}
		}
	}

}
void bomb1(void) {
	gotoxy(100, 40);
	cout << "enter home number:";
	gotoxy(100, 41);
	cin >> bn;
	for (hb = 3; hb <= 40; hb += 4) {
		for (kb = 5; kb <= 80; kb += 8) {
			if (bn == notp1[kb][hb]) {
				break;
			}
		}
		if (bn == notp1[kb][hb]) {
			break;
		}
	}
	gotoxy(kb - 4, hb);
	cout << "!";
	gotoxy(100, 40);
	cout << "                    ";
	gotoxy(100, 41);
	cout << "    ";
	timer1 = 0;
	gotoxy(0, 41);
}
void bomb2(void) {
	gotoxy(100, 40);
	cout << "enter home number:";
	gotoxy(100, 41);
	cin >> bn;
	for (hb = 3; hb <= 40; hb += 4) {
		for (kb = 5; kb <= 80; kb += 8) {
			if (bn == notp1[kb][hb]) {
				break;
			}
		}
		if (bn == notp1[kb][hb]) {
			break;
		}
	}
	gotoxy(kb - 4, hb);
	cout << "!";
	gotoxy(100, 40);
	cout << "                    ";
	gotoxy(100, 41);
	cout << "    ";
	timer2 = 0;
	gotoxy(0, 41);
}
void bomb_destroy1(void) {
	if (counter1 == 0) {
		if (((w == kb - 1) && (v == hb - 1)) || ((w == kb - 9) && (v == hb - 1)) || ((w == kb - 17) && (v == hb - 1)) || ((w == kb + 7) && (v == hb - 1)) || ((w == kb + 15) && (v == hb - 1))) {
			gotoxy(w, v);
			cout << " ";
			w = 4;
			v = 38;
			gotoxy(w, v);
			cout << "$";
		}
		gotoxy(kb - 4, hb);
		cout << " ";
		timer1 = 1;
		counter1 = 3;
	}
}
void bomb_destroy2(void) {
	if (counter2 == 0) {
		if (((a == kb - 1) && (b == hb - 1)) || ((a == kb - 9) && (b == hb - 1)) || ((a == kb - 17) && (b == hb - 1)) || ((a == kb + 7) && (b == hb - 1)) || ((a == kb + 15) && (b == hb - 1))) {
			gotoxy(a, b);
			cout << " ";
			a = 4;
			b = 38;
			gotoxy(4, 38);
			cout << "@";
		}
		gotoxy(kb - 4, hb);
		cout << " ";
		timer2 = 1;
		counter2 = 3;
	}
}
void fPositions1(void) {
	if ((b == 2)) {
		switch (a) {
		case 12:
			if (n == 6 || n == 5 || n == 4 || n == 3 || n == 2) {
				gotoxy(100, 10);
				cout << "player 1: you can not move , you need just one place to WIN!!";
				turn = 0;
				p();
			}
			break;
		case 20:
			if (n == 6 || n == 5 || n == 4 || n == 3) {
				gotoxy(100, 10);
				cout << "player 1: you can not move ,you need just two places to WIN!!";
				turn = 0;
				p();
			}
			break;
		case 28:
			if (n == 6 || n == 5 || n == 4) {
				gotoxy(100, 10);
				cout << "player 1: you can not move ,you need just three places to WIN!!";
				turn = 0;
				p();
			}
			break;
		case 36:
			if (n == 6 || n == 5) {
				gotoxy(100, 10);
				cout << "player 1: you can not move ,you need just four places to WIN!!";
				turn = 0;
				p();
			}
			break;
		case 44:
			if (n == 6) {
				gotoxy(100, 10);
				cout << "player 1: you can not move ,you need just five places to WIN!!";
				turn = 0;
				p();
			}
			break;
		default:
			break;
		}

	}
}
void fPositions2(void) {
	if ((v == 2)) {
		switch (w) {
		case 12:
			if (n == 6 || n == 5 || n == 4 || n == 3 || n == 2) {
				gotoxy(100, 11);
				cout << "player2: you can not move , you need just one place to WIN!!";
				turn = 1;
				p();
			}
			break;
		case 20:
			if (n == 6 || n == 5 || n == 4 || n == 3) {
				gotoxy(100, 11);
				cout << "player2:  you can not move ,you need just two places to WIN!!";
				turn = 1;
				p();
			}
			break;
		case 28:
			if (n == 6 || n == 5 || n == 4) {
				gotoxy(100, 11);
				cout << "player2:  you can not move ,you need just three places to WIN!!";
				turn = 1;
				p();
			}
			break;
		case 36:
			if (n == 6 || n == 5) {
				gotoxy(100, 11);
				cout << "player2:  you can not move ,you need just four places to WIN!!";
				turn = 1;
				p();
			}
			break;
		case 44:
			if (n == 6) {
				gotoxy(100, 11);
				cout << "player2: you can not move ,you need just five places to WIN!!";
				turn = 1;
				p();
			}
			break;
		default:
			break;
		}
	}
}
void option(void) {
	int optselection;
	gotoxy(82, 15); cout << "1.number of the bomb";
	gotoxy(82, 19); cout << "2.back";
	gotoxy(82, 20);
	cin >> optselection;
	switch (optselection) {
	case 1:
		gotoxy(60, 24);
		cout << "you can now choose between 0 to 5 for your desired numbers of the bombs :";
		gotoxy(82, 25);
		cin >> bombnumber;
		bnumber1 = bombnumber;
		bnumber2 = bombnumber;
		gotoxy(60, 24); cout << "                                                                         ";
		gotoxy(82, 25); cout << "     ";
		gotoxy(70, 24);
		cout << " your changes has been applied";
		Sleep(2000);
		gotoxy(70, 24);
		cout << "                               ";
		option();
		break;
	case 2:
		system("cls");
		menu();
		break;
	default:
		gotoxy(75, 24);
		cout << "inavlid key !!!!!!!!!!";
		Sleep(2000);
		gotoxy(82, 24);
		cout << "                         ";
		break;
	}
}
void finish(void) {

	if ((a == 4) && (b == 2)) {
		system("cls");
		system("color cf");
		gotoxy(60, 24);
		cout << "((((((((((((PLAYER ONE WINS)))))))))))";
		Sleep(10000);
		gotoxy(60, 24);
		cout << "                                      ";
		Sleep(1000);
		system("cls");
		menu();
	}
	if ((w == 4) && (v == 2)) {
		system("cls");
		system("color cf");
		gotoxy(60, 24);
		cout << "((((((((((((PLAYER TWO WINS)))))))))))";
		Sleep(10000);
		gotoxy(60, 24);
		cout << "                                      ";
		Sleep(1000);
		system("cls");
		menu();
	}

}

void save(void) {
	out.open("save.txt");
	out << a << endl << b << endl << w << endl << v << endl << bnumber1 << endl << bnumber2 << endl
		<< turn << endl;
	for (int i = 0; i < 7; i++) {
		out << ai[i] << endl;
		out << aj[i] << endl;
		out << bj[i] << endl;
		out << bi[i] << endl;
		out << sp[i] << endl;
		out << sp1[i] << endl;
	}
}
void load(void) {
	in.open("save.txt");
	in >> a >> b >> w >> v >> bnumber1 >> bnumber2
		>> turn;
	for (int i = 0; i < 7; i++) {
		in >> ai[i];
		in >> aj[i];
		in >> bj[i];
		in >> bi[i];
		in >> sp[i];
		in >> sp1[i];
	}
}
