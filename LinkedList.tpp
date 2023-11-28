#include "LinkedList.h"
#include <stdexcept>

template <typename T>
using Node = typename LinkedList<T>::Node;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size_(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::clear();
}

template <typename T>
void LinkedList<T>::insert(T value)
{
	// Insert at end of list
	LinkedList<T>::insertAt(size_, value);
}

template <typename T>
void LinkedList<T>::insertAt(int index, T value)
{
	// Insert at specified index
	if (index < 0 || index > size_)
	{
		throw std::out_of_range("Index out of range");
	}
	Node *newNode = new Node();
	newNode->data = value;
	if (size_ == 0)
	{
		// first element in list
		newNode->prev = nullptr;
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
	}
	else if (index == 0)
	{
		// adding to start of list
		newNode->prev = nullptr;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (index == size_)
	{
		// adding to end of list
		newNode->next = nullptr;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else
	{
		// adding in middle of list
		Node *prevNode = LinkedList<T>::getNodeAt(index - 1);
		Node *currNode = LinkedList<T>::getNodeAt(index);

		newNode->prev = currNode->prev;
		newNode->next = currNode;

		currNode->prev = newNode;
		prevNode->next = newNode;
	}
	size_++;
}

template <typename T>
void LinkedList<T>::remove()
{
	// Removal of the last element
	LinkedList<T>::removeAt(size_ - 1);
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
	// Removal of node at specified index
	if (index < 0 || index >= size_)
	{
		throw std::out_of_range("Index out of range");
	}
	Node *nodeToRemove = getNodeAt(index);
	if (size_ == 1)
	{
		// Node is the only node in the list, so just reset head and tail
		head = nullptr;
		tail = nullptr;
	}
	else if (nodeToRemove == tail)
	{
		// Removing the last element
		tail = nodeToRemove->prev;
		tail->next = nullptr;
	}
	else if (nodeToRemove == head)
	{
		// Removing the first element
		head = nodeToRemove->next;
		head->prev = nullptr;
	}
	else
	{
		// Removing from middle of list
		nodeToRemove->prev->next = nodeToRemove->next;
		nodeToRemove->next->prev = nodeToRemove->prev;
	}
	delete nodeToRemove;
	size_--;
}

template <typename T>
void LinkedList<T>::clear()
{
	for (int i = size_; i > 0; i--)
	{
		LinkedList<T>::remove();
	}
}

template <typename T>
T LinkedList<T>::get(int index) const
{
	// Getter for node at specified index implementation
	if (index < 0 || index >= size_)
	{
		throw std::out_of_range("Index out of range");
	}

	return LinkedList<T>::getNodeAt(index)->data;
}

template <typename T>
int LinkedList<T>::size() const
{
	return size_;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::getNodeAt(int index) const
{
	// Helper function to get node at specified index
	typename LinkedList<T>::Node *current = head;
	while (index-- > 0)
	{
		current = current->next;
	}
	return current;
}
