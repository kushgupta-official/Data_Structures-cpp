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
	void shiftup(int loc){
		while (loc>=0 && arr[loc]>arr[loc/2]){
			swap(arr[loc],arr[loc/2]);
			loc=loc/2;
		}
	}
	void shiftdown(int loc){
		while(loc<size && (arr[loc]<arr[loc*2] || arr[loc*2+1])){
			if (arr[loc*2]>arr[loc*2+1]){
				swap(arr[loc],arr[loc*2]);
				loc=loc*2;
			}
			else{
				swap(arr[loc],arr[loc*2+1]);
				loc=loc*2+1;
			}
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
};

void heapify(int arr[],int n){
	heap h;
	for (int i=0;i<n;i++){
		h.insert(arr[i]);
	}
	cout<<endl;
	for (int i=0;i<n;i++){
		arr[i]=h.extractMax();
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return;
}

void display_array(int arr[],int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

int main(void){
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	heapify(arr,n);
	cout<<endl;
	display_array(arr,n);
	return 0;
}
