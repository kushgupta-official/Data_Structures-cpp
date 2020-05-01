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
