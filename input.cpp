#include <cstdlib>
#include <iostream>
#include <string>

#include "Node.h"
#include "LinkedList.h"
#include "Heap.h"
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[]) {
	
	int N, E;	//N is number of nodes; E is number of edges
	int node1,node2,edge; //2 nodes followed by edge as input
	
	cin >> N;
	cin >> E;

	Relation *weightArray = new Relation[E];	//Array to hold nodes and weight for heap.
	LinkedList *llistArray = new LinkedList[N+1]; //to make adjacency list


	for(int i=0;i<E;i++){
		cin >> node1 >> node2  >> edge;
		weightArray[i].weight = edge;
		weightArray[i].n1 = node1;
		weightArray[i].n2 = node2;
		llistArray[node1].addTail(node2);
		llistArray[node2].addTail(node1);
	}
	for(int i=0;i<E;i++){
		cout << weightArray[i].n1 << weightArray[i].n2 << weightArray[i].weight
			<< "\n";
	}
	
/*
	for(int i=1;i<N+1;i++){
		llistArray[i].printList(stdout);
		cout << "\n";
	}
*/	
	Heap *heap = new Heap(weightArray,E);
	cout << "\n";
/*
	heap->printHeap();
	heap->deleteMin();
	heap->deleteMin();
	cout << "\n";
	heap->printHeap();
*/
	Graph graph(E);
	Relation r;
	int one, two, findOne, findTwo;
	for(int i=0; i < E; i++){
		//printf("hi\n");
		r = heap->deleteMin();
		//printf("yo12\n");
		one = r.n1;
		two = r.n2;
		findOne = graph.find(r.n1);
		findTwo = graph.find(r.n2);
		printf("Relation one = %i, two = %i,  weight = %i\n", one, two, r.weight);
		//printf("findOne : %i ", findOne);
		//printf("findTwo : %i\n", findTwo);

		if(findOne == 0 && findTwo == 0){ //relation is an independant set
			printf("added unique set\n");
			graph.addUniqueSet(one,two);
		}else if(findOne> 0 && findTwo > 0 && findTwo != findOne){ //relation has nodes in two independent sets
			printf("merged list %i and %i\n", findOne, findTwo);
			graph.Union(findOne,findTwo);
		}
		graph.print();
	}//for loop


}

