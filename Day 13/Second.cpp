

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

struct Element {
public:
	vector<Element> values;
	bool isArray = false;
	int value = 0;
	void makeArray() {
		Element temp;
		temp.isArray = false;
		temp.value = this->value;
		this->values.push_back(temp);
		this->isArray = true;

	}
	int operator<(Element a) {
		// -1 and 1 means a is larger, 0 means a is smaller
		if (this->isArray + a.isArray == 1) {
			if (this->isArray) {
				a.makeArray();
			}
			else {
				this->makeArray();
			}
		}
		if (this->isArray) {
			for (int i = 0; i < this->values.size(); i++) {
				if (a.values.size() == i) {
					return 0;
				}
				int comp = this->values[i] < a.values[i];
				if (comp == 0) {
					return 0;
				}
				if (comp == -1) {
					return -1;
				}
			}
			if (this->values.size() < a.values.size()) {
				return -1;
			}
			if (this->values.size() == a.values.size()) {
				return 1;
			}
			return 0;
		}
		if (value < a.value) {
			return -1;
		}
		if (value > a.value) {
			return 0;
		}
		return 1;



	}
};

int findEndingBracket(string str) {
	int layer = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ']') {
			layer--;
		}
		if (str[i] == '[') {
			layer++;
		}
		if (layer == 0) {
			return i;
		}
	}
	return str.length();
}

vector<string> split(string str) {
	vector<string> res;
	int commaPos = 0;
	int bracketPos = 0;
	while (true) {
		commaPos = str.find(',');
		if (commaPos == 0) {
			str = str.substr(1, str.length());
		}
		else {
			bracketPos = str.find('[');
			if (commaPos == bracketPos && commaPos == string::npos) {
				break;
			}
			commaPos = commaPos < 0 ? 10000 : commaPos;
			bracketPos = bracketPos < 0 ? 10000 : bracketPos;
			if (commaPos < bracketPos) {
				res.push_back(str.substr(0, commaPos));
				str = str.substr(commaPos + 1, str.length());
			}
			else {
				int temp = findEndingBracket(str.substr(bracketPos, str.length()));
				res.push_back(str.substr(bracketPos, temp + 1 - bracketPos));
				str = str.substr(temp + 1, str.length());
			}
		}
	}
	if (str.length() > 0) {
		res.push_back(str);
	}
	return res;
}

Element ParseElement(string str) {
	vector<string> objects = split(str.substr(1, str.length() - 2));
	Element el;
	el.isArray = true;
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i][0] == '[') {
			el.values.push_back(ParseElement(objects[i]));
		}
		else {
			Element temp;
			temp.isArray = false;
			if (objects[i].length() == 0) {
				temp.value = -1;
				temp.isArray = true;
			}
			else {
				temp.value = stoi(objects[i]);
			}
			el.values.push_back(temp);
		}
	}
	return el;
}

int getNumber(string num) {
	return stoi(num);
}

bool correctOrder(string left, string right) {
	if (left[0] == ',') {
		return correctOrder(left.substr(1, left.length()), right);
	}
	if (right[0] == ',') {
		return correctOrder(left, right.substr(1, right.length()));
	}
	if (left[0] != right[0]) {

		if (right[0] == ']') {
			return false;
		}
		if (left[0] == ']') {
			return true;
		}
		if (left[0] == '[' && right[0] != '[') {
			int comma = right.find(',');
			int bracket = right.find(']');
			comma = comma < 0 ? 10000 : comma;
			bracket = bracket < 0 ? 10000 : bracket;
			int stop = comma < bracket ? comma : bracket;
			right.insert(right.begin(), '[');
			right.insert(right.begin() + stop + 1, ']');
			return correctOrder(left, right);
		}
		if (right[0] == '[' && left[0] != '[') {
			int comma = left.find(',');
			int bracket = left.find(']');
			comma = comma < 0 ? 10000 : comma;
			bracket = bracket < 0 ? 10000 : bracket;
			int stop = comma < bracket ? comma : bracket;
			left.insert(left.begin(), '[');
			left.insert(left.begin() + stop + 1, ']');
			return correctOrder(left, right);
		}

		return getNumber(left) < getNumber(right);
	}
	else {
		return correctOrder(left.substr(1, left.length()), right.substr(1, right.length()));
	}
}

vector<Element> insertionSort(vector<Element> input) {
	vector<Element> res;
	res.push_back(input[0]);
	for (int i = 1; i < input.size(); i++) {
		bool inserted = false;
		for (int j = 0; j < res.size(); j++) {
			if (input[i] < res[j]) {
				res.insert(res.begin() + j, input[i]);
				inserted = true;
				break;
			}
		}
		if (!inserted) {
			res.push_back(input[i]);
		}
	}
	return res;
}

int main() {
	fstream f;
	f.open("input.txt");
	string lineOne = "";
	string lineTwo = "";
	vector<Element> elements;
	string divOne = "[[2]]";
	string divTwo = "[[6]]";
	elements.push_back(ParseElement(divOne));
	elements.push_back(ParseElement(divTwo));
	elements[0].value = -20;
	elements[1].value = -20;
	while (!f.eof()) {
		getline(f, lineOne);
		getline(f, lineTwo);
		Element eleOne = ParseElement(lineOne);
		Element eleTwo = ParseElement(lineTwo);
		elements.push_back(eleOne);
		elements.push_back(eleTwo);
		getline(f, lineOne);
	}
	
	vector<Element> sorted = insertionSort(elements);
	int product = 1;
	for (int i = 0; i < sorted.size(); i++) {
		if (sorted[i].value == -20) {
			product *= (i+1);
		}
	}
	std::cout << product;
}


