#ifndef HEAP_H
#define HEAP_H
#include "Node.h"
class Heap {
	private:
		Relation *array;
		int size;

		void sort();

	public:
		Heap(Relation *,int);		//constructor
		void printHeap();
//		Relation deleteMin();		//Deletes top of Heap and returns deleted relation
};
#endif
