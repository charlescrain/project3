//main file
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <iostream>


using namespace std;

// Node -----------
class Node {
  public:
	int value;
	Node *next;
};

// Relation --------
class Relation {
	public:
		int n1, n2, weight, parent;
};

//LinkedList ----------------------
class LinkedList {
  private:
	Node *head;
	Node *tail; 
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
	int countOccurrences(int m);

	void printList(FILE *f);

	// returns int value of node pointed to by head
	// used to name the sets for unionfind
	int getHead();



	// recursive methods to add for warmup
	int countOccurrencesRec(int m);
	// recursive methods to add for problems
	void addSorted(int v);
};

LinkedList::LinkedList()
{
	head = NULL;
 	tail = NULL;
}


/* destructor
 *
 
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

	// getHead value
	int LinkedList::getHead()
	{	
		if(head == NULL){
			return 0;
		}else{
			return head->value;
		}
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


	/* removeHead
	 * remove the first element in a linked list
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


//Heap -------------------------
class Heap {
	private:
		Relation *array;
		int size;

		void sort();

	public:
		Heap(Relation *,int);		//constructor
		void printHeap();
		Relation deleteMin();		//Deletes top of Heap and returns deleted relation
	};


	Heap::Heap(Relation *oldArray,int length){
		array = oldArray;
		size = length;
		sort();
	}


	void Heap::sort(){
		bool sorting = true;
		int tmpW,tmp1,tmp2;
		int index=(size-1)/2; //size is 1 more than length
		while(1){
			
			if(index == 0){
				while((2*index+2 < size-1) || (2*index+1 < size-1)){  //if at least one of the children is in the array
					if(2*index+2 > size-1){ //no right child
						if(array[index].weight > array[2*index+1].weight){
							tmpW = array[index].weight;
							tmp1 = array[index].n1;
							tmp2 = array[index].n2;
							array[index].weight = array[2*index+1].weight;
							array[index].n1 = array[2*index+1].n1;
							array[index].n2 = array[2*index+1].n2;

							array[2*index+1].weight = tmpW;
							array[2*index+1].n1 = tmp1;
							array[2*index+1].n2 = tmp2;
							index = 2*index+1;
						}else{
							break;
						}
					}else if(array[2*index+1].weight <= array[2*index+2].weight){
						if(array[index].weight > array[2*index+1].weight){
							tmpW = array[index].weight;
							tmp1 = array[index].n1;
							tmp2 = array[index].n2;
							array[index].weight = array[2*index+1].weight;
							array[index].n1 = array[2*index+1].n1;
							array[index].n2 = array[2*index+1].n2;

							array[2*index+1].weight = tmpW;
							array[2*index+1].n1 = tmp1;
							array[2*index+1].n2 = tmp2;
							index = 2*index+1;
						}else{
							break;
						}
					}else if(array[2*index+1].weight >  array[2*index+2].weight){
						if(array[index].weight > array[2*index+2].weight){
							tmpW = array[index].weight;
							tmp1 = array[index].n1;
							tmp2 = array[index].n2;
							array[index].weight = array[2*index+2].weight;
							array[index].n1 = array[2*index+2].n1;
							array[index].n2 = array[2*index+2].n2;

							array[2*index+2].weight = tmpW;
							array[2*index+2].n1 = tmp1;
							array[2*index+2].n2 = tmp2;
							index = 2*index+2;
						}else{
							break;
						}
					}
				}
				break;
				
			}else if(2*index+2 > size-1){ //no right child
				if(2*index+1 > size-1){ //no left child
					index--;
				}else{ //only left child
					if(array[index].weight > array[2*index+1].weight){
						tmpW = array[index].weight;
						tmp1 = array[index].n1;
						tmp2 = array[index].n2;
						array[index].weight = array[2*index+1].weight;
						array[index].n1 = array[2*index+1].n1;
						array[index].n2 = array[2*index+1].n2;

						array[2*index+1].weight = tmpW;
						array[2*index+1].n1 = tmp1;
						array[2*index+1].n2 = tmp2;
						index = 2*index+1;
					}else{
						index--;
					}
				}
				
			}else if(array[2*index+1].weight <= array[2*index+2].weight){
				if(array[index].weight > array[2*index+1].weight){
					tmpW = array[index].weight;
					tmp1 = array[index].n1;
					tmp2 = array[index].n2;
					array[index].weight = array[2*index+1].weight;
					array[index].n1 = array[2*index+1].n1;
					array[index].n2 = array[2*index+1].n2;

					array[2*index+1].weight = tmpW;
					array[2*index+1].n1 = tmp1;
					array[2*index+1].n2 = tmp2;
					index = 2*index+1;
				}else{
					index--;
				}
			}else if(array[2*index+1].weight >  array[2*index+2].weight){
				if(array[index].weight > array[2*index+2].weight){
					tmpW = array[index].weight;
					tmp1 = array[index].n1;
					tmp2 = array[index].n2;
					array[index].weight = array[2*index+2].weight;
					array[index].n1 = array[2*index+2].n1;
					array[index].n2 = array[2*index+2].n2;

					array[2*index+2].weight = tmpW;
					array[2*index+2].n1 = tmp1;
					array[2*index+2].n2 = tmp2;
					index = 2*index+2;
				}else{
					index--;
				}
			}
		}
	}

	Relation Heap::deleteMin(){
		Relation deleted = array[0];
		int tmpW,tmp1,tmp2;
		int i,index;
		if(array[0].weight == -1)
			return deleted;
		for(i=size-1;i>-1;i--){
			if(array[i].weight != -1)
				break;
		}
		array[0] = array[i];
		array[i].weight = -1;
		array[i].n1 = -1;
		array[i].n2 = -1;

		index = 0;
		if(i == index){
			return deleted;
		}
		
		while((2*index+2 < size-1) || (2*index+1 < size-1)){  //if at least one of the children is in the array
			if(array[2*index+2].weight == -1 && array[2*index+1].weight == -1){
				//at bottom of heap
				return deleted;
			}else if(array[2*index+2].weight == -1){ //no right child
				if(array[index].weight > array[2*index+1].weight){
					tmpW = array[index].weight;
					tmp1 = array[index].n1;
					tmp2 = array[index].n2;
					array[index].weight = array[2*index+1].weight;
					array[index].n1 = array[2*index+1].n1;
					array[index].n2 = array[2*index+1].n2;

					array[2*index+1].weight = tmpW;
					array[2*index+1].n1 = tmp1;
					array[2*index+1].n2 = tmp2;
					index = 2*index+1;
				}else{
					return deleted;
				}
			}else if(array[2*index+1].weight <= array[2*index+2].weight){
				if(array[index].weight > array[2*index+1].weight){
					tmpW = array[index].weight;
					tmp1 = array[index].n1;
					tmp2 = array[index].n2;
					array[index].weight = array[2*index+1].weight;
					array[index].n1 = array[2*index+1].n1;
					array[index].n2 = array[2*index+1].n2;

					array[2*index+1].weight = tmpW;
					array[2*index+1].n1 = tmp1;
					array[2*index+1].n2 = tmp2;
					index = 2*index+1;
				}else{
					return deleted;
				}
			}else if(array[2*index+1].weight >  array[2*index+2].weight){
				if(array[index].weight > array[2*index+2].weight){
					tmpW = array[index].weight;
					tmp1 = array[index].n1;
					tmp2 = array[index].n2;
					array[index].weight = array[2*index+2].weight;
					array[index].n1 = array[2*index+2].n1;
					array[index].n2 = array[2*index+2].n2;

					array[2*index+2].weight = tmpW;
					array[2*index+2].n1 = tmp1;
					array[2*index+2].n2 = tmp2;
					index = 2*index+2;
				}else{
					return deleted;
				}
			}
		}
			return deleted;

	}//deletemin




//Graph  ----------------------------------
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
		void print();
		void mergeNode(int name,int a);

};

	Graph::Graph(int RelationCount){
		array = new LinkedList[RelationCount];
		size = RelationCount;
		
	}//Graph(int RelationCount)

	void Graph::Union(int name1, int name2){
		int i;
		LinkedList *first;
		LinkedList *sec;

		for(i=0; i<size; i++){
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

	}//Union



	int Graph::find(int n){
		int i;
		for(i=0; i<size; i++){
			if (array[i].getHead()>0){ // if head is 0 then linked list is empty
				if(array[i].countOccurrences(n) > 0){ // if value is found
					
					return array[i].getHead();// return first value (name of the set)
				}
			}
		}
		return 0; // 0 is indicator that value isn't found
	}//find

	void Graph::addUniqueSet(int a, int b){
		int i;

		for(i=0; i<size; i++){
			if(array[i].getHead() == 0){
				array[i].addTail(a);
				array[i].addTail(b);
				return;
			}
		}
		
	}//adduniqueset

	// case where the relation includes a node from a set and an independant node
	// so we merge the node onto the existing set
	void Graph::mergeNode(int name, int a){
		for(int i = 0; i<size; i++){
			if(array[i].getHead() == name){
				array[i].addTail(a);
				return;
			}
		}
	}//merge node





//main ---------------------------------------
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

	
	Heap *heap = new Heap(weightArray,E);


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
		//printf("Relation one = %i, two = %i,  weight = %i\n", one, two, r.weight);
		//printf("findOne : %i ", findOne);
		//printf("findTwo : %i\n", findTwo);

		if(findOne == 0 && findTwo == 0){ //relation is an independant set
		  //printf("added unique set\n");
			cout <<one << " " << two << "\n";
			graph.addUniqueSet(one,two);
		}else if(findOne> 0 && findTwo > 0 && findTwo != findOne){ //relation has nodes in two independent sets
			graph.Union(findOne,findTwo);
			//	printf("merged list %i and %i\n", findOne, findTwo);
		      	cout <<one << " " << two << "\n";
		}else if(findOne > 0 && findTwo ==0){ //Relation has a node from existing set, and an independent set
			graph.mergeNode(findOne,two);
			cout <<one << " " << two << "\n";
		}else if(findOne ==0 && findTwo> 0){// ""
			graph.mergeNode(findTwo,one);
			cout <<one << " " << two << "\n";
		}
		//graph.print();
	}//for loop


}