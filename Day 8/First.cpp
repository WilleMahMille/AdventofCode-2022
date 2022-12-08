/*

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

const int mapSize = 99;

short binaryMap[mapSize][mapSize] = {0};
short treeMap[mapSize][mapSize] = {};

void checkDirection(int xStart, int yStart, int dx, int dy) {
	int xIndex = xStart;
	int yIndex = yStart;
	int max = -1;
	for (int i = 0; i < mapSize; i++) {
		if (treeMap[xIndex][yIndex] > max) {
			max = treeMap[xIndex][yIndex];
			binaryMap[xIndex][yIndex] = 1;
		}
		xIndex += dx;
		yIndex += dy;
	}
}

int countBinaryMap() {
	int counter = 0;
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (binaryMap[i][j] == 1) {
				counter++;
			}
		}
	}
	return counter;
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
		checkDirection(i, 0, 0, 1);
	}
	for (int i = 0; i < mapSize; i++) {
		checkDirection(i, mapSize - 1, 0, -1);
	}
	for (int i = 0; i < mapSize; i++) {
		checkDirection(0, i, 1, 0);
	}
	for (int i = 0; i < mapSize; i++) {
		checkDirection(mapSize - 1, i, -1, 0);
	}
	std::cout << countBinaryMap() << "\n";

}


*/