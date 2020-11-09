#pragma once
#include <iostream>
#ifndef LIST_H
#define LIST_H
class elem {
private:
	int inf;
	elem* next;
public:
	elem(int elem_inf) { inf = elem_inf; next = nullptr;}
	~elem() {};
	elem* getNext() { return next; }
	void setNext(elem* elem_next) { next = elem_next; }
	int getInf() { return inf; }
	void setInf(int elem_inf) { inf = elem_inf; }
};

class list {
private:
	elem* begin, * end;
	size_t size;
public:
	list() { begin = nullptr; end = nullptr; size = 0;}
	~list() { clear(); }

	//Adding an element to the end of the list
	void push_back(int temp) {
		elem* newElem = new elem(temp);
		if (isEmpty()) begin = newElem;
		else end->setNext(newElem);
		end = newElem;
		size++;
	}

	//Adding an element to the begin of the list
	void push_front(int temp) {
		elem* newElem = new elem(temp);
		if (isEmpty()) end = newElem;
		else newElem->setNext(begin);
		begin = newElem;
		size++;
	}

	//Deleting last element of the list
	void pop_back(){
		if (!isEmpty()) {
			if (size == 1) {
				end = nullptr;
				begin = nullptr;
				size = 0;
			}
			else {
				elem* newEnd = begin;
				while (newEnd->getNext() != end) newEnd = newEnd->getNext();
				newEnd->setNext(nullptr);
				elem* deleted = end;
				delete deleted;
				end = newEnd;
				size--;
			}
		}
		else throw "List is Empty";
	}

	//Deleting first element of the list
	void pop_front() {
		if (!isEmpty()) {
			if (size == 1) {
				begin = nullptr;
				end = nullptr;
				size = 0;
			}
			else {
				elem* newBeg = begin->getNext();
				elem* deleted = begin;
				delete deleted;
				begin = newBeg;
				size--;
			}
		}
		else throw "List is Empty";
	}

	//Adding an element to any position in the list
	void insert(int data, size_t pos) {
		if (pos <= size) {
			if (isEmpty() || pos == size) push_back(data);
			else {
				if (pos == 0) push_front(data);
				else {
					elem* newElem = new elem(data);
					elem* iter = begin;
					while (pos-- > 1)
						iter = iter->getNext();
					newElem->setNext(iter->getNext());
					iter->setNext(newElem);
					size++;
				}
			}
		}
		else throw "Wrong index";
	}

	//Getting an element by index
	int at(size_t pos) {
		if (pos < size) {
			elem* iter = begin;
			while (pos-- != 0) iter = iter->getNext();
			return iter->getInf();
		}
		else throw "Wrong index";
	}

	//Deleting an element by index
	void remove(size_t pos) {
		if (pos < size) {
			if (pos == 0) pop_front();
			else {
				if (pos == size - 1) pop_back();
				else {
					elem* iter = begin;
					while (pos-- > 1) iter = iter->getNext();
					elem* nextElem = iter->getNext();
					iter->setNext(nextElem->getNext());
					size--;
				}
			}
		}
		else throw "Wrong index";
	}

	//Getting size of the list
	size_t getSize() { return size; }

	//Output an elements from the list to console
	void print_to_console() {
		elem* iter = begin;
		for (size_t i = 0; i < size; i++) {
			std::cout << iter->getInf() << " ";
			iter = iter->getNext();
		}
		std::cout << std::endl;
	}

	//Deleting an elements of the list
	void clear() {
		while (size) pop_back();
	}

	//Replacing an element by index with new one
	void set(size_t pos, int data) {
		if (pos < size) {
			elem* iter = begin;
			while (pos-- != 0) iter = iter->getNext();
			iter->setInf(data);
		}
		else throw "Wrong index";
	}

	//Checking the list for completeness
	bool isEmpty() {
		if (size == 0) return true; // 1 - Empty
		else return false;			// 0 - Filled
	}

	//Finding the first occurrence of another list in the list
	size_t find_first(list *lst) {
		size_t counter = 0;
		size_t firstpos = 0;
		size_t counter1 = 0;
		size_t counter2 = 0;
		size_t counter3 = 0;
		while (counter2 < size) {
			if (at(counter2) == lst->at(0)) {
				firstpos = counter2; // memorizing the position, and then checking whether the list is included in the list
				counter3 = counter2;
				for (size_t i = 0; i < lst->getSize(); i++) {
					if (lst->at(i) == at(counter3)) {
						counter++;
						counter3++;
						//std::cout << lst->at(i) << std::endl;
						if (counter == lst->getSize()) {
							counter1 = counter;
						}
					}
					else {
						counter = 0;
						break;
					}
				}
				counter2 = counter3;
			}
			if (counter1 == lst->getSize()) break;
			counter2++;
		}		
		if (counter1 == lst->getSize()) {
			std::cout << firstpos << std::endl;
			return firstpos;
		}
		else {
			throw "The entry is missing";
		}
	}
};
#endif