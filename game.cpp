#include <iostream>
#include <cstdlib>

using namespace std;
void chart(void);
int main() {
	int x;

	cout << "1.start\n"
		<< "2.option\n"
		<< "3.load\n"
		<< "4.help\n"
		<< "5.about\n"
		<< "6.exit\n";
	cin >> x;
/*
	switch (x) {
	case 1:
		system("cls");
		chart();
		break;
	case 2:
		
	}
*/



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