

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


class Monkey {
private:
	char operation;
	int var;
	long long int divNum;
	vector<long long int> items;
	int falseMonkey;
	int trueMonkey;
	int monkeyNum;
	int itemsInspected = 0;
public:
	Monkey(vector<long long int> items, char operation, int var, int divNum, int falseMonkey, int trueMonkey) {
		this->items = items;
		this->operation = operation;
		this->var = var;
		this->divNum = divNum;
		this->falseMonkey = falseMonkey;
		this->trueMonkey = trueMonkey;
	}

	void operate() {
		itemsInspected++;
		long long int temp = this->var == -1 ? items[0] : this->var;
		switch (this->operation)
		{
		case 'A':
			items[0] += temp;
			break;
		case 'M':
			items[0] *= temp;
			break;
		default:
			std::cout << "error\n";
			break;
		}
	}
	int test() {
		this->operate();
		items[0] /= 3;
		if (items[0] % this->divNum == 0) {
			return this->trueMonkey;
		}
		return this->falseMonkey;
	}
	long long int itemThrow() {
		long long int temp = items[0];
		this->items.erase(this->items.begin());
		return temp;
	}
	bool hasRound() {
		return this->items.size() != 0;
	}
	int getInspected() {
		return itemsInspected;
	}
	void receiveItem(long long int item) {
		items.push_back(item);
	}

};

vector<long long int> parseItems(string items) {
	int start = 0;
	vector<long long int> itemVec;
	for (int i = 0; i < items.length(); i++) {
		if (items[i] == ',') {
			itemVec.push_back(stoi(items.substr(start, i - start)));
			start = i + 1;
		}
	}
	itemVec.push_back(stoi(items.substr(start, items.length())));
	return itemVec;
}

Monkey parseMonkey(vector<string> line) {
	vector<long long int> items = parseItems(line[1].substr(17, line[1].length()));
	char op = line[2][23];
	switch (op) {
	case '*':
		op = 'M';
		break;
	case '+':
		op = 'A';
		break;
	default:
		std::cout << "wrong operator\n";
		break;
	}
	string strVar = line[2].substr(25, line[2].length());
	int var = -1;
	if (strVar != "old") {
		var = stoi(strVar);
	}
	int divNum = stoi(line[3].substr(21, line[3].length()));
	int trueMonkey = stoi(line[4].substr(line[4].find('y') + 1, line[4].length()));
	int falseMonkey = stoi(line[5].substr(line[5].find('y') + 1, line[5].length()));

	Monkey monkey = Monkey(items, op, var, divNum, falseMonkey, trueMonkey);
	return monkey;
}

int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	vector<Monkey> monkeys;

	while (!f.eof()) {
		vector<string> temp = vector<string>();
		getline(f, line);
		while (!f.eof() && line != "") {
			temp.push_back(line);
			getline(f, line);
		}
		temp.push_back(line);
		monkeys.push_back(parseMonkey(temp));
	}
	std::cout << "loaded monkeys\n";

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < monkeys.size(); j++) {
			while (monkeys[j].hasRound()) {
				int thrownTo = monkeys[j].test();
				long long int item = monkeys[j].itemThrow();
				if (item < 0) {
					std::cout << "overflowed\n";
				}
				monkeys[thrownTo].receiveItem(item);
			}
		}
	}

	int max[2] = { 0 };
	int index[2] = { 0 };
	for (int i = 0; i < monkeys.size(); i++) {
		if (monkeys[i].getInspected() > max[0]) {
			max[1] = max[0];
			index[1] = index[0];
			max[0] = monkeys[i].getInspected();
			index[0] = i;
		}
		else if (monkeys[i].getInspected() > max[1]) {
			max[1] = monkeys[i].getInspected();
			index[1] = i;
		}
	}
	std::cout << max[0] * max[1] << "\n";

}


