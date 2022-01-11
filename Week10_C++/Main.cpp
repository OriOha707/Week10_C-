#include"Customer.h"
#include<map>
#define NUM_OF_ITEMS 10
#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3
#define EXIT 4
int main()
{
	std::string menu = "Welcome to MagshiMart!\n1. to sign as customer and buy items\n2. to update existing customer's items\n3. to print the customer who pays the most'\n4. to exit";
	int choice = 0, itemNum = -1, ans = 0;
	std::cout << menu << std::endl;
	std::cin >> choice;
	std::string username;
	std::map<std::string, Customer> abcCustomers;
	Item itemList[NUM_OF_ITEMS] = { Item("Milk","00001",5.3),Item("Cookies","00002",12.6),Item("bread","00003",8.9),Item("chocolate","00004",7.0),Item("cheese","00005",15.3),Item("rice","00006",6.2),Item("fish", "00008", 31.65),Item("chicken","00007",25.99),Item("cucumber","00009",1.21),Item("tomato","00010",2.32) };
	while (choice != 4)
	{
		if (choice == OPTION_1)
		{
			std::cout << "Enter userName:" << std::endl;
			std::cin >> username;
			if (abcCustomers.find(username) != abcCustomers.end())
			{
				std::cerr << "name is already taken" << std::endl;
			}
			else
			{
				abcCustomers[username] = Customer(username);//creating a custumer with the name
				std::cout << "the items u can buy are: (0 to exit)" << std::endl;
				for (int i = 0; i < NUM_OF_ITEMS; i++)
				{
					std::cout << i + 1 << "." << itemList[i].getName() << " " << itemList[i].getSerial() << " " << itemList[i].getPrice() << std::endl;
				}
				std::cout << "Enter number:" << std::endl;
				itemNum = -1;
				while (itemNum != 0)
				{
					std::cin >> itemNum;
					while (itemNum < 0 || itemNum > NUM_OF_ITEMS)
					{
						std::cout << "not an option" << std::endl;
						std::cin >> itemNum;
					}
					if (itemNum != 0)
						abcCustomers[username].addItem(itemList[itemNum - 1]);
				}
			}
		}
		else if (choice == OPTION_2)
		{
			std::cout << "Enter username:" << std::endl;
			std::cin >> username;
			if (abcCustomers.find(username) == abcCustomers.end())
			{
				std::cout << "Customer was not found" << std::endl;
			}
			else
			{
				do
				{
					std::map<std::string, Customer>::iterator myItr = abcCustomers.find(username);
					std::set<Item> myItems = myItr->second.getItems();
					for (auto it = myItems.begin(); it != myItems.end(); ++it)
						std::cout << "You have " << it->getName() << " " << it->getCount() << " time/s" << std::endl;
					std::cout << "1. Add items\n2. Remove items\n3. Back to menu" << std::endl;
					std::cin >> ans;
					if (ans == OPTION_1)
					{
						std::cout << "the items u can buy are: (0 to exit)" << std::endl;
						for (int i = 0; i < 10; i++)
						{
							std::cout << i + 1 << "." << itemList[i].getName() << " " << itemList[i].getSerial() << " " << itemList[i].getPrice() << std::endl;
						}
						std::cout << "Enter number:" << std::endl;
						itemNum = -1;
						while (itemNum != 0)
						{
							std::cin >> itemNum;
							while (itemNum < 0 || itemNum > NUM_OF_ITEMS)
							{
								std::cout << "not an option" << std::endl;
								std::cin >> itemNum;
							}
							if (itemNum != 0)
								abcCustomers[username].addItem(itemList[itemNum - 1]);
						}
					}
					else if (ans == OPTION_2)
					{
						std::cout << "the items u can remove are: (0 to exit)" << std::endl;
						for (int i = 0; i < NUM_OF_ITEMS; i++)
						{
							std::cout << i + 1 << "." << itemList[i].getName() << " " << itemList[i].getSerial() << " " << itemList[i].getPrice() << std::endl;
						}
						std::cout << "Enter number:" << std::endl;
						itemNum = -1;
						while (itemNum != 0)
						{
							std::cin >> itemNum;
							while (itemNum < 0 || itemNum > NUM_OF_ITEMS)
							{
								std::cout << "not an option" << std::endl;
								std::cin >> itemNum;
							}
							if (itemNum != 0)
								abcCustomers[username].removeItem(itemList[itemNum - 1]);
						}
					}
					else if (OPTION_3 == 3)
						std::cout << "returning to menu" << std::endl;
					else
						std::cout << "not an option please try agian" << std::endl;
				} while (ans != OPTION_1 && ans != OPTION_2 && ans != OPTION_3);
			}
		}
		else if (choice == OPTION_3)
		{
			if (abcCustomers.begin() == abcCustomers.end())
			{
				std::cout << "There are no Customers!!!" << std::endl;
			}
			else
			{
				//The first Customer
				double mostMoney = abcCustomers.begin()->second.totalSum();
				std::string mostMoneyName = abcCustomers.begin()->second.getName();
				//The next Customer
				auto it = abcCustomers.begin()++;
				for (; it != abcCustomers.end(); ++it)
				{
					if (mostMoney < it->second.totalSum())
					{
						mostMoney = it->second.totalSum();
						mostMoneyName = it->second.getName();
					}
				}
				std::cout << "The customer who payed the most is: \n" << "The name: " << mostMoneyName << "\n" << "The total sum: " << mostMoney << std::endl;
			}
		}
		else if (choice == EXIT)
			std::cout << "bye" << std::endl;
		else
		{
			std::cout << "not an option" << std::endl;
		}
		std::cout << menu << std::endl;
		std::cin >> choice;
	}
	return 0;
}