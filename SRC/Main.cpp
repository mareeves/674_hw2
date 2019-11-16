#include <iostream>
#include <vector>
#include "ISort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "smoothSort.h"
using namespace std; 

int main(){
	vector<int> *vec = new vector<int>(); 

	vec->push_back(2);
	vec->push_back(4);
	vec->push_back(8);
	vec->push_back(1);
	vec->push_back(10);
	vec->push_back(11);
	vec->push_back(13);
	vec->push_back(3);
	vec->push_back(7);
	vec->push_back(9);
	vec->push_back(14);
	vec->push_back(16);
	vec->push_back(15);
	vec->push_back(19);
	vec->push_back(18);
	vec->push_back(20);
	
	
	
	smoothSort *ss = new smoothSort();
	ss->sort(*vec);
	
	free(vec);
	free(ss);
	return 0;
}