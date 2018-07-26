#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cassert>

#import "wildcardgen.h"

void printUsage(const std::string& execName, const std::string& reason) {
	std::cout << "Invalid command: " << reason << std::endl;
	std::cout << "Usage: " << execName << " <input-string>" << std::endl;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printUsage(argv[0], "wrong number of arguments");
		return -1;
	}
	std::string input = argv[1];

	WildcardBinaryGenerator<1000, 'X'> generator(input);
	while (generator.hasNext()) {
		std::cout << generator.next() << std::endl;
	}

	return 0;
}