# include <iostream>

using namespace std;

class avl{
public:
	int data;
	avl *left;
	avl *right;
	int height;

	avl (int value){
		this->data=value;
		this->left=NULL;
		this->right=NULL;
		height=1;
	}
}

avl *root=NULL;

void insert(int value){
	avl *temp=new avl(value);
	avl *trav=root;
	while (trav!=NULL){
		if (trav->data < value){
			trav=trav->right;
		}
		else if (trav->data > value){
			trav=trav->left;
		}
		else{
			return;
		}
	}
	trav=temp;
}

int main(){
	int arr[]={4,2,5,3,6,1,8,7};
	for (int i=0;i<sizeof(arr)/sizeof(int);i++){
		t.insert(arr[i]);
	}
	inorder(t);
}