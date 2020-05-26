# include <iostream>
# include <algorithm>
using namespace std;

class PriorityQueue{
	int arr[15];
	int size;

	public:

	PriorityQueue(){
		for (int i=0;i<15;i++){
			arr[i]=-1;
		}
		size=0;
	}
	int parent(int loc){
		return (loc-1)/2;
	}
	int left_child(int loc){
		return (2*loc)+1;
	}
	int right_child(int loc){
		return (2*loc)+2;
	}
	void shiftup(int loc){
		while (loc>=0 && arr[loc]>arr[parent(loc)]){
			swap(arr[loc],arr[parent(loc)]);
			loc=parent(loc);
		}
	}
	void shiftdown(int loc){
//		this->display();
		int maxIndex=loc;
		int l=left_child(loc);
		int r=right_child(loc);
		if (l<size && arr[maxIndex]<arr[l]){
			maxIndex=l;
		}
		if(r<size && arr[maxIndex]<arr[r]){
			maxIndex=r;
		}
		if(loc!=maxIndex){
			swap(arr[loc],arr[maxIndex]);			
			shiftdown(maxIndex);
		}
	}
	void insert(int i){
		arr[size]=i;
		shiftup(size);
		this->size++;
	}
	int extractMax(){
		int res=arr[0];
		arr[0]=arr[size-1];
		this->size--;
		shiftdown(0);
		return res;
	}
	void display(){
		for (int i=0;i<size;i++){
			cout<<this->arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(void){
	PriorityQueue pq;
	pq.insert(1);
	cout<<pq.extractMax()<<endl;
	pq.insert(2);
	pq.insert(3);
	cout<<pq.extractMax()<<endl;
	pq.insert(4);
	pq.insert(5);
	pq.insert(6);
	pq.insert(7);
	cout<<pq.extractMax()<<endl;
	pq.display();
	return 0;
}
