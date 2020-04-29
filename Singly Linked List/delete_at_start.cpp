void delete_at_start(){
	node *ptr,*qtr,*temp;
	temp=start;
	start=start->next;
	temp->next=NULL;
	free(temp);
	cout<<"First Node Deleted";
}
