
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	int sum = 0;
	while (!f.eof()) {
		getline(f, line);
		string comp1 = line.substr(0, line.length() / 2);
		string comp2 = line.substr(line.length() / 2, line.length());
		string temp = "";
		for (int i = 0; i < comp1.length(); i++) {
			for (int j = 0; j < comp2.length(); j++) {
				if (comp1[i] == comp2[j] && temp.find(comp1[i]) == string::npos) {
					temp += comp1[i];
					if (comp1[i] >= 'a' && comp1[i] <= 'z') {
						sum += comp1[i] - 'a' + 1;
					}
					else {
						sum += comp1[i] - 'A' + 27;
					}
				}
			}
		}

	}
	std::cout << sum << "\n";
}

