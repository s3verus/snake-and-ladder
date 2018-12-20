#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdio>


using namespace std;

int x;
int n;
int sc = 1;
void one();
void two();
void three();
void four();
void five();
void six();
void sal(void);
void start();
void dice();
void gotoxy(int, int);
void p(void);
void p1(void);
void p2(void);
void menu(void);
void chart(void);
void about(void);
void back(void);

int main() {
	system("title snake and ladder");
	menu();


	cin.get();
	cin.get();

	return 0;
}

void chart(void) {
	system("color D4");
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

	p1();
	p2();
	sal();

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
	system("color B3");
	cout << "1.start\n"
		<< "2.option\n"
		<< "3.load\n"
		<< "4.help\n"
		<< "5.about\n"
		<< "6.exit\n";
	cin >> x;

	switch (x) {
	case 1:
		system("cls");
		chart();
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
		cout << "invalid key!!";
		Sleep(2000);
		system("cls");
		menu();
	/*	clock_t time;
		time = 2000;
		cout << time;
		while(clock() < time) {
			cout << "invalid key!! you can choose between 1 to 6";
		}*/
		break;
	}

	back();

}
void p(void) {
	gotoxy(100, 30); cout << "1.dice";
	gotoxy(100, 31); cout << "2.bomb";
	gotoxy(100, 32); cout << "3.save";
	gotoxy(100, 33); cout << "4.back";
	gotoxy(100, 34); cout << "0.exit";
	gotoxy(0, 41);

	cin >> x;
	switch (x) {
	case 1:
			while (int turn = 1) {
				dice();
				p();
				if (n == 6) {
					p();
					continue;
				}
				turn--;
				continue;
			}
			while (int turn = 0) {
				dice();
				p();
				if (n == 6) {
					p();
					continue;
				}
				turn++;
				continue;
			}
			break;
	case 2:
		cout << "65666";
		break;
	case 3:
		cout << "3434343";
		break;
	case 4:
		system("cls");
		menu();
		break;
	case 0:
		exit(0);
		break;
	default:
		/*clock_t time;
		time = clock();
		while (clock() < time) {
			cout << "invalid key!!";
		}*/

		break;

	}

}

void p1(void) {
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
		start();
		break;
	default:
		cout << "invalid number";

	}
}

void sal(void) {
	for (int i = 3; i <= 80; i += 8) {
		for (int j = 1; j <= 40; j += 4) {
			gotoxy(i, j);
			cout << i << j;
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

void start(void) {


		while (sc == 1) {
			gotoxy(4, 38); cout << "@";
			sc--;
		}
}

void gotoxy(int x, int y) {

	COORD coord{ 0,0 };
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
