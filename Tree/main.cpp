# include <iostream>
# include <stdlib.h>
using namespace std;

struct node{
	struct node *left;
	int data;
	struct node *right;
};

node *root=NULL;
void check(){
	if (root==NULL){
		cout<<"Tree does not exist";
		return;
	}
}
node *create_btree(){
	int x;
	node *p;
	cout<<"\nEnter Data (-1 for NULL or No Data) : ";
	cin>>x;
	if (x==-1){
		return NULL;
	}
	p=(node*)malloc(sizeof(node*));
	p->data=x;
	cout<<"Enter left child of "<<x;
	p->left=create_btree();
	cout<<"Enter right child of "<<x;
	p->right=create_btree();
	return p;
}

void preorder(node *t){
	if(t){
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(node *t){
	if(t){
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
}

void postorder(node *t){
	if(t){
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<" ";
	}
}

int max_depth(node *t){
	if (t==NULL){
		return 0;
	}
	else{
		int left_depth=max_depth(t->left);
		int right_depth=max_depth(t->right);
		
		if (left_depth>right_depth){
			return left_depth+1;
		}
		else{
			return right_depth+1;
		}
	}
}
int menu(){
	int choice;
	cout<<"\n\nMenu : ";
	cout<<"\n1. Create a Binary Tree";
	cout<<"\n2. Show Preorder";
	cout<<"\n3. Show Inorder";
	cout<<"\n4. Show Postorder";
	cout<<"\n5. Calculate Maximum Height/Depth of the Tree";
	cout<<"\n\nEnter your Choice : ";
	cin>>choice;
	return choice;
}
int main(void){
	int choice;
	do{
		choice=menu();
		switch(choice){
			case 1:
				{
					root=create_btree();
					break;
				}
			case 2:
				{
					preorder(root);
					break;
				}
			case 3:
				{
					inorder(root);
					break;
				}
			case 4:
				{
					postorder(root);
					break;
				}
			case 5:
				{
					int depth=max_depth(root);
					cout<<depth;	
				}
				
		}
	}while(1);
}
