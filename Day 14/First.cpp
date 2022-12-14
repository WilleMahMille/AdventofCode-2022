

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void FillRock(int xStart, int yStart, int xEnd, int yEnd, vector<vector<int>>& map) {
	xStart = xStart - 400;
	xEnd = xEnd - 400;
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


void AddRock(string line, vector<vector<int>> &map) {
	int commaPos = line.find(',');
	int arrowPos = line.find('-');
	int xStart = stoi(line.substr(0, commaPos)); 
	int yStart = stoi(line.substr(commaPos + 1, arrowPos - commaPos - 1)); 
	int xEnd, yEnd;
	while (arrowPos != string::npos) {
		line = line.substr(arrowPos + 3, line.length());
		xEnd = stoi(line.substr(0, commaPos));
		yEnd = stoi(line.substr(commaPos + 1, arrowPos - commaPos - 1));
		FillRock(xStart, yStart, xEnd, yEnd, map);
		xStart = xEnd;
		yStart = yEnd;
		commaPos = line.find(',');
		arrowPos = line.find('-');
	}
	xEnd = stoi(line.substr(0, commaPos));
	yEnd = stoi(line.substr(commaPos + 1, arrowPos - commaPos - 1));
	FillRock(xStart, yStart, xEnd, yEnd, map);
}

int FindSandCount(vector<vector<int>> sandMap) {
	int xSand = 100;
	int ySand = 0;
	int sandCount = 0;
	while(ySand < 199){
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
			xSand = 100;
		}
	}
	return sandCount;
}


int main() {
	vector<vector<int>> sandMap;
	for (int i = 0; i < 200; i++) {
		vector<int> temp = vector<int>(200, 0);
		sandMap.push_back(temp);
	}
	fstream f;
	f.open("input.txt");
	string line = "";
	while (!f.eof()) {
		getline(f, line);
		AddRock(line, sandMap);


	}
	int sandCount = FindSandCount(sandMap);
	std::cout << sandCount << "\n";
}


