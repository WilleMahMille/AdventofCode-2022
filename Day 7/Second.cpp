

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

struct Directory {
	Directory() {
		subDirectories = vector<Directory*>();
	}
	vector<Directory*> subDirectories;
	Directory* parent;
	int size = 0;
	string name = "";
	void calcAllTotalSize() {
		for (Directory* subdir : subDirectories) {
			subdir->calcAllTotalSize();
			size += subdir->size;
		}
	}
	void getAllAboveSize(int maxSize, vector<Directory*>* list) {
		if (maxSize <= size) {
			list->push_back(this);
		}
		for (Directory* subdir : subDirectories) {
			subdir->getAllAboveSize(maxSize, list);
		}
	}
	Directory* getSub(string name) {
		for (Directory* subdir : subDirectories) {
			if (subdir->name == name) {
				return subdir;
			}
		}
		return nullptr;
	}
};




int main() {
	fstream f;
	f.open("input.txt");
	string line = "";
	Directory* root = new Directory();
	root->name = "Root";
	Directory* currentDir = root;
	while (!f.eof()) {
		getline(f, line);

		if (line[0] == '$') {
			string command = line.substr(2, 2);
			if (command == "cd") {
				string arg = line.substr(5, line.length());
				if (arg == "..") {
					currentDir = currentDir->parent;
				}
				else if (arg == "/") {
					currentDir = root;
				}
				else {
					currentDir = currentDir->getSub(arg);
				}
			}
		}
		else {
			if (line.substr(0, 3) == "dir") {
				string name = line.substr(4, line.length());
				Directory* temp = new Directory();
				temp->name = name;
				temp->parent = currentDir;
				currentDir->subDirectories.push_back(temp);
			}
			else {
				int size = stoi(line.substr(0, line.find(' ')));
				currentDir->size += size;
			}
		}

	}
	//root -> ctd ->gzcjrs
	root->calcAllTotalSize();
	int requiredSpace = 30'000'000 - (70'000'000 - root->size);
	vector<Directory*> list;
	root->getAllAboveSize(requiredSpace, & list);
	int max = INT_MAX;
	for (Directory* dir : list) {
		max = max < dir->size ? max : dir->size;
	}
	std::cout << max << "\n";
}


