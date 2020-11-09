#include <iostream>
#include "list.h"



int main() {
	list list1, list2;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(6);
	list2.push_back(4);
	list2.push_back(5);
	list1.print_to_console();
	list2.print_to_console();
	list1.find_first(&list2);
	return 0;
}