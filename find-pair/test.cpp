#define CATCH_CONFIG_MAIN

#include <vector>
#include <functional>

#include "giftcards.h"
#include "catch.h"

using namespace std;

bool testEmpty() {
	vector<Item> items = {};
	pair<Item, Item> pair = findPair(items, 400);

	return pair.first.name.empty();
}


bool testNotEnoughMoney() {
	vector<Item> items = {
			Item("a", 1),
			Item("b", 2),
			Item("c", 3),
			Item("d", 4),
			Item("e", 5),
			Item("f", 6),
			Item("g", 7)
	};
	pair<Item, Item> pair = findPair(items, 1);

	return pair.first.name.empty();
}

bool testNotEnoughMoneySameItemNotUsedTwice() {
	vector<Item> items = {
			Item("a", 1),
			Item("b", 2),
			Item("c", 3),
			Item("d", 4),
			Item("e", 5),
			Item("f", 6),
			Item("g", 7)
	};
	pair<Item, Item> pair = findPair(items, 2);

	return pair.first.name.empty();
}

bool testHugeInventory() {
	vector<Item> items;
	for (int i = 0; i < 10*1000*1000; ++i) {
		items.push_back(Item("item" + to_string(i), i));
	}
	pair<Item, Item> pair = findPair(items, 400000);
	cout << "testHugeInventory " << pair.first << " " << pair.second;
	return !pair.first.name.empty();

}

bool testSampleCase1() {
	vector<Item> items = {
			Item("Candy Bar", 500),
			Item("Paperback Book", 700),
			Item("Detergent", 1000),
			Item("Headphones", 1400),
			Item("Earmuffs", 2000),
			Item("Bluetooth Stereo", 6000)
	};
	pair<Item, Item> pair = findPair(items, 2500);

	return pair.first.name == "Candy Bar" && pair.second.name == "Earmuffs";
}

bool testSampleCase2() {
	vector<Item> items = {
			Item("Candy Bar", 500),
			Item("Paperback Book", 700),
			Item("Detergent", 1000),
			Item("Headphones", 1400),
			Item("Earmuffs", 2000),
			Item("Bluetooth Stereo", 6000)
	};
	pair<Item, Item> pair = findPair(items, 1100);

	return pair.first.name.empty();
}


TEST_CASE( "pairs are computed", "[pairs]" ) {
	REQUIRE( testEmpty() );
	REQUIRE( testNotEnoughMoney() );
	REQUIRE( testNotEnoughMoneySameItemNotUsedTwice() );
	REQUIRE( testHugeInventory() );

	REQUIRE( testSampleCase1() );
	REQUIRE( testSampleCase2() );
}