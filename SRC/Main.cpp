#include <iostream>
#include <vector>
#include "ISort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "smoothSort.h"
#include "countingSort.h"
#include "radixSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "bubbleSort.h"
#include "bubbleSortwFlag.h"

using namespace std; 

int main(){
	vector<int> *vec = new vector<int>(); 

	vec->push_back(90);
	vec->push_back(90);
	vec->push_back(90);
	vec->push_back(170);
	vec->push_back(45);
	vec->push_back(75);
	vec->push_back(90);
	vec->push_back(802);
	vec->push_back(24);
	vec->push_back(2);
	vec->push_back(66);
	


		
	
	
	mergeSort *ss = new mergeSort();
	ss->sort(*vec);
	
	delete(vec);
	delete(ss);
	return 0;
}