using namespace std;
class radixSort : public ISort{

	public:
	
	radixSort(){
	}
	
	~radixSort(){
		
	}
	void sort(vector<int> &vector);
	
	void radixCountingSort(vector <int> &vector, int n, int exp, int max)
	{ 
		//fully sorted array
		int * output = new int[n]{}; 
		int * count = new int[max]{}; 
	  
		// store occurrences in count array
		for (int i = 0; i < n; i++) 
			count[ (vector[i]/exp)%10 ]++; 
	  
	  	//sum with previous element down the array
		for (int i = 1; i < 10; i++) 
			count[i] += count[i - 1]; 
	  
		// Build the output array 
		for (int i = n - 1; i >= 0; i--) 
		{ 
			output[count[ (vector[i]/exp)%10 ] - 1] = vector[i]; 
			count[ (vector[i]/exp)%10 ]--; 
		} 
	  
		//copy the output to vector
		for (int i = 0; i < n; i++){ 
			vector[i] = output[i]; 
		}
        
        //delete two arrays
        delete[] output;
		delete[] count; 
	}
	
	

		
	
	
};

void radixSort::sort(vector<int> &vector){
	// find the max value
	int max = *max_element(vector.begin(), vector.end());
	
	//run a for loop starting with least->most sig value
	for(int place = 1; max/place > 0; place *=10){
		// use a version of counting sort for fast results
		radixCountingSort(vector, vector.size(), place, max);
	}

}
	
	