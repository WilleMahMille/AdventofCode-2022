



#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

int mapKey(int x, int y) {
	return (y * 10000) + x;
}

int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	int xpos[10] = { 0 };
	int ypos[10] = { 0 };

	map<int, int> visited;


	while (!f.eof()) {
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
			xpos[0] += dx;
			ypos[0] += dy;
			for (int j = 0; j < 9; j++) {
				int headX = xpos[j];
				int headY = ypos[j];
				int tailX = xpos[j + 1];
				int tailY = ypos[j + 1];
				if (abs(headX - tailX) == 2) {
					xpos[j + 1] += (headX - tailX) / 2;
					if (abs(headY - tailY) == 1) {
						ypos[j + 1] += headY - tailY;
					}
				}
				if (abs(headY - tailY) == 2) {
					ypos[j + 1] += (headY - tailY) / 2;
					if (abs(headX - tailX) == 1) {
						xpos[j + 1] += headX - tailX;
					}
				}
				
			}
			visited[mapKey(xpos[9], ypos[9])] = 1;
			
		}

	}

	std::cout << visited.size() << "\n";
}


