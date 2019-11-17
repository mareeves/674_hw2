using namespace std;
class bubbleSortwFlag : public ISort{

	public:
	
	bubbleSortwFlag(){
	}
	
	~bubbleSortwFlag(){
		
	}
	void sort(vector<int> &vector);
	
	void bubbleSortExecution(vector<int> &vector, int n) 
	{ 
	   int i, j; 
	   bool swapped; 
	   for (i = 0; i < n-1; i++) 
	   { 
		 swapped = false; 
		 for (j = 0; j < n-i-1; j++) 
		 { 
			if (vector[j] > vector[j+1]) 
			{ 
			   swap(vector[j], vector[j+1]); 
			   swapped = true; 
			} 
		 } 
	  
		 // IF no two elements were swapped by inner loop, then break 
		 if (swapped == false) 
			break; 
	   } 
	} 

};

void bubbleSortwFlag::sort(vector<int> &vector){
	int n = vector.size();
	bubbleSortExecution(vector, n);
	for(int i = 0; i < vector.size(); i++){
    	cout << vector[i] << endl;
    } 
}


	
	
