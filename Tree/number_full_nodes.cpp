int number_full_nodes(node *t){
	if(!t){
		return -1;
	}
	else{
		return 1 + number_full_nodes(t->left) + number_full_nodes(t->right);
	}
}
