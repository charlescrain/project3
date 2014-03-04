#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
 	tail = NULL;
	// TODO: initialize tail
}

/* copy constructor
 * TODO:  Copy the entire linked list for a DEEP COPY
 */

LinkedList::LinkedList(LinkedList &oldlist)
{
	head = NULL;
	tail = NULL;
	Node *tmp, *tmp2;
	if (oldlist.head == NULL)
		 ;

	else
	{
		for (tmp = oldlist.head;tmp != NULL; tmp = tmp->next)
		{
			Node *n = new Node();
			if(head == NULL)
			{
				head = n;
				n->value = tmp->value;
				n->next = NULL;
				tmp2 = n;
			}
			else
			{
				n->value = tmp->value;
				tmp2->next = n;
				tmp2 = n;
			}

		}
		tmp2->next = NULL;
		tail = tmp2;
	}

	
	
}

/* destructor
 *
 * TODO: delete all of the nodes in the linked list
 */
LinkedList::~LinkedList()
{
	if(head == NULL)
		;
	else
	{
		Node *tmp;


		for (tmp= head;head != NULL; tmp= head)
		{
			head = head->next;
			delete tmp;
		}
	}


}


/* addHead
 * add an item to the front of the linked list
 * TODO: properly update the tail pointer
 */

void LinkedList::addHead(int v)
{
	// create a new Link and put v into that Link
	Node *l = new Node();
	l->value = v;
	// if the list is empty, this link is the only thing in it
	// all we need to do is point head to the link
	if (head == NULL)
	{
		head = l;
		head->next = NULL;
		tail = head;
	}
	// if there is already something there, we point this new link
	// to the old head of the list.  Then, when we point head to this
	// Link, it becomes the beginning of the list, and the old beginning
	// is now 2nd.
	else
	{
		l->next = head;
		head = l;
	}
}

/* addTail
 * add an element to the end of the linked list
 * TODO: properly update the tail pointer
 * make code more efficient if tail pointer helps
 */

void LinkedList::addTail(int v)
{
	// make a new link for the new item
	Node *l = new Node();
	l->value = v;
	l->next = NULL;
	// if the list is empty, this is the only one
	if (head == NULL)
	{
		head = l;
	}
	// otherwise, we need to go to the back and add the node
	else
	{

		// advance l2 so it points to the last link
		Node *l2;
		for(l2 = head;l2->next != NULL; l2 = l2->next)
			;
		// now add this l to the end by hooking l2 to it
		l2->next = l;
		tail = l;
	}
}

/* removeHead
 * remove the first element in a linked list
 * TODO: update tail pointer
 */

int LinkedList::removeHead()
{
	// if the list is empty, return 0
	if (head == NULL)
		return 0;
	// set a temporary pointer to head
	Node *tmp = head;
	// advance head so it points to the next one
	head = head->next;
	// record the return value before deleting the Link
	int retval = tmp->value;
	// delete the Link
	delete tmp;

	if(head == NULL)
		tail = NULL;
	// return the value
	return retval;
}

/* removeTail
 * remove the last element of a linked list
 * TODO: update tail pointer
 * make code more efficient if tail pointer helps
 */
int LinkedList::removeTail()
{
	// if the list is empty, return 0
	if (head == NULL)
		return 0;
	// if there is only one item, remove it
	if (head->next == NULL)
	{
		// record the value to return
		int retval = head->value;
		// delete the Link
		delete head;
		// set head to NULL, indicating an empty list
		head = NULL;
		// return the value from that Link
		return retval;
	}
	// advance to the next to last link
	Node *l2;
	for(l2 = head;l2->next->next != NULL; l2 = l2->next)
		;
	
	// record the return value
	int retval = l2->next->value;
	// delete the Link
	delete l2->next;
	// set this node to be pointing to null, removing the Link
	l2->next = NULL;
	tail = l2;
	
	// return the value
	return retval;
}

/* removeTailRec
 *
 * public method for recursive implementation
 * TODO: fill in the code
 */
int LinkedList::removeTailRec()
{
	Node *tmp;
	int v;
	// first do the base cases that do not require recursion
	if (head == NULL)
		return 0;
	else if(head->next == NULL)
	{
		tmp = head;
		v = tmp->value;
		delete tmp;
		head = NULL;
		return v;
	}
	else if(head->next->next == NULL)
	{
		tmp = head->next;
		v = tmp->value;
		delete tmp;
		head->next = NULL;
		return v;
	}
	else
		removeTail(head->next);

	// if none of those were true, call the recursive helper method
}

/* removeTail(Node *)
 * recursive implementation of removeTail
 * TODO: fill in implementation
 */

int LinkedList::removeTail(Node *h)
{
	Node *tmp;
	if (h->next->next == NULL)
	{	
		tmp = h->next;
		int v = tmp->value;
		delete tmp;
		h->next = NULL;
		tail = h;
		return v;
	}
	else
		removeTail(h->next);

	// else call the recursive method
}

/* countOccurrences
 * 
 * iterative implementation of countOccurrences
 */
int LinkedList::countOccurrences(int m)
{
	int sum = 0;
	Node *tmp;
	for(tmp = head; tmp != NULL; tmp = tmp->next)
		if (tmp->value == m)
			sum++;
	return sum;
	
}

/* countOccurrencesRec
 *
 * public method that calls the recursive method
 * TODO: fill in this code
 */

int LinkedList::countOccurrencesRec(int m)
{
	if (head == NULL)
		return 0;
	else 
	{
		if(head->value == m)
			return 1 + countOccurrences(head->next,m);
		else 
			return countOccurrences(head->next,m);
	}
}

int LinkedList::countOccurrences(Node *h, int m)
{
	
	// check for the base case(s)
	if(h == NULL)
		return 0;
	else
	{
		if (h->value == m)
			return 1 + countOccurrences(h->next,m);
		else 
			return countOccurrences(h->next,m);
	}
}



void LinkedList::printList(FILE *f)
{
	Node *l;
	fprintf(f,"Printing iteratively forwards: ");
	fprintf(f,"List: ");
	for(l = head; l != NULL; l = l->next)
	{
		fprintf(f, "%d, ",l->value);
	}
	fprintf(f,"\n");
}
/* addSorted
 *
 * RECURSIVE public implementation of addSorted
*/
void LinkedList::addSorted(int v)
{
	if(head == NULL)
		addHead(v);
	else if(head->next == NULL)
	{
		if(head->value <= v)
			addTail(v);
		else
			addHead(v);
	}
	else if(head->value > v)
			addHead(v);
	else if(head->next->value > v)
	{
		Node *t = new Node;
		t->value = v;
		t->next = head->next;
		head->next = t;
	}

	else
		addSorted(head->next,v);
	// base case(s) outside of recursive call
	
	
	// call recursive method

}

/* addSorted
 *
 * RECURSIVE private implementation of addSorted
*/
void LinkedList::addSorted(Node *n, int v)
{
	
	// base case(s)

	
	if(n->next->value >= v )
	{
		Node *t = new Node;
		t->value = v;
		t->next = n->next;
		n->next = t;

	}
	else if(n->next->next == NULL)
		addTail(v);
	else 
		addSorted(n->next,v);
	// smaller case


	// general case
}


