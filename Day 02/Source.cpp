#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool winner(char me, char opp) {
	if (me == 'Y' && opp == 'A') { //paper beats rock
		return true;
	}
	if (me == 'Z' && opp == 'B') { //scissors beats paper
		return true;
	}
	if (me == 'X' && opp == 'C') { //rock beats scissor
		return true;
	}
	return false;
}

int calculateScore(char me, char opp) {
	
	int score = 0;
	switch (me) {
	case 'X':
		score += (opp - 'A' + 2) % 3 + 1;
		break;
	case 'Y':
		score += (opp - 'A') % 3 + 1 + 3;
		break;
	case 'Z':
		score += (opp - 'A' + 1) % 3 + 1 + 6;
		break;
	}
	return score;
}

int main() {

	fstream f;
	f.open("input.txt");
	string line = "";
	int total = 0;
	while (!f.eof()) {
		getline(f, line);
		char me = line[2];
		char opp = line[0];
		total += calculateScore(me, opp);
	}
	std::cout << total << "\n";

}
