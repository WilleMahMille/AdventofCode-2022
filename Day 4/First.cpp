
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


bool overlapping(int oneS, int oneE, int twoS, int twoE) {
	if (oneS <= twoS && oneE >= twoE) {
		return true;
	}
	if (twoS <= oneS && twoE >= oneE) {
		return true;
	}
	return false;
}

int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	int sum = 0;
	while (!f.eof()) {
		getline(f, line);
		int dash = line.find('-');
		int comma = line.find(',');
		int oneStart = stoi(line.substr(0, dash));
		int oneEnd = stoi(line.substr(dash + 1, comma));
		string partTwo = line.substr(comma + 1, line.length());
		dash = partTwo.find('-');
		int twoStart = stoi(partTwo.substr(0, dash));
		int twoEnd = stoi(partTwo.substr(dash + 1, partTwo.length()));
		sum += overlapping(oneStart, oneEnd, twoStart, twoEnd);

	}
	std::cout << sum << "\n";
}


