using namespace std;
class ISort{

	public:
		ISort(){}
		virtual ~ISort(){}
		virtual void sort(vector<int> & vector){
			cout << "generic" << endl;
		};
};