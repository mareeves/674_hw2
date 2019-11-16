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
		int pivot = vector[high]; // pivot  
		int i = (low - 1); // Index of smaller element  
		
		for (int j = low; j <= high - 1; j++)  
		{  
			// If current element is smaller than the pivot  
			if (vector[j] < pivot)  
			{  
				i++; // increment index of smaller element  
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
			int pi = partition(vector, low, high);  
	  
			// Separately sort elements before  
			// partition and after partition  
			quickSortExecute(vector, low, pi - 1);  
			quickSortExecute(vector, pi + 1, high);  
    	} 
	}
		
	
	
};

void quickSort::sort(vector<int> &vector){
	int low = 0;
	int high = vector.size();
	quickSortExecute(vector, low, high);
	
	for(int i = 0; i<vector.size() ; i++){
		cout << vector[i] << endl;
	}
 
}


	
	