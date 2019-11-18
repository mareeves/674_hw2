using namespace std;
class insertionSort : public ISort{

	public:
	insertionSort(){}
	~insertionSort(){}
	void sort(vector<int> & vector);

};

void insertionSort::sort(vector<int> &vec){
	for(int i=0; i < vec.size() ; i++){
		int primeNode = i;
		int swapNode = i-1;
		while(vec[primeNode] < vec[swapNode] && swapNode!=-1){
			//cout << "swapNode " << swapNode << endl;
			//cout << "primeNode " << primeNode << endl;
			int tempNode = vec[swapNode];
			vec[swapNode] = vec[primeNode];
			vec[primeNode] = tempNode;
			primeNode = primeNode-1;
			swapNode = swapNode-1;
		}
	}
	
}
