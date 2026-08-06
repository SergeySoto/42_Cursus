#include "easyfind.hpp"

#include <vector>
#include <list>
#include <iostream>

int main() {

	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	std::list<int> mylist;
	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);


	const std::vector<int> myconstvector(myvector);
	try {
		std::cout << "----- Tests elements found in myvector-----" << std::endl;
		std::cout << "First number: " << *easyfind(myvector, 10) << std::endl;
		std::cout << "Second number: " << *easyfind(myvector,20) << std::endl;
		std::cout << "Last number: " << *easyfind(myvector, 30) << std::endl;
		std::cout << "----- Tests elements found in mylist-----" << std::endl;
		std::cout << "First number: " << *easyfind(mylist, 100) << std::endl;
		std::cout << "Second number: " << *easyfind(mylist, 200) << std::endl;
		std::cout << "Last number: " << *easyfind(mylist, 300) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "----- Test element not found -----" << std::endl;
		std::cout << "Number: " << *easyfind(myvector, 11) << std::endl; 
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "----- Test read only list -----" << std::endl;
		std::cout << "Number in const list: " << *easyfind(myconstvector, 20) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}