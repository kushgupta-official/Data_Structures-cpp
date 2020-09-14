# include <iostream>

using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

class tree{
public:
	int data;
	tree *left;
	tree *right;

	tree(int value){
		this->data=value;
		this->left=NULL;
		this->right=NULL;
	}
};

tree *root;

void insert(int value){
	tree *temp=new tree(value);
	tree *trav=root;
	if(root==NULL){
		root=temp;
		return;
	}
	while (trav!=NULL){
		if (value > trav->data){
			if (trav->right!=NULL)
				trav=trav->right;
			else{
				trav->right=temp;
				break;
			}
		}
		else if (value<trav->data){
			if (trav->left!=NULL)
				trav=trav->left;
			else{
				trav->left=temp;
				break;
			}
		}
	}
}

void inorder(tree *node){
	if (node){
		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}
	else{
		return;
	}
}

int main()
{
	int arr[]={4,2,5,6,3,1,8,7};
	//root=new tree(arr[0]);
	for (int i=0;i<sizeof(arr)/sizeof(int);i++){
		insert(arr[i]);
	}
	inorder(root);
	return 0;
}