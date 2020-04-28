void insert_at_position(){
	node *temp,*ptr,*qtr;
	cout<<"Enter data : ";
	cin>>qtr->data;
	int pos;
	cout<<"Enter position you want to insert data at : ";
	cin>>pos;
	temp=start;
	int i=0;
	while (temp->next!=NULL){
		if (i==pos-1){
			break;
		}
		i++;
		temp=temp->next;
	}
	ptr=temp->next;
	temp->next=
}
