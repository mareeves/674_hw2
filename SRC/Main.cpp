#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
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
	myfile.open ("randomNumbers.txt");
	for(int i = 0; i<6400 ; i++){
			for(int j = 0; j<9 ; j++){
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


void printAll(vector<int> &vec){
	for(int i=0; i< vec.size(); i++){
		cout << vec[i] << endl;
	};
	cout << endl << endl << endl;
}

void runTest(ISort *temp, vector<double> &times){
	clock_t begin,end;
	double elapsed_secs;
	
	int x;
	ifstream myfile;
	vector<int> *vec1 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<1000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec1->push_back(x);
		
	}
    myfile.close();
    
    begin = clock();
    temp->sort(*vec1);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "elapsed seconds: " << elapsed_secs << endl;
	times.push_back(elapsed_secs);
    //printAll(*vec1);
    delete(vec1);
    myfile.close();
    
    
    
    
    
    vector<int> *vec2 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<2000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec2->push_back(x);
		
	}
    myfile.close();
    begin = clock();
    temp->sort(*vec2);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "elapsed seconds: " << elapsed_secs << endl;
	times.push_back(elapsed_secs);
    //printAll(*vec2);
    delete(vec2);
    myfile.close();
    
    
    
    
    
    
    vector<int> *vec3 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<4000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec3->push_back(x);
		
	}
    myfile.close();
    begin = clock();
    temp->sort(*vec3);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    times.push_back(elapsed_secs);
    cout << "elapsed seconds: " <<  elapsed_secs << endl;
	//printAll(*vec3);
    delete(vec3);
    myfile.close();
    
    
    
    
    
    
    
    
    vector<int> *vec4 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<8000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec4->push_back(x);
		
	}
    myfile.close();
    begin = clock();
    temp->sort(*vec4);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    times.push_back(elapsed_secs);
    cout <<  "elapsed seconds: " << elapsed_secs << endl;
	//printAll(*vec4);
    delete(vec4);
    myfile.close();
    
    
    
    
    
    
    
    vector<int> *vec5 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<16000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec5->push_back(x);
		
	}
    myfile.close();
    begin = clock();
    temp->sort(*vec5);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    times.push_back(elapsed_secs);
    cout << "elapsed seconds: " << elapsed_secs << endl;
	//printAll(*vec5);
    delete(vec5);
    myfile.close();
    
    
    
    
    vector<int> *vec6 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<32000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec6->push_back(x);
		
	}
    myfile.close();
    begin = clock();
    temp->sort(*vec6);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    times.push_back(elapsed_secs);
    cout << "elapsed seconds: " << elapsed_secs << endl;
	//printAll(*vec6);
    delete(vec6);
    myfile.close();
    
    
    
    
    vector<int> *vec7 = new vector<int>(); 

    myfile.open("randomNumbers.txt");
    for(int i = 0; i<64000; i++){
    	myfile >> x;
    	if(x<0){
    		x = x * -1;
    	}
		vec7->push_back(x);
		
	}
    myfile.close();
    begin = clock();
    temp->sort(*vec7);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    times.push_back(elapsed_secs);
    cout << "elapsed seconds: " << elapsed_secs << endl;
	//printAll(*vec7);
    delete(vec7);
    myfile.close();
        
}








