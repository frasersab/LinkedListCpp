#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedList
{
  public:
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

#include "LinkedList.tpp"
#endif // LINKED_LIST_H}
