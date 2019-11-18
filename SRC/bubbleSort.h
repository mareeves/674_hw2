using namespace std;
class bubbleSort : public ISort{

	public:
	
	bubbleSort(){
	}
	
	~bubbleSort(){
		
	}
	void sort(vector<int> &vector);
	
	void bubbleSortExecution(vector<int> &vector, int n)  
	{  
		int i, j;  
		for (i = 0; i < n-1; i++){      
		  
		// Last i elements are already in place  
			for (j = 0; j < n-i-1; j++){  
				if (vector[j] > vector[j+1]){ 
					//cout << "swapping " << vector[j] << " with " << vector[j+1] << endl;  
					swap(vector[j], vector[j+1]);
					//cout << "swapped " << vector[j] << " with " << vector[j+1] << endl; 
				}
					
			}
		} 
	}  

};

void bubbleSort::sort(vector<int> &vector){
	int n = vector.size();
	bubbleSortExecution(vector, n); 
	for(int i = 0; i < vector.size(); i++){
    	cout << vector[i] << endl;
    } 
}


	
	
