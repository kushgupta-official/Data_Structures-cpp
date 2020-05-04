/*int number_full_nodes(node *t){
	if(t==NULL){
		return 0;
	}
	else{
		int n=0;
		if (t->left!=NULL && t->right!=NULL){
			n++;
		}
		n+=(number_full_nodes(t->left) + number_full_nodes(t->right));
		return n;
	}
}*/

unsigned int number_full_nodes(node* t) 
{ 
    if (root == NULL) 
       return 0; 
   
    int res = 0; 
    if  (t->left && t->right)  
       res++; 
   
    res += (number_full_nodes(t->left) +  
            number_full_nodes(t->right)); 
    return res; 
} 
