#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Node.h"
#include "LinkedList.cpp"
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
	for(int i=1;i<N+1;i++){
		llistArray[i].printList(stdout);
		cout << "\n";
	}
	return 0;

}
