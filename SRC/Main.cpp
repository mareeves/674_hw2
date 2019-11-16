#include <iostream>
#include <vector>
#include "ISort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "smoothSort.h"
using namespace std; 

int main(){
	vector<int> *vec = new vector<int>(); 

	vec->push_back(9);
	vec->push_back(8);
	vec->push_back(7);
	vec->push_back(6);
	vec->push_back(5);
	vec->push_back(4);
	vec->push_back(3);
	vec->push_back(2);
	vec->push_back(1);

		
	
	
	smoothSort *ss = new smoothSort();
	ss->sort(*vec);
	
	free(vec);
	free(ss);
	return 0;
}