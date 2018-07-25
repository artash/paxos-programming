#include <string>
#include <iostream>
#include <fstream>

#include "giftcards.h"

using namespace std;

void printUsage(const string& execName, const string& reason) {
	cout << reason << endl;
	cout << "Usage: " << execName << " <filename> <target>" << endl;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printUsage(argv[0], "Invalid number of arguments: " + std::to_string(argc));
	}

	string fileName = argv[1];
	int target = atoi(argv[2]);

	ifstream ifs(fileName);
	if (ifs.fail()) {
		printUsage(argv[0], "Failed opening file: " + fileName);
	}
	auto items = readItems(ifs, target);

	//cout << endl << "finding a pair for target " << target << endl;
	pair<Item, Item> pair = findPair(items, target);
	if (pair.first.name == "") {
		cout << "Not possible" << endl;
	} else {
		cout << pair.first << ", " << pair.second;
	}

	return 0;
}


