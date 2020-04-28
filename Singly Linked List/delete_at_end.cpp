void delete_at_end(){
	node *ptr,*qtr,*temp;
	temp=start;
	
	if(start->next==NULL){
		start=NULL;
	}
	else{
		while(temp->next!=NULL)
		{
			qtr=temp;
			temp=temp->next;
		}
		free(temp);
		qtr->next=NULL;
	}
	cout<<"Last node Deleted\n";
}
