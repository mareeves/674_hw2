using namespace std;
class mergeSort : public ISort{

	public:
	
	mergeSort(){
	}
	
	~mergeSort(){
		
	}
	void sort(vector<int> &vector);
	
	
void merge(vector<int> &vector, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp vectorays */
    int * L = new int[n1]{};
    int * R = new int[n2]{}; 
  
    /* Copy data to temp vectorays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = vector[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = vector[m + 1+ j]; 
  
    /* Merge the temp vectorays back into vector[l..r]*/
    i = 0; // Initial index of first subvectoray 
    j = 0; // Initial index of second subvectoray 
    k = l; // Initial index of merged subvectoray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            vector[k] = L[i]; 
            i++; 
        } 
        else
        { 
            vector[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        vector[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        vector[k] = R[j]; 
        j++; 
        k++; 
    } 
    
    delete[] L;
    delete[] R;
} 
  
/* l is for left index and r is right index of the 
   sub-vectoray of vector to be sorted */
void mergeSortExecution(vector<int> &vector, int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSortExecution(vector, l, m); 
        mergeSortExecution(vector, m+1, r); 
  
        merge(vector, l, m, r); 
    } 
} 
		
	
	
};

void mergeSort::sort(vector<int> &vector){
	mergeSortExecution(vector, 0, vector.size() - 1);
	for(int i= 0; i<vector.size(); i++){
	  cout << vector[i] << endl;
	}
}


	
	
