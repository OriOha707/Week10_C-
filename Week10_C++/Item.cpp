#include "Item.h"
/*
constructor
*/
Item::Item(std::string name, std::string serialNumber, double Price) :_name(name), _serialNumber(serialNumber), _unitPrice(Price)
{
	this->_count = 1;
}
/*
distructor
*/
Item::~Item()
{
}
/*
calculating the total price of the items
*/
double Item::totalPrice()
{
	return this->_count * this->_unitPrice;
}
/*
getting the name of the item
*/
std::string Item::getName()const
{
	return this->_name;
}
/*
getting the serial number
*/
std::string Item::getSerial()const
{
	return this->_serialNumber;
}
/*
getting the price
*/
double Item::getPrice()const
{
	return this->_unitPrice;
}
/*
getting the amount of the items in the list
*/
int Item::getCount() const
{
	return this->_count;
}
/*
setting a new count
*/
void Item::setCount(int num)
{
	this->_count = num;
}
/*
operator < for classes
*/
bool Item::operator<(const Item& other) const
{
	if (this->_unitPrice < other._unitPrice)
		return true;
	return false;
}
/*
operator > for classes
*/
bool Item::operator>(const Item& other) const
{
	if (this->_unitPrice > other._unitPrice)
		return true;
	return false;
}
/*
operator == for classes
*/
bool Item::operator==(const Item& other) const
{
	if (this->_unitPrice == other._unitPrice)
		return true;
	return false;
}