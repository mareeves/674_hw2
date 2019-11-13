#include <iostream>
#include <vector>
#include "ISort.h"
#include "insertionSort.h"
#include "selectionSort.h"
using namespace std; 

int main(){
	vector<int> *vec = new vector<int>(); 

	vec->push_back(16);
	vec->push_back(8);
	vec->push_back(20);
	vec->push_back(23);
	vec->push_back(4);
	vec->push_back(3);
	vec->push_back(1);
	vec->push_back(2);
	vec->push_back(5);
	vec->push_back(0);
	
	
	selectionSort *ss = new selectionSort();
	ss->sort(*vec);
	
	free(vec);
	free(ss);
	return 0;
}