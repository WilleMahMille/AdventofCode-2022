/*

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

int mapKey(int x, int y) {
	return (y << 8) + x;
}

int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	int headX = 0;
	int headY = 0;
	int tailX = 0;
	int tailY = 0;

	map<int, int> visited;
	getline(f, line);
	char direction = line[0];
	int steps = stoi(line.substr(2, line.length()));
	int dx = 0;
	int dy = 0;
	switch (direction) {
	case 'R':
		dx = 1;
		break;
	case 'L':
		dx = -1;
		break;
	case 'U':
		dy = 1;
		break;
	case 'D':
		dy = -1;
		break;
	}

	for (int i = 0; i < steps; i++) {
		headX += dx;
		headY += dy;
		if (abs(headX - tailX) == 2) {
			tailX += dx;
			if (abs(headY - tailY) == 1) {
				tailY += headY - tailY;
			}
		}
		if(abs(headY - tailY) == 2) {
			tailY += dy;
			if (abs(headX - tailX) == 1) {
				tailX += headX - tailX;
			}
		}
		visited[mapKey(tailX, tailY)] = 1;
	}

	while (!f.eof()) {
		getline(f, line);
		
		direction = line[0];
		steps = stoi(line.substr(2, line.length()));
		dx = 0;
		dy = 0;
		switch (direction) {
		case 'R':
			dx = 1;
				break;
		case 'L':
			dx = -1;
			break;
		case 'U':
			dy = 1;
			break;
		case 'D':
			dy = -1;
			break;
		}

		for (int i = 0; i < steps; i++) {
			headX += dx;
			headY += dy;
			if (abs(headX - tailX) == 2) {
				tailX += dx;
				if (abs(headY - tailY) == 1) {
					tailY += headY - tailY;
				}
			}
			if (abs(headY - tailY) == 2) {
				tailY += dy;
				if (abs(headX - tailX) == 1) {
					tailX += headX - tailX;
				}
			}
			visited[mapKey(tailX, tailY)] = 1;
		}

	}

	std::cout << visited.size() << "\n";
}


*/