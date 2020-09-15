# include <bits/stdc++.h>

using namespace std;

class tree{
public:
	int data;
	tree *left;
	tree *right;
	int height;

	tree (int value){
		this->data=value;
		this->left=NULL;
		this->right=NULL;
		height=1;
	}
};

tree *root=NULL;

int height(tree *t){
	if (t==NULL){
		return 0;
	}
	return t->height;
}

tree *rightRotate(tree *a){
	tree *b=a->left;
	tree *c=b->right;
	b->right=a;
	a->left=c;

	a->height=1+max(height(a->left),height(a->right));
	b->height=1+max(height(b->left),height(b->right));

	return b;
}

tree *leftRotate(tree *a){
	tree *b=a->right;
	tree *c=b->left;
	b->left=a;
	a->right=c;

	a->height=1+max(height(a->left),height(a->right));
	b->height=1+max(height(b->left),height(b->right));

	return b;
}

int getBalance(tree *node){
	if (node==NULL){
		return 0;
	}
	return height(node->left)-height(node->right);
}

tree* insert(int value,tree *node){
	if (node==NULL){
		return (new tree(value));
	}
	if (value > node->data){
		node->right=insert(value,node->right);
	}
	else if (value < node->data){
		node->left=insert(value,node->left);
	}
	else{
		return node;		//for same valued
	}
	//cout<<node->data<<" "<<value<<endl;
	node->height=1+max(height(node->left),height(node->right));

	int balance=getBalance(node);

	if (balance>1 && node->left->data > value){		//ll
		return rightRotate(node);
	}

	if (balance<-1 && node->right->data < value){	//rr
		return leftRotate(node);
	}

	if (balance>1 && node->left->data < value){		//lr
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance<-1 && node->right->data > value){
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void inorder(tree *t){
	if (t!=NULL){
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	else{
		return;
	}
}

int main(){
	int arr[]={10,20,30,40,50,25};
	for (int i=0;i<sizeof(arr)/sizeof(int);i++){
		root=insert(arr[i],root);
	}
	cout<<"Inorder : ";
	inorder(root);
}