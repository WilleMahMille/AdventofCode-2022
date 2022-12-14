

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void FillRock(int xStart, int yStart, int xEnd, int yEnd, vector<vector<int>>& map) {
	xStart = xStart;
	xEnd = xEnd;
	if (xStart > xEnd) {
		int temp = xStart;
		xStart = xEnd;
		xEnd = temp;
	}
	if (yStart > yEnd) {
		int temp = yStart;
		yStart = yEnd;
		yEnd = temp;
	}
	for (int i = xStart; i <= xEnd; i++) {
		for (int j = yStart; j <= yEnd; j++) {
			map[i][j] = 5;
		}
	}
}


int AddRock(string line, vector<vector<int>>& map) {
	//returns largest y-value
	int commaPos = line.find(',');
	int arrowPos = line.find('-');
	int xStart = stoi(line.substr(0, commaPos));
	int yStart = stoi(line.substr(commaPos + 1, arrowPos - commaPos - 1));
	int maxY = yStart;
	int xEnd, yEnd;
	while (arrowPos != string::npos) {
		line = line.substr(arrowPos + 3, line.length());
		xEnd = stoi(line.substr(0, commaPos));
		yEnd = stoi(line.substr(commaPos + 1, arrowPos - commaPos - 1));
		FillRock(xStart, yStart, xEnd, yEnd, map);
		maxY = maxY > yEnd ? maxY : yEnd;
		xStart = xEnd;
		yStart = yEnd;
		commaPos = line.find(',');
		arrowPos = line.find('-');
	}
	xEnd = stoi(line.substr(0, commaPos));
	yEnd = stoi(line.substr(commaPos + 1, arrowPos - commaPos - 1));
	FillRock(xStart, yStart, xEnd, yEnd, map);
	maxY = maxY > yEnd ? maxY : yEnd;
	return maxY;
}

int FindSandCount(vector<vector<int>> sandMap) {
	int xSand = 500;
	int ySand = 0;
	int sandCount = 0;
	while (sandMap[500][0] == 0) {
		if (sandMap[xSand][ySand + 1] == 0) {
			ySand++;
		}
		else if (sandMap[xSand - 1][ySand + 1] == 0) {
			xSand--;
			ySand++;
		}
		else if (sandMap[xSand + 1][ySand + 1] == 0) {
			xSand++;
			ySand++;
		}
		else {
			sandMap[xSand][ySand] = 1;
			sandCount++;
			ySand = 0;
			xSand = 500;

		}
	}
	return sandCount;
}


int main() {
	int maxY = 0;
	vector<vector<int>> sandMap;
	for (int i = 0; i < 1000; i++) {
		vector<int> temp = vector<int>(200, 0);
		sandMap.push_back(temp);
	}
	fstream f;
	f.open("input.txt");
	string line = "";
	while (!f.eof()) {
		getline(f, line);
		int temp = AddRock(line, sandMap);
		maxY = temp > maxY ? temp : maxY;

	}
	FillRock(0, maxY+2, 999, maxY+2, sandMap);
	int sandCount = FindSandCount(sandMap);
	std::cout << sandCount << "\n";
}


