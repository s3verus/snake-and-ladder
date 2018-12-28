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
int c = 3;
int v = 38;
int a = 4;
int b = 38;
int w = 4;
int x;
int n;
int sc1 = 1;
int sc2 = 1;
int turn = 1;
int k = 1;
int l = 1;
int l2 = 1;
int ai[7];
int aj[7];
int sl = 0;
int ti = 0;
int tj = 0;
int i = 4;
int j = 1;
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
void notp(void);
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
//void fs();

int main() {
	system("title snake and ladder");
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 10000, 10000, TRUE); // 800 width, 100 height
	menu();

	cin.get();
	cin.get();

	return 0;
}

void chart(void) {
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
	cout << "we dicided to design a game in cpp type \n"
		<< "and this is a game about a snake-and-ladder chart \n"
		<< "with some fun options included in the game \n"
		<< "and the game is gonig to be design by \n"
		<< "three-of-use (.Benyamin Ghahremani .Ali Abdollahi .Alireza Salimi)\n"
		<< "from iran for the university's project. \n"
		<< "           -HOPE YOU ENJOY IT-          \n";


	back();

}

void menu(void) {
	system("color  b3");
	gotoxy(0, 0); cout << "1.start";
	gotoxy(0, 1); cout << "2.option";
	gotoxy(0, 2); cout << "3.load";
	gotoxy(0, 3); cout << "4.help";
	gotoxy(0, 4); cout << "5.about";
	gotoxy(0, 5);
	/*HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(m_hConsole,
		//	FOREGROUND_RED |
		//	FOREGROUND_GREEN |
		FOREGROUND_RED |
		BACKGROUND_BLUE);*/
	//00000///SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "6.exit";
	gotoxy(0, 7);
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

		break;
	case 3:
		system("cls");

		break;
	case 4:
		system("cls");

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
		while (x == 1) {

			while (turn == 1) {
				gotoxy(111, 6); cout << "    ";
				gotoxy(111, 8); cout << "turn";
				dice();
				pm1();
				if (n == 6) {
					gotoxy(111, 8); cout << "    ";
					gotoxy(111, 6); cout << "turn";
					start1();
					p();
					pm1();
					continue;
				}
				turn--;
				p();
			}
			while (turn == 0) {
				gotoxy(111, 8); cout << "    ";
				gotoxy(111, 6); cout << "turn";
				dice();
				gotoxy(3, 38); cout << " ";
				pm2();
				if (n == 6) {
					gotoxy(111, 6); cout << "    ";
					gotoxy(111, 8); cout << "turn";
					start2();
					p();
					pm2();
					continue;
				}
				turn++;
				p();
			}
				continue;
			}
		break;
	case 2:
		break;
	case 3:
		//ofstream save("save.cpp");
		chart();
		k++;
		p();
		//save.close();
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
void notp(void) {
	int num = 100;
	int n1 = 1;
	for (int j = 3; j <= 40; j += 4) {
		if (n1 == 1) {
			for (int i = 5; i <= 80; i += 8) {
				gotoxy(i, j);
				cout << num;
				num--;
			}
			n1--;
		}
		else {
			for (int i = 77; i >= 5; i -= 8) {
				gotoxy(i, j);
				cout << num;
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
	//srand(time(NULL));
	while (sl < 7) {
		ti = i;
		tj = j;
		i = 8 * (1 + rand() % 9) - 4;
		j = 4 * (1 + rand() % 9) - 3;
		if ((i == 4 && j == 1) && (i == 4 && j == 37)) {
			continue;
		}
		if ((i != ti) && (j != tj)) {
			continue;
		}
			gotoxy(i, j);
			cout << "s<<";
			ai[sl] = i;
			aj[sl] = j;
			sl++;
	}
}
	void ldd(void){
	sl = 0;
	ti = 0;
	tj = 0;
	i = 4;
	j = 1;
	while (sl < 7) {
		ti = i;
		tj = j;
		//srand(time(NULL));
		i = 8 * (1 + rand() % 9) - 4;
		j = 4 * (1 + rand() % 9) - 3;
		for (sl = 0; sl < 7; sl++) {
			if (ai[sl] == i || aj[sl] == j) {
				//ldd();
			}
		}
		if ((i == 4 && j == 1) && (i == 4 && j == 37)) {
			continue;
		}
		if (i != ti || j != tj) {
			continue;
		}
		else {
			gotoxy(i, j);
			cout << "l>>";
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
		gotoxy(w-1, v); cout << "$";
		sc2--;
	}
}

void gotoxy(int x, int y) {

	COORD coord{ 0,0 };
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


void pm1(void){
	int h = 0;
if (sc1 == 0) {
	while (h < n) {
		if (a < 76 &&  (k1 % 2 == 0)) {
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
				if (a > 4 ) {
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

void pm2(void) {
	int h = 0;
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

void mouse(void) {

}
void changeColor(int h) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, h);
}
void ladder(void) {

}
