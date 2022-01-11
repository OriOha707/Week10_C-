#pragma once
#include <iostream>
#include "Item.h"
#include <set>
#include <iterator>
class Customer
{
private:
	std::string _name;
	std::set<Item> _items;
public:
	Customer(std::string name);
	Customer();
	~Customer();
	double totalSum();
	std::string getName();
	std::set<Item> getItems();
	void addItem(Item item);
	void removeItem(Item item);
};