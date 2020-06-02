# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class heap_sort
{
	std::vector<int> data;

	void ReadData(){
		int n;
		cout<<"Enter Number of elements : ";
		cin>>n;
		data.resize(n);
		cout<<"Enter Elements :\n";
		for (int i=0;i<n;i++){
			cin>>data[i];
		}
	}

	int left_child(int i){
		return (2*i+1);
	}

	int right_child(int i){
		return (2*i+2);
	}

	void shift_down(int pos,int size){
		int maxIndex=pos;
		if(left_child(pos)<size && data[maxIndex]<data[left_child(pos)]){
			maxIndex=left_child(pos);
		}
		if (right_child(pos)<size && data[maxIndex]<data[right_child(pos)]){
			maxIndex=right_child(pos);
		}
		if (maxIndex!=pos){
			swap(data[maxIndex],data[pos]);
		//	cout<<maxIndex<<" ";
			shift_down(maxIndex,size);
		}
	}
	void sort(){
		int size=data.size();
		for (int i=size/2;i>=0;i--){
			shift_down(i,size);
		//	cout<<endl;
		}
		
		int temp=size-1;
		for (int i=0;i<size-1;i++){
			swap(data[0],data[temp]);
			temp--;
			shift_down(0,temp);
		}
	}

	void display(){
		cout<<"\nSorted Array : ";
		for (int i=0;i<data.size();i++){
			cout<<data[i]<<" ";
		}
	}

public:

	void solve(){
		ReadData();
		sort();
		display();
	}
};

int main()
{
	heap_sort h;
	h.solve();
	return 0;
}