void insert_at_start(){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	cout<<"Enter Data you want to insert at start : ";
	cin>>temp->data;
	if (start==NULL){
		start=temp;
		start->next=NULL;
	}
	else{
		temp->next=start;
		start=temp;
	}
}