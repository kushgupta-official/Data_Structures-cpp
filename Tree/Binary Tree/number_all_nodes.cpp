int number_all_nodes(node *t){
	if(!t){
		return 0;
	}
	else if(t){
		return 1 + number_all_nodes(t->left) + number_all_nodes(t->right);
	}
}
