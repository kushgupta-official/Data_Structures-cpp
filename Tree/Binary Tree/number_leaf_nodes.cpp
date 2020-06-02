int number_leaf_nodes(node *t){
	if (t==NULL){
		return 0;
	}
	if(t->left==NULL && t->right==NULL){
		return 1;
	}
	else{
		int count=number_leaf_nodes(t->left) + number_leaf_nodes(t->right);
		return(count);
	}
}
