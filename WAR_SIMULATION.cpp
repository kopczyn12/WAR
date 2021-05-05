#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct karta {
	short value;
	string label;
};

int main() {
	cout << "  ---------------------------------------  " << endl;
	cout << "  SYMULATOR GRY KARCIANEJ WOJNA (2 GRACZY)" << endl;
	cout << "  ---------------------------------------  " << endl;
	queue <karta> p1, p2;
	vector <karta> karty = { {2,"2 serce"},      {2,"2 karo"},      {2,"2 pik"},      {2,"2 trefl"},
							 {3,"3 serce"},      {3,"3 karo"},      {3,"3 pik"},      {3,"3 trefl"},
							 {4,"4 serce"},      {4,"4 karo"},      {4,"4 pik"},      {4,"4 trefl"},
							 {5,"5 serce"},      {5,"5 karo"},      {5,"5 pik"},      {5,"5 trefl"},
							 {6,"6 serce"},      {6,"6 karo"},      {6,"6 pik"},      {6,"6 trefl"},
							 {7,"7 serce"},      {7,"7 karo"},      {7,"7 pik"},      {7,"7 trefl"},
							 {8,"8 serce"},      {8,"8 karo"},      {8,"8 pik"},      {8,"8 trefl"},
							 {9,"9 serce"},      {9,"9 karo"},      {9,"9 pik"},      {9,"9 trefl"},
							 {10,"10 serce"},    {10,"10 karo"},    {10,"10 pik"},    {10,"10 trefl"},
							 {11,"walet serce"}, {11,"walet karo"}, {11,"walet pik"}, {11,"walet trefl"},
							 {12,"dama serce"},  {12,"dama karo"},  {12,"dama pik"},  {12,"dama trefl"},
							 {13,"krol serce"},  {13,"krol karo"},  {13,"krol pik"},  {13,"krol trefl"},
							 {14,"as serce"},    {14,"as karo"},    {14,"as pik"},    {14,"as trefl"} };

	random_shuffle(karty.begin(), karty.end());

	for (int i = 0; i < 26; i++) {
		p1.push(karty[i]);
	}
	for (int i = 26; i < 52; i++) {
		p2.push(karty[i]);
	}

	while (!p1.empty() && !p2.empty()) {
		cout << "Wcisnij x aby rozpoczac nastepna ture: ";
		char x;
		cin >> x;
		if (x != 'x') {
			continue;
		}
		if (p1.front().value > p2.front().value) {
			cout << "GRACZ 1: " << p1.front().label << endl;
			cout << "GRACZ 2: " << p2.front().label << endl;
			cout << "Wygrywa GRACZ 1" << endl << endl;
			p1.push(p1.front());
			p1.push(p2.front());
			p1.pop();
			p2.pop();
		}
		else if (p1.front().value < p2.front().value) {
			cout << "GRACZ 1: " << p1.front().label << endl;
			cout << "GRACZ 2: " << p2.front().label << endl;
			cout << "Wygrywa GRACZ 2" << endl << endl;
			p2.push(p2.front());
			p2.push(p1.front());
			p2.pop();
			p1.pop();
		}
		else {
			vector <karta> temp;
			while (p1.front().value == p2.front().value) {
				cout << "GRACZ 1: " << p1.front().label << endl;
				cout << "GRACZ 2: " << p2.front().label << endl;
				cout << "DOGRYWKA!" << endl << endl;
				temp.push_back(p1.front());
				temp.push_back(p2.front());
				p1.pop();
				p2.pop();
			}
			if (p1.front().value > p2.front().value) {
				cout << "GRACZ 1: " << p1.front().label << endl;
				cout << "GRACZ 2: " << p2.front().label << endl;
				cout << "Wygrywa GRACZ 1" << endl << endl;
				temp.push_back(p1.front());
				temp.push_back(p2.front());
				p1.pop();
				p2.pop();
				for (int i = 0; i < temp.size(); i++) {
					p1.push(temp[i]);
				}
				temp.clear();
			}
			else if (p1.front().value < p2.front().value) {
				cout << "GRACZ 1: " << p1.front().label << endl;
				cout << "GRACZ 2: " << p2.front().label << endl;
				cout << "Wygrywa GRACZ 2" << endl << endl;
				temp.push_back(p1.front());
				temp.push_back(p2.front());
				p1.pop();
				p2.pop();
				for (int i = 0; i < temp.size(); i++) {
					p2.push(temp[i]);
				}
				temp.clear();
			}
		}
	}
	if (p1.empty()) {
		cout << "GRE WYGRYWA GRACZ 2" << endl;
	}
	else {
		cout << "GRE WYGRYWA GRACZ 1" << endl;
	}
	return 0;
}