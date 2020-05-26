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
	
	void shiftup(int loc){
		
		while(loc>=0 && arr[loc]>arr[loc/2]){
			swap(arr[loc],arr[loc/2]);
			loc=loc/2;
		}
	}

	void shiftdown(int loc){

		while(loc<size && (arr[loc]<arr[2*loc] || arr[2*loc+1])){
			if (arr[2*loc]>arr[2*loc+1]){
				swap(arr[loc],arr[2*loc]);
				loc=2*loc;
			}
			else{
				swap(arr[loc],arr[2*loc+1]);
				loc=2*loc+1;
			}
		}
	}

	void insert(int x){
		this->size++;
		arr[size-1]=x;
		shiftup(size-1);
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
			cout<<arr[i]<<" ";
		}
	}
};

int main(void){
	PriorityQueue pq;
	pq.insert(1);
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
