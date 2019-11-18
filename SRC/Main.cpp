#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
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


void makeRandomList(){
	ofstream myfile;
	for(int i = 0; i<4000 ; i++){
		myfile.open ("randomNumbers.txt");
		for(int i = 0; i<400; i++){
			for(int j = 0; j<10 ; j++){
				if(j == 0){
					myfile << rand() % 100 + 1 << "-";
				}
				if(j==9){
					myfile << rand() % 100 + 1 << "\n";
				}
				
				else{
					myfile << rand() % 100 + 1 << "-";
				}
			}
		}
  		myfile.close();
	}
}
int main(){
	vector<int> *vec = new vector<int>(); 

    ifstream myfile;
    myfile.open("randomNumbers.txt");
    int x;
    while(myfile >> x){
    	for(int i = 0; i < 1000; i++){
			if(x < 0){
				x = x * -1;
			}
			vec->push_back(x);
		}
    }
    
	


		
	
	
	mergeSort *ss = new mergeSort();
	ss->sort(*vec);
	
	delete(vec);
	delete(ss);
	//makeRandomList();
	return 0;
}