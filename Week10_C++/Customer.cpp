#include "Customer.h"
/*
constructor
*/
Customer::Customer(std::string name) :_name(name)
{
}
/*
constructor
*/
Customer::Customer()
{
	this->_name = "";
}
/*
distructor
*/
Customer::~Customer()
{
}
/*
calculating the total price of the shopping list
*/
double Customer::totalSum()
{
	double sum = 0;
	for (std::set<Item>::iterator i = _items.begin(); i != _items.end(); i++)
	{
		sum += i->getPrice();
	}
	return sum;
}
/*
getting the name of the costumer
*/
std::string Customer::getName()
{
	return this->_name;
}
/*
getting the list of items
*/
std::set<Item> Customer::getItems()
{
	return this->_items;
}
/*
adding an item to the list
*/
void Customer::addItem(Item item)
{
	if (this->_items.find(item) == this->_items.end())
	{
		this->_items.insert(item);
	}
	else
	{
		std::set<Item>::iterator i = this->_items.find(item);
		int add = i->getCount() + 1;
		Item q = Item(i->getName(), i->getSerial(), i->getPrice());
		this->_items.erase(i);
		q.setCount(add);
		this->_items.insert(q);
	}
}
/*
removing an item from the list
*/
void Customer::removeItem(Item item)
{
	if (this->_items.find(item) == this->_items.end())
	{
		std::cout << "was not found" << std::endl;
	}
	std::set<Item>::iterator i = this->_items.find(item);
	if (i->getCount() == 1)
	{
		this->_items.erase(i);
	}
	else
	{
		int remove = i->getCount() - 1;
		Item q = Item(i->getName(), i->getSerial(), i->getPrice());
		this->_items.erase(i);
		q.setCount(remove);
		this->_items.insert(q);
	}
}