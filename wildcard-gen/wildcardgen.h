#ifndef WILDCARD_WILDCARDGEN_H
#define WILDCARD_WILDCARDGEN_H

#import <string>
#import <vector>
#import <cmath>
#import <cassert>
#import <bitset>

/**
 * Given a string composed of only 1s, 0s, and wildcard characters, this class generates every possible combination
 * where you replace the Wildcard with both 0 and 1. To generate all combinations, initialize an instance of this class
 * with an input string consisting of 0s, 1s and Wildcard characters. Then, use hasNext() and next() methods in a loop
 * to iterate through all combinations.
 *
 * Note: Instances of this class are not reusable, i.e. once you generate all combinations by calling next() enough
 * number of times, you would need to create a new instance to regenerate the combinations.
 *
 * @tparam MaxWildcards the maximum number of wildcards this generator can handle. Set to some realistic value based on
 * 	your use case.
 * @tparam Wildcard the wildcard character, e.g. 'X'.
 */
template<int MaxWildcards, char Wildcard>
class WildcardBinaryGenerator {
public:
	/**
	 * Constructor that takes the input string. Checks for invalid characters and throws std::invalid_argument if invalid
	 * characters are present.
	 *
	 * @param input the input string.
	 */
	WildcardBinaryGenerator(const std::string &input)
			: input(input) {

		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == Wildcard) {
				wildcardIndices.push_back(i);
			} else if ( (input[i] != '0') && (input[i] != '1') ) {
				throw std::invalid_argument("input string should contain only 0s, 1s and " + std::string(1, Wildcard)
											+ " characters");
			}
		}
		wildcardCount = wildcardIndices.size();
		totalCombinations = std::pow(2, wildcardCount);
	}

	bool hasNext() const {
		return bits.to_ulong() < totalCombinations;
	}

	std::string next() {
		std::string result = input;
		for (int i = 0; i < wildcardCount; ++i) {
			int firstBitIndex = bits.size() - wildcardCount;
			result[wildcardIndices[i]] = '0' + bits[i];
		}
		bits = std::bitset<MaxWildcards>(bits.to_ulong() + 1); // TODO optimize to avoid allocating a new bitset
		return result;
	}

private:
	std::string input;
	std::bitset<MaxWildcards> bits;
	std::vector<int> wildcardIndices;
	int wildcardCount;
	int totalCombinations;
};


#endif //WILDCARD_WILDCARDGEN_H
