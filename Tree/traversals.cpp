void preorder(node *t){
	if(t){
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);
	}
	else{
		return;
	}
}

void inorder(node *t){
	if(t){
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	else{
		return;
	}
}

void postorder(node *t){
	if(t){
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<" ";
	}
	else{
		return;
	}
}
