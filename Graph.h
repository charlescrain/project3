#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"

class Graph{
	private:
		int size;
		int filled;
		LinkedList *array;
	
	public:
		Graph(int);
		void Union(int, int);
		int find(int);
		void addUniqueSet(int a, int b);

};


#endif