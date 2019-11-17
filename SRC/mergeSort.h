using namespace std;
class mergeSort : public ISort{

	public:
	
	mergeSort(){
	}
	
	~mergeSort(){
		
	}
	void sort(vector<int> &vector);
	
	
void merge(vector<int> &vector, int left, int m, int right) 
{ 
    int i,j,k; 
    int n1 = m - left + 1; 
    int n2 =  right - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = vector[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = vector[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
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
} 
	
	void mergeSortExecution(vector<int> &vector, int left, int right){
		if(left < right){
			int m = left+(right-1)/2;
			
			mergeSortExecution(vector, left, m);
			mergeSortExecution(vector, m+1, right);
			
			merge(vector, left, m, right);
		}
	}
		
	
	
};

void mergeSort::sort(vector<int> &vector){
	mergeSortExecution(vector, 0, vector.size()-1);
	for(int i= 0; i<vector.size(); i++){
	  cout << vector[i] << endl;
	}
}


	
	