int main(){	
	selectionSort *ss = new selectionSort();
	insertionSort *is = new insertionSort();
	countingSort *cs = new countingSort();
	radixSort *rs = new radixSort();
	quickSort *qs = new quickSort();
	mergeSort *ms = new mergeSort();
	bubbleSort *bs = new bubbleSort();
	bubbleSortwFlag *bswf = new bubbleSortwFlag();
	heapSort *hs = new heapSort();
	
	ofstream myfile;
	myfile.open ("times.txt");
	
	vector <double> * times = new vector<double>; 
	
	runTest(ss, *times);
	delete(ss);
	runTest(is, *times);
	delete(is);
	runTest(cs, *times);
	delete(cs);
	runTest(rs, *times);
	delete(rs);
	runTest(qs, *times);
	delete(qs);
	runTest(ms, *times);
	delete(ms);
	runTest(bs, *times);
	delete(bs);
	runTest(bswf, *times);
	delete(bswf);
	runTest(hs, *times);
	delete(hs);
	
	cout << "size of times: " <<times->size() << endl;
	
	//Selection Sort
	myfile << "Selection Sort 1000 elements: " << times->at(0) << "\n";
	myfile << "Selection Sort 2000 elements: " << times->at(1) << "\n";
	myfile << "Selection Sort 4000 elements: " << times->at(2) << "\n";
	myfile << "Selection Sort 8000 elements: " << times->at(3) << "\n";
	myfile << "Selection Sort 16000 elements: " << times->at(4) << "\n";
	myfile << "Selection Sort 32000 elements: " << times->at(5) << "\n";
	myfile << "Selection Sort 64000 elements: " << times->at(6) << "\n";
	myfile << "\n\n\n\n";

	//Insertion Sort 
	myfile << "Insertion Sort 1000 elements: " << times->at(7) << "\n";
	myfile << "Insertion Sort 2000 elements: " << times->at(8) << "\n";
	myfile << "Insertion Sort 4000 elements: " << times->at(9) << "\n";
	myfile << "Insertion Sort 8000 elements: " << times->at(10) << "\n";
	myfile << "Insertion Sort 16000 elements: " << times->at(11) << "\n";
	myfile << "Insertion Sort 32000 elements: " << times->at(12) << "\n";
	myfile << "Insertion Sort 64000 elements: " << times->at(13) << "\n";
	myfile << "\n\n\n\n";

	
	//Counting Sort
	myfile << "Counting Sort 1000 elements: " << times->at(14) << "\n";
	myfile << "Counting Sort 2000 elements: " << times->at(15) << "\n";
	myfile << "Counting Sort 4000 elements: " << times->at(16) << "\n";
	myfile << "Counting Sort 8000 elements: " << times->at(17) << "\n";
	myfile << "Counting Sort 16000 elements: " << times->at(18) << "\n";
	myfile << "Counting Sort 32000 elements: " << times->at(19) << "\n";
	myfile << "Counting Sort 64000 elements: " << times->at(20) << "\n";
	myfile << "\n\n\n\n";

	
	//Radix Sort
	myfile << "Radix Sort 1000 elements: " << times->at(21) << "\n";
	myfile << "Radix Sort 2000 elements: " << times->at(22) << "\n";
	myfile << "Radix Sort 4000 elements: " << times->at(23) << "\n";
	myfile << "Radix Sort 8000 elements: " << times->at(24) << "\n";
	myfile << "Radix Sort 16000 elements: " << times->at(25) << "\n";
	myfile << "Radix Sort 32000 elements: " << times->at(26) << "\n";
	myfile << "Radix Sort 64000 elements: " << times->at(27) << "\n";
	myfile << "\n\n\n\n";

	
	//Quick Sort
	myfile << "Quick Sort 1000 elements: " << times->at(28) << "\n";
	myfile << "Quick Sort 2000 elements: " << times->at(29) << "\n";
	myfile << "Quick Sort 4000 elements: " << times->at(30) << "\n";
	myfile << "Quick Sort 8000 elements: " << times->at(31) << "\n";
	myfile << "Quick Sort 16000 elements: " << times->at(32) << "\n";
	myfile << "Quick Sort 32000 elements: " << times->at(33) << "\n";
	myfile << "Quick Sort 64000 elements: " << times->at(34) << "\n";
	myfile << "\n\n\n\n";

	//Merge Sort
	myfile << "Merge Sort 1000 elements: " << times->at(35) << "\n";
	myfile << "Merge Sort 2000 elements: " << times->at(36) << "\n";
	myfile << "Merge Sort 4000 elements: " << times->at(37) << "\n";
	myfile << "Merge Sort 8000 elements: " << times->at(38) << "\n";
	myfile << "Merge Sort 16000 elements: " << times->at(39) << "\n";
	myfile << "Merge Sort 32000 elements: " << times->at(40) << "\n";
	myfile << "Merge Sort 64000 elements: " << times->at(41) << "\n";
	myfile << "\n\n\n\n";

	
	//Bubble Sort
	myfile << "Bubble Sort 1000 elements: " << times->at(42) << "\n";
	myfile << "Bubble Sort 2000 elements: " << times->at(43) << "\n";
	myfile << "Bubble Sort 4000 elements: " << times->at(44) << "\n";
	myfile << "Bubble Sort 8000 elements: " << times->at(45) << "\n";
	myfile << "Bubble Sort 16000 elements: " << times->at(46) << "\n";
	myfile << "Bubble Sort 32000 elements: " << times->at(47) << "\n";
	myfile << "Bubble Sort 64000 elements: " << times->at(48) << "\n";
	myfile << "\n\n\n\n";

	
	//Bubble Sort w Flag
	myfile << "Bubble Sort w Flag 1000 elements: " << times->at(49) << "\n";
	myfile << "Bubble Sort w Flag 2000 elements: " << times->at(50) << "\n";
	myfile << "Bubble Sort w Flag 4000 elements: " << times->at(51) << "\n";
	myfile << "Bubble Sort w Flag 8000 elements: " << times->at(52) << "\n";
	myfile << "Bubble Sort w Flag 16000 elements: " << times->at(53) << "\n";
	myfile << "Bubble Sort w Flag 32000 elements: " << times->at(54) << "\n";
	myfile << "Bubble Sort w Flag 64000 elements: " << times->at(55) << "\n";
	myfile << "\n\n\n\n";

	
	//Heap Sort 
	myfile << "Heap Sort 1000 elements: " << times->at(48) << "\n";
	myfile << "Heap Sort 2000 elements: " << times->at(49) << "\n";
	myfile << "Heap Sort 4000 elements: " << times->at(50) << "\n";
	myfile << "Heap Sort 8000 elements: " << times->at(51) << "\n";
	myfile << "Heap Sort 16000 elements: " << times->at(52) << "\n";
	myfile << "Heap Sort 32000 elements: " << times->at(53) << "\n";
	myfile << "\n\n\n\n";


	myfile.close();
	delete(times);
	
	return 0;
	
}