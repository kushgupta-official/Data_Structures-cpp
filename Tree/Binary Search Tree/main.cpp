# include <iostream>

using namespace std;

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
	while (1){
		if (value > trav->data){
			if (trav->right!=NULL)
				trav=trav->right;
			else{
				trav->right=temp;
				break;
			}
		}
		else if (value < trav->data){
			if (trav->left!=NULL)
				trav=trav->left;
			else{
				trav->left=temp;
				break;
			}
		}
		else{
			return;
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

void search(int value){
	cout<<"\nVisiting Elements : ";
	tree *trav=root;
	while(1){
		cout<<trav->data<<" ";
		if (trav->data==value){
			return;
		}
		else if (value > trav->data){
			trav=trav->right;
		}
		else if (value < trav->data){
			trav=trav->left;
		}
		if (trav==NULL){
			cout<<"\nElement not Found\n";
			return;
		}
	}
}

int main()
{
	int arr[]={4,2,5,6,3,1,8,7};
	for (int i=0;i<sizeof(arr)/sizeof(int);i++){
		insert(arr[i]);
	}
	inorder(root);
	search(9);
	return 0;
}