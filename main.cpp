#include <iostream>
#include <exception>
#include <cassert>
#include <string>
#include "LinkedList.h"

void testEmptyList()
{
	LinkedList<int> list;
	assert(list.size() == 0);
	try
	{
		int value = list.get(0);
		std::cerr << "Error: expected out-of-range exception" << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Passed: empty list throws out-of-range exception" << std::endl;
	}
}

void testInsertion()
{
	LinkedList<int> list;
	list.insert(5);
	assert(list.size() == 1);
	assert(list.get(0) == 5);

	list.insert(3);
	assert(list.size() == 2);
	assert(list.get(0) == 5);
	assert(list.get(1) == 3);

	list.insert(7);
	assert(list.size() == 3);
	assert(list.get(0) == 5);
	assert(list.get(1) == 3);
	assert(list.get(2) == 7);
}

void testInsertionAt()
{
	LinkedList<int> list;
	list.insertAt(0, 5);
	assert(list.size() == 1);
	assert(list.get(0) == 5);

	list.insertAt(1, 3);
	assert(list.size() == 2);
	assert(list.get(0) == 5);
	assert(list.get(1) == 3);

	list.insertAt(2, 7);
	assert(list.size() == 3);
	assert(list.get(0) == 5);
	assert(list.get(1) == 3);
	assert(list.get(2) == 7);
}

void testRemove()
{
	LinkedList<int> list;
	list.insert(5);
	list.insert(3);
	list.insert(7);

	list.remove();
	assert(list.size() == 2);
	assert(list.get(0) == 5);
	assert(list.get(1) == 3);

	list.remove();
	assert(list.size() == 1);
	assert(list.get(0) == 5);

	list.remove();
	assert(list.size() == 0);
}

void testRemoveAt()
{
	LinkedList<int> list;
	list.insert(5);
	list.insert(3);
	list.insert(7);

	list.removeAt(1);
	assert(list.size() == 2);
	assert(list.get(0) == 5);
	assert(list.get(1) == 7);

	list.removeAt(0);
	assert(list.size() == 1);
	assert(list.get(0) == 7);

	list.removeAt(0);
	assert(list.size() == 0);
}

void testClear()
{
	LinkedList<int> list;
	list.insert(5);
	list.insert(3);
	list.insert(7);
	list.clear();
	assert(list.size() == 0);
}

void testAccessors()
{
	LinkedList<int> list;
	list.insert(5);
	list.insert(3);
	list.insert(7);

	assert(list.get(0) == 5);
	assert(list.get(1) == 3);
	assert(list.get(2) == 7);

	try
	{
		int value = list.get(3);
		std::cerr << "Error: expected out-of-range exception" << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Passed: out-of-range index throws exception" << std::endl;
	}
}

void testStrings()
{
	LinkedList<std::string> list;

	list.insert("red fox");
	list.insert("lemon");
	list.insert("");

	assert(list.get(0) == "red fox");
	assert(list.get(1) == "lemon");
	assert(list.get(2) == "");

	list.clear();
	assert(list.size() == 0);
}

void testIterator()
{
	LinkedList<int> list;
	list.insert(5);
	list.insert(3);
	list.insert(7);
	
	int i = 0;
	for (auto it : list)
	{
		assert(it == list.get(i));
		i++;
	}
	i--;
	for (auto it = list.rbegin(); it != list.rend(); --it)
	{
		assert(*it == list.get(i));
		i--;
	}
}

int main()
{
	testEmptyList();
	testInsertion();
	testInsertionAt();
	testRemove();
	testRemoveAt();
	testClear();
	testAccessors();
	testStrings();
	testIterator();
	std::cout << "Tests completed" << std::endl;
	return 0;
}
