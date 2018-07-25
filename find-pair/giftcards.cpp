#include <algorithm>
#import <iostream>
#include <sstream>
#include <vector>

#include "giftcards.h"

using namespace std;


ostream& operator<<(ostream& os, const Item& item) {
	os << item.name << " " << item.price;
	return os;
}

vector<Item> readItems(istream& is, int target) {
	string line;
	vector<Item> items;
	string name;
	int price = 0;
	// as soon as price >= target we should stop reading, because going forward we'll only get items that we cannot buy
	while (getline(is, line) && (price < target)) {
		istringstream iss(line);
		getline(iss, name, ',');
		string tmp;
		getline(iss, tmp);
		price = stoi(tmp);
		Item item{name, price};
		//cout << item << endl;
		items.push_back(item);
	}

	return items;
}

pair<Item, Item> findPair(const vector<Item>& items, int target) {
	int i = 0;
	int j = items.size() - 1;

	int closestSum = 0;
	pair<Item, Item> closestPair = make_pair(Item(), Item());
	while (i < j) {
		int sum = items[i].price + items[j].price;
		if (sum == target) {
			return make_pair(items[i], items[j]);
		} else if (sum > target) {
			j--;
		} else {
			// sum < target
			if (sum > closestSum) {
				closestSum = sum;
				closestPair = make_pair(items[i], items[j]);
			}
			i++;
		}
	}
	return closestPair;
}
