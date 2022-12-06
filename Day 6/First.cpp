

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


int main() {
	fstream f;
	f.open("input.txt");
	string line = "";

	getline(f, line);
	string marks = "";
	for (int i = 0; i < line.length(); i++) {
		int find = marks.find(line[i]);
		if (find == string::npos) {
			marks.push_back(line[i]);
		}
		else {
			marks = marks.substr(find+1, marks.length());
			marks.push_back(line[i]);
		}
		if (marks.length() == 4) {
			std::cout << i + 1 << "\n";
			break;
		}
	}


}



