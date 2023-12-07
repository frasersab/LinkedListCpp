#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <iterator>
#include <cstddef>

template <typename T>
class LinkedList
{
  public:
	// Tags
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = T *;
	using reference = T &;

	class Iterator;
	Iterator begin();
	Iterator end();
	Iterator rbegin();
	Iterator rend();

	// Constructors
	LinkedList();
	LinkedList(const LinkedList &);
	~LinkedList();

	// Insertion
	void insert(T);
	void insertAt(int, T);

	// Deletion
	void remove();
	void removeAt(int);
	void clear();

	// Accessors
	T get(int) const;
	int size() const;

  private:
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};

	Node *getNodeAt(int index) const;

	Node *head; // first node in the list
	Node *tail; // last node in the list
	int size_;	// number of nodes in the list
};

// Iterator class
template <typename T>
class LinkedList<T>::Iterator
{
  public:
	// Constructors
	Iterator(LinkedList<T> *list, LinkedList<T>::Node *current);

	// Operator overloads
	reference operator*();
	pointer operator->();

	Iterator &operator++();
	Iterator &operator--();

	bool operator==(const Iterator &other) const;
	bool operator!=(const Iterator &other) const;

  private:
	LinkedList<T> *list_;
	LinkedList<T>::Node *current_;
};

#include "LinkedList.tpp"
#endif // LINKED_LIST_H}
