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

	while(sec->getHead() > 0){ 
		first->addTail(sec->removeHead());// deletes sec llist while adding to first
	}

}



int Graph::find(int n){
	int i;
	for(i=0; i<size; i++){
		if (array[i].getHead()>0){ // if head is 0 then linked list is empty
			if(array[i].countOccurrences(n) > 0){ // if value is found
				printf("found %i!\n", n);
				return array[i].getHead();// return first value (name of the set)
			}
		}
	}
	return 0; // 0 is indicator that value isn't found
}

void Graph::addUniqueSet(int a, int b){
	int i;

	for(i=0; i<size; i++){
		if(array[i].getHead() == 0){
			array[i].addTail(a);
			array[i].addTail(b);
			return;
		}
	}
	
}

void Graph::print(){
	
	for(int i = 0; i < size; i++){
		if(array[i].getHead() != 0){
			printf("index %i:  ", i);
			array[i].printList(stdout);
		}
	}	
		
		
	
}


