
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int getCol(int index) {
	return (index - 1) / 4;
}

vector<vector<char>> buildStructure(fstream* f) {
	vector<vector<char>> structure;
	for (int i = 0; i < 9; i++) {
		structure.push_back(vector<char>());
	}
	string line = "";
	getline(*f, line);
	while (line[1] != '1') {
		for (int i = 1; i < line.length(); i += 4) {
			if (line[i] != ' ') {
				int col = getCol(i);
				structure[col].insert(structure[col].begin(), line[i]);
			}
		}
		getline(*f, line);
	}
	getline(*f, line);
	return structure;
}

void moveCrates(int from, int to, int count, vector<vector<char>>& structure) {
	int size = structure[from].size() - 1;
	for (int i = 0; i < count; i++) {
		int size = structure[from].size() - 1;
		char c = structure[from][size];
		structure[from].pop_back();
		structure[to].push_back(c);
	}
}

int main() {
	fstream f;
	f.open("input.txt");
	//build crane structure

	vector<vector<char>> structure = buildStructure(&f);
	string line = "";
	while (!f.eof()) {
		getline(f, line);
		int start = 4;
		int end = line.find('f') - 2;
		int count = stoi(line.substr(start, start - end));
		start = end + 6;
		end = line.find('t') - 2;
		int from = stoi(line.substr(start, start - end)) - 1;
		start = end + 4;
		end = line.length();
		int to = stoi(line.substr(start, start - end)) - 1;
		moveCrates(from, to, count, structure);
	}
	for (int i = 0; i < structure.size(); i++) {
		int size = structure[i].size();
		if (size > 0) {
			std::cout << structure[i][size-1];
		}
	}
	std::cout << "\n";


}

