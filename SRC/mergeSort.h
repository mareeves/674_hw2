using namespace std;
class mergeSort : public ISort{

	public:
	
	mergeSort(){
	}
	
	~mergeSort(){
		
	}
	void sort(vector<int> &vector);
	
	
void merge(vector<int> &vector, int left, int middle, int right) 
{ 
    int i, j, k; 
    int sizeLeft = middle - left + 1; 
    int sizeRight =  right - middle; 
  
    /* create temp vectorays */
    int * L = new int[sizeLeft]{};
    int * R = new int[sizeRight]{}; 
  
    /* Copy data to temp vectorays L[] and R[] */
    for (i = 0; i < sizeLeft; i++) 
        L[i] = vector[left + i]; 
    for (j = 0; j < sizeRight; j++) 
        R[j] = vector[middle + 1+ j]; 
  
    // Merging the temp back into vector
    
    //index of first sub array
    i = 0; 
    //index of second sub array
    j = 0;
    
	//index of merged sub array    
	k = left;  
    while (i < sizeLeft && j < sizeRight) 
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
    while (i < sizeLeft) 
    { 
        vector[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < sizeRight) 
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
void mergeSortExecution(vector<int> &vector, int left, int right) 
{ 
    if (left < right) 
    { 

        // Find the middle to separate between left and right 
        int middle = left+(right-left)/2; 
  
        // Sort first half
        mergeSortExecution(vector, left, middle); 
        
        //Sort second half
        mergeSortExecution(vector, middle+1, right); 
  		
  		
  		//Merge them together when finished
        merge(vector, left, middle, right); 
    } 
} 
		
	
	
};

void mergeSort::sort(vector<int> &vector){
	mergeSortExecution(vector, 0, vector.size() - 1);
}


	
	
