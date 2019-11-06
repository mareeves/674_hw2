using namespace std;
class insertionSort : public ISort{

	public:
	insertionSort(){}
	~insertionSort(){}
	void sort(vector<int> & vector);

};

void insertionSort::sort(vector<int> & vector){
	cout << "insertionSort" << endl;
}