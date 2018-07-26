#define CATCH_CONFIG_MAIN

#include <vector>

#include "wildcardgen.h"
#include "catch.h"

using namespace std;



TEST_CASE( "wildcard binary generator works with empty strings") {
	WildcardBinaryGenerator<1000, 'X'> generator("");
	REQUIRE(generator.hasNext());

	SECTION( "empty string emits just one result" ) {
		REQUIRE( generator.next() == "" );
		REQUIRE( !generator.hasNext() );
	}
}

TEST_CASE( "wildcard binary generator works when there are no wildcards") {
	string input = "01010110001101";
	WildcardBinaryGenerator<1000, 'X'> generator(input);
	REQUIRE(generator.hasNext());

	SECTION( "inputs with no wildcard emits just one result" ) {
		REQUIRE( generator.next() == input );
		REQUIRE( !generator.hasNext() );
	}
}

TEST_CASE( "generator returns 2 results when there is just one wildcard") {
	string input = "01X10110001101";
	WildcardBinaryGenerator<1000, 'X'> generator(input);
	REQUIRE(generator.hasNext());

	string input0 = input;
	string input1 = input;
	std::replace(input0.begin(), input0.end(), 'X', '0');
	std::replace(input1.begin(), input1.end(), 'X', '1');

	SECTION( "inputs with one wildcard outputs two results" ) {
		string item = generator.next();
		REQUIRE( (item == input0 || item == input1) );

		item = generator.next();
		REQUIRE( (item == input0 || item == input1) );
	}
}

TEST_CASE( "generator works when there are only wildcards in the string") {
	string input = "XXX";
	WildcardBinaryGenerator<1000, 'X'> generator(input);
	REQUIRE(generator.hasNext());

	vector<string> expected = {"000", "001", "010", "011", "100", "101", "110", "111"};

	SECTION( "all 8 combinations are generated when the input is XXX" ) {
		while (generator.hasNext()) {
			string item = generator.next();
			REQUIRE( std::find(expected.begin(), expected.end(), item) != expected.end() );
		}
	}
}

TEST_CASE( "generator works with huge input strings") {
	string input = "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
					"X0X1X0" // wildcards only here
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101"
				   "01010101010110101010101010101010101101010101010101010101011010101010101010101010110101010101";
	WildcardBinaryGenerator<1000, 'X'> generator(input);
	REQUIRE(generator.hasNext());

	SECTION( "all 8 combinations are generated when the input is huge and contains 3 X-es" ) {
		int count = 0;
		while (generator.hasNext()) {
			string item = generator.next();
			count++;
		}
		REQUIRE ( count == 8 );
	}
}