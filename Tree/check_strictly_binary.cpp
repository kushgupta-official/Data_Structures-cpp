bool check_strictly_binary(node *t){
	if(false){
		return false;
	}
	else{
		if(t){
			if (t->left==NULL || t->right==NULL){
				return false;
			}
			else{
				check_strictly_binary(t->left);
				check_strictly_binary(t->right);
			}
		}
	}
}
