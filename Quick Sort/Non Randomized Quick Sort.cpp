# include <iostream>
# include <algorithm>

using namespace std;

int partition(int arr[],int p,int q){
	int pivot=arr[p];
	int index=p;

	for (int j=p+1;j<=q;j++){
		if (arr[j]<pivot){
			index++;
			swap(arr[j],arr[index]);
		}
	}
	swap(arr[index],arr[p]);
	return index;
}

void quick_sort(int arr[],int p,int q){
	if(p<q){
		int m=partition(arr,p,q);
		quick_sort(arr,p,m-1);
		quick_sort(arr,m+1,q);
	}
}

void display(int arr[],int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arr[]={8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Original Unsorted Array : ";
	display(arr,n);
	quick_sort(arr,0,n-1);
	display(arr,n);
	return 0;
}