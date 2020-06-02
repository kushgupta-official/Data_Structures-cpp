int number_internal_nodes(node *t){
	if (t==NULL){
		return 0;
	}
	if(t->left==NULL && t->right==NULL){
		return 0;
	}
	else{
		return(1+number_internal_nodes(t->left) + number_internal_nodes(t->right));
	}
}
