

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int image[100][100] = { 0 };
	fstream f;
	f.open("input.txt");
	string line = "";
	int cycle = 1;
	int registerValue = 1;
	int sum = 0;
	while (!f.eof()) {
		getline(f, line);
		int temp = 0;
		if (line[0] == 'a') {
			temp = stoi(line.substr(5, line.length()));
			cycle++;
			if ((cycle - 20) % 40 == 0 && cycle <= 220) {
				sum += registerValue * cycle;
			}
			if (cycle % 40 == 0) {
				std::cout << "\n";
			}
			if ((cycle - 1) % 40 >= registerValue - 1 && (cycle - 1) % 40 <= registerValue + 1) {
				std::cout << "#";
				image[(cycle - 1) % 40][(cycle - 1) / 6] = 1;
			}
			else {
				std::cout << ".";
				image[(cycle - 1) % 40][(cycle - 1) / 6] = 0;
			}
		}
		cycle++;
		registerValue += temp;
		if (cycle % 40 == 0) {
			std::cout << "\n";
		}
		if ((cycle - 20) % 40 == 0 && cycle <= 220) {
			sum += registerValue * cycle;
		}
		if ((cycle - 1) % 40 >= registerValue - 1 && (cycle - 1) % 40 <= registerValue + 1) {
			std::cout << "#";
			image[(cycle - 1) % 40][(cycle - 1) / 6] = 1;
		}
		else {
			std::cout << ".";
			image[(cycle - 1) % 40][(cycle - 1) / 40] = 0;
		}
	}
	std::cout << "\n\n";
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 40; j++) {
			std::cout << image[i][j];
		}
		std::cout << "\n";
	}
	std::cout << sum << "\n";
}


