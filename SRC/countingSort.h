using namespace std;
class countingSort : public ISort{

	public:
	
	countingSort(){
	}
	
	~countingSort(){
		
	}
	void sort(vector<int> &vector);
	
	
	
};

void countingSort::sort(vector<int> &vector){
	// find the largest integer in the array and 
	int max = *max_element(vector.begin(), vector.end()) + 1;	
	int *array = new int[max]{};
	int *sortedArray = new int[vector.size()];
	
	//Increment each count of a value
	for(int i=0; i<vector.size(); i++){
		++array[vector[i]]; 
	}
	
	//Go down the line and add to previous node
	for(int i=0; i<max-1; i++){
		array[i+1] = array[i+1] + array[i]; 
	}
	
	for(int i=0; i<vector.size(); i++){
		//cout << "element in the list is " << vector[i] << endl;
		//cout << "in sum list this value is " << array[vector[i]] << endl;
		sortedArray[array[vector[i]]-1] = vector[i];
		//cout << "put " << vector[i] << " in position " << array[vector[i]] << endl;
		--array[vector[i]];
		
	}
	
	//make the vector a copy of the solution array
	for(int i=0; i<vector.size(); i++){
		vector[i] =  sortedArray[i];
	}

	
	
	delete[] sortedArray;
	delete[] array; 
}
	
	