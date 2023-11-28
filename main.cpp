#include <iostream>
#include <exception>
#include <cassert>
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

void testDeletion()
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

void testDeletionAt()
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

int main()
{
	testEmptyList();
	testInsertion();
	testInsertionAt();
	testDeletion();
	testDeletionAt();
	testClear();
	testAccessors();
	std::cout << "Tests completed" << std::endl;
	return 0;
}
