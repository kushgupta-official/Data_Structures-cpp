# include <iostream>
# include <algorithm>
using namespace std;

class heap{
	int arr[15];
	int size;
public:
	heap(){
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

void heapify(int arr[],int n){
	heap h;
	for (int i=0;i<n;i++){
		h.insert(arr[i]);
	}
//	h.display();
	for (int i=0;i<n;i++){
		arr[i]=h.extractMax();
//		h.display();
	}
//	cout<<endl;
	
	return;
}

void display_array(int arr[],int n){
	cout<<"Sorted Array : ";
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

int main(void){
	int arr[]={1,4,3,2,6,7,8,2,9,0}; 

	int n=sizeof(arr)/sizeof(arr[0]);
	heapify(arr,n);
	cout<<endl;
	display_array(arr,n);
	return 0;
}
