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
