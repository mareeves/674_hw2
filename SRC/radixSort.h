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
    int * output = new int[n]{}; // output array 
    int * count = new int[max]{}; 
  
    // Store count of occurrences in count[] 
    for (int i = 0; i < n; i++) 
        count[ (vector[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (int i = n - 1; i >= 0; i--) 
    { 
        output[count[ (vector[i]/exp)%10 ] - 1] = vector[i]; 
        count[ (vector[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (int i = 0; i < n; i++) 
        vector[i] = output[i]; 
        
        delete[] output;
		delete[] count; 
	}
	
	

		
	
	
};

void radixSort::sort(vector<int> &vector){
	int max = *max_element(vector.begin(), vector.end());
	for(int place = 1; max/place > 0; place *=10){
		radixCountingSort(vector, vector.size(), place, max);
	}
	
	for(int i = 0; i < vector.size(); i++){
		cout << vector[i] << endl;
	}
}
	
	