#include <cstdlib>
#include <iostream>
#include <string>

#include "Heap.h"
#include "Node.h"
using namespace std;


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

}
void Heap::printHeap(){
	for(int i=0;i<size;i++){
		cout << array[i].n1 << array[i].n2 << array[i].weight
			<< "\n";
	}
}

