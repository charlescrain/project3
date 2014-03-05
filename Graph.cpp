#include <cstdlib>
#include <iostream>
#include <string>
#include "Graph.h"



using namespace std;

Graph::Graph(int RelationCount){
	array = new LinkedList[RelationCount];
	size = RelationCount;
	
}


void Graph::Union(int name1, int name2){
	int i;
	LinkedList *first;
	LinkedList *sec;
	for(i=0; i<filled; i++){
		if(array[i].getHead()==name1){
			first = &array[i];
		}
		if(array[i].getHead()==name2){
			sec = &array[i];
		}
	}
	first->merge(sec);
	delete(sec);
}



int Graph::find(int n){
	int i;
	for(i=0; i<size; i++){
		if (array[i].getHead() >0){
			return array[i].getHead();// first value is name of each set.
		}
	}
	return 0;
}

void Graph::addUniqueSet(int a, int b){
	int i;

	for(i=0; i<size; i++){
		if(array[i].getHead() > 0){
		}else{
			array[i].addTail(a);
			array[i].addTail(b);
			return;
		}
	}
	
}


