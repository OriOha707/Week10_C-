#pragma once
#include <iostream>
class Item
{
protected:
	std::string _name;
	std::string _serialNumber;
	int _count;
	double _unitPrice;
public:
	Item(std::string name, std::string serialNumber, double Price);
	~Item();
	double totalPrice();
	std::string getName()const;
	std::string getSerial()const;
	double getPrice()const;
	int getCount()const;
	void setCount(int num);
	bool operator<(const Item& other) const;
	bool operator>(const Item& other) const;
	bool operator==(const Item& other) const;
};