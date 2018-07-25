#ifndef GIFTCARDS_H
#define GIFTCARDS_H

#include <vector>
#include <string>

/**
 * A data structure representing a shop item. It has a name and an integer price.
 */
struct Item {
	Item() {};
	Item(const std::string &name, int price) : name(name), price(price) {}

	std::string name;
	int price;
};

/**
 * Serialization of an Item to an ostream.
 *
 * @param os the ostream being serialized to.
 * @param item an Item instance.
 * @return returns the same ostream as passed to function arguments.
 */
std::ostream& operator<<(std::ostream& os, const Item& item);

/**
 * Read the list of items with their prices into a vector of Item structures. An additional target parameter is passed as
 * an optimization to stop reading items as soon as a price read is greater or equal to target.
 *
 * @param is the input stream to read from.
 * @param target stops reading once an item read is larger or equal than target.
 * @return returns a vector of items.
 */
std::vector<Item> readItems(std::istream& is, int target);

/**
 * Given a vector of Items, finds two distinct items in the list whose sum is minimally under (or equal to) the given
 * target. If no solution exists, returns a pair of empty Items, i.e. items whose name == "" and price == 0
 *
 * @param items the vector of Items.
 * @param target the target price.
 * @return std::pair of 2 Item structures. If no solution is possible, returns a pair of empty items.
 */
std::pair<Item, Item> findPair(const std::vector<Item>& items, int target);

#endif //GIFTCARDS_H
