int number_full_nodes(node* t) 
{
	stack <node*>s;
	vector <int>preorder;
	s.push(t);
	while(!s.empty()){
		preorder.push_back(s.top()->data);
		t=s.top();
		s.pop();
		if(t->right!=NULL){
			s.push(t->right);
		}
		if(t->left!=NULL){
			s.push(t->left);
		}
	}
	return s.size();
} 
