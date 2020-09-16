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

	node->height=1+max(height(node->left),height(node->right));

	int balance=getBalance(node);

	if (balance>1 && getBalance(node->left)>=0){		//ll
		return rightRotate(node);
	}

	if (balance<-1 && getBalance(node->right)<=0){	//rr
		return leftRotate(node);
	}

	if (balance>1 && getBalance(node->left)<0){		//lr
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance<-1 && getBalance(node->right)>0){	//rl
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

tree *minNode(tree *node){		//returns left most node i.e. minimum valued node in the tree 
	while(node->left!=NULL){
		node=node->left;
	}
	return node;
}

tree *deleteNode(int value,tree *node){
	if (node==NULL){
		return node;
	}
	if (value > node->data){
		node->right=deleteNode(value,node->right);
	}
	else if (value < node->data){
		node->left=deleteNode(value,node->left);
	}
	else{
		tree *temp;
		if (node->left==NULL && node->right==NULL){		//if it's a leaf node
			temp=node;
			node=NULL;
		}
		else if (node->left!=NULL && node->right==NULL){	//if only left child
			temp=node->left;
			*node=*temp;
			free(temp);
		}
		else if (node->left==NULL && node->right!=NULL){	//if only right child
			temp=node->right;
			*node=*temp;
			free(temp);
		}
		else{		//if both childs are non null
			temp=minNode(node->right);
			node->data=temp->data;
			node->right=deleteNode(node->data,node->right);
		}
	}

	if (node==NULL){
		return node;
	}

	node->height=1 + max(height(node->left),height(node->right));

	int balance=getBalance(node);

	if (balance>1 && getBalance(node->left)>=0){		//ll
		return rightRotate(node);
	}

	if (balance<-1 && getBalance(node->right)<=0){	//rr
		return leftRotate(node);
	}

	if (balance>1 && getBalance(node->left)<0){		//lr
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance<-1 && getBalance(node->right)>0){	//rl
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
	int arr[]={4,3,7,5,6,1,2,8,4};
	for (int i=0;i<sizeof(arr)/sizeof(int);i++){
		root=insert(arr[i],root);
	}
	cout<<"Inorder : ";
	inorder(root);
	root=deleteNode(4,root);
	cout<<"\nInorder : ";
	inorder(root);
	return 0;
}