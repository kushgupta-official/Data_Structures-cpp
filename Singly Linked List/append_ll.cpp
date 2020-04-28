void append_ll(){
	
	struct node *temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter Data you want to append : ";
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
