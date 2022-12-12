#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	int temp = 0;
	int elf = 0;
	int it = 0;
	int topthree[] = {0, 0, 0};
	fstream f;
	f.open("input.txt");
	while (!f.eof()) {
		it++;
		string res = "";
		getline(f, res);
		if (res != "") {
			temp += stoi(res);
		}
		else {
			for (int i = 0; i < 3; i++) {
				if (topthree[i] < temp) {
					int temptwo = topthree[i];
					topthree[i] = temp;
					temp = temptwo;
				}
			}
			temp = 0;
		}

	}
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += topthree[i];
	}
	std::cout << sum << " by elf on line " << elf << "\n";
}


