#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	fstream f;
	f.open("input.txt");
	string bag1 = "";
	string bag2 = "";
	string bag3 = "";
	int sum = 0;
	while (!f.eof()) {

		getline(f, bag1);
		getline(f, bag2);
		getline(f, bag3);

		for (int i = 0; i < bag1.length(); i++) {
			if (bag2.find(bag1[i]) != string::npos && bag3.find(bag1[i]) != string::npos) {
				if (bag1[i] >= 'a' && bag1[i] <= 'z') {
					sum += bag1[i] - 'a' + 1;
				}
				else {
					sum += bag1[i] - 'A' + 27;
				}
				break;
			}
		}
	}
	std::cout << sum << "\n";
}


