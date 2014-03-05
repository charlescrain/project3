#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
  private:
	Node *head;
	Node *tail; // add this tail
	// private recursive helper methods
	int countOccurrences(Node *,int m);
	int removeTail(Node *);
	// private recursive helper methods for problems
	void addSorted(Node *,int v);

  public:
	LinkedList();
	// implement the copy constructor
	LinkedList(LinkedList &otherlist);
	// implement the destructor
	~LinkedList();

	void addHead(int v);
	void addTail(int v);
	int removeHead();
	int removeTail();
	// add for warmup
	int removeTailRec();
	int countOccurrences(int m);

	void printList(FILE *f);

	// returns int value of node pointed to by head
	// used to name the sets for unionfind
	int getHead();
	// merge will take a linked list an append it onto the end of this one.
	void merge(LinkedList *otherlist);

	// recursive methods to add for warmup
	int countOccurrencesRec(int m);
	// recursive methods to add for problems
	void addSorted(int v);
};

#endif
