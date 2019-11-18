using namespace std;
class selectionSort : public ISort{

	public:
	selectionSort(){}
	~selectionSort(){}
	void sort(vector<int> & vector);

};

void selectionSort::sort(vector<int> & vector){
	int currentMin = 0;
	int currentItem = 0;
	int sorted = 0;
	int temp = 0;
	
	while(true){
		currentMin = sorted;
		for(int i = sorted ; i<vector.size(); i++){
			if(vector[currentMin] > vector[i]){
				currentMin = i;
			}
		}
		temp = vector[sorted];
		vector[sorted] = vector[currentMin];
		vector[currentMin] = temp;
		sorted = sorted+1;
		if(sorted == vector.size()-1){
			break;
		}
	}
}