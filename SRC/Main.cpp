#include <iostream>
#include <vector>
#include "ISort.h"
#include "insertionSort.h"
#include "selectionSort.h"
using namespace std; 

int main(){
	vector<int> *vec = new vector<int>(); 
	vector<int>::iterator it;
	
	vec->push_back(4);
	vec->push_back(3);
	vec->push_back(1);
	vec->push_back(2);
	vec->push_back(5);
	
	insertionSort *is = new insertionSort();
	is->sort(*vec);
	
	free(vec);
	free(is);
	return 0;
}