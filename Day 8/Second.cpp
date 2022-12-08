

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

const int mapSize = 99;

int scenicMap[mapSize][mapSize] = { 0 };
short treeMap[mapSize][mapSize] = {};

void checkTree(int xStart, int yStart) {
	if (xStart == mapSize - 1 || xStart == 0 || yStart == mapSize - 1 || yStart == 0) {
		scenicMap[xStart][yStart] = 0;
		return;
	}
	int scenicScore = 1;
	int treeHeight = treeMap[xStart][yStart];
	int tempScore = 1;
	for (int i = xStart - 1; i >= 0; i--) {
		if (treeHeight > treeMap[i][yStart] && i != 0) {
			tempScore++;
		}
		else {
			break;
		}
	}
	scenicScore *= tempScore;
	tempScore = 1;
	for (int i = yStart - 1; i >= 0; i--) {
		if (treeHeight > treeMap[xStart][i] && i != 0) {
			tempScore++;
		}
		else {
			break;
		}
	}
	scenicScore *= tempScore;
	tempScore = 1;
	for (int i = xStart + 1; i < mapSize; i++) {
		if (treeHeight > treeMap[i][yStart] && i != mapSize - 1) {
			tempScore++;
		}
		else {
			break;
		}
	}
	scenicScore *= tempScore;
	tempScore = 1;
	for (int i = yStart + 1; i < mapSize; i++) {
		if (treeHeight > treeMap[xStart][i] && i != mapSize -1) {
			tempScore++;
		}
		else {
			break;
		}
	}
	scenicScore *= tempScore;
	scenicMap[xStart][yStart] = scenicScore;
}

int checkScenicMap() {
	int max = 0;
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			max = max < scenicMap[i][j] ? scenicMap[i][j] : max;
		}
	}
	return max;
}


int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	int row = 0;
	while (!f.eof()) {
		getline(f, line);

		for (int i = 0; i < line.length(); i++) {
			int temp = line[i] - '0';
			treeMap[row][i] = temp;
		}
		row++;
	}
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			checkTree(i, j);
		}
	}
	std::cout << checkScenicMap() << "\n";

}


