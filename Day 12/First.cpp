/*

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


bool checkDirection(vector<vector<char>>& map, int xpos, int ypos, int dx, int dy) {
	if (map.size() <= xpos + dx || 0 > xpos + dx || map[0].size() <= ypos + dy || 0 > ypos + dy) {
		return false;
	}
	if (map[xpos + dx][ypos + dy] == 'z' + 5) {
		return false;
	}
	int dist = map[xpos + dx][ypos + dy] - map[xpos][ypos];
	bool temp = dist >= -1;
	return temp;
}

void updateStepMap(vector<vector<char>>& map, vector<vector<int>>& stepmap) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			if (checkDirection(map, i, j, 1, 0)) {
				stepmap[i + 1][j] = stepmap[i][j] + 1 < stepmap[i + 1][j] ? stepmap[i][j] + 1 : stepmap[i + 1][j];
			}
			if (checkDirection(map, i, j, -1, 0)) {
				stepmap[i - 1][j] = stepmap[i][j] + 1 < stepmap[i - 1][j] ? stepmap[i][j] + 1 : stepmap[i - 1][j];

			}
			if (checkDirection(map, i, j, 0, 1)) {
				stepmap[i][j + 1] = stepmap[i][j] + 1 < stepmap[i][j + 1] ? stepmap[i][j] + 1 : stepmap[i][j + 1];

			}
			if (checkDirection(map, i, j, 0, -1)) {
				stepmap[i][j - 1] = stepmap[i][j] + 1 < stepmap[i][j - 1] ? stepmap[i][j] + 1 : stepmap[i][j - 1];
			}
		}
	}
}



int main() {
	fstream f;
	f.open("input.txt");
	string line = "";

	vector<vector<char>> map;

	int xstart = 0;
	int ystart = 0;
	int xgoal = 0;
	int ygoal = 0;
	int row = 0;
	while (!f.eof()) {
		getline(f, line);
		vector<char> temp = vector<char>();
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == 'S') {
				line[i] = 'a' - 1;
				xstart = row;
				ystart = i;
			}
			if (line[i] == 'E') {
				line[i] = 'z' + 1;
				xgoal = row;
				ygoal = i;
			}
			temp.push_back(line[i]);

		}
		row++;
		map.push_back(temp);
		
	}
	vector<vector<int>> stepmap;
	for (int i = 0; i < map.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < map[0].size(); j++) {
			temp.push_back(10000);
		}
		stepmap.push_back(temp);
	}
	stepmap[xgoal][ygoal] = 0;
	for (int i = 0; i < map[0].size() * map.size() / 2; i++) {
		updateStepMap(map, stepmap);
	}

	std::cout << stepmap[xstart][ystart] << "\n";

}
*/

