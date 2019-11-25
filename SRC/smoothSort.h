using namespace std;
class smoothSort : public ISort{

	public:
	
	void sort(vector<int> &vec){
		vector<int>::iterator begin = vec.begin();
		vector<int>::iterator end = vec.end();
		SmoothsortExecute(begin, end);
	
	};	
	smoothSort(){
	}
	
	~smoothSort(){
		
	}
	
	static const size_t kNumLeonardoNumbers = 46;

	const size_t kLeonardoNumbers[kNumLeonardoNumbers] = {
	1u, 1u, 3u, 5u, 9u, 15u, 25u, 41u, 67u, 109u, 177u, 287u, 465u, 753u, 
	1219u, 1973u, 3193u, 5167u, 8361u, 13529u, 21891u, 35421u, 57313u, 92735u,
	150049u, 242785u, 392835u, 635621u, 1028457u, 1664079u, 2692537u, 
	4356617u, 7049155u, 11405773u, 18454929u, 29860703u, 48315633u, 78176337u,
	126491971u, 204668309u, 331160281u, 535828591u, 866988873u, 1402817465u,
	2269806339u, 3672623805u
	};
	
	struct HeapShape {
	std::bitset<kNumLeonardoNumbers> trees;
	
	size_t smallestTreeSize;
	};

	template <typename RandomIterator>
	RandomIterator SecondChild(RandomIterator root) {
	return root - 1;
	}
	

	template <typename RandomIterator>
	RandomIterator FirstChild(RandomIterator root, size_t size) {

	return SecondChild(root) - kLeonardoNumbers[size - 2];
	}
	
	template <typename RandomIterator, typename Comparator>
	RandomIterator LargerChild(RandomIterator root, size_t size, Comparator comp) {
	RandomIterator first  = FirstChild(root, size);
	RandomIterator second = SecondChild(root);
		return comp(*first, *second)? second : first;
	}

	template <typename RandomIterator, typename Comparator>
	void RebalanceSingleHeap(RandomIterator root, size_t size, Comparator comp) {

	while (size > 1) {
	  RandomIterator first  = FirstChild(root, size);
	  RandomIterator second = SecondChild(root);
	
	  RandomIterator largerChild;
	  size_t childSize;
	  if (comp(*first, *second)) { 
		largerChild = second; // Second child is larger...
		childSize = size - 2; // ... and has order k - 2.
	  } else {
		largerChild = first;  // First child is larger...
		childSize = size - 1; // ... and has order k - 1.
	  }
	
	  /* If the root is bigger than this child, we're done. */
	  if (!comp(*root, *largerChild))
		return;
	
	  /* Otherwise, swap down and update our order. */
	  std::iter_swap(root, largerChild);
	  root = largerChild;
	  size = childSize;
	}
	}

	template <typename RandomIterator, typename Comparator>
	void LeonardoHeapRectify(RandomIterator begin, RandomIterator end,
						   HeapShape shape, Comparator comp) {

	RandomIterator itr = end - 1;

	size_t lastHeapSize;

	while (true) {
	  lastHeapSize = shape.smallestTreeSize;
	
	  if (size_t(std::distance(begin, itr)) == kLeonardoNumbers[lastHeapSize] - 1)
		break;

	  RandomIterator toCompare = itr;
	
	  if (shape.smallestTreeSize > 1) {

		RandomIterator largeChild = LargerChild(itr, shape.smallestTreeSize,
												comp);
		  
		if (comp(*toCompare, *largeChild))
		  toCompare = largeChild;
	  }
	
	  RandomIterator priorHeap = itr - kLeonardoNumbers[lastHeapSize];
	
	  if (!comp(*toCompare, *priorHeap))
		break;
	
	  std::iter_swap(itr, priorHeap);
	  itr = priorHeap;
	
	  do {
		shape.trees >>= 1;
		++shape.smallestTreeSize;
	  } while (!shape.trees[0]);
	}
	
	RebalanceSingleHeap(itr, lastHeapSize, comp);
	}

	template <typename RandomIterator, typename Comparator>
	void LeonardoHeapAdd(RandomIterator begin, RandomIterator end,
					   RandomIterator heapEnd,
					   HeapShape& shape, Comparator comp) {
	
	if (!shape.trees[0]) {
	  shape.trees[0] = true;
	  shape.smallestTreeSize = 1;
	}
	else if (shape.trees[1] && shape.trees[0]) {
	  shape.trees >>= 2;

	  shape.trees[0] = true;

	  shape.smallestTreeSize += 2;
	} 
	else if (shape.smallestTreeSize == 1) {
	  shape.trees <<= 1;
	  shape.smallestTreeSize = 0;
	  shape.trees[0] = true;
	} 
	else {

	  shape.trees <<= shape.smallestTreeSize - 1;
	  shape.trees[0] = true;

	  shape.smallestTreeSize = 1;
	}
	

	bool isLast = false;
	switch (shape.smallestTreeSize) {

	case 0:
	  if (end + 1 == heapEnd)
		isLast = true;
	  break;
	
	case 1:
	  if (end + 1 == heapEnd || (end + 2 == heapEnd && !shape.trees[1]))
		isLast = true;
	  break;
	
	default:
	  if (size_t(std::distance(end + 1, heapEnd)) < kLeonardoNumbers[shape.smallestTreeSize - 1] + 1)
		isLast = true;
	  break;
	}
	
	if (!isLast)
	  RebalanceSingleHeap(end, shape.smallestTreeSize, comp);
	else
	  LeonardoHeapRectify(begin, end + 1, shape, comp);
	}

	template <typename RandomIterator, typename Comparator>
	void LeonardoHeapRemove(RandomIterator begin, RandomIterator end,
						  HeapShape& shape, Comparator comp) {

	
	if (shape.smallestTreeSize <= 1) {
	  /* Keep scanning up the list looking for the next tree. */
	  do {
		shape.trees >>= 1;
		++shape.smallestTreeSize;
	  } while (shape.trees.any() && !shape.trees[0]);
	  return;
	}
	
	const size_t heapOrder = shape.smallestTreeSize;
	shape.trees[0] = false;
	shape.trees <<= 2;
	shape.trees[1] = shape.trees[0] = true;
	shape.smallestTreeSize -= 2;

	RandomIterator leftHeap  = FirstChild(end - 1, heapOrder);
	RandomIterator rightHeap = SecondChild(end - 1);

	HeapShape allButLast = shape;
	++allButLast.smallestTreeSize;
	allButLast.trees >>= 1;

	LeonardoHeapRectify(begin, leftHeap + 1,  allButLast, comp);
	LeonardoHeapRectify(begin, rightHeap + 1, shape, comp);
	}
	
	template <typename RandomIterator, typename Comparator>
	void SmoothsortExecute(RandomIterator begin, RandomIterator end, Comparator comp) {
	if (begin == end || begin + 1 == end) return;
	
	HeapShape shape;
	shape.smallestTreeSize = 0;
	
	for (RandomIterator itr = begin; itr != end; ++itr)
	LeonardoHeapAdd(begin, itr, end, shape, comp);

	for (RandomIterator itr = end; itr != begin; --itr)
	LeonardoHeapRemove(begin, itr, shape, comp);
	}
	
	
	template <typename RandomIterator>
	void SmoothsortExecute(RandomIterator begin, RandomIterator end) {
  	SmoothsortExecute(begin, end,
             std::less<typename std::iterator_traits<RandomIterator>::value_type>());
	}

	
	
};











	
	