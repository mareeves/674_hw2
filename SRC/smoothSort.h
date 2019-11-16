using namespace std;
class smoothSort : public ISort{

	public:
	
	int root;
	int *leo = new int[18];
	
	
	smoothSort(){
		leo[0]=1;leo[1]=1;leo[2]=3;leo[3]=5;leo[4]=9;leo[5]=15;leo[6]=25;
		leo[7]=41;leo[8]=67;leo[9]=109;leo[10]=177;leo[11]=287;leo[12]=465;
		leo[13]=753;leo[14]=1219;leo[15]=1973;leo[16]=3193;leo[17]=5167;
		
	}
	
	struct heapShape{
		bitset<18> trees;
		int smallestTreeSize;
		
	};
	
	
	void printAll(vector<int> &vec){
		for(int i=0; i< vec.size(); i++){
			cout << vec[i] << endl;
		};
		cout << endl << endl << endl;
	}
	
	int compare(int first, int second, vector<int> vector){
		if(vector[first]>vector[second]){
			return first;
		}
		else{
			return second;
		}
	}
	
	int distance(int first, int second, vector<int> &vector){
		for(int i = first; i<vector.size(); i++){
			if(vector[i]==vector[second]){
				return i-first;
			}
		}
		
		return -1;
	}
	
	int firstChild(int root, int size){
		return secondChild(root) - leo[size-2];
	}
	
	int secondChild(int root){
		return root -1;
	}
	
	int largerChild(int root, int size, vector<int> &vector){
		int first = firstChild(root, size);
		int second = secondChild(root);
		return compare(first, second, vector);
	}
	
	void rebalanceSingleHeap(int root, int size, vector<int> &vector){
		while(size>1){
			int first = firstChild(root, size);
			int second = secondChild(root);
			int largerChild;
			int childSize;
			
			if(compare(first, second, vector) == second){
				largerChild = second;
				childSize = size - 2;
			}
			else{	
				largerChild = first;
				childSize = size - 1;
			}
			
			if(compare(root, largerChild, vector) == root)
			return;
			
			
			swap(vector[root], vector[largerChild]);
			root = largerChild;
			size = childSize;
			
		}
	}
		
			
	void leonardoHeapRectify(int begin, int end, heapShape hs, vector<int> &vector){
		int itr = end - 1;
		int lastHeapSize;
		
		while(true){
			lastHeapSize = hs.smallestTreeSize;
			if(distance(begin,itr,vector) == leo[lastHeapSize] -1)
			break;
			
			int toCompare = itr;
			
			if(hs.smallestTreeSize > 1){
				int largeChild = largerChild(itr, hs.smallestTreeSize, vector);
				
				if(compare(toCompare, largeChild, vector) == largeChild){
					toCompare = largeChild;
				}
			}
			
			int priorHeap = itr - leo[lastHeapSize];
			
			if(compare(toCompare, priorHeap, vector) == toCompare)
			break;
			
			swap(vector[itr], vector[priorHeap]);
			itr = priorHeap;
			
			do {
				hs.trees >>= 1;
				++hs.smallestTreeSize;
			} while(!hs.trees[0]);
			
		}
		
	}
	
	void leonardoHeapAdd(int begin, int end, int heapEnd, heapShape hs, vector<int> &vector){
		if (!hs.trees[0]) {
      		hs.trees[0] = true;
      		hs.smallestTreeSize = 1;
    	}    	
    	else if (hs.trees[1] && hs.trees[0]) {
		  hs.trees >>= 2;
		  hs.trees[0] = true;
		  hs.smallestTreeSize += 2;
    	}     	
		else if (hs.smallestTreeSize == 1) {
		  hs.trees <<= 1;
		  hs.smallestTreeSize = 0;
	
		  hs.trees[0] = true;
		} 
		else {

		  hs.trees <<= hs.smallestTreeSize - 1;
		  hs.trees[0] = true;

		  hs.smallestTreeSize = 1;
		}
		
		bool isLast = false;
		switch (hs.smallestTreeSize) {
		case 0:
		  if (end + 1 == heapEnd)
			isLast = true;
		  break;

		case 1:
		  if (end + 1 == heapEnd || (end + 2 == heapEnd && !hs.trees[1]))
			isLast = true;
		  break;

		default:
		  if (int(distance(end + 1, heapEnd, vector)) < leo[hs.smallestTreeSize - 1] + 1)
			isLast = true;
		  break;
		}	
		if (!isLast)
		  rebalanceSingleHeap(end, hs.smallestTreeSize, vector);
		else
		  leonardoHeapRectify(begin, end + 1, hs, vector);
	}
	
	
	void leonardoHeapRemove(int begin, int end,
                          heapShape hs, vector<int> & vector) {
	

		if (hs.smallestTreeSize <= 1) {
		  do {
			hs.trees >>= 1;
			++hs.smallestTreeSize;
		  } while (hs.trees.any() && !hs.trees[0]);
		  return;
		}
	

		const int heapOrder = hs.smallestTreeSize;
		hs.trees[0] = false;
		hs.trees <<= 2;
		hs.trees[1] = hs.trees[0] = true;
		hs.smallestTreeSize -= 2;
		

		int leftHeap  = firstChild(end - 1, heapOrder);
		int rightHeap = secondChild(end - 1);
	

		heapShape allButLast = hs;
		++allButLast.smallestTreeSize;
		allButLast.trees >>= 1;
		
		cout << "made it this far" << endl;
		leonardoHeapRectify(begin, leftHeap + 1,  allButLast, vector);
		leonardoHeapRectify(begin, rightHeap + 1, hs, vector);
  }
  
		
		
	
	
	//////
	
	//////
	
	
	//////
	
	//////
	
	void sort(vector<int> & vector);
	
	~smoothSort(){
		
	}
	
	
	
	

};

void smoothSort::sort(vector<int> & vector){
	int begin = 0;
	int end = vector.size();
	if (begin == end || begin + 1 == end) return;
	
	heapShape hs;
	hs.smallestTreeSize = 0;
	
	
	for (int itr = begin; itr != end; ++itr)
	leonardoHeapAdd(begin, itr, end, hs, vector);
	
	for (int itr = end; itr != begin; --itr)
	leonardoHeapRemove(begin, itr, hs, vector);
	
	//printAll(vector);
}