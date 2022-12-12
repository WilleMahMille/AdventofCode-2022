
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


long long int monkeyOP(long long int old, int monkey) {
	switch (monkey) {
	case 0:
		return old * 19;
	case 1:
		return old * 11;
	case 2:
		return old + 6;
	case 3:
		return old + 5;
	case 4:
		return old + 7;
	case 5:
		return old * old;
	case 6:
		return old + 2;
	case 7:
		return old + 3;
	default:
		std::cout << "incorrect monkey\n";
		return 0;
	}
}

int monkeyTE(long long int item, int monkey) {
	switch (monkey) {
	case 0:
		return item % 17 == 0 ? 4 : 7;
	case 1:
		return item % 3 == 0 ? 3 : 2;
	case 2:
		return item % 19 == 0 ? 0 : 4;
	case 3:
		return item % 7 == 0 ? 2 : 0;
	case 4:
		return item % 2 == 0 ? 7 : 5;
	case 5:
		return item % 5 == 0 ? 1 : 6;
	case 6:
		return item % 11 == 0 ? 3 : 1;
	case 7:
		return item % 13 == 0 ? 5 : 6;
	default:
		std::cout << "incorrect monkey\n";
		return -1;
	}
}

vector<vector<long long int>> items = { {72, 64, 51, 57, 93, 97, 68}, {62},
		{57, 94, 69, 79, 72}, {80, 64, 92, 93, 64, 56}, {70, 88, 95, 99, 78, 72, 65, 94},
		{57, 95, 81, 61}, {79, 99}, {68, 98, 62} };

/*
vector<vector<int>> items = { {79, 98}, {54, 65, 75, 74}, {79, 60, 97}, {74} };
long long int monkeyOP(long long int old, int monkey) {
	switch (monkey) {
	case 0:
		return old * 19;
	case 1:
		return old + 6;
	case 2:
		return old * old;
	case 3:
		return old + 3;
	default:
		std::cout << "incorrect monkey\n";
		return 0;
	}
}
int monkeyTE(int item, int monkey) {
	switch (monkey) {
	case 0:
		return item % 23 == 0 ? 2 : 3;
	case 1:
		return item % 19 == 0 ? 2 : 0;
	case 2:
		return item % 13 == 0 ? 1 : 3;
	case 3:
		return item % 17 == 0 ? 0 : 1;
	default:
		std::cout << "incorrect monkey\n";
		return -1;
	}
}
*/

int main() {
	// i dont care anymore :)
	
	
	int itemInspections[8] = { 0 };
	for (int i = 0; i < 10'000; i++) {
		for (int j = 0; j < 8; j++) {
			while (items[j].size() > 0) {
				long long int item = monkeyOP(items[j][0], j);
				item = item % (17 * 3 * 19 * 7 * 2 * 5 * 11 * 13); //9'699'690;
				int to = monkeyTE(item, j);
				itemInspections[j]++;
				if (item < 0) {
					std::cout << "overflowed\n";
				}
				items[to].push_back(item);
				items[j].erase(items[j].begin());
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		std::cout << itemInspections[i] << "\n";
	}
	std::cout << "done\n";

}

