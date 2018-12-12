#include <iostream>
#include <cstdlib>

using namespace std;

int x;

void menu(void);
void chart(void);
void about(void);
void back(void);
int main() {

	menu();


	cin.get();
	cin.get();

	return 0;
}

void chart(void) {
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
	}

	back();

}
