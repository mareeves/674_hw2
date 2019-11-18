using namespace std;
class quickSort : public ISort{

	public:
	
	quickSort(){
	}
	
	~quickSort(){
		
	}
	void sort(vector<int> &vector);
	
	
	int partition (vector<int> & vector, int low, int high)  
		{  
		
		//Make the pivot element the highest element in the array
		int pivot = vector[high];   
		int i = low;  
		
		for (int j = low; j < high; j++)  
		{  
			// If current element is smaller than the pivot  
			if (vector[j] < pivot)  
			{  
				// increment 
				i++;
				
				//swap  
				swap(vector[i], vector[j]);  
			}  
		}  
		swap(vector[i + 1], vector[high]);  
		return (i + 1);  
	}  
	
	void quickSortExecute(vector<int> &vector, int low, int high){
		if (low < high)  
    	{  
			/* pi is partitioning index, arr[p] is now  
			at right place */
			int partIndex = partition(vector, low, high);  
	  
			// sort before partition index 
			quickSortExecute(vector, low, partIndex - 1);
			
			//sort after partition index  
			quickSortExecute(vector, partIndex + 1, high);  
    	} 
	}
		
	
	
};

void quickSort::sort(vector<int> &vector){
	int low = 0;
	int high = vector.size();
	//execute quick sort
	quickSortExecute(vector, low, high);
 
}


	
	